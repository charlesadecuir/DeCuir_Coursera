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
 * @file stats.c
 * @brief Calculates and prints various statistics on an array-structured data
 *      set. Prints data set in sorted and unsorted order.
 *
 * This module takes as input a data set structured as an array, calculates
 * several statistics on the data set, and prints the results to the screen.
 * Calculated statistics include:
 *    -Median
 *    -Mean
 *    -Maximum
 *    -Minimum
 *
 * In addition, the array data set will also be printed to the screen in
 * unsorted order as well as descending sorted order.
 *
 * @author Charles De Cuir
 * @date Created February 17 2018, Edited February 17 2018
 *
 */

#include "stats.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Size of the Data Set */
#define SIZE (40)

int compare_uint_descending(const void* a, const void* b);
int compare_uint_ascending(const void* a, const void* b);

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  print_array(test, SIZE);

  print_statistics(test, SIZE);
}

//-----------------------------------------------------------------------------
void print_statistics(unsigned char* data, unsigned int length) {
  printf("Median value is: %u\n", find_median(data, length));
  printf("Mean value is: %u\n", find_mean(data, length));
  printf("Max value is: %u\n", find_maximum(data, length));
  printf("Min value is: %u\n", find_minimum(data, length));
}

//-----------------------------------------------------------------------------
void print_array(unsigned char* data, unsigned int length) {
  printf("[");
  for (int i = 0; i < length; i++) {
    printf("%u", data[i]);

    if (i < (length-1)) {
      printf(", ");
    }
  }
  printf("]\n");
}

//-----------------------------------------------------------------------------
unsigned int find_median(unsigned char* data, unsigned int length) {
  unsigned char sorted_data[length];

  memcpy(sorted_data, data, length);
  qsort(sorted_data, SIZE, sizeof(unsigned char), compare_uint_ascending);

  // Use linear interpolation for even-sized data set
  if (SIZE & 0x01) {
    return sorted_data[SIZE / 2];
  } else {
    return (sorted_data[SIZE / 2 - 1] + sorted_data[SIZE / 2]) / 2;
  }
}

//-----------------------------------------------------------------------------
unsigned int find_mean(unsigned char* data, unsigned int length) {
  unsigned int sum = 0;

  for (int i = 0; i < length; i++) {
    sum += data[i];
  }

  return sum / length;
}

//-----------------------------------------------------------------------------
unsigned int find_maximum(unsigned char* data, unsigned int length) {
  unsigned int max = data[0];

  for (int i = 1; i < length; i++) {
    if (data[i] > max) {
      max = data[i];
    }
  }

  return max;
}

//-----------------------------------------------------------------------------
unsigned int find_minimum(unsigned char* data, unsigned int length) {
  unsigned int min = data[0];

  for (int i = 1; i < length; i++) {
    if (data[i] < min) {
      min = data[i];
    }
  }

  return min;
}

//-----------------------------------------------------------------------------
void sort_array(unsigned char* data, unsigned int length) {
  qsort(data, SIZE, sizeof(unsigned char), compare_uint_descending);
}

//-----------------------------------------------------------------------------
int compare_uint_ascending(const void* a, const void* b) {
  if (*(unsigned char*)a < *(unsigned char*)b) {
    return -1;
  }

  return *(unsigned char*)a > *(unsigned char*)b;
}

//-----------------------------------------------------------------------------
int compare_uint_descending(const void* a, const void* b) {
  if (*(unsigned char*)a > *(unsigned char*)b) {
    return -1;
  }

  return *(unsigned char*)a < *(unsigned char*)b;
}


