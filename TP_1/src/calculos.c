/*
 * calculos.c
 *
 *  Created on: 11 sept 2021
 *      Author: Matii
 */
#include "calculos.h"

float suma(float numeroUno, float numeroDos){

	float resultado;

	resultado = numeroUno +numeroDos;

	return resultado;
}
float resta(float numeroUno, float numeroDos){

	float resultado;

	resultado = numeroUno - numeroDos;

	return resultado;
}
float multiplicacion(float numeroUno, float numeroDos){

	float resultado;

	resultado = numeroUno * numeroDos;

	return resultado;
}

int division(float numeroUno, float numeroDos, float* resultadoDivision){

	int retorno;
	retorno=0;

	if(numeroDos!=0){
		*resultadoDivision = numeroUno / numeroDos;
		retorno = 1;
	}

	return retorno;
}

void factorial(float numero, float* pResultado ){
	float acumulador;
	acumulador = 1;
	while(numero > 1) {
	       acumulador *= numero;
	       numero--;
	    }
	*pResultado = acumulador;
}
