/*
 * Employee.h
 *
 *  Created on: 20 nov 2021
 *      Author: Matii
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_



#include "LinkedList.h"


#define ERROR -1
#define EXITO 1

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo);
void employee_delete(LinkedList* listEmployee, int id);
void employee_modify(LinkedList* listEmployee, int id);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int find_EmployeeById(LinkedList* listEmployee, int id);

int ordenPorID(void* pPersonA,void* pPersonB);
int ordenPorNombre(void* pPersonA,void* pPersonB);
int ordenPorHoras(void* pPersonA,void* pPersonB);
int ordenPorSueldo(void* pPersonA,void* pPersonB);


#endif /* EMPLOYEE_H_ */
