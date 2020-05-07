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
 * @file <stats.c> 
 * @brief <Analyse unsigned char array data items for coursera course assesment>
 *
 * <Reports maximum, minimum, mean and median of the data set>
 *
 * @author <csilvaeza>
 * @date <May 6, 2020>
 *
 */



#include <stdio.h>
#include <stdint.h>
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
  print_statistics(test, SIZE);
  sort_array(test, SIZE);
  print_array(test, SIZE);

}

void print_statistics(unsigned char arreglo[], uint16_t n_datos){

    printf("Statistics of Array[%u]:\n", n_datos);
    printf("\tMaximum:\t%u\n", find_maximum(arreglo, SIZE));
    printf("\tMinimum:\t%u\n", find_minimum(arreglo, SIZE));
    printf("\tMean:\t%u\n", find_mean(arreglo, SIZE));
    printf("\tMedian:\t%u\n", find_median(arreglo, SIZE));
}
    
void print_array(unsigned char arreglo[], uint16_t n_datos){

    uint16_t indice;

    printf("Arreglo[%u] = \n", n_datos);
	for(indice = 0; indice < n_datos; indice++){
        printf("%u\t", arreglo[indice]);
	}
    printf("\n");
}

unsigned char find_mean(unsigned char arreglo[], uint16_t n_datos){

	uint16_t indice;
	uint16_t media = 0;

	/* Sumatoria de todos los valores de las muestras */
	for(indice = 0; indice < n_datos; indice++){
		media += arreglo[indice];
	}

	/* Divide el resultado de la sumatoria entre el número de muestras */
	media /= n_datos;

	return media;
}
unsigned char find_median(unsigned char arreglo[], uint16_t n_datos){

	uint16_t mediana;
	unsigned char arreglo_ordenado[n_datos];
	uint16_t indice;

	/* Hacer una copia del arreglo (para no alterar el original) */
	for(indice = 0; indice < n_datos; indice++){
		arreglo_ordenado[indice] = arreglo[indice];
	}

	sort_array(arreglo_ordenado, n_datos);

	if(n_datos % 2){
		mediana = arreglo_ordenado[n_datos/2];
	}else{
		mediana = arreglo_ordenado[n_datos/2 - 1 ];
		mediana += arreglo_ordenado[n_datos/2];
		mediana /= 2;
	}

	return mediana;
}
unsigned char find_maximum(unsigned char arreglo[], uint16_t n_datos){

	unsigned char mayor;
	uint16_t indice;

	/* Asumir que el primer elemento del arreglo es el menor */
	mayor = arreglo[0];

	/* Comparar el número "menor" con todos los demás elementos del arreglo */
	for(indice = 1; indice < n_datos; indice++){
		/* Actualizar el valor de "menor" */
		if(arreglo[indice] > mayor){
			mayor = arreglo[indice];
		}
	}
	return mayor;
}

unsigned char find_minimum(unsigned char arreglo[], uint16_t n_datos){

	unsigned char menor;
	uint16_t indice;

	/* Asumir que el primer elemento del arreglo es el menor */
	menor = arreglo[0];

	/* Comparar el número "menor" con todos los demás elementos del arreglo */
	for(indice = 1; indice < n_datos; indice++){
		/* Actualizar el valor de "menor" */
		if(arreglo[indice] < menor){
			menor = arreglo[indice];
		}
	}
	return menor;
}

void sort_array(unsigned char arreglo[], uint16_t n_datos){

	/* Indicador para saber si los datos están desordenados */
	uint16_t datos_desordenados;

	uint16_t indice;
	unsigned char temporal;

	/* Ordenar los elementos de forma ascendente */
	do{
		/* Se asume que los datos están ordenados */
		datos_desordenados = 0;

		/* Se comparan los datos de dos en dos */
		for(indice = 0; indice < (n_datos - 1); indice++){

			/* Si alguna pareja de datos está desordenada ... */
			if(arreglo[indice] < arreglo[indice + 1]){

				/* Se indica en la variable "datos_desordenados" */
				datos_desordenados = 1;
				/* y se ordena los datos de forma ascendente */
				temporal = arreglo[indice];
				arreglo[indice] = arreglo[indice + 1];
				arreglo[indice + 1] = temporal;
			}

		}

	/* Repetir el procedimiento hasta que todos los datos se encuentren
	 * ordenados de forma ascendente*/
	}while(datos_desordenados);
}

/* Add other Implementation File Code Here */
