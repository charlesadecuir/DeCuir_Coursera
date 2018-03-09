/**
 * @file data.h
 * @brief Some very basic data manipulation.
 *
 * This header file provides a few basic data maipulation
 * functions.
 *
 * @author Charles De Cuir
 * @date Mar 3 2018
 *
 */

#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>
#include <stdlib.h>

// Enum for radix definitions 2 to 16.
typedef enum {
  BASE_2 = 2,
  BASE_3,
  BASE_4,
  BASE_5,
  BASE_6,
  BASE_7,
  BASE_8,
  BASE_9,
  BASE_10,
  BASE_11,
  BASE_12,
  BASE_13,
  BASE_14,
  BASE_15,
  BASE_16
} Base;

/**
 * @brief Convert integer to ASCII.
 *
 * Converts data from a standard integer type into
 * a null-terminated ASCII string. Supports bases
 * 2 to 16.
 *
 * @param data Integer to convert
 * @param ptr Pointer to the converted ASCII string
 * @param base Numerical base (radix) of integer
 *
 * @return The length of the converted data.
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Convert ASCII to integer.
 *
 * Converts data from an ASCII string
 * to an integer type. Supports bases 2 to 16.
 *
 * @param ptr Pointer to ASCII string to convert
 * @param digits Number of digits to be converted
 * @param base Numerical base (radix) of integer
 *
 * @return The converted integer
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */
