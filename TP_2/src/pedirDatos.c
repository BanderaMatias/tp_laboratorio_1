/*
 * blibioteca.c
 *
 *  Created on: 7 sept 2021
 *      Author: Matii
 */

#include "pedirDatos.h"

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
	    int i;
	    for(i=0; i<=reintentos; i++)
	    {
	        if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	        {
	            printf("%s", mensaje);
	            fflush(stdin);
	            if(fgets(pResultado,len,stdin)!=NULL)
	            {
	                retorno = 1;
	                break;
	            }
	            else
	                printf("%s", mensajeError);
	        }
	    }
	    return retorno;

}
