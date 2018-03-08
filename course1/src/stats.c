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
 *      set and prints data set in sorted order.
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
 * descending sorted order.
 *
 * @author Charles De Cuir
 * @date Created February 17 2018, Edited February 17 2018
 *
 */

#include "stats.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_uint_ascending(const void* a, const void* b);
int compare_uint_descending(const void* a, const void* b);

//-----------------------------------------------------------------------------
void print_statistics(unsigned char* data, unsigned int length) {
  printf("--------------------------------------------------\n");
  printf("|              Data Set Statistics               |\n");
  printf("--------------------------------------------------\n");
  printf("\tMedian:\n\t\t%u\n", find_median(data, length));
  printf("\tMean:\n\t\t%u\n", find_mean(data, length));
  printf("\tMax:\n\t\t%u\n", find_maximum(data, length));
  printf("\tMin:\n\t\t%u\n", find_minimum(data, length));

  sort_array(data, length);

  printf("\nSorted Data Set (Descending):\n\t");
  print_array(data, length);
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
  qsort(sorted_data, length, sizeof(unsigned char), compare_uint_ascending);

  // Use linear interpolation for even-sized data set
  if (length & 0x01) {
    return sorted_data[length / 2];
  } else {
    return (sorted_data[length / 2 - 1] + sorted_data[length / 2]) / 2;
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
  qsort(data, length, sizeof(unsigned char), compare_uint_descending);
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
