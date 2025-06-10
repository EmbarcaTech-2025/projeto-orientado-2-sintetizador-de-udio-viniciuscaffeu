#include "sintetizador.h"
#include "utils.h"

void inicializar_perifericos() {
    //stdio_init_all();

    gpio_init(PIN_BOTAO_A);
    gpio_init(PIN_BOTAO_B);
    gpio_set_dir(PIN_BOTAO_A, GPIO_IN);
    gpio_set_dir(PIN_BOTAO_B, GPIO_IN);
    gpio_pull_up(PIN_BOTAO_A);
    gpio_pull_up(PIN_BOTAO_B);

    gpio_init(PIN_LED_R);
    gpio_init(PIN_LED_G);
    gpio_init(PIN_LED_B);
    gpio_set_dir(PIN_LED_R, GPIO_OUT);
    gpio_set_dir(PIN_LED_G, GPIO_OUT);
    gpio_set_dir(PIN_LED_B, GPIO_OUT);

    gpio_put(PIN_LED_R, 0);
    gpio_put(PIN_LED_G, 0);
    gpio_put(PIN_LED_B, 0);
}

int main() {
    inicializar_perifericos();

    while (true) {
        if (gpio_get(PIN_BOTAO_A) == 0) {
            gpio_put(PIN_LED_R, 1);
        } else {
            gpio_put(PIN_LED_R, 0);
        }

        if (gpio_get(PIN_BOTAO_B) == 0) {
            gpio_put(PIN_LED_G, 1);
        } else {
            gpio_put(PIN_LED_G, 0);
        }

        sleep_ms(10);
    }
}



