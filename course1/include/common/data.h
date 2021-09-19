/******************************************************************************
 * Copyright (C) 2017 by Danillo Santos - Skynet Terminators
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Danillo Santos and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file data.h
 * @brief Abstraction of data operations
 *
 * This header file provides an abstraction of data operations
 *
 * @author Danillo Santos
 * @date Sep 18 2021
 *
 */
#ifndef __DATA_H
#define __DATA_H

/**
 * @brief Integer-to-ASCII Converts data from a standard integer type into an
 *        ASCII string.
 *
 * All operations performed using pointer arithmetic, not array indexing.
 * The data signed 32-bit number will have a maximum string size 
 * (Hint: Think base 2).
 * Converted string is null terminated.
 * Handles signed data.
 * Does not use any string functions or libraries.
 *
 * @param data int32_t number to convert
 * @param ptr uint8_t* pointer to converted data destination
 * @param base uint32_t value of numeric base. Supported: 2 to 16.
 *
 * @return Length of the converted data, includes null terminator
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief ASCII-to-Integer Converts data from an ASCII represented string into
 *        an integer type.
 *
 * All operations performed using pointer arithmetic, not array indexing.
 * The data signed 32-bit number will have a maximum string size 
 * (Hint: Think base 2).
 * String must be null terminated.
 * Handles signed data.
 * Does not use any string functions or libraries.
 *
 * @param ptr uint8_t* character string to convert
 * @param digits uint8_t number of digits in character set
 * @param base uint32_t value of numeric base. Supported: 2 to 16.
 *
 * @return Converted 32-bit signed integer.
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H */
