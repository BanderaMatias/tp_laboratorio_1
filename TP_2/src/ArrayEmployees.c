/*
 * ArrayEmployees.c
 *
 *  Created on: 11 oct 2021
 *      Author: Matii
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "ArrayEmployees.h"
#include "pedirDatos.h"

#define REINTENTOS 5
#define LENSTRING 51
/*
 * return = 0 error al inicializar el array
 * return = 1 array inicializado exitosamente
 */
int initEmployees(Employee* list, int len){
	int retorno = 0;

	if(list != NULL && len >1){
		for(int i = 0; i < len ; i++){
				list[i].isEmpty =0;

			}
		retorno=1;
	}
	return retorno;
}
/*
 * return 0 error en la carga
 * return 1 cargar exitosa
 * return -1 no hay lugar para cargar  *
 */
int addEmployee(Employee* list, int len){

	int retorno = 0;

	for(int i = 0; i < len ; i++){

		if(list[i].isEmpty ==0){

			if(pedirNumero(&list[i].id, "Ingrese el ID del nuevo empleado: ", "El valor ingresado es incorrecto o no es un numero.", 1, INT_MAX, REINTENTOS) == 0)break;

			if(pedirStringTexto(list[i].name,LENSTRING, "Ingrese el nombre del empleado: ", "El nombre ingresado es incorrecto",REINTENTOS) == 0)break;

			if(pedirStringTexto(list[i].lastName, LENSTRING, "Ingrese el apellido del empleado: ", "El apellido ingresado es incorrecto",REINTENTOS)==0)break;

			if(pedirFlotante(&list[i].salary, "Ingrese el salario del nuevo empleado: ", "El valor ingresado es incorrecto o no es un numero.", INT_MIN, INT_MAX, REINTENTOS)==0)break;

			if(pedirNumero(&list[i].sector, "Ingrese el numero de sector del nuevo empleado: ", "El valor ingresado es incorrecto o no es un numero.", INT_MIN, INT_MAX, REINTENTOS)==0)break;

			list[i].isEmpty =1;

			retorno = 1;
			printf("ID: %d Nombre: %s Apellido: %s Salario %f Sector: %d Vacio? %d",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector,list[i].isEmpty );

		    break;
		}
		retorno = -1;

	}
	return retorno;
}

/*
 * return = 0 Los paramatros que pasaron no son compatibles
 * reutrn = i Encontro el ID que buscaba
 * return = -1 nose encontro el ID
 */

int findEmployeeById(Employee* list, int len,int id){

	int retorno = 0;

	for(int i = 0; i < len ; i++){

		if(list[i].id == id && list[i].isEmpty ==1){

			retorno = i;

			break;
		}
		retorno = -1;

	}
	return retorno;
}

int removeEmployee(Employee* list, int len, int id){

	int retorno = 0;

	int index = findEmployeeById(list, len,id);
	if(index != -1){
		list[index].isEmpty =0;
		retorno = 1;
	}

	return retorno;
}

int modifyEmployee(Employee* list, int len, int id){

	int retorno = 0;

	int index = findEmployeeById(list, len,id);

	if(index != -1 && list[index].isEmpty ==1 ){

		pedirNumero(&list[index].id, "Ingrese el ID del nuevo empleado: ", "El valor ingresado es incorrecto o no es un numero.", 1, INT_MAX, REINTENTOS);

		pedirStringTexto(list[index].name,LENSTRING, "Ingrese el nombre del empleado: ", "El nombre ingresado es incorrecto",REINTENTOS);

		pedirStringTexto(list[index].lastName, LENSTRING, "Ingrese el apellido del empleado: ", "El apellido ingresado es incorrecto",REINTENTOS);

		pedirFlotante(&list[index].salary, "Ingrese el salario del nuevo empleado: ", "El valor ingresado es incorrecto o no es un numero.", INT_MIN, INT_MAX, REINTENTOS);

		pedirNumero(&list[index].sector, "Ingrese el numero de sector del nuevo empleado: ", "El valor ingresado es incorrecto o no es un numero.", INT_MIN, INT_MAX, REINTENTOS);

		retorno = 1;
	}

	return retorno;
}

int printEmployees(Employee* list, int length){

	for(int i =0; i<length ; i++){
		if(list[i].isEmpty == 1){
			printf("ID: %d \nNombre: %s Apellido: %s Salario %f \nSector: %d ",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
		}
	}
	return 1;
}


