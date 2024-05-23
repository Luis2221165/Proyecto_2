//***************************************************************************
//Universidad del valle de Guatemala
//IE2023: Programación de Microcontroladores
//Autor: Luis Angel Ramirez Orózco
//Proyecto: Proyecto 2
//Hardware: ATMEGA328P
//Creado: 22/05/2024
//***************************************************************************
//***************************************************************************
//***************************************************************************


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "ADC/ADC.h"
#include "PWM1/PWM1.h"
#include "PWM0/PWM0.h"

volatile uint8_t opcion_menu = 0;
uint8_t adc_value_A = 0;
uint8_t adc_value_B = 0;
uint8_t adc_value_C = 0;
uint8_t adc_value_D = 0;

void initializeHardware() {
	DDRD &= ~(1 << 2); // Configura el pin del botón como entrada (PD2)
	PORTD |= (1 << 2); // Activa el pull-up interno en el pin del botón

	PCICR |= (1 << PCIE2); // Habilita interrupciones por cambio de pin en el puerto C
	PCMSK2 |= (1 << PCINT18); // Configura la interrupción para el pin PC0

	DDRC |= (1 << 0) | (1 << 1) | (1 << 5); // Configura los pines de los LEDs como salidas

	initADC(); // Inicializa el ADC
	setupPWM1(); // Inicializa el PWM1
	setupPWM0(); // Inicializa el PWM0

	sei(); // Habilita las interrupciones globales
}

int main(void) {
	initializeHardware();

	while (1) {
		handleOption();
	}

	return 0;
}

void handleOption() {
	PORTC &= ~((1 << 0) | (1 << 1) | (1 << 5)); // Apaga todos los LEDs

	switch (opcion_menu) {
		case 0: // Modo Manual
		startADCConversion(0x06); // Canal A (A6)
		startADCConversion(0x04); // Canal B (A4)
		startADCConversion(0x03); // Canal C (A3)
		startADCConversion(0x02); // Canal D (A2)
		PORTC |= (1 << 0); // Enciende el primer LED (C0)
		break;
		case 1: // Modo EEPROM
		PORTC |= (1 << 1); // Enciende el segundo LED (C1)
		break;
		case 2: // Modo Adafruit
		PORTC |= (1 << 5); // Enciende el tercer LED (C5)
		break;
	}
}

ISR(ADC_vect) {
	uint8_t channel = ADMUX & 0x07;
	uint8_t value = ADCH;

	switch (channel) {
		case 0x04: // Canal B
		adc_value_B = value;
		setPWMChannelB((adc_value_B * 180) / 255 + 10);
		break;
		case 0x03: // Canal C
		adc_value_C = value;
		setPWMChannelC((adc_value_C * 180) / 255 + 10);
		break;
		case 0x02: // Canal D
		adc_value_D = value;
		setPWMChannelD((adc_value_D * 180) / 255 + 10);
		break;
		default: // Canal A
		adc_value_A = value;
		setPWMChannelA((adc_value_A * 180) / 255 + 10);
		break;
	}

	ADCSRA |= (1 << ADIF); // Limpia la bandera de interrupción del ADC
}

ISR(PCINT2_vect) {
	static uint8_t last_state = 0;
	uint8_t current_state = PIND & (1 << PD2);

	if (current_state == 0 && last_state != 0) {
		opcion_menu++;
		if (opcion_menu > 2)
		opcion_menu = 0;
	}

	last_state = current_state;
}

