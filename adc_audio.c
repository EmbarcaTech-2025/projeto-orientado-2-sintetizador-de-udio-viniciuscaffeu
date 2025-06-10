#include "sintetizador.h"
#include "adc_audio.h"
#include "utils.h"

void iniciar_adc() {
    adc_init();
    adc_gpio_init(PIN_MICROFONE);
    adc_select_input(0); // ADC0 no GPIO26
}

uint16_t ler_microfone() {
    return adc_read(); // Valor de 0 a 4095
}

void gravar_audio(uint16_t *buffer, uint32_t tamanho, float taxa_amostragem) {
    float intervalo_ms = 1000.0f / taxa_amostragem;
    for (uint32_t i = 0; i < tamanho; i++) {
        buffer[i] = ler_microfone();
        delay_ms((uint32_t) intervalo_ms);
    }
}
