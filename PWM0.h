
#ifndef PWM0_H_
#define PWM0_H_

#include <avr/io.h>

/**
 * @brief Configures PWM0.
 */
void initializePWM0(void);

/**
 * @brief Sets the duty cycle for PWM Channel C.
 * @param duty_cycle Duty cycle value (0-255).
 */
void setPWMDutyCycleC(uint8_t duty_cycle);

/**
 * @brief Sets the duty cycle for PWM Channel D.
 * @param duty_cycle Duty cycle value (0-255).
 */
void setPWMDutyCycleD(uint8_t duty_cycle);

#endif /* PWM0_H_ */
