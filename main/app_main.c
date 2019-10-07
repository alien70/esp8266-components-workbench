/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/uart.h"

#define LED (GPIO_NUM_2)

#define AUX (GPIO_NUM_0)
#define M0 (GPIO_NUM_16) // Grey
#define M1 (GPIO_NUM_5)  // White

#define LORA_TXD (GPIO_NUM_13)
#define LORA_RXD (GPIO_NUM_15)
#define LORA_RTS (UART_PIN_NO_CHANGE)
#define LORA_CTS (UART_PIN_NO_CHANGE)

void led_task(void *argc)
{
    int level = 0;
    for (;;)
    {
        level = !level; //gpio_get_level(AUX);
        gpio_set_level(LED, level);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        printf("Hello, World!\n");
    }
}

void setup()
{
    gpio_set_direction(LED, GPIO_MODE_OUTPUT);

    xTaskCreate(led_task, "led_task", 1024, NULL, 10, NULL);
}

void app_main()
{
    setup();
}
