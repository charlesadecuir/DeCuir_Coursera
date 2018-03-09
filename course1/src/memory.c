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
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Charles De Cuir
 * @date March 3 2018
 *
 */
#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/
//------------------------------------------------------------------------------
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length) {
  // Save pointer to dst.
  uint8_t* dst_start = dst;
  uint8_t* tmp;

  // Allocate temporary swap space if pointers overlap.
  if ((src >= dst && (src + length) >= dst) ||
      (dst >= src && (dst + length) >= src)) {
    tmp = (uint8_t*) malloc(length * sizeof(uint8_t));
  }

  // Use swap to move memory contents if necessary, otherwise
  // do a direct copy.
  if (tmp != NULL) {
    uint8_t* tmp_start = tmp;
    for (uint32_t i = 0; i < length; i++) {
      *tmp++ = *src++;
    }

    tmp = tmp_start;

    for (uint32_t i = 0; i < length; i++) {
      *dst++ = *tmp++;
    }
  }
  else {
    for (uint32_t i = 0; i < length; i++) {
      *dst++ = *src++;
    }
  }

  return dst_start;
}

//------------------------------------------------------------------------------
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length) {
  // Save pointer to dst.
  uint8_t* dst_start = dst;

  // Directly copy data from src to dst.
  for (uint32_t i = 0; i < length; i++) {
    *dst++ = *src++;
  }

  return dst_start;
}

//------------------------------------------------------------------------------
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value) {
  // Save pointer to src.
  uint8_t* src_start = src;

  // Set each byte individually to the given value.
  for (uint32_t i = 0; i < length; i++) {
    *src++ = value;
  }

  return src_start;
}

//------------------------------------------------------------------------------
uint8_t * my_memzero(uint8_t * src, size_t length) {
  // Save pointer to src.
  uint8_t* src_start = src;

  // Set each byte individually to zero.
  for (uint32_t i = 0; i < length; i++) {
    *src++ = 0u;
  }

  return src_start;
}

//------------------------------------------------------------------------------
uint8_t * my_reverse(uint8_t * src, size_t length) {
  // Save pointer to src stard and end.
  uint8_t* src_start = src;
  uint8_t* src_end = src + length - 1;
  uint8_t tmp;

  // Swap each byte starting at the ends working inward.
  for (; src <= src_end; src++,src_end--) {
    tmp = *src;
    *src = *src_end;
    *src_end = tmp;
  }

  return src_start;
}

//------------------------------------------------------------------------------
int32_t * reserve_words(size_t length) {
  // Malloc 32-bit words.
  return (int32_t*) malloc(length * sizeof(int32_t));
}

//------------------------------------------------------------------------------
void free_words(uint32_t * src) {
  // Free given pointer.
  free(src);
  return;
}

//------------------------------------------------------------------------------
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

//------------------------------------------------------------------------------
void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

//------------------------------------------------------------------------------
void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

//------------------------------------------------------------------------------
void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

