/*
 * bliblioteca.h
 *
 *  Created on: 7 sept 2021
 *      Author: Matii
 */

#ifndef PEDIRDATOS_H_
#define PEDIRDATOS_H_

#include <stdio.h>
#include <stdlib.h>

int pedirNumero(int* pResultado, char mensaje[], char Error[], int minimo, int maximo, int reintentos);
int pedirFlotante(float* pResultado, char mensaje[], char Error[], float minimo, float maximo, int reintentos);
int pedirCaracter(char* pResultado, char mensaje[], char Error[], char minimo, char maximo, int reintentos);


#endif /* PEDIRDATOS_H_ */
