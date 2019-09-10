#include "cppmain.hpp"

#include "main.h"
#include "tim.h"
#include "gpio.h"

#include "stm32_led.hpp"

void setup(void) {
    static Stm32Led led_b(LED_B_GPIO_Port, LED_B_Pin, GPIO_PIN_SET);
    static Stm32Led led_r(LED_R_GPIO_Port, LED_R_Pin, GPIO_PIN_SET);
    static Stm32Led led_o(LED_O_GPIO_Port, LED_O_Pin, GPIO_PIN_SET);
    static Stm32Led led_g(LED_G_GPIO_Port, LED_G_Pin, GPIO_PIN_SET);

    // タイマスタート
	HAL_TIM_Base_Start_IT(&htim6);

    // LEDを点滅させる
    led_b.setFlash();
    led_r.setFlash();
    led_o.setFlash();
    led_g.setFlash();
}

void loop(void) {
   
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim) {
    if(htim->Instance == TIM6) {
        Stm32Led::interrupt_handler();
    }
}
