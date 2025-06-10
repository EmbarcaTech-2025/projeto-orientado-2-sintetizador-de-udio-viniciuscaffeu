#ifndef PWM_AUDIO_H
#define PWM_AUDIO_H

#include <stdint.h>

void iniciar_pwm();
void reproduzir_audio(uint16_t *buffer, uint32_t tamanho, float taxa_amostragem);

#endif
