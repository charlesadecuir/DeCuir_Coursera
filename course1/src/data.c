/**
 * @file data.c
 * @brief Some very basic data manipulation.
 *
 * This file provides a few basic data maipulation
 * functions.
 *
 * @author Charles De Cuir
 * @date Mar 3 2018
 *
 */

#include "data.h"
#include "memory.h"

//------------------------------------------------------------------------------
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
  uint8_t* ptr_start = ptr;
  uint8_t negative = 0;

  // Flag if negative
  if (data < 1) {
    negative = 1;
    data = abs(data);
  }

  char digit;
  uint8_t digit_counter = 0;
  while(data != 0) {
    // Extract lowest digit.
    digit = data % base;
    data -= digit;
    data /= base;

    // Convert digit to ASCII.
    if (digit >= 10) {
      digit += 55;
    }
    else {
      digit += 48;
    }

    *ptr++ = digit;
    digit_counter++;
  }

  // Add negative sign if necessary.
  if (negative) {
    *ptr++ = '-';
    digit_counter++;
  }

  // Reverse the string.
  my_reverse(ptr_start, digit_counter);

  // Append null terminator.
  *ptr = '\0';

  return digit_counter;
}

//------------------------------------------------------------------------------
// Helper function to compute exponents.
int32_t power(int32_t base, uint32_t exponent) {
  int32_t power = 1;
  while (exponent--) {
    power *= base;
  }

  return power;
}

//------------------------------------------------------------------------------
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {
  int32_t converted_int = 0;
  uint8_t negative = 0;

  // Check for a negative sign.
  if (*ptr == '-') {
    negative = 1;
    ptr++;
    digits--;
  }

  // Iterate over characters in the string.
  for (int32_t i = digits-1; i >= 0; i--) {
    char digit = *ptr++;

    // Convert digit from ASCII.
    if (digit > 57) {
      digit -= 55;
    }
    else {
      digit -= 48;
    }

    // Build integer using positional exponentiation.
    converted_int += digit * power(base, i);
  }

  // Negate integer if necessary.
  if (negative) {
    converted_int *= -1;
  }

  return converted_int;
}
