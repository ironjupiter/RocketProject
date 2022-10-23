/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include <stdio.h>

int main() {
#ifndef PICO_DEFAULT_LED_PIN
#warning blink example requires a board with a regular LED
#else

    stdio_init_all();
    const uint LED_OUT = 1;
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    const uint BUTTON_IN = 2;
    const uint BUTTON_OUT = 4;
    gpio_init(LED_OUT);
    gpio_init(LED_PIN);
    gpio_init(BUTTON_IN);
    gpio_init(BUTTON_OUT);
    gpio_set_dir(LED_OUT, GPIO_OUT);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_set_dir(BUTTON_IN, GPIO_IN);
    gpio_set_dir(BUTTON_OUT, GPIO_OUT);
    gpio_put(BUTTON_OUT, 1);
    gpio_put(LED_PIN, 1);

    const uint SLAVE_POWER = 16;
    const uint SERIAL_CLOCK = 19;
    const uint SERIAL_DRIVE = 18;

    gpio_set_function(SERIAL_CLOCK, GPIO_FUNC_I2C);
    gpio_set_function(SERIAL_DRIVE, GPIO_FUNC_I2C);

    uint hz = i2c_init(i2c1, 1000);
    //uint8_t MPU_ADDRESS = 0x68;
    //bi_decl(bi_2pins_with_func(SERIAL_DRIVE, SERIAL_CLOCK, GPIO_FUNC_I2C));

   // mpu6050_reset();

    int16_t acceleration[3], gyro[3], temp;

    while (true) {
        
        if(gpio_get(BUTTON_IN) == 0){
            gpio_put(LED_OUT, 0);
            gpio_put(LED_PIN, 1);
        } else {
            gpio_put(LED_OUT, 1);
            gpio_put(LED_PIN, 0);
        }
        
        printf(" sanity check \n");
        //printf("hertz %d \n", hz);

        sleep_ms(250);
    }
#endif
}

