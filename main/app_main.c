/* MQTT (over TCP) Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#include "driver/gpio.h"
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/event_groups.h>
#include "mqtt_service.h"

static const char *TAG = "MQTT_EXAMPLE";

static response_data_t* response;



void app_main(void)
{
    response = build_response_data_struct();
    init_mqtt(response);
    gpio_set_direction(2, GPIO_MODE_OUTPUT);
    vTaskDelay(2000 / portTICK_PERIOD_MS);

    while(!response->response->is_connected);

    subscribe();
    vTaskDelay(2000 / portTICK_PERIOD_MS);

    while(1) {
        while(response->response->has_received_data == 0) vTaskDelay(100 / portTICK_PERIOD_MS); 
        if(get_response(response)) {
            gpio_set_level(2, 1);
        }
        while(1) vTaskDelay(100 / portTICK_PERIOD_MS); 
    }
}
