/*
 ============================================================================
 Name        : TP2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "ArrayEmployees.h"
#include "pedirDatos.h"

#define REINTENTOS 5
#define CANTIDADEMP 1000


int main(void) {

	setbuf(stdout,NULL);

	int opcion;
	int salir;
	int borrarID;
	int modificarID;

	Employee lista[CANTIDADEMP];

	salir = 0;

	if(initEmployees(lista, CANTIDADEMP)==0){
		printf("Hubo un error al inicializar el array");

		salir=1;
	}

	printf("1) ALTAS \n");
	printf("2) MODIFICAR \n");
	printf("3) BAJA \n");
	printf("4) INFORMAR \n");
	printf("5) Salir \n");

	while(salir == 0){

		pedirNumero(&opcion,"Selecionar -->", "No es una opcion valida",1, 5, REINTENTOS);

		switch(opcion){
			case 1:{
				addEmployee(lista, CANTIDADEMP);

				break;
			}
			case 2:{
				pedirNumero(&modificarID,"Ingrese el ID del empelado que desea modificar", "No es una opcion valida",1, INT_MAX, REINTENTOS);

				modifyEmployee(lista, CANTIDADEMP, modificarID);

				break;
			}
			case 3:{
				pedirNumero(&borrarID,"Ingrese el ID del empelado que desea eliminar", "No es una opcion valida",1, INT_MAX, REINTENTOS);

				removeEmployee(lista, CANTIDADEMP, borrarID);

				break;
			}
			case 4:{
				printEmployees(lista, CANTIDADEMP);
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
