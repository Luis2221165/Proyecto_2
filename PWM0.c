
#include "PWM0.h"

void initializePWM0(void) {
	// Configure PWM pins as outputs
	DDRD |= (1 << DDD6); // Channel C (OC0A)
	DDRD |= (1 << DDD5); // Channel D (OC0B)

	// Configure PWM mode on Timer0
	TCCR0A = (1 << COM0A1) | (1 << COM0B1) | (1 << WGM00) | (1 << WGM01); // Fast PWM Mode, Non-Inverted
	TCCR0B = (1 << CS01) | (1 << CS00); // Prescaler of 64
}

void setPWMDutyCycleC(uint8_t duty_cycle) {
	OCR0A = (duty_cycle * 180) / 255 + 10;
}

void setPWMDutyCycleD(uint8_t duty_cycle) {
	OCR0B = (duty_cycle * 180) / 255 + 10;
}
