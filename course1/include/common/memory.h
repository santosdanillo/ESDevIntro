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
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Danillo Santos
 * @date Sep 18 2021
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint.h>
#include <stdlib.h>

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/**
 * @brief Move from the source location to the destination.
 *
 * Handle overlap of source and destination. 
 * Copy occurs with no data corruption.
 * All operations performed using pointer arithmetic, not array indexing. 
 *
 * @param src Pointer to data source
 * @param dst Pointer to data destination
 * @param length Number of bytes
 *
 * @return Pointer to the destination (dst)
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Copy from the source location to the destination.
 *
 * The behavior is undefined if there is overlap of source and destination.
 * Copy still occur, but will likely corrupt data.
 * All operations performed using pointer arithmetic, not array indexing. 
 *
 * @param src Pointer to data source
 * @param dst Pointer to data destination
 * @param length Number of bytes
 *
 * @return Pointer to the destination (dst)
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Set all locations of a memory location to a given value.
 *
 * All operations performed using pointer arithmetic, not array indexing. 
 * Shall NOT reuse the set_all() function
 *
 * @param src Pointer to a source memory location 
 * @param length Number of bytes
 * @param value Value to be set in memory location
 *
 * @return pointer to the source (src).
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief Zero out all of the memory.
 *
 * All operations performed using pointer arithmetic, not array indexing.
 * Shall NOT reuse the clear_all() function
 *
 * @param src Pointer to a memory location, a 
 * @param length Number of bytes
 *
 * @return pointer to the source (src).
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief Reverse the order of all of the bytes.
 *
 * All operations performed using pointer arithmetic, not array indexing.
 *
 * @param src Pointer to source memory location 
 * @param length Number of bytes
 *
 * @return Pointer to src
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief Take number of words to allocate in dynamic memory
 *
 * All operations are performed using pointer arithmetic, not array indexing.
 *
 * @param length Number of bytes
 *
 * @return Pointer to memory if successful, or a Null Pointer if not successful
 */
int32_t * reserve_words(size_t length);

/**
 * @brief Free a dynamic memory allocation by providing the pointer src to the function
 *
 * All operations are performed using pointer arithmetic, not array indexing.
 *
 * @param src Pointer to data source
 *
 * @return void.
 */
void free_words(uint32_t * src);

#endif /* __MEMORY_H__ */
