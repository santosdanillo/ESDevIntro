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
 * @brief Implementation of functions to analyse array of char data.
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
}

/* Add other Implementation File Code Here */
void print_statistics()
{}

void print_array(unsigned char * data, unsigned int length)
{}

unsigned char find_median(unsigned char * data, unsigned int length)
{}

unsigned char find_mean(unsigned char * data, unsigned int length)
{}

unsigned char find_maximum(unsigned char * data, unsigned int length)
{}

unsigned char find_minimum(unsigned char * data, unsigned int length)
{}

void sort_array(unsigned char * data, unsigned int length)
{}