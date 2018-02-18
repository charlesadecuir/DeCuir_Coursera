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
 * @file stats.h
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
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief Prints all calculated statistics.
 *
 * Prints the following to the screen:
 *   -The values in the data set (unsorted)
 *   -The median value of the data set
 *   -The mean value of the data set
 *   -The maximum value of the data set
 *   -The minimum value of the data set
 *   -The data set in descending order
 *
 * @param data Pointer to the input data set
 * @param length Length of the data set
 *
 * @return Void
 */
void print_statistics(unsigned char* data, unsigned int length);

/**
 * @brief Prints the input data set.
 *
 * Prints the input data set in the order presented.
 *
 * @param data Pointer to the input data set
 * @param length Length of the data set
 *
 * @return Void.
 */
void print_array(unsigned char* data, unsigned int length);

/**
 * @brief Calculates median value.
 *
 * Calculates the median value of the data set.
 *
 * @param data Pointer to the input data set
 * @param length Length of the data set
 *
 * @return The median value of the data set.
 */
unsigned int find_median(unsigned char* data, unsigned int length);

/**
 * @brief Calculates mean value.
 *
 * Calculates the mean value of the data set.
 *
 * @param data Pointer to the input data set
 * @param length Length of the data set
 *
 * @return The mean value of the data set.
 */
unsigned int find_mean(unsigned char* data, unsigned int length);

/**
 * @brief Calculates maximum value.
 *
 * Calculates the maximum value of the data set.
 *
 * @param data Pointer to the input data set
 * @param length Length of the data set
 *
 * @return The maximum value of the data set.
 */
unsigned int find_maximum(unsigned char* data, unsigned int length);


/**
 * @brief Calculates minimum value.
 *
 * Calculates the minimum value of the data set.
 *
 * @param data Pointer to the input data set
 * @param length Length of the data set
 *
 * @return The minimum value of the data set.
 */
unsigned int find_minimum(unsigned char* data, unsigned int length);


/**
 * @brief Sorts the data set in decending order.
 *
 * Sorts the and prints the data set in descending order
 * (largest to smallest).
 *
 * @param data Pointer to the input data set
 * @param length Length of the data set
 *
 * @return Void.
 */
void sort_array(unsigned char* data, unsigned int length);

#endif /* __STATS_H__ */
