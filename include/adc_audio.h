#ifndef ADC_AUDIO_H
#define ADC_AUDIO_H

#include <stdint.h>

void iniciar_adc();
uint16_t ler_microfone();
void gravar_audio(uint16_t *buffer, uint32_t tamanho, float taxa_amostragem);

#endif
