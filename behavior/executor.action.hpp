#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

class Blink : public CAT::Action {
public:
    void act(CAT::Element * element) override {
        
        const gpio_num_t led_pin = GPIO_NUM_15;
        gpio_set_direction(led_pin, GPIO_MODE_OUTPUT);

        for (int i = 0; i < 4; ++i) {
            gpio_set_level(led_pin, 1); 
            vTaskDelay(pdMS_TO_TICKS(150));

            gpio_set_level(led_pin, 0); 
            vTaskDelay(pdMS_TO_TICKS(150));
        }

    }
};