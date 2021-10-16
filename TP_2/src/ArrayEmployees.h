/*
 * ArrayEmployees.h
 *
 *  Created on: 11 oct 2021
 *      Author: Matii
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_



struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}typedef Employee;

int initEmployees(Employee* list, int len);
int addEmployee(Employee* list, int len);
int removeEmployee(Employee* list, int len, int id);
int modifyEmployee(Employee* list, int len, int id);
int printEmployees(Employee* list, int length);
int orderByName(Employee* list, int length);
int calcularPromedio(Employee* list,int length);

#endif /* ARRAYEMPLOYEES_H_ */
