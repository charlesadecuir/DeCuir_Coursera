/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
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
 * @author Charles De Cuir
 * @date Mar 3 2018
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint.h>
#include <stdlib.h>

/**
 * @brief Moves data from one pointer to another.
 *
 * Moves all data from source byte pointer to destination
 * byte pointer. Cleanly handles overlapping buffers.
 *
 * @param src Pointer to source data
 * @param dst Pointer to destination data
 * @param length Amount of bytes to move
 *
 * @return Pointer to the destination data.
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Copies data from one pointer to another.
 *
 * Copies all data from source byte pointer to destination
 * byte pointer. Overlapping pointers yields undefined
 * behavior.
 *
 * @param src Pointer to source data
 * @param dst Pointer to destination data
 * @param length Amount of bytes to copy
 *
 * @return Pointer to the destination data.
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Sets source data to a given value.
 *
 * Sets all data at source byte pointer to a given
 * value.
 *
 * @param src Pointer to source data
 * @param length Amount of bytes to set
 * @param value Value to which to set data
 *
 * @return Pointer to the source data.
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief Zeros out all source data.
 *
 * Sets all data from source byte pointer to zero.
 *
 * @param src Pointer to source data
 * @param length Amount of bytes to set to zero
 *
 * @return Pointer to the source data.
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief Reverse the order of source data.
 *
 * Reverse the order of all bytes of the source
 * data.
 *
 * @param src Pointer to source data
 * @param length Amount of bytes to reverse
 *
 * @return Pointer to the source data.
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief Dynamically allocate words.
 *
 * Creates a dynamic allocation of a given
 * number of words.
 *
 * @param length Amount of bytes to allocate
 *
 * @return Pointer to the allocated data.
 */
int32_t * reserve_words(size_t length);

/**
 * @brief Frees a dynamic allocation.
 *
 * Frees a previous dynamic allocation of a given
 * number of words.
 *
 * @param src Pointer to the data to be freed.
 *
 * @return Void.
 */
void free_words(uint32_t * src);

/**
 * @brief Sets a value of a data array.
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
 * @brief Clear a value of a data array.
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
 * @brief Returns a value of a data array.
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
 * @brief Sets data array elements to a value.
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
 * @brief Clears elements in a data array.
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

#endif /* __MEMORY_H__ */
