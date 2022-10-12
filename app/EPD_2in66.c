/* ***************************************************************************
* | File      	:  	EPD_2in66.c
* | Author      :   Waveshare team
* | Function    :   2.66inch e-paper
* | Info        :
*----------------
* |	This version:   V1.0
* | Date        :   2020-07-29
* | Info        :
* -----------------------------------------------------------------------------
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documnetation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to  whom the Software is
# furished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#
******************************************************************************/
#include "EPD_2in66.h"

#include <stdio.h>
#include <string.h>

#include "main.h"

extern SPI_HandleTypeDef hspi1;

const unsigned char WF_PARTIAL[159] = {
    0x00,
    0x40,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x80,
    0x80,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x40,
    0x40,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x80,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x0A,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x02,
    0x01,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x01,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x22,
    0x22,
    0x22,
    0x22,
    0x22,
    0x22,
    0x00,
    0x00,
    0x00,
    0x22,
    0x17,
    0x41,
    0xB0,
    0x32,
    0x36,
};

// Hardware reset
static void EPD_2IN66_Reset(void) {
	HAL_GPIO_WritePin(DISP_RST_GPIO_Port, DISP_RST_Pin, GPIO_PIN_SET);
	HAL_Delay(200);
	HAL_GPIO_WritePin(DISP_RST_GPIO_Port, DISP_RST_Pin, GPIO_PIN_RESET);
	HAL_Delay(2);
	HAL_GPIO_WritePin(DISP_RST_GPIO_Port, DISP_RST_Pin, GPIO_PIN_SET);
	HAL_Delay(200);
}

// Send command
void EPD_2IN66_SendCommand(uint8_t Reg) {
	HAL_GPIO_WritePin(DISP_DC_GPIO_Port, DISP_DC_Pin, GPIO_PIN_RESET);
#ifndef USE_HARDWARE_CS
	HAL_GPIO_WritePin(DISP_CS_GPIO_Port, DISP_CS_Pin, GPIO_PIN_RESET);
#endif
	HAL_SPI_Transmit(&hspi1, &Reg, 1, 500);
#ifndef USE_HARDWARE_CS
	HAL_GPIO_WritePin(DISP_CS_GPIO_Port, DISP_CS_Pin, GPIO_PIN_SET);
#endif
}

// Send data
void EPD_2IN66_SendData(uint8_t Data) {
	HAL_GPIO_WritePin(DISP_DC_GPIO_Port, DISP_DC_Pin, GPIO_PIN_SET);
#ifndef USE_HARDWARE_CS
	HAL_GPIO_WritePin(DISP_CS_GPIO_Port, DISP_CS_Pin, GPIO_PIN_RESET);
#endif
	HAL_StatusTypeDef status = HAL_SPI_Transmit(&hspi1, &Data, 1, 500);
#ifndef USE_HARDWARE_CS
	HAL_GPIO_WritePin(DISP_CS_GPIO_Port, DISP_CS_Pin, GPIO_PIN_SET);
#endif
}

// Send data
static void EPD_2IN66_SendLongData(const uint8_t *Data, uint16_t Size) {
	HAL_GPIO_WritePin(DISP_DC_GPIO_Port, DISP_DC_Pin, GPIO_PIN_SET);
#ifndef USE_HARDWARE_CS
	HAL_GPIO_WritePin(DISP_CS_GPIO_Port, DISP_CS_Pin, GPIO_PIN_RESET);
#endif
	HAL_StatusTypeDef status = HAL_SPI_Transmit(&hspi1, (uint8_t *)Data, Size, 500);
#ifndef USE_HARDWARE_CS
	HAL_GPIO_WritePin(DISP_CS_GPIO_Port, DISP_CS_Pin, GPIO_PIN_SET);
#endif
}

// Wait until the busy_pin goes LOW
void EPD_2IN66_ReadBusy(void) {
	HAL_Delay(10);
	while (HAL_GPIO_ReadPin(DISP_BUSY_GPIO_Port, DISP_BUSY_Pin) == GPIO_PIN_SET) {  // LOW: idle, HIGH: busy
		HAL_Delay(1);
	}
	HAL_Delay(10);
}

// Activate Display Update Sequence
void EPD_2IN66_TurnOnDisplay(void) {
	EPD_2IN66_SendCommand(0x20);  // Activate Display Update Sequence (specified in R22h)
	EPD_2IN66_ReadBusy();
}

// Send LUT
static void EPD_2IN66_SetLUT(void) {
	EPD_2IN66_SendCommand(0x32);  // set LUT
	EPD_2IN66_SendLongData(WF_PARTIAL, sizeof(WF_PARTIAL));
	EPD_2IN66_ReadBusy();
}

// Initialize the e-Paper register
void EPD_2IN66_Init(void) {
	EPD_2IN66_Reset();
	EPD_2IN66_ReadBusy();
	EPD_2IN66_SendCommand(0x12);  // soft  reset
	EPD_2IN66_ReadBusy();

	/*	Y increment, X increment	*/
	EPD_2IN66_SendCommand(0x11);  // data entry mode
	EPD_2IN66_SendData(0x03);
	/*	Set RamX-address Start/End position	*/
	EPD_2IN66_SendCommand(0x44);  //
	EPD_2IN66_SendData(0x01);
	EPD_2IN66_SendData(EPD_2IN66_LINE_SIZE);
	/*	Set RamY-address Start/End position	*/
	EPD_2IN66_SendCommand(0x45);
	EPD_2IN66_SendData(0);
	EPD_2IN66_SendData(0);
	EPD_2IN66_SendData((EPD_2IN66_HEIGHT & 0xff));
	EPD_2IN66_SendData((EPD_2IN66_HEIGHT & 0x100) >> 8);

	EPD_2IN66_ReadBusy();
	// EPD_2IN66_TurnOnDisplay();
}


// Initialize the e-Paper register(Partial display)
void EPD_2IN66_Init_Partial(void) {
	EPD_2IN66_Reset();
	EPD_2IN66_ReadBusy();
	EPD_2IN66_SendCommand(0x12);  // soft  reset
	EPD_2IN66_ReadBusy();

	EPD_2IN66_SetLUT();
	EPD_2IN66_SendCommand(0x37);
	EPD_2IN66_SendData(0x00);
	EPD_2IN66_SendData(0x00);
	EPD_2IN66_SendData(0x00);
	EPD_2IN66_SendData(0x00);
	EPD_2IN66_SendData(0x00);
	EPD_2IN66_SendData(0x40);
	EPD_2IN66_SendData(0x00);
	EPD_2IN66_SendData(0x00);
	EPD_2IN66_SendData(0x00);
	EPD_2IN66_SendData(0x00);

	/* Y increment, X increment */
	EPD_2IN66_SendCommand(0x11);
	EPD_2IN66_SendData(0x03);
	/*	Set RamX-address Start/End position	*/
	EPD_2IN66_SendCommand(0x44);
	EPD_2IN66_SendData(0x01);
	EPD_2IN66_SendData(EPD_2IN66_LINE_SIZE);
	/*	Set RamY-address Start/End position	*/
	EPD_2IN66_SendCommand(0x45);
	EPD_2IN66_SendData(0);
	EPD_2IN66_SendData(0);
	EPD_2IN66_SendData((EPD_2IN66_HEIGHT & 0xff));
	EPD_2IN66_SendData((EPD_2IN66_HEIGHT & 0x100) >> 8);

	EPD_2IN66_SendCommand(0x3C); /* Border waveform */
	EPD_2IN66_SendData(0x80);

	EPD_2IN66_SendCommand(0x22);
	EPD_2IN66_SendData(0xCF);
	EPD_2IN66_SendCommand(0x20);
	EPD_2IN66_ReadBusy();
}

// Clear screen
void EPD_2IN66_Clear(void) {
	EPD_2IN66_SendCommand(0x24);
	uint8_t blankLine[EPD_2IN66_LINE_SIZE];
	memset(blankLine, 0xff, EPD_2IN66_LINE_SIZE);

	for (uint16_t j = 0; j <= EPD_2IN66_HEIGHT; j++) {
		EPD_2IN66_SendLongData(blankLine, EPD_2IN66_LINE_SIZE);
	}
	// EPD_2IN66_TurnOnDisplay();
}

// Sends the image buffer in RAM to e-Paper and displays
void EPD_2IN66_Display(const uint8_t *image) {
	EPD_2IN66_SendCommand(0x24);
	EPD_2IN66_SendLongData(image, EPD_2IN66_LINE_SIZE * EPD_2IN66_HEIGHT);
}

// Enter sleep mode
void EPD_2IN66_Sleep(void) {
	EPD_2IN66_SendCommand(0x10);
	EPD_2IN66_SendData(0x01);
	// EPD_2IN66_ReadBusy();
}

// Activates display update sequence. TODO: test, not used yet
void EPD_2IN66_RefreshDisplay(void) {
	// Write on the Display update control register
	EPD_2IN66_SendCommand(0x22);

	// Display update data sequence option
	EPD_2IN66_SendData(0xC4);  // ?

	// Launching the update: Nothing should interrupt this sequence in order to avoid display corruption
	EPD_2IN66_SendCommand(0x20);

	// added:
	EPD_2IN66_ReadBusy();
	HAL_GPIO_WritePin(DISP_RST_GPIO_Port, DISP_RST_Pin, GPIO_PIN_SET);
}

// Disables the clock and the charge pump. TODO: test, not used yet
void EPD_2IN66_CloseChargePump(void) {
	// Write on the Display update control register
	EPD_2IN66_SendCommand(0x22);

	// Disable CP then Disable Clock signal
	EPD_2IN66_SendData(0x03);

	// Launching the update: Nothing should interrupt this sequence in order to avoid display corruption
	EPD_2IN66_SendCommand(0x20);

	// added:
	HAL_Delay(400);
}

// this method is copied from ST GDE021A11 driver for testing
void EPD_2IN66_SetDisplayWindow(uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height) {
	// Set Y position and the height
	EPD_2IN66_SendCommand(0x44);
	EPD_2IN66_SendData(Ypos);
	EPD_2IN66_SendData(Height);
	// Set X position and the width
	EPD_2IN66_SendCommand(0x45);
	EPD_2IN66_SendData(Xpos);
	EPD_2IN66_SendData(Width);
	// Set the height counter
	EPD_2IN66_SendCommand(0x4E);
	EPD_2IN66_SendData(Ypos);
	// Set the width counter
	EPD_2IN66_SendCommand(0x4F);
	EPD_2IN66_SendData(Xpos);
}

// this method is copied from ST GDE021A11 driver for testing
void gde021a1_Init(void) {
	// Initialize the GDE021A11 (250x122) [172x18] ?
	// EPD_IO_Init();

	EPD_2IN66_SendCommand(0x10);  // Deep sleep mode disable
	EPD_2IN66_SendData(0x00);
	EPD_2IN66_SendCommand(0x11);  // Data Entry Mode Setting
	EPD_2IN66_SendData(0x03);
	EPD_2IN66_SendCommand(0x44);  // Set the RAM X start/end address
	EPD_2IN66_SendData(0x00);     // RAM X address start = 00h
	EPD_2IN66_SendData(0x11);     // RAM X adress end = 11h (17 * 4pixels by address = 72 pixels)
	EPD_2IN66_SendCommand(0x45);  // Set the RAM Y start/end address
	EPD_2IN66_SendData(0x00);     // RAM Y address start = 0
	EPD_2IN66_SendData(0xAB);     // RAM Y adress end = 171
	EPD_2IN66_SendCommand(0x4E);  // Set RAM X Address counter
	EPD_2IN66_SendData(0x00);
	EPD_2IN66_SendCommand(0x4F);  // Set RAM Y Address counter
	EPD_2IN66_SendData(0x00);
	EPD_2IN66_SendCommand(0xF0);  // Booster Set Internal Feedback Selection
	EPD_2IN66_SendData(0x1F);
	EPD_2IN66_SendCommand(0x21);  // Disable RAM bypass and set GS transition to GSA = GS0 and GSB = GS3
	EPD_2IN66_SendData(0x03);
	EPD_2IN66_SendCommand(0x2C);  // Write VCOMregister
	EPD_2IN66_SendData(0xA0);
	EPD_2IN66_SendCommand(0x3C);  // Border waveform
	EPD_2IN66_SendData(0x64);
	EPD_2IN66_SendCommand(0x32);  // Write LUT register

	// EPD_2IN66_SendLongData(WF_PARTIAL, sizeof(WF_PARTIAL));

	for (uint8_t nb_bytes = 0; nb_bytes < sizeof(WF_PARTIAL); nb_bytes++) {
		EPD_2IN66_SendData(WF_PARTIAL[nb_bytes]);
	}
}
