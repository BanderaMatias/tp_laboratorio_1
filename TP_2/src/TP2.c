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
	int flagEmpleado=0;
	int imprimir;


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

		pedirStringEntero(&opcion,"\nSelecionar -->", "No es una opcion valida",1, 5, REINTENTOS);

		switch(opcion){
			case 1:{
				if(addEmployee(lista, CANTIDADEMP)==1){
					flagEmpleado= 1;
				}else{
					printf("No se pudo crear correctamente el empleado");
				}

				break;
			}
			case 2:{
				if(flagEmpleado==1){
					pedirStringEntero(&modificarID,"Ingrese el ID del empelado que desea modificar", "No es una opcion valida",1, INT_MAX, REINTENTOS);

					modifyEmployee(lista, CANTIDADEMP, modificarID);

				}else{
					printf("Debes ingresar un empleado primero");
				}


				break;
			}
			case 3:{
				if(flagEmpleado==1){
					pedirStringEntero(&borrarID,"Ingrese el ID del empelado que desea eliminar", "No es una opcion valida",1, INT_MAX, REINTENTOS);

					removeEmployee(lista, CANTIDADEMP, borrarID);
				}else{
					printf("Debes ingresar un empleado primero");
				}
				break;
			}
			case 4:{
				if(flagEmpleado==1){

					pedirStringEntero(&imprimir,"\nSi quiere imprimir todoslos empledos ingrese 1\nSi quiere ver los empleados que superan el salario promerio presione 2", "No es una opcion valida",1, 2, REINTENTOS);
					if(imprimir==1){
					orderByName(lista,CANTIDADEMP);
					printEmployees(lista, CANTIDADEMP);
					}
					if(imprimir==2){
					calcularPromedio(lista,CANTIDADEMP);
					}
				}else{
					printf("Debes ingresar un empleado primero");
				}

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
