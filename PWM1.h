#ifndef PWM1_H_
#define PWM1_H_

#include <avr/io.h>

/**
 * @brief Configures PWM1.
 */
void initializePWM1(void);

/**
 * @brief Sets the duty cycle for PWM Channel A.
 * @param duty_cycle Duty cycle value (0-255).
 */
void setPWMDutyCycleA(uint8_t duty_cycle);

/**
 * @brief Sets the duty cycle for PWM Channel B.
 * @param duty_cycle Duty cycle value (0-255).
 */
void setPWMDutyCycleB(uint8_t duty_cycle);

#endif /* PWM1_H_ */
