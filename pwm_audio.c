#include "sintetizador.h"
#include "pwm_audio.h"
#include "utils.h"

void iniciar_pwm() {
    gpio_set_function(PIN_PWM, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(PIN_PWM);

    // Configurar frequência base do PWM
    pwm_set_wrap(slice_num, 4095); // 12 bits
    pwm_set_enabled(slice_num, true);
}

void reproduzir_audio(uint16_t *buffer, uint32_t tamanho, float taxa_amostragem) {
    float intervalo_ms = 1000.0f / taxa_amostragem;
    uint slice_num = pwm_gpio_to_slice_num(PIN_PWM);

    for (uint32_t i = 0; i < tamanho; i++) {
        pwm_set_gpio_level(PIN_PWM, buffer[i]); // Valor de 0 a 4095
        delay_ms((uint32_t) intervalo_ms);
    }

    pwm_set_gpio_level(PIN_PWM, 0); // Desliga o PWM no final
}
