/******************************************************************************
 * Copyright (C) 2017 by Danillo Santos - Skynet Terminators
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Danillo Santos and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file data.c
 * @brief Implementation of data operations
 *
 * @author Danillo Santos
 * @date Sep 18 2021
 *
 */

#include "platform.h"
#include <stdint.h>
#include <math.h>
#include <limits.h>

uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base)
{
    uint8_t *buffer = ptr;
    int32_t curr = 0;

    if (data == 0)
    {
        *buffer++ = '0';
        curr++;
        *buffer++ = '\0';
        curr++;
        return curr;
    }

    int32_t nDig = 0;
    if (data < 0)
    {
        *buffer++ = '-';
        curr++;
        nDig++;
        data *= -1;
    }

    nDig += (int32_t)floor(log(data) / log(base)) + 1;

    while (curr < nDig)
    {
        int32_t baseVal = (int32_t)pow(base, nDig - 1 - curr);
        int32_t nVal = data / baseVal;
        char value = nVal + '0';
        *buffer++ = value;
        curr++;
        data -= baseVal * nVal;
    }
    *buffer = '\0';
    curr++;
    // PRINTF("%s data:%d base:%d str:%s size:%d\n",
    //        __FUNCTION__, data, base, ptr, curr);
    return (uint8_t)curr;
}

int32_t my_atoi(uint8_t *ptr, uint8_t digits, uint32_t base)
{
    int32_t res = 0;
    int32_t i = 0;
    uint8_t *ptData = ptr;
    int8_t negative = 0;

    if (*ptData == '-')
    {
        negative = 1;
        ptData++;
        i++;
    }
    else if (*ptData == '+')
    {
        ptData++;
        i++;
    }

    for (; i < digits; ++i)
    {
        res = res * base + (*ptData++) - '0';
        if (*ptData == '\0')
            break;
    }

    res = negative ? -res : res;
    // PRINTF("%s str:%s dig:%d base:%d res:%d\n",
    //        __FUNCTION__, ptr, digits, base, res);
    return res;
}
