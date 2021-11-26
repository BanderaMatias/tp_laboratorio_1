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

int myGets(char *pResultado, int len)
 {
 	int retorno=-1;
 	int indexFinal;
 	if(fgets(pResultado,len,stdin)!=NULL)
 	{
 		fflush(stdin);
 		indexFinal = strlen(pResultado)-1;
 		if(pResultado[indexFinal] == '\n')
 			{
 			pResultado[indexFinal] = '\0';
 			}
 		retorno = 0;
 	}
 	return retorno;
}


int esNombre(char *cadena)
{
	int i;
	int retorno = -1;
	if(cadena != NULL)
	{
		for(i=0;i<52;i++)
		{
			if((cadena[i]>='A'&&cadena[i]<='Z')||(cadena[i]>='a'&&cadena[i]<='z'))
			{
				retorno=0;
			}else{
				if(cadena[i]=='\0')
				{
					retorno=0;
					break;
				}else{
					retorno =-1;
					break;
				}
			}
		}
	}
	return retorno;
}

int pedirStringTexto(char *pResultado, int len, char *mensaje, char *mensajeError, int intentos)
{
	int retorno = -1;
	int i;
	char bufferCadenaAux[128];
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && intentos >= 0)
	{
		for(i=0; i<=intentos; i++)
		{
			printf("\n%s\n", mensaje);
			fflush(stdin);
			if(myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0  && strlen(bufferCadenaAux)>0)
			{
				strncpy(pResultado, bufferCadenaAux,len);

				if (esNombre(pResultado)==0)
				{
					puts("verifique el nombre");
					retorno = 0;
					break;
				}else
				{
					printf("%s\n", mensajeError);
				}
			}else
				{
					printf("%s\n", mensajeError);
				}
		}
	}
	return retorno;
}


int esNumericaFloat(char *cadena)
{
 	int i=0;
 	int retorno = -1;
 	int puntos=0;
 	if(cadena != NULL && strlen(cadena) > 0)
 	{
 		while(cadena[i] != '\0')
 		{
			if(cadena[i] >= '0' && cadena[i] <= '9')
			{
 				retorno=0;
			}
			else if(cadena[i]=='.')
			{
				retorno=0;
				puntos++;
			}
			else
			{
				retorno=-1;
			}
			i++;
 		}
 		if(puntos>1)
 		{
 			retorno=-1;
 		}
 	}
 	return retorno;
}


int pedirFlotante(float *pResultado, char *mensaje, char *mensajeError, float minimo, float maximo, int intentos)
 {
 	int retorno = -1;
 	float bufferInt;
 	int i;
 	char bufferCadenaAux[32];

 	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && intentos >= 0)
 	{
 		for(i=0; i<=intentos; i++)
 		{
 			printf("\n%s\n", mensaje);
 			fflush(stdin);
 			if(myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
 			{
 				if(esNumericaFloat(bufferCadenaAux)==0)
 					{
 					bufferInt = atof(bufferCadenaAux);
 					if(bufferInt >= minimo && bufferInt <= maximo)
 						{
 							*pResultado = bufferInt;
 							retorno = 0;
 							break;
 						}else
 							{
 							printf("%s", mensajeError);
 							}
 					}
 				else
 					{
 					printf("%s", mensajeError);
 					}
 			}
 			else
 				{
 				printf("%s", mensajeError);
 				}
 		}
 		if(retorno==-1)
 		{
 			printf("\nTe quedaste sin intentos\n");
 		}
 	}
 	return retorno;
 }





int esNumerica(char cadena[])
{
    int estado= -1;
    if (cadena!=NULL && strlen(cadena)>0)
    {
        estado=-1;
        for(int i=0; i<strlen(cadena);i++)
        {
            if(cadena[i]<='9' && cadena[i]>='0')
            {
                estado=0;

            }else{
            	estado=-1;
            	break;
            }


        }
    }
    return estado;
}


int pedirStringEntero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos){
    int retorno = -1;
    int bufferInt;
    int i;
    char bufferCadenaAux[16];
    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        for(i=0; i<=reintentos; i++)
        {
            printf("%s", mensaje);
            fflush(stdin);

            if(myGets(bufferCadenaAux,16)==0)
            {

                if(esNumerica(bufferCadenaAux)==0)
                {
                    bufferInt = atoi(bufferCadenaAux);
                    if(bufferInt >= minimo && bufferInt <= maximo){
                        *pResultado = bufferInt;
                        retorno = 0;
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
