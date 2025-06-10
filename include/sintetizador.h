#ifndef SINTETIZADOR_H
#define SINTETIZADOR_H

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/pwm.h"
#include "hardware/gpio.h"
#include "hardware/i2c.h"

#define BUFFER_SIZE 16000       // 2 segundos a 8 kHz
#define SAMPLE_RATE 8000        // Hz

#define PIN_MICROFONE 28        // ADC0 no GPIO26
#define PIN_PWM 21              // Saída PWM para buzzer

#define PIN_BOTAO_A 5
#define PIN_BOTAO_B 6

#define PIN_LED_R 13
#define PIN_LED_G 11
#define PIN_LED_B 12

extern uint16_t buffer[BUFFER_SIZE];

#endif
