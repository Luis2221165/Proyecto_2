
#include "EPROM.h"
#include <avr/io.h>

// Lectura de EEPROM
uint8_t readEEPROM(uint16_t address) {
	while (EECR & (1 << EEPE)); // Espera a que termine la escritura anterior
	EEAR = address; // Establece la dirección de lectura
	EECR |= (1 << EERE); // Inicia la lectura
	return EEDR; // Retorna los datos leídos
}

// Escritura en EEPROM
void writeEEPROM(uint16_t address, uint8_t data) {
	while (EECR & (1 << EEPE)); // Espera a que termine la escritura anterior
	EEAR = address; // Establece la dirección de escritura
	EEDR = data; // Establece los datos a escribir
	EECR |= (1 << EEMPE); // Habilita la escritura de datos
	EECR |= (1 << EEPE); // Inicia la escritura
}
