/*
 ============================================================================
 Name        : TP1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"
#include "pedirDatos.h"

#define REINTENTOS 5



int main(void) {

		setbuf(stdout,NULL);

		int opcion;
		int divisionValida;
		int resultadoNumeroUno;
		int resultadoNumeroDos;
		int flagPrimerOperando;
		int flagSegundoOperando;
		int salir;

		float numeroUno;
		float numeroDos;
		float resultadoDivision;
		float resultadoSuma;
		float resultadoResta;
		float resultadoMultiplicacion;
		float resultadoFactorialUno;
		float resultadoFactorialDos;

		salir = 0;
		numeroUno = 0;
		numeroDos = 0;
		resultadoFactorialUno=1;
		resultadoFactorialDos=1;
		flagPrimerOperando = 0;
		flagSegundoOperando =0;

		printf("1) Ingresar 1er operando \n");
		printf("2) Ingresar 2do operando \n");
		printf("3) Calcular todas las operaciones \n");
		printf("4) Informar resultados \n");
		printf("5) Salir \n");




		while(salir == 0){
			printf("Elija una opcion :");
			scanf("%d", &opcion);
			system("cls");

			printf("El primer operando es: %.2f \n",numeroUno);
			printf("El segundo operando es: %.2f \n",numeroDos);
			switch(opcion){
				case 1:{

					resultadoNumeroUno = pedirFlotante(&numeroUno, "Ingrese el primer operando: ", "El numero ingresado es invalido", -99999999,  9999999, REINTENTOS);
					if(resultadoNumeroUno == 1){
						flagPrimerOperando = 1;
					}
					break;
				}
				case 2:{

					resultadoNumeroDos = pedirFlotante(&numeroDos, "Ingrese el segundo operando: ", "El numero ingresado es invalido", -99999999,  9999999, REINTENTOS);
					if(resultadoNumeroDos == 1){
						flagSegundoOperando = 1;
					}
					break;
				}
				case 3:{
					if(flagPrimerOperando == 1 && flagSegundoOperando==1){

						resultadoSuma = suma( numeroUno,  numeroDos);
						resultadoResta = resta( numeroUno, numeroDos);
						resultadoMultiplicacion = multiplicacion(numeroUno, numeroDos);
						divisionValida = division(numeroUno, numeroDos, &resultadoDivision);
						factorial(numeroUno, &resultadoFactorialUno);
						factorial(numeroDos, &resultadoFactorialDos);

					}else{
						printf("Falta ingresar alguno de los operandos");
					}

					break;
				}
				case 4:{
						printf("El resultado de la suma es : %.2f \n",resultadoSuma);
						printf("El resultado de la resta es : %.2f \n" ,resultadoResta);
						printf("El resultado de la multiplicacion es : %.2f \n",resultadoMultiplicacion);
						if(divisionValida == 1){
							printf("El resultado de la division es : %.2f \n",resultadoDivision);
						}else{
							printf("No es posible dividir por cero \n");
						}
						printf("El factorial del primer operando es : %.2f \n",resultadoFactorialUno);
						printf("El factorial del segundo operando es : %.2f \n",resultadoFactorialDos);


					break;
				}
				case 5:{
					salir = 1;
					break;
				}
				default:{

					break;
				}
			}

		}

	return EXIT_SUCCESS;
}
