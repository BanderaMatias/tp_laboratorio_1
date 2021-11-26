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
int addEmployee(Employee* list, int len,int id){

	int retorno = 0;
	if (list!=NULL&&len>=0&&id>0)
	{
		for(int i = 0; i < len ; i++){

			if(list[i].isEmpty ==0){

				list[i].id=id;

				if(pedirStringTexto(list[i].name,LENSTRING, "\nIngrese el nombre del empleado: ", "El nombre ingresado es incorrecto",REINTENTOS) == -1)break;

				if(pedirStringTexto(list[i].lastName, LENSTRING, "\nIngrese el apellido del empleado: ", "El apellido ingresado es incorrecto",REINTENTOS)==-1)break;

				if(pedirFlotante(&list[i].salary, "\nIngrese el salario del nuevo empleado: ", "El valor ingresado es incorrecto o no es un numero.", 1, INT_MAX, REINTENTOS)==-1)break;

				if(pedirStringEntero(&list[i].sector, "\nIngrese el numero de sector del nuevo empleado: ", "El valor ingresado es incorrecto o no es un numero.", 1, INT_MAX, REINTENTOS)==-1)break;

				list[i].isEmpty =1;

				retorno = 1;
				printf("\nID: %d Nombre: %s Apellido: %s Salario %f Sector: %d",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
				break;
			}
			retorno = -1;
		}
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
	if (list!=NULL&&len>=0&&id>0)
	{
		for(int i = 0; i < len ; i++){

			if(list[i].id == id && list[i].isEmpty ==1){

				retorno = i;

				break;
			}
			retorno = -1;

		}
	}	
	return retorno;
}

int removeEmployee(Employee* list, int len, int id){

	int retorno = 0;
	if (list!=NULL&&len>=0&&id>0)
	{
		int index = findEmployeeById(list, len,id);
		if(index != -1){
			list[index].isEmpty =0;
			retorno = 1;
		}
	}
	return retorno;
}

int modifyEmployee(Employee* list, int len, int id){

	int retorno = 0;
	if (list!=NULL&&len>=0&& id>0)
	{
		int index = findEmployeeById(list, len,id);

		if(index != -1 && list[index].isEmpty ==1 ){

			pedirStringTexto(list[index].name,LENSTRING, "Ingrese el nombre del empleado: ", "El nombre ingresado es incorrecto",REINTENTOS);

			pedirStringTexto(list[index].lastName, LENSTRING, "Ingrese el apellido del empleado: ", "El apellido ingresado es incorrecto",REINTENTOS);

			pedirFlotante(&list[index].salary, "Ingrese el salario del nuevo empleado: ", "El valor ingresado es incorrecto o no es un numero.", 1, INT_MAX, REINTENTOS);

			pedirStringEntero(&list[index].sector, "Ingrese el numero de sector del nuevo empleado: ", "El valor ingresado es incorrecto o no es un numero.", 1, INT_MAX, REINTENTOS);

			retorno = 1;
		}
	}
	return retorno;
}



int ordenarEmpleados(Employee* list, int length)
{
	int listaSectore[length];
	for (int i = 0; i < length; i++)
	{
		listaSectore[i]=0;
	}
	
	int indexSectore=0;
	int flagLista=0;

	if (list!=NULL && length>=0)
	{
		for (int i = 0; i < length; i++)
		{
			if (list[i].isEmpty==1)
			{
				
				for (int j = 0; j < length; j++)
				{
					if (listaSectore[j]==list[i].sector)
					{
						flagLista=1;
						break;
					}
					
				}
				if (flagLista==0)
				{
					listaSectore[indexSectore]=list[i].sector;
					indexSectore++;
				}
				flagLista=0;	
			}	
				
			
		}
		orderByName(list,length);
		 for (int k = 0; k < length; k++)
		 {
			if(listaSectore[k]!=0)
			{
				for (int l = 0; l < length; l++)
				{
					if (listaSectore[k]== list[l].sector && list[l].isEmpty==1)
					{
						printf("ID: %d Nombre: %s Apellido: %s Salario %f Sector: %d \n",list[l].id,list[l].name,list[l].lastName,list[l].salary,list[l].sector);
					}
					
				}
			}
			
		 }
		 
		
	}
	return 1;
}

int orderByName(Employee* list, int length){


	int auxId;
	char auxName[51];
	char auxLastName[51];
	float auxSalary;
	int auxSector;

	if (list!=NULL&& length>0)
	{
		for(int i =0; i<length ; i++){

			for(int j=i; j<length;j++){

				if(list[i].isEmpty == 1 && list[j].isEmpty == 1){
				}
				if(stricmp(list[i].lastName,list[j].lastName)>0 && list[i].isEmpty==1 && list[j].isEmpty==1){

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

	}
	
	//orderBySector(list,length);



	return 1;
}

int printEmployees(Employee* list, int length){

	int retorno=-1;
	
	if(list!=NULL&&length>=0)
	{
		for(int i =0; i<length ; i++)
		{
			if(list[i].isEmpty == 1 )
			{			
					printf("ID: %d Nombre: %s Apellido: %s Salario %f Sector: %d \n",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
			}
			retorno=0;
		}
	}
	return retorno;
}


int calcularPromedio(Employee* list,int length){
	float totalSalary=0;
	float totalEmployees=0;
	float promedio =0.0;

	if (list!=NULL&&length>=0)
	{
		/* code */
	}
	
	{
		for(int i =0;i<length;i++){
			if(list[i].isEmpty == 1){

				totalSalary= totalSalary + list[i].salary;
				totalEmployees++;
			}
		}

		promedio=totalSalary/totalEmployees;

		printf("\nEl total de salarios es: %.2f y el promedio del mismo es %.2f",totalSalary,promedio);
		printf("\nLos siguientes empleados superanel promedio de salario:");
		for(int j =0;j<length;j++)
		{
				if(list[j].isEmpty == 1){

					if(list[j].salary >=promedio){
						printf("\nID: %d Nombre: %s Apellido: %s Salario %f Sector: %d ",list[j].id,list[j].name,list[j].lastName,list[j].salary,list[j].sector);
					}

				}
		}
	}
	return 1;
}






