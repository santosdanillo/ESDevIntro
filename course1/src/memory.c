/******************************************************************************
 * Copyright (C) 2017 by Danillo Santos - Skynet Terminators
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Danillo Santos  and the University of Colorado are not liable for any
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
 * @author Danillo Santos 
 * @date Sep 18 2021
 *
 */
#include "memory.h"
#include "platform.h"
#include "stdlib.h"

#define STACK_SIZE (1024u * 10u) // 10KB
uint8_t m_stack[STACK_SIZE];
uint8_t *m_ptStackBg = &m_stack[0]; // stack begin pointer
uint8_t *m_ptStackEd = &m_stack[0]; // stack end pointer

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char *ptr, unsigned int index, char value)
{
    ptr[index] = value;
}

void clear_value(char *ptr, unsigned int index)
{
    set_value(ptr, index, 0);
}

char get_value(char *ptr, unsigned int index)
{
    return ptr[index];
}

void set_all(char *ptr, char value, unsigned int size)
{
    unsigned int i;
    for (i = 0; i < size; i++)
    {
        set_value(ptr, i, value);
    }
}

void clear_all(char *ptr, unsigned int size)
{
    set_all(ptr, 0, size);
}

uint8_t *my_memmove(uint8_t *src, uint8_t *dst, size_t length)
{
    uint8_t *source = src;
    uint8_t *destination = dst;
    uint32_t i;
    for (i = 0; i < length; i++)
    {
        *destination++ = *source++;
    }
    return dst;
}

uint8_t *my_memcopy(uint8_t *src, uint8_t *dst, size_t length)
{
    // PRINTF("%s src:%p length:%d val:%u\n", __FUNCTION__, src, (int32_t)length, value);
    int32_t i;
    uint8_t *ptDataFrom = src;
    uint8_t *ptDataTo = dst;
    for (i = 0; i < length; i++)
    {
        *ptDataTo++ = *ptDataFrom++;
    }
    return dst;
}

uint8_t *my_memset(uint8_t *src, size_t length, uint8_t value)
{
    // PRINTF("%s src:%p length:%d val:%u\n", __FUNCTION__, src, (int32_t)length, value);
    int32_t i;
    uint8_t *ptData = src;
    for (i = 0; i < length; i++)
    {
        *ptData++ = value;
    }
    return src;
}

uint8_t *my_memzero(uint8_t *src, size_t length)
{
    // PRINTF("%s src:%p length:%d\n", __FUNCTION__, src, (int32_t)length);
    int32_t i;
    uint8_t *ptData = src;
    for (i = 0; i < length; i++)
    {
        *ptData++ = 0u;
    }
    return src;
}

uint8_t *my_reverse(uint8_t *src, size_t length)
{
    return NULL;
}

int32_t *reserve_words(size_t length)
{
    int32_t stackSpace = STACK_SIZE - (m_ptStackEd - m_ptStackBg);
    int32_t *dataStart = (int32_t *)m_ptStackEd;
    int32_t numBytes = (int32_t)length + (int32_t)sizeof(size_t);

    if (numBytes > stackSpace)
    {
        return NULL;
    }

    *dataStart = numBytes;   // add block length to the stack and increment
    m_ptStackEd += numBytes; // increase end of stack pointer

    // PRINTF("%s ptStackEd:%p ptData:%p size:%d\n",
    //        __FUNCTION__, m_ptStackEd, dataStart, *dataStart);

    dataStart++;
    return dataStart;
}

void free_words(uint32_t *src)
{
    int32_t *sizePt = (int32_t *)src;
    sizePt--;
    int32_t numBytes = *sizePt;
    int32_t endOfStackSize = (m_ptStackEd - (uint8_t *)(sizePt));

    if (numBytes == endOfStackSize)
    {
        // last block
        m_ptStackEd -= numBytes;
        // PRINTF("%s last block of data in stack. ptStackEd:%p\n",
        //        __FUNCTION__, m_ptStackEd);
    }

    // PRINTF("%s ptStackEd:%p src:%p size:%d end of stack size:%d\n",
    //        __FUNCTION__, m_ptStackEd, src, numBytes, endOfStackSize);

    // block in the middle, does not move the stack end pointer
    my_memzero((uint8_t *)(src - sizeof(size_t)), ((*sizePt) + sizeof(size_t)));
}
