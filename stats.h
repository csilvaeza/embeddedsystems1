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
 * @brief Header file of stats.c
 *
 * This header contains function declarations and function comments to analyse
 * and print the statistics an array, such as minimum, maximum, mean and media.
 *
 * @author csilvaeza
 * @date May 7, 2020
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 
#include <stdint.h>

/**
 * @brief Prints statistics of an array
 *
 * Given an array and a length prints statistics of an array, including
 * minimum, maximum, mean, median.
 *
 * @param arreglo The array to analyse
 * @param n_datos The length of the array
 */
void print_statistics(unsigned char arreglo[], uint16_t n_datos);

/**
 * @brief Prints array to the screen
 *
 * Given an array and a length, prints the array to the screen
 *
 *
 * @param arreglo The array to analyse
 * @param n_datos The length of the array
 */

void print_array(unsigned char arreglo[], uint16_t n_datos);
/**
 * @brief Return the mean
 *
 * Given an array and a length, returns the mean
 *
 * @param arreglo The array to analyse
 * @param n_datos The length of the array
 *
 * @return The mean of the array 
 */

unsigned char find_mean(unsigned char arreglo[], uint16_t n_datos);
/**
 * @brief Return the median value
 *
 * Given an array and a length, returns the median value
 *
 * @param arreglo The array to analyse
 * @param n_datos The length of the array
 *
 * @return The median of the array 
 */
unsigned char find_median(unsigned char arreglo[], uint16_t n_datos);
/**
 * @brief Return the maximum.
 *
 * Given an array and a length, returns the maximum.
 *
 * @param arreglo The array to analyse
 * @param n_datos The length of the array
 *
 * @return The maximum of the array 
 */
unsigned char find_maximum(unsigned char arreglo[], uint16_t n_datos);

/**
 * @brief Return the minimum
 *
 * Given an array and a length, returns the minimum
 *
 * @param arreglo The array to analyse
 * @param n_datos The length of the array
 *
 * @return The minimum of the array 
 */

unsigned char find_minimum(unsigned char arreglo[], uint16_t n_datos);

/**
 * @brief Sorts an array from largest to smallest
 *
 * Given an array and a length, sorts the array. The zeroth Element should be
 * the largest value, and the last element (n-1) shoud be the smallest value.
 *
 * @param arreglo The array to analyse
 * @param n_datos The length of the array
 */
void  sort_array(unsigned char arreglo[], uint16_t n_datos);

#endif /* __STATS_H__ */
