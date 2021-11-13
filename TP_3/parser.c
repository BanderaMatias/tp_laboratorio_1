#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* pEaux;

    char id[16];
    char nombre[128];
    char horasTrabajadas[16];
    char sueldo[16];
    
    if (pFile!=NULL)
    {   
        //Llega
        do       
        {
            pEaux = employee_new();
            
            
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo)==4)
            {          
            	
                pEaux = employee_newParametros(id,nombre,horasTrabajadas,sueldo);
                
                ll_add(pArrayListEmployee,pEaux);
                
            }
            else
            {
            	
               // employee_delete(pEaux);
            }
        }while(feof(pFile)==0);  

    }


    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    
    //LinkedList* lista = ll_newLinkedList();
    //FILE* f = fopen("prueba.txt","rb");

    Employee* pEaux;
    
    if (pFile!=NULL)
    {   
        do       
        {
            pEaux = employee_new();
            
            if(fread(pEaux,sizeof(Employee),1,pFile)==1)
            {
                ll_add(pArrayListEmployee,pEaux);
            }
            else
            {
                //employee_delete(pEaux);
            }
        }while(feof(pFile)==0);  

    }

    return 1;
}
