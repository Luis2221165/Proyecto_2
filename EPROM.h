#ifndef EPROM_H_
#define EPROM_H_

#include <avr/io.h>

/**
 * @brief Lee un byte de la EEPROM en la direcci�n especificada.
 * @param uiAddress Direcci�n de la EEPROM.
 * @return El byte le�do.
 */
unsigned char readEEPROM(unsigned int uiAddress);

/**
 * @brief Escribe un byte en la EEPROM en la direcci�n especificada.
 * @param uiAddress Direcci�n de la EEPROM.
 * @param ucData Byte a escribir.
 */
void writeEEPROM(unsigned int uiAddress, unsigned char ucData);

#endif /* EPROM_H_ */
