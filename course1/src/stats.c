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

#include "stats.h"
#include "platform.h"
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* Size of the Data Set */
#define SIZE (40)

// void main()
// {
//     unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
//                                 114,  88,  45,  76, 123,  87,  25,  23,
//                                 200, 122, 150,  90,  92,  87, 177, 244,
//                                 201,   6,  12,  60,   8,   2,   5,  67,
//                                   7,  87, 250, 230,  99,   3, 100,  90};

//   /* Other Variable Declarations Go Here */
//   /* Statistics and Printing Functions Go Here */

//   sort_array(test, SIZE);

//   print_statistics(test, SIZE);
// }

/* Add other Implementation File Code Here */

void print_statistics(unsigned char *data, unsigned int length)
{
    print_array(data, length);
    PRINTF("Median: %d\n", find_median(data, length));
    PRINTF("Mean: %d\n", find_mean(data, length));
    PRINTF("Max: %d\n", find_maximum(data, length));
    PRINTF("Min: %d\n", find_minimum(data, length));
}

void print_array(unsigned char *data, unsigned int length)
{
#define ELEMENTS_PER_LINE 8
#ifdef VERBOSE
    unsigned int i;
    unsigned int elemLeft = ELEMENTS_PER_LINE;

    PRINTF("Array:\n");
    for (i = 0; i < length; i++)
    {
        PRINTF("%d\t", data[i]);

        if (--elemLeft == 0)
        {
            elemLeft = ELEMENTS_PER_LINE;
            PRINTF("\n");
        }
    }
    PRINTF("\n");
#endif
}

unsigned char find_median(unsigned char *data, unsigned int length)
{
    unsigned int midIdx = length / 2;

    if ((length % 2) == 0)
    {
        // even number of elements, for a sorted array,
        // median is the average of both middle two elements
        return (unsigned char)floor((data[midIdx - 1] + data[midIdx]) / 2);
    }

    // odd number of elements, for a sorted array,
    // median is the middle element
    return data[midIdx];
}

unsigned char find_mean(unsigned char *data, unsigned int length)
{
    int i;
    unsigned int sum = 0;
    for (i = 0; i < length; i++)
    {
        sum += data[i];
    }
    sum = floor(sum / length);

    return (sum > UCHAR_MAX) ? UCHAR_MAX : (unsigned char)sum;
}

unsigned char find_maximum(unsigned char *data, unsigned int length)
{
    return data[0];
}

unsigned char find_minimum(unsigned char *data, unsigned int length)
{
    return data[length - 1];
}

int compare_unsigned_char(const void *a, const void *b)
{
    unsigned char arg1 = *(const unsigned char *)a;
    unsigned char arg2 = *(const unsigned char *)b;

    if (arg1 < arg2)
        return 1;
    if (arg1 > arg2)
        return -1;
    return 0;
}

void sort_array(unsigned char *data, unsigned int length)
{
    qsort(data, length, sizeof(unsigned char), compare_unsigned_char);
}