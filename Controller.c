#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "pedirDatos.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* f = fopen(path,"r");

    parser_EmployeeFromText(f,pArrayListEmployee);
    puts("-->Controller");
    fclose(f);


    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* f = fopen(path,"rb");
    parser_EmployeeFromBinary(f,pArrayListEmployee);
    fclose(f);
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;
    int auxId;
    char auxNombre[128];
    int auxHoras;
    int auxSueldo;

    pEmployee=employee_new();
    employee_getId(pEmployee,&auxId);
    employee_getNombre(pEmployee,auxNombre);
    employee_getHorasTrabajadas(pEmployee,&auxHoras);
    employee_getSueldo(pEmployee,&auxSueldo);
    ll_add(pArrayListEmployee,pEmployee);

    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int modificarID;
    pedirStringEntero(&modificarID,"Ingrese el ID del empleado que dese eliminar","El ID ingresado es invalido, ingreselo nuevamente: ",0,INT_MAX,3);
    employee_modify(pArrayListEmployee,modificarID);
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int borrarID;

    pedirStringEntero(&borrarID,"Ingrese el ID del empleado que dese eliminar","El ID ingresado es invalido, ingreselo nuevamente: ",0,INT_MAX,3);
    employee_delete(pArrayListEmployee,borrarID);   
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* f = fopen(path,"w");
    Employee* pEaux; 
    if(f!=NULL)
    {
        fprintf(f,"id,nombre,horasTrabajadas,sueldo\n");
        for(int i=1; i<ll_len(pArrayListEmployee); i++)
        {
            pEaux = ll_get(pArrayListEmployee,i);
            fprintf(f,"%d,%s,%d,%d\n",pEaux->id,pEaux->nombre,pEaux->horasTrabajadas,pEaux->sueldo);
        }
        fclose(f);
    }
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

