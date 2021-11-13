#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <limits.h> 
#include <ctype.h> 
#include "Employee.h"
#include "pedirDatos.h"
#include "LinkedList.h"



Employee*  employee_new(void)
{
    Employee* pEmployee = malloc(sizeof(Employee));

	return pEmployee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo)
{
    

	Employee* pS;
    int auxId;
    int auxHorasTrabajadas;
    int auxSueldo;

	if (idStr != NULL && esNumerica(idStr)==1 && nombreStr != NULL && horasTrabajadasStr!=NULL && esNumerica(horasTrabajadasStr)==1)	
	{
       auxId=atoi(idStr);
       auxHorasTrabajadas=atoi(horasTrabajadasStr);
       auxSueldo=atoi(sueldo);


        pS= employee_new();


        if(pS!=NULL)
        {
            employee_setId(pS,auxId);
			employee_setNombre(pS,nombreStr);
			employee_setHorasTrabajadas(pS,auxHorasTrabajadas);
			employee_setSueldo(pS, auxSueldo);
			//pS->id=idStr;
            //strncpy(pS->nombre,nombreStr,128);
            //pS->horasTrabajadas=auxHorasTrabajadas;
            //pS->sueldo=auxSueldo;
        }
	}
	return pS;
}

int find_EmployeeById(LinkedList* listEmployee, int id)
{
    Employee* pEmployee;

    int retorno =-1;

    if (listEmployee!=NULL && id > 0)
    {
        for (int i = 0; i < ll_len(listEmployee); i++)
        {
            pEmployee= ll_get(listEmployee,i);

            if(pEmployee->id==id) 
            {
                retorno=i;
                break;
            }
             
        }
    }
    
    return retorno;
    
}

void employee_delete(LinkedList* listEmployee, int id)
{
	int borrarID;

	if (listEmployee!=NULL)
	{
		borrarID=find_EmployeeById(listEmployee,id);
		if (borrarID!=-1)
		{
			//free(borrarID);

			free(ll_get(listEmployee,borrarID));

			ll_remove(listEmployee,borrarID);
		}
		
	}
}

void employee_modify(LinkedList* listEmployee, int id)
{
	int modificarID;
	Employee* auxEmployee;

	if (listEmployee!=NULL)
	{
		modificarID=find_EmployeeById(listEmployee,id);
		auxEmployee= ll_get(listEmployee,modificarID);

		if (modificarID!=-1 && auxEmployee!=NULL)
		{
			employee_getNombre(auxEmployee,auxEmployee->nombre);
			employee_getHorasTrabajadas(auxEmployee,&auxEmployee->horasTrabajadas);
			employee_getSueldo(auxEmployee,&auxEmployee->sueldo);
		}
		
	}
}


int employee_setId(Employee* this,int id)//numerico
{
	int retorno = -1;//error

	if(this != NULL && id >= 0)
	{
		this->id = id;//me guarda en el id de this el id que le paso por parametros
		retorno = 1;//exito
	}
	return retorno;
}

int employee_getId(Employee* this,int* id)
{
	int retorno = -1;//error

	pedirStringEntero(id,"\nIngrese el ID del empleado:","\nEl ID ingresado no es valido, ingreselo nuevamente: ",0,INT_MAX,3);

	if(this != NULL && id != NULL)
	{
		this->id= *id;//me guarda en el puntero a id lo que hay en this id
		retorno = 1;//exito
	}
	return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;//error

	if(this != NULL && nombre != NULL)
	{
	
			strncpy(this->nombre, nombre, 128);
			retorno = 1;//exito
	
	}
	return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;//error
	int auxChar;
	pedirStringTexto(nombre,128,"\nIngrese el nombre de empleado:","\nEl nombre ingresado es invalido, ingreselo nuevamente: ",3);

	if(this != NULL && nombre != NULL)
	{
		if(nombre[0]>= 'a' && nombre[0]<='z')
		{
			auxChar=nombre[0];
			nombre[0]=auxChar-32;
		}
		strncpy(this->nombre,nombre, 128);
		retorno = 1;//exito
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;//error

	if(this != NULL && horasTrabajadas >= 0)
	{
		this->horasTrabajadas = horasTrabajadas;//me guarda en horasTrabajadas de this las horas que le paso por parametros
		retorno = 1;//exito
	}
	return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;//error

	pedirStringEntero(horasTrabajadas,"\nIngrese la cantidad de horas trabajadas del empleado:","\nLa cantidad de horas ingresada no es valida, ingreselo nuevamente: ",0,INT_MAX,3);

	if(this != NULL && horasTrabajadas != NULL)
	{
		this->horasTrabajadas=*horasTrabajadas;//me guarda en el puntero a horasTrabajadas lo que hay en this horasTrabajadas
		retorno = 1;//exito
	}
	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;//error

	if(this != NULL && sueldo >= 0)
	{
		this->sueldo = sueldo;//me guarda en sueldo de this el sueldo que le paso por parametros
		retorno = 1;//exito
	}
	return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;//error

	pedirStringEntero(sueldo,"\nIngrese el sueldo del empleado:","\nEl sueldo ingresado no es valido, ingreselo nuevamente: ",0,INT_MAX,3);

	if(this != NULL && sueldo != NULL)
	{
		this->sueldo=*sueldo;//me guarda en el puntero a sueldo lo que hay en this sueldo
		retorno = 1;//exito
	}
	return retorno;
}
/**
 * @brief 
 * 
 * @param pEmpA 
 * @param pEmpB 
 * @return int 
 */
int ordenPorID(void* pEmpA,void* pEmpB)
{
if(((Employee*)pEmpA)->id > ((Employee*)pEmpB)->id)
{
 return 1;
}
if(((Employee*)pEmpA)->id < ((Employee*)pEmpB)->id)
{
 return -1;
}
return 0;
}
/**
 * @brief 
 * 
 * @param pEmpA 
 * @param pEmpB 
 * @return int 
 */
int ordenPorNombre(void* pEmpA,void* pEmpB)
{
	int retorno;
	Employee* emp1 = (Employee*)pEmpA;
	Employee* emp2 = (Employee*)pEmpB;
	 

	if (strcmp(emp1->nombre, emp2->nombre)>0)
	{
		retorno =1;
	}
	else if(strcmp(emp1->nombre, emp2->nombre)<0)
	{
		retorno = -1;
	}
	else
	{
		retorno=0;
	} 

	return retorno;
	
}
/**
 * @brief 
 * 
 * @param pEmpA 
 * @param pEmpB 
 * @return int 
 */
int ordenPorHoras(void* pEmpA,void* pEmpB)
{
if(((Employee*)pEmpA)->horasTrabajadas > ((Employee*)pEmpB)->horasTrabajadas)
{
 return 1;
}
if(((Employee*)pEmpA)->horasTrabajadas < ((Employee*)pEmpB)->horasTrabajadas)
{
 return -1;
}
return 0;
}
/**
 * @brief 
 * 
 * @param pEmpA 
 * @param pEmpB 
 * @return int 
 */
int ordenPorSueldo(void* pEmpA,void* pEmpB)
{
if(((Employee*)pEmpA)->sueldo > ((Employee*)pEmpB)->sueldo)
{
 return 1;
}
if(((Employee*)pEmpA)->sueldo < ((Employee*)pEmpB)->sueldo)
{
 return -1;
}
return 0;
}


