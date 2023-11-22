#include <stdio.h>
#include "led.h"
#include "lights_car.h"
#include "lights_pedestrian.h"
#include "button.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

extern "C" 
{
    void app_main(void)
    {
        Led red_c(GPIO_NUM_4); //red_auto
        Led yellow_c(GPIO_NUM_5); //yellow_auto
        Led green_c(GPIO_NUM_18); //green_auto
        Led red_p(GPIO_NUM_19); //red_chodec
        Led green_p(GPIO_NUM_21); //zelene_chodec
        Led wait_led(GPIO_NUM_2); //cakajte
        Button tlacidlo(GPIO_NUM_22); //button

        Lights_car* semafor_auto = new Lights_car(green_c, yellow_c, red_c);
        Lights_pedestrian* semafor_chodec = new Lights_pedestrian(green_p, red_p);

        while(1){
            semafor_auto->setGreen();
            semafor_chodec->setRed();
            while(tlacidlo.getState()){
                vTaskDelay(10 / portTICK_PERIOD_MS);
                continue;
            }
            wait_led.on();
            vTaskDelay(3000 / portTICK_PERIOD_MS);
            semafor_auto->setYellow();
            vTaskDelay(1500 / portTICK_PERIOD_MS);
            semafor_auto->setRed();
            vTaskDelay(3000 / portTICK_PERIOD_MS);
            wait_led.off();
            semafor_chodec->setGreen();
            vTaskDelay(5000 / portTICK_PERIOD_MS);
            semafor_chodec->setRed();
            vTaskDelay(3000 / portTICK_PERIOD_MS);
            semafor_auto->setYellow();
            vTaskDelay(1500 / portTICK_PERIOD_MS);
        }

    }

}
