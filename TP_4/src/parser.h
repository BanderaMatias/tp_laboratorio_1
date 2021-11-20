/*
 * parser.h
 *
 *  Created on: 6 nov 2021
 *      Author: Matii
 */

#ifndef PARSER_H_
#define PARSER_H_

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_maxId(FILE* pFile , int* maxId);
#endif /* PARSER_H_ */
