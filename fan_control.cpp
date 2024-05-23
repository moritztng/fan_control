#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

int main()
{
    uint FAN_GPIO = 2;
    uint SLICE_NUM = pwm_gpio_to_slice_num(FAN_GPIO);
    uint16_t WRAP = 125000 / 20;
    float DEFAULT_SPEED = 0.05;

    stdio_init_all();
    gpio_set_function(FAN_GPIO, GPIO_FUNC_PWM);
    pwm_set_wrap(SLICE_NUM, WRAP);
    pwm_set_chan_level(SLICE_NUM, PWM_CHAN_A, (uint16_t)(DEFAULT_SPEED * WRAP));
    pwm_set_enabled(SLICE_NUM, true);
    while (true)
    {
        float speed;
        scanf("%f", &speed);
        printf("%f\n", speed);
        pwm_set_chan_level(SLICE_NUM, PWM_CHAN_A, (uint16_t)(speed * WRAP));
    }
}
