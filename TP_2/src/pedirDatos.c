/*
 * blibioteca.c
 *
 *  Created on: 7 sept 2021
 *      Author: Matii
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pedirDatos.h"
/*
int pedirNumero(int* pResultado, char mensaje[], char Error[], int minimo, int maximo, int reintentos)
{

	int bufferInt;
	int retorno = 0;

	if(pResultado != NULL && mensaje != NULL && Error != NULL && minimo<=maximo && reintentos>=0)
	{
		do
		{
			printf("%s",mensaje);
			scanf("%d",&bufferInt);

			if(bufferInt>=minimo && bufferInt<=maximo)
			{
				*pResultado = bufferInt;
				retorno = 1;
				break;

			}
			else
			{
				printf("%s",Error);
				reintentos--;
			}
		} while(reintentos>=0);
	}

	return retorno;

}

int pedirCaracter(char* pResultado, char mensaje[], char Error[], char minimo, char maximo, int reintentos)
{

	char bufferChar;
	int retorno = 0;

	if(pResultado != NULL && mensaje != NULL && Error != NULL && minimo<=maximo && reintentos>=0)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			scanf("%c",&bufferChar);

			if(bufferChar>=minimo && bufferChar<=maximo)
			{
				*pResultado = bufferChar;
				retorno = 1;
				break;

			}
			else
			{
				printf("%s",Error);
				reintentos--;
			}
		} while(reintentos>=0);
	}

	return retorno;

}
*/
int pedirFlotante(float* pResultado, char mensaje[], char Error[], float minimo, float maximo, int reintentos){

		float bufferFloat;
		int retorno = 0;

		if(pResultado != NULL && mensaje != NULL && Error != NULL && minimo<=maximo && reintentos>=0)
		{
			do
			{
				printf("%s",mensaje);
				scanf("%f",&bufferFloat);

				if(bufferFloat>=minimo && bufferFloat<=maximo)
				{
					*pResultado = bufferFloat;
					retorno = 1;
					break;

				}
				else
				{
					printf("%s",Error);
					reintentos--;
				}
			} while(reintentos>=0);
		}

		return retorno;

}



int pedirStringTexto(char* pResultado,int len, char mensaje[], char mensajeError[],int reintentos){
		int retorno = 0;
	    int indexFinal;

	    for(int i=0; i<=reintentos; i++)
	    {
	        if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	        {
	            printf("%s", mensaje);
	            fflush(stdin);
	            if(fgets(pResultado,len,stdin)!=NULL)
	            {
	            	indexFinal = strlen(pResultado)-1;

					if(pResultado[indexFinal] == '\n')
					{
						pResultado[indexFinal] = '\0';
					}
	                retorno = 1;
	                break;
	            }
	            else
	                printf("%s", mensajeError);
	        }
	    }
	    return retorno;

}

int esNumerica(char cadena[])
{
    int estado= 0;
    if (cadena!=NULL && strlen(cadena)>0)
    {
        estado=0;
        for(int i=0; i<strlen(cadena);i++)
        {
            if(cadena[i]<'9' && cadena[i]>'0')
            {
                estado=1;

            }else{
            	estado=0;
            	break;
            }


        }
    }
    return estado;
}


int pedirStringEntero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos){
    int retorno = 0;
    int bufferInt;
    int i;
    char bufferCadenaAux[16];
    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        for(i=0; i<=reintentos; i++)
        {
            printf("%s", mensaje);
            fflush(stdin);

            if(pedirStringTexto(bufferCadenaAux,sizeof(bufferCadenaAux),"","",1)==1)
            {

                if(esNumerica(bufferCadenaAux)==1)
                {
                    bufferInt = atoi(bufferCadenaAux);
                    if(bufferInt >= minimo && bufferInt <= maximo){
                        *pResultado = bufferInt;
                        retorno = 1;
                        break;
                    }else{
                        printf("%s", mensajeError);
                    }
                }
                else {
                    printf("%s", mensajeError);
                }
            }
            else {
                printf("%s", mensajeError);
            }
        }
    }
    return retorno;
}

