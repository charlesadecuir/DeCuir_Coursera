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



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  print_array(test, SIZE);

}

//-----------------------------------------------------------------------------
void print_statistics(unsigned char* data, unsigned int length) {
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
}

//-----------------------------------------------------------------------------
unsigned int find_mean(unsigned char* data, unsigned int length) {
}

//-----------------------------------------------------------------------------
unsigned int find_maximum(unsigned char* data, unsigned int length) {
}

//-----------------------------------------------------------------------------
unsigned int find_minimum(unsigned char* data, unsigned int length) {
}

//-----------------------------------------------------------------------------
void sort_array(unsigned char* data, unsigned int length) {
}
