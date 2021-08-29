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
 * @brief Definition of functions to analyse array of unsigned char data.
 *
* Provide functions to analyze an array of unsigned data items 
 *	and report analytics on the max, min, mean and the median of the
 *	data set.
 * Reorder this data set from large to small.
 * All statistics are rounded down to the nearest integer.
 * Prints data to the screen in nicely formatted presentation.
 *
 * @author Danillo Santos
 * @date 29-Aug-2021
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief A function to print to stdio an array statics
 *
 * Prints the statistics of an array including minimum, maximum, mean, and median.
 *
 * @param none
 *
 * @return none
 */
void print_statistics();

/**
 * @brief A function to print the content of a unsigned char array to stdio
 *
 * Given an array of data and a length, prints the array to the screen
 *
 * @param data: A unsigned char pointer to the 1st Array element
 * @param length: An unsigned int with the size of the array
 *
 * @return none
 */
void print_array(unsigned char * data, unsigned int length);

/**
 * @brief A function that finds the median element of an array
 *
 * Given an array of data and a length, returns the median value
 *
 * @param data: A unsigned char pointer to the 1st Array element
 * @param length: An unsigned int with the size of the array
 *
 * @return median: The median element of the array
 */
unsigned char find_median(unsigned char * data, unsigned int length);

/**
 * @brief A function that calculates the mean of the elements in an array
 *
 * Given an array of data and a length, returns the mean
 *
 * @param data: A unsigned char pointer to the 1st Array element
 * @param length: An unsigned int with the size of the array
 *
 * @return mean: The mean of all the array elements
 */
unsigned char find_mean(unsigned char * data, unsigned int length);

/**
 * @brief A function that finds the maximum element of an array
 *
 * Given an array of data and a length, returns the maximum
 *
 * @param data: A unsigned char pointer to the 1st Array element
 * @param length: An unsigned int with the size of the array
 *
 * @return maximum: The max element of the array
 */
unsigned char find_maximum(unsigned char * data, unsigned int length);

/**
 * @brief A function that finds the minimum element of an array
 *
 * Given an array of data and a length, returns the minimum
 *
 * @param data: A unsigned char pointer to the 1st Array element
 * @param length: An unsigned int with the size of the array
 *
 * @return maximum: The min element of the array
 */
unsigned char find_minimum(unsigned char * data, unsigned int length);

/**
 * @brief A function that sorts an array
 *
 * Given an array of data and a length, sorts the array from largest to smallest.
 * (The zeroth Element should be the largest value, 
 * and the last element (n-1) should be the smallest value.)
 *
 * @param data: A unsigned char pointer to the 1st Array element
 * @param length: An unsigned int with the size of the array
 *
 * @return none
 */
void sort_array(unsigned char * data, unsigned int length);

#endif /* __STATS_H__ */
