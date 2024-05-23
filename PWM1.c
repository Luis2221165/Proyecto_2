#include "PWM1.h"

void initializePWM1(void) {
	// Configure PWM pins as outputs
	DDRB |= (1 << DDB1); // Channel A (OC1A)
	DDRB |= (1 << DDB2); // Channel B (OC1B)

	// Configure PWM mode on Timer1
	TCCR1A = (1 << COM1A1) | (1 << COM1B1) | (1 << WGM10); // Fast PWM Mode, Non-Inverted
	TCCR1B = (1 << WGM12); // Fast PWM Mode

	// Configure prescaler for Timer1
	TCCR1B |= (1 << CS12); // Prescaler of 1024
}

void setPWMDutyCycleA(uint8_t duty_cycle) {
	OCR1A = (duty_cycle * 180) / 255 + 10; // Set duty cycle for channel A
}

void setPWMDutyCycleB(uint8_t duty_cycle) {
	OCR1B = (duty_cycle * 180) / 255 + 10; // Set duty cycle for channel B
}
