#include "gui.h"

#include <stdio.h>

#include "EPD_2in66.h"
#include "lvgl.h"
#include "stm32l4s5i_iot01.h"
#include "stm32l4s5i_iot01_accelero.h"
#include "stm32l4s5i_iot01_gyro.h"
#include "stm32l4s5i_iot01_hsensor.h"
#include "stm32l4s5i_iot01_magneto.h"
#include "stm32l4s5i_iot01_psensor.h"
#include "stm32l4s5i_iot01_tsensor.h"
#include "tx_api.h"

#define DISPLAY_LINE_SIZE EPD_2IN66_LINE_SIZE
#define DISPLAY_SIZE (EPD_2IN66_LINE_SIZE * EPD_2IN66_HEIGHT)
// note: width and height are swapped since image is rotated
#define SCREEN_WIDTH EPD_2IN66_HEIGHT
#define SCREEN_HEIGHT EPD_2IN66_WIDTH

extern lv_font_t liberation_mono_20;
extern TX_MUTEX sensorsMutex;

static uint8_t _image[DISPLAY_SIZE];
static char *_message;
static uint32_t _messageCountDown = 0;
static uint32_t _sensorDataCountDown = 0;
static void SetPixel(uint16_t x, uint16_t y, bool pixelSet);
static uint16_t DrawLvString(uint16_t posX, uint16_t posY, const char *str, lv_font_t const *pFont);
static void DisplaySensorData(void);
static void DisplayMessage(const char *message);
static void DrawBorder(void);
static void RemoveChar(char *str, char garbage);

void gui_thread_entry(ULONG parameter) {
	printf("Starting GUI thread\r\n\r\n");
	// display init
	memset(_image, 0xFF, DISPLAY_SIZE);
	EPD_2IN66_Init_Partial();
	EPD_2IN66_TurnOnDisplay();
	EPD_2IN66_Display(_image);
	EPD_2IN66_TurnOnDisplay();

	show_message("Hello World!\nB-L4S5I-IOT01A demo");
	// DrawBorder();
	tx_thread_sleep(300);

	while (1) {
		if (_messageCountDown > 0) {
			_messageCountDown--;
		} else if (_sensorDataCountDown > 0) {
			_sensorDataCountDown--;
		} else if (_sensorDataCountDown == 0) {
			DisplaySensorData();
			_sensorDataCountDown = 20;
		}

		tx_thread_sleep(10);
	}
}

void show_message(const char *message) {
	if (message == NULL) {
		dismiss_message();
	} else {
		size_t len = strlen(message);
		_message = malloc(len + 1);
		strcpy(_message, message);
		DisplayMessage(_message);
		_messageCountDown = 40;
	}
	if (_message != NULL) {
		free(_message);
		_message = NULL;
	}
}

void dismiss_message(void) {
	_messageCountDown = 0;
	_sensorDataCountDown = 0;
}

static void DisplaySensorData(void) {
	static char textBuffer[64];
	memset(_image, 0xFF, DISPLAY_SIZE);

	UINT mutexStatus = TX_NO_INSTANCE;
	if (sensorsMutex.tx_mutex_id != 0) {
		// lock sensors shared access
		mutexStatus = tx_mutex_get(&sensorsMutex, TX_WAIT_FOREVER);
	}

	double temp = BSP_TSENSOR_ReadTemp();
	double pressure = BSP_PSENSOR_ReadPressure();
	double humidity = BSP_HSENSOR_ReadHumidity();
	int16_t magneto[3];
	BSP_MAGNETO_GetXYZ(magneto);
	int16_t accelero[3];
	BSP_ACCELERO_AccGetXYZ(accelero);
	float gyro[3];
	BSP_GYRO_GetXYZ(gyro);

	if (mutexStatus == TX_SUCCESS) {
		mutexStatus = tx_mutex_put(&sensorsMutex);
	}

	snprintf(textBuffer, sizeof(textBuffer), "temp: %.1f°C", temp);
	DrawLvString(0, 0, textBuffer, &liberation_mono_20);
	snprintf(textBuffer, sizeof(textBuffer), "pressure: %.1fhPa", pressure);
	DrawLvString(0, 25, textBuffer, &liberation_mono_20);
	snprintf(textBuffer, sizeof(textBuffer), "humidity: %.1f%%", humidity);
	DrawLvString(0, 50, textBuffer, &liberation_mono_20);
	snprintf(textBuffer, sizeof(textBuffer), "magneto: %i %i %i", magneto[0], magneto[1], magneto[2]);
	DrawLvString(0, 75, textBuffer, &liberation_mono_20);
	snprintf(textBuffer, sizeof(textBuffer), "accelero: %i %i %i", accelero[0], accelero[1], accelero[2]);
	DrawLvString(0, 100, textBuffer, &liberation_mono_20);
	snprintf(textBuffer, sizeof(textBuffer), "gyro: %.0f %.0f %.0f", (double)gyro[0], (double)gyro[1], (double)gyro[2]);
	DrawLvString(0, 125, textBuffer, &liberation_mono_20);

	EPD_2IN66_Display(_image);
	EPD_2IN66_TurnOnDisplay();
}

void DisplayMessage(const char *message) {
	const uint8_t LineWidth = 24;
	const uint8_t MaxLineCount = 6;
	const uint8_t LineHeight = 25;
	char lineBuffer[4 * LineWidth + 1];
	uint32_t nextCharIndex = 0;  // index of the next character in string
	uint32_t lineBeginCharIndex = 0;
	uint32_t currentChar = 0;
	uint16_t lineCharCount = 0;  // line char count
	uint8_t lineIndex = 0;       // line index

	memset(_image, 0xFF, DISPLAY_SIZE);

	do {
		currentChar = lv_txt_utf8_next(message, &nextCharIndex);
		if (currentChar == 13) continue;  // skip '\r' char
		if (currentChar) lineCharCount++;
		if (lineCharCount % LineWidth == 0 || (currentChar == 0 && lineCharCount > 0) || currentChar == 10) {
			uint16_t copyLen = nextCharIndex - lineBeginCharIndex + 1 - (currentChar == 10 ? 1 : 0);
			strlcpy(lineBuffer, message + lineBeginCharIndex, copyLen);
			RemoveChar(lineBuffer, '\r');  // TODO: improve to make sure no part of the complex UTF char is removed
			DrawLvString(0, lineIndex * LineHeight, lineBuffer, &liberation_mono_20);
			lineBeginCharIndex = nextCharIndex;
			lineCharCount = 0;
			lineIndex++;
		}
	} while (lineIndex < MaxLineCount && currentChar);

	EPD_2IN66_Display(_image);
	EPD_2IN66_TurnOnDisplay();
}

uint16_t DrawLvString(uint16_t posX, uint16_t posY, const char *str, const lv_font_t *pFont) {
	lv_font_glyph_dsc_t dsc;
	uint16_t newPosX = posX;
	uint32_t nextCharIndex = 0;  // index of the next character in string
	uint32_t currentChar = lv_txt_utf8_next(str, &nextCharIndex);

	while (currentChar) {
		// for each char in the string
		uint32_t nextChar = lv_txt_utf8_next(str, &nextCharIndex);
		bool ret = lv_font_get_glyph_dsc(pFont, &dsc, currentChar, nextChar);

		if (!ret) {
			// char not found - draw '?' (0x3F)
			currentChar = '?';
			// get glyph descriptor
			ret = lv_font_get_glyph_dsc(pFont, &dsc, currentChar, 0);
			if (!ret) {
				// '?' char not found either
				currentChar = nextChar;
				continue;
			}
		}

		// get glyph bitmap
		const uint8_t *bitmap = lv_font_get_glyph_bitmap(pFont, currentChar);
		// get bitmap vertical offset
		int16_t offsetY = pFont->line_height - pFont->base_line - dsc.ofs_y - dsc.box_h;  // box offset from the top
		                                                                                  // draw glyph bitmap
		uint8_t z = 0;
		for (uint16_t y = offsetY; y < dsc.box_h + offsetY; y++) {
			for (uint16_t x = dsc.ofs_x; x < dsc.box_w + dsc.ofs_x; x++) {
				SetPixel(newPosX + x, posY + y, ((*bitmap << z) & 0x80));
				z++;
				z %= 8;
				if (z == 0) bitmap++;
			}
		}

		newPosX += dsc.adv_w;
		currentChar = nextChar;
	}

	return newPosX - posX;
}

static void SetPixel(uint16_t x, uint16_t y, bool pixelSet) {
	uint16_t dispY = SCREEN_WIDTH - x - 1;
	uint16_t dispX = y;
	uint16_t addr = dispX / 8 + dispY * DISPLAY_LINE_SIZE;
	if (pixelSet) {
		_image[addr] &= ~(0x80 >> (dispX % 8));
	} else {
		_image[addr] |= (0x80 >> (dispX % 8));
	}
}

static void DrawBorder(void) {
	for (uint16_t i = 0; i < SCREEN_WIDTH; i++) {
		SetPixel(i, 0, true);
		SetPixel(i, SCREEN_HEIGHT - 1, true);
	}
	for (uint16_t i = 0; i < SCREEN_HEIGHT; i++) {
		SetPixel(0, i, true);
		SetPixel(SCREEN_WIDTH - 1, i, true);
	}
}

// Source: https://stackoverflow.com/questions/5457608/how-to-remove-the-character-at-a-given-index-from-a-string-in-c
void RemoveChar(char *str, char garbage) {
	char *src, *dst;
	for (src = dst = str; *src != '\0'; src++) {
		*dst = *src;
		if (*dst != garbage) dst++;
	}
	*dst = '\0';
}