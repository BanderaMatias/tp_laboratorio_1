#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "pedirDatos.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int flagListaCargada = 0;
int flagAddSinCargar =0;
int flagConfirmacion = 0;
int flagTexto=0;
int flagBinario=0;

int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
        puts("Menu:\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n3. Alta de empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n7. Ordenar empleados\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n10. Salir");
		pedirStringEntero(&option,"\nSelecionar -->", "No es una opcion valida",0,10, 3);

        switch(option)
        {
            case 1:{
                if(flagListaCargada ==0)
                {
                    if(controller_loadFromText("dataTexto.csv",listaEmpleados)==1)  flagListaCargada=1;
                }
                else
                {
                    puts("La lista ya se encuentra cargada");
                }    
                break;
            }
            case 2:{
                if(flagListaCargada ==0)
                {
                    if(controller_loadFromBinary("dataBinario.csv",listaEmpleados)==1) flagListaCargada=1;
                }
                else
                {
                    puts("La lista ya se encuentra cargada");
                }
                break;
            }
            case 3:{
                if(flagListaCargada ==0)
                {
                    controller_addEmployee(listaEmpleados);
                    flagAddSinCargar =1;
                }
                else
                {
                    controller_addEmployee(listaEmpleados);
                }
                break;
            }
            case 4:{
                if(flagAddSinCargar==1 || flagListaCargada==1)
                {
                    controller_editEmployee(listaEmpleados);
                }
                else
                {
                    puts("No se puede modificar un empleado si no se cargo una lista o se creo uno previamente");
                }
                break;
            }
            case 5:{ 
                if(flagAddSinCargar==1 || flagListaCargada==1)
                {
                    controller_removeEmployee(listaEmpleados);
                }
                else
                {
                    puts("No se puede eliminar un empleado si no se cargo una lista o se creo uno previamente");
                }   
               
                break;
            }
            case 6:{
                if(flagAddSinCargar==1 || flagListaCargada==1)
                {
                    controller_ListEmployee(listaEmpleados);
                }
                else
                {
                    puts("No se puede listar empleados si no se cargo una lista o se creo uno previamente");
                }   
                
                break;
            }
            case 7:{
                if(flagAddSinCargar==1 || flagListaCargada==1)
                {
                    controller_sortEmployee(listaEmpleados);
                }
                else
                {
                    puts("No se puede ordenar empleados si no se cargo una lista o se creo uno previamente");
                }   
               
                break;
            }
            case 8:{
                if(flagAddSinCargar==1 || flagListaCargada==1)
                {
                    if (flagListaCargada==0)
                    {
                        pedirStringEntero(&flagConfirmacion,"Esta apunto de sobrescribir el archivo sin aberlo cargado previamente, ¿Esta seguro de guardar?\n1)NO\n2)SI","El valor ingresaod no es correcto, intente nuevamente:\n1)NO\n2)SI",1,2,5);
                        if (flagConfirmacion==2)
                        {
                            controller_saveAsText("dataTexto.csv",listaEmpleados);
                        }
                        
                    }
                    else{
                        controller_saveAsText("dataTexto.csv",listaEmpleados);
                    }
                }
                else
                {
                    puts("No se puede guardar empleados si no se cargo una lista o se creo uno previamente");
                }   

                break;
            }
            case 9:{
                if(flagAddSinCargar==1 || flagListaCargada==1)
                {
                    if (flagListaCargada==0)
                    {
                        pedirStringEntero(&flagConfirmacion,"Esta apunto de sobrescribir el archivo sin aberlo cargado previamente, ¿Esta seguro de guardar?\n1)NO\n2)SI","El valor ingresaod no es correcto, intente nuevamente:\n1)NO\n2)SI",1,2,5);
                        if (flagConfirmacion==2)
                        {
                             controller_saveAsBinary("dataBinario.csv",listaEmpleados);
                        }
                        
                    }
                    else{
                         controller_saveAsBinary("dataBinario.csv",listaEmpleados);
                    }
                   
                }
                else
                {
                    puts("No se puede guardar empleados si no se cargo una lista o se creo uno previamente");
                }   
                
                break;
            }
            case 10:{
                if (flagTexto==0 && flagBinario ==0)
                {
                    pedirStringEntero(&flagConfirmacion,"Esta apunto de cerrar el programa sin haber guardado los cambios, ¿Esta seguro?\n1)NO\n2)SI","El valor ingresaod no es correcto, intente nuevamente:\n1)NO\n2)SI",1,2,5);

                    if (flagConfirmacion == 1)
                    {
                        option=0;
                    }
                    
                }
                else if(flagTexto==0 || flagBinario ==0)
                {
                    pedirStringEntero(&flagConfirmacion,"Esta apunto de cerrar el programa y guardo los cambios en un solo tipo de archivo, ¿Esta seguro?\n1)NO\n2)SI","El valor ingresaod no es correcto, intente nuevamente:\n1)NO\n2)SI",1,2,5);

                    if (flagConfirmacion == 1)
                    {
                        option=0;
                    }
                }
            
                

                break;
            }
        }

        system("pause");
        system("cls");
    }while(option != 10);

    
    return 0;
}

