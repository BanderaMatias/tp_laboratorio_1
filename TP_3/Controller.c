#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "pedirDatos.h"

/**
 * @brief 
 * 
 * @param path 
 * @param maxId 
 * @return int 
 */
int controller_id(char* path, int* maxId)
{
    FILE* f = fopen(path,"rb");
    if (f!=NULL)
    {
        parser_maxId(f,maxId);
        fclose(f);
    }
    return 1;
}
/**
 * @brief 
 * 
 * @param path 
 * @param maxId 
 * @return int 
 */
int controller_saveId(char* path, int* maxId)
{
    FILE* f = fopen(path,"wb");
    if (f!=NULL)
    {
        fwrite(maxId,sizeof(int),1,f);

        fclose(f);
    }
    return 1;
}

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
    if (f!=NULL)
    {
        parser_EmployeeFromText(f,pArrayListEmployee);
    }
    else
    {
        f = fopen(path,"w");  
        puts("No se encontro el archivo, por lo tanto lo creamos");
    }
    
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
    if (f != NULL)
    {
        parser_EmployeeFromBinary(f,pArrayListEmployee);
    }
    else
    {
       f = fopen(path,"wb");  
        puts("No se encontro el archivo, por lo tanto lo creamos");
    }
    
    
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
    controller_id("id.csv", &auxId);

    pEmployee=employee_new();
    pEmployee->id= auxId;
    employee_getNombre(pEmployee,auxNombre);
    employee_getHorasTrabajadas(pEmployee,&auxHoras);
    employee_getSueldo(pEmployee,&auxSueldo);
    ll_add(pArrayListEmployee,pEmployee);

    auxId++;
    controller_saveId("id.csv", &auxId);

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
    Employee* pEaux;

    if (pArrayListEmployee !=NULL)
    {
        for (int i = 1; i < ll_len(pArrayListEmployee); i++)
        {
            pEaux= ll_get(pArrayListEmployee,i);
            printf("%d,%s,%d,%d\n",pEaux->id,pEaux->nombre,pEaux->horasTrabajadas,pEaux->sueldo);

        }
    }


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
    controller_ListEmployee(pArrayListEmployee);
    int modificarID;
    pedirStringEntero(&modificarID,"Ingrese el ID del empleado que dese modificar","El ID ingresado es invalido, ingreselo nuevamente: ",0,INT_MAX,3);
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
    controller_ListEmployee(pArrayListEmployee);
    int borrarID;

    pedirStringEntero(&borrarID,"Ingrese el ID del empleado que dese eliminar","El ID ingresado es invalido, ingreselo nuevamente: ",0,INT_MAX,3);
    employee_delete(pArrayListEmployee,borrarID);   
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
    int orden=0;
    pedirStringEntero(&orden,"\nOrdenar por:\n1)ID ASC\n2)ID DESC \n3)Nombre A-Z\n4)Nombre Z-A \n5)Horas ASC\n6)Horas DESC \n7)Sueldo ASC \n8)Sueldo DESC\n9)Salir.","\nEl valor ingresado no es valido",1,9,3);

    switch (orden)
    {
    case 1:{
        ll_sort(pArrayListEmployee,ordenPorID,1);
        break;
    }
    case 2:{
        ll_sort(pArrayListEmployee,ordenPorID,0);
        break;
    }
    case 3:{
        ll_sort(pArrayListEmployee,ordenPorNombre,1);
        break;
    }
    case 4:{
        ll_sort(pArrayListEmployee,ordenPorNombre,0);
        break;
    }
    case 5:{
        ll_sort(pArrayListEmployee,ordenPorHoras,1);
        break;
    }
    case 6:{
        ll_sort(pArrayListEmployee,ordenPorHoras,0);
        break;
    }
    case 7:{
        ll_sort(pArrayListEmployee,ordenPorSueldo,1);
        break;
    }
    case 8:{
        ll_sort(pArrayListEmployee,ordenPorSueldo,0);
        break;
    }
    case 9:{    
        
        break;
    }
       
    }
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
    FILE* f = fopen(path,"wb");
    Employee* pEaux; 
    if(f!=NULL && pArrayListEmployee != NULL)
    {
        for(int i=0; i<pArrayListEmployee->size; i++)
        {
            pEaux = ll_get(pArrayListEmployee,i);
           
            if (pEaux != NULL)
            {
                fwrite(pEaux,sizeof(Employee),1,f);
            }

            pEaux= NULL;
            
            //fprintf(f,"%d,%s,%d,%d\n",pEaux->id,pEaux->nombre,pEaux->horasTrabajadas,pEaux->sueldo);
        }
        fclose(f);
    }
    return 1;
}

