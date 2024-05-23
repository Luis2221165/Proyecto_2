#include "ADC.h"

void configureADC(void) {
	// Reset ADC Multiplexer Selection Register (ADMUX)
	ADMUX = 0;

	// Set ADC6 as analog input (MUX2:0 = 0b110)
	//ADMUX |= (1 << MUX2) | (1 << MUX1);

	// Set reference voltage to AVCC with capacitor at AREF
	ADMUX |= (1 << REFS0);
	ADMUX &= ~(1 << REFS1);

	// Configure ADC to operate in 8-bit mode
	ADMUX |= (1 << ADLAR);

	// Reset ADC Control and Status Register A (ADCSRA)
	ADCSRA = 0;

	// Enable ADC and set prescaler to 128 (Sampling frequency = F_CPU / 128)
	ADCSRA |= (1 << ADIE) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
	ADCSRA |= (1 << ADEN); // Enable ADC
}
