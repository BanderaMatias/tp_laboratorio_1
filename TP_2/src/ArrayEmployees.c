/*
 * ArrayEmployees.c
 *
 *  Created on: 11 oct 2021
 *      Author: Matii
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

			if(pedirStringEntero(&list[i].id, "Ingrese el ID del nuevo empleado: ", "El valor ingresado es incorrecto o no es un numero.", 1, INT_MAX, REINTENTOS) == 0)break;

			if(pedirStringTexto(list[i].name,LENSTRING, "Ingrese el nombre del empleado: ", "El nombre ingresado es incorrecto",REINTENTOS) == 0)break;

			if(pedirStringTexto(list[i].lastName, LENSTRING, "Ingrese el apellido del empleado: ", "El apellido ingresado es incorrecto",REINTENTOS)==0)break;

			if(pedirFlotante(&list[i].salary, "Ingrese el salario del nuevo empleado: ", "El valor ingresado es incorrecto o no es un numero.", 1, INT_MAX, REINTENTOS)==0)break;

			if(pedirStringEntero(&list[i].sector, "Ingrese el numero de sector del nuevo empleado: ", "El valor ingresado es incorrecto o no es un numero.", 1, INT_MAX, REINTENTOS)==0)break;

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

		pedirStringEntero(&list[index].id, "Ingrese el ID del nuevo empleado: ", "El valor ingresado es incorrecto o no es un numero.", 1, INT_MAX, REINTENTOS);

		pedirStringTexto(list[index].name,LENSTRING, "Ingrese el nombre del empleado: ", "El nombre ingresado es incorrecto",REINTENTOS);

		pedirStringTexto(list[index].lastName, LENSTRING, "Ingrese el apellido del empleado: ", "El apellido ingresado es incorrecto",REINTENTOS);

		pedirFlotante(&list[index].salary, "Ingrese el salario del nuevo empleado: ", "El valor ingresado es incorrecto o no es un numero.", 1, INT_MAX, REINTENTOS);

		pedirStringEntero(&list[index].sector, "Ingrese el numero de sector del nuevo empleado: ", "El valor ingresado es incorrecto o no es un numero.", 1, INT_MAX, REINTENTOS);

		retorno = 1;
	}

	return retorno;
}



int orderByName(Employee* list, int length){


	int auxId;
	char auxName[51];
	char auxLastName[51];
	float auxSalary;
	int auxSector;


	for(int i =0; i<length ; i++){

		for(int j=i; j<length;j++){

			if(list[i].isEmpty == 1 && list[j].isEmpty == 1){
			}
			if(*list[i].lastName > *list[j].lastName && list[i].isEmpty==1 && list[j].isEmpty==1){

				auxId= list[i].id;
				strncpy(auxName,list[i].name,51);
				strncpy(auxLastName,list[i].lastName,51);
				auxSalary=list[i].salary;
				auxSector=list[i].sector;

				list[i].id =list[j].id	;
				strncpy(list[i].name, list[j].name,51);
				strncpy(list[i].lastName, list[j].lastName,51);
				list[i].salary= list[j].salary;
				list[i].sector= list[j].sector;

				list[j].id = auxId;
				strncpy(list[j].name,auxName,51);
				strncpy(list[j].lastName,auxLastName,51);
				list[j].salary = auxSalary;
				list[j].sector = auxSector;
			}

		}

	}



	return 1;
}
int listSectores(int *listSector,int sector , int length){
	int retorno=0;

	    for(int i =0; i<length; i++){
	            if(listSector[i]==sector){
	                retorno=1;
	                break;
	        }
	    }
	    return retorno;
}

int orderBySector(Employee* list, int length, int* listaSectores ){

	int swap;
	int mayor;
	int vueltas;

	for(int j=0;j< length;j++){
		listaSectores[j]=0;
	}

	int auxIndex=0;

	for(int i =0; i<length ; i++){

		if(list[i].isEmpty == 1){
			if(listSectores(listaSectores,list[i].sector,length)==0){
				listaSectores[auxIndex]=list[i].sector;
				auxIndex++;
			}
		}


	}


		vueltas = 0;
		mayor = listaSectores[0];

		do{
		for(int j=vueltas;j<length ;j++){
			if(mayor>listaSectores[j]){
				mayor = listaSectores[j];
				swap=listaSectores[vueltas];
				listaSectores[vueltas]= mayor;

				listaSectores[j]=swap;
			}

		}
		vueltas++;
		mayor =listaSectores[vueltas];
		}while(vueltas<length);


	return 1;
}

int printEmployees(Employee* list, int length){
	int listaSectores[100];
	orderBySector(list, length, listaSectores);
	for(int j=0;j<length;j++){
		for(int i =0; i<length ; i++){
			if(list[i].isEmpty == 1 && listaSectores[j]!=0){
				if(listaSectores[j]==list[i].sector){
					printf("ID: %d Nombre: %s Apellido: %s Salario %f Sector: %d \n",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
				}
			}
		}
	}
	return 1;
}


int calcularPromedio(Employee* list,int length){
	float totalSalary=0;
	float totalEmployees=0;
	float promedio =0.0;

	for(int i =0;i<length;i++){
		if(list[i].isEmpty == 1){

			totalSalary= totalSalary + list[i].salary;
			totalEmployees++;
		}
	}

	promedio=totalSalary/totalEmployees;

	printf("\nEl total de salarios es: %.2f y el promedio del mismo es %.2f",totalSalary,promedio);
	printf("\nLos siguientes empleados superanel promedio de salario:");
	for(int j =0;j<length;j++){
			if(list[j].isEmpty == 1){

				if(list[j].salary >=promedio){
					printf("\nID: %d Nombre: %s Apellido: %s Salario %f Sector: %d ",list[j].id,list[j].name,list[j].lastName,list[j].salary,list[j].sector);
				}

			}
		}
	return 1;
}






