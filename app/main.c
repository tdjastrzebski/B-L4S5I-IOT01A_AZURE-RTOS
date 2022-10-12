/* Copyright (c) Microsoft Corporation.
   Licensed under the MIT License. */

#include <stdio.h>

#include "tx_api.h"

#include "board_init.h"
#include "sntp_client.h"
#include "stm_networking.h"
#include "stm32l4s5i_iot01.h"
#include "nx_client.h"
#include "azure_config.h"
#include "gui.h"

#define GUI_THREAD_STACK_SIZE 16384
#define AZURE_THREAD_STACK_SIZE 16384
#define AZURE_THREAD_PRIORITY 4

TX_THREAD azure_thread;
TX_THREAD gui_thread;
TX_MUTEX sensorsMutex = {};
TX_TIMER blinkLedTimer;

ULONG azure_thread_stack[AZURE_THREAD_STACK_SIZE / sizeof(ULONG)];
ULONG gui_thread_stack[GUI_THREAD_STACK_SIZE / sizeof(ULONG)];

static void blinkLed(ULONG data);

static void azure_thread_entry(ULONG parameter)
{
    UINT status;

    printf("Starting Azure thread\r\n\r\n");

    // Initialize the network
    if ((status = stm_network_init(WIFI_SSID, WIFI_PASSWORD, WIFI_MODE)))
    {
        printf("ERROR: Failed to initialize the network (0x%08x)\r\n", status);
    }

    else if ((status = azure_iot_nx_client_entry(&nx_ip, &nx_pool, &nx_dns_client, sntp_time)))
    {
        printf("ERROR: Failed to run Azure IoT (0x%04x)\r\n", status);
    }
}

void tx_application_define(void *first_unused_memory)
{
    UINT status = tx_timer_create(&blinkLedTimer, "blink LED", blinkLed, 0x1234, 50, 10, TX_AUTO_ACTIVATE);
    
    status = tx_mutex_create(&sensorsMutex, "Sensors mutex", TX_NO_INHERIT);
    
    // Create GUI thread
    status = tx_thread_create(&gui_thread, "GUI thread", gui_thread_entry, 0, gui_thread_stack, GUI_THREAD_STACK_SIZE, 2, 2, TX_NO_TIME_SLICE, TX_AUTO_START);
    if (status != TX_SUCCESS)
    {
        printf("ERROR: GUI thread creation failed\r\n");
    }
    // static TX_TIMER displayRefreshTimer;
    // status = tx_timer_create(&displayRefreshTimer, "display refresh timer", DisplayTemp, 0x1234, 500, 500, TX_AUTO_ACTIVATE);

    // Create Azure thread
    status = tx_thread_create(&azure_thread,
                              "Azure Thread",
                              azure_thread_entry,
                              0,
                              azure_thread_stack,
                              AZURE_THREAD_STACK_SIZE,
                              AZURE_THREAD_PRIORITY,
                              AZURE_THREAD_PRIORITY,
                              TX_NO_TIME_SLICE,
                              TX_AUTO_START);

    if (status != TX_SUCCESS)
    {
        printf("ERROR: Azure IoT thread creation failed\r\n");
    }
}

int main(void)
{
    // Initialize the board
    board_init();

    // Enter the ThreadX kernel
    tx_kernel_enter();

    return 0;
}

static void blinkLed(ULONG data)
{
    static uint32_t pattern = 0xF0F0CCC0;
    static uint32_t shift = 0;
    HAL_GPIO_WritePin(LED2_GPIO_PORT, LED2_PIN, (pattern >> shift) & 0x1 ? GPIO_PIN_SET : GPIO_PIN_RESET);
    shift++;
    shift %= 32;
}
