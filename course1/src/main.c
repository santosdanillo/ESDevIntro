/******************************************************************************
 * Copyright (C) 2021 by Danillo Santos - Skynet Terminators
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Danillo Santos and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file main.c
 * @brief Main entry point to the course1 final Assessment
 *
 * @author Danillo Santos
 * @date Sep 18 2021
 *
 */
#include "course1.h"

int main(void)
{
  #ifdef COURSE1
  course1();
  #endif

  return 0;
}
