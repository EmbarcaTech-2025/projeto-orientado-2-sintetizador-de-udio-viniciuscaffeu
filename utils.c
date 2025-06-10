#include "pico/stdlib.h"
#include "sintetizador.h"
#include "utils.h"

void delay_ms(uint32_t ms) {
    sleep_ms(ms);
}

void acender_led_rgb(uint8_t r, uint8_t g, uint8_t b) {
    gpio_put(PIN_LED_R, r);
    gpio_put(PIN_LED_G, g);
    gpio_put(PIN_LED_B, b);
}

void apagar_led_rgb() {
    gpio_put(PIN_LED_R, 0);
    gpio_put(PIN_LED_G, 0);
    gpio_put(PIN_LED_B, 0);
}
