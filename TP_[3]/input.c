/*
 * input.c
 *
 *  Created on: 3 jun 2022
 *      Author: User
 */

#include "input.h"


int utn_getnumero(int* pResultado,char* mensaje, char* mensajeError,int minimo, int maximo)
{
    int retorno = -1;
    char buffer1[5];
    int buffer;

        do{
            printf("%s", mensaje);
            fflush(stdin);
            scanf("%s",buffer1);

            if (!(esEnteroValido(buffer1)))
            {
            	printf("%s", mensajeError);
            	fflush(stdin);
            }
            else
            {
            	buffer = strtol(buffer1, NULL, 10);
            	if( buffer > minimo && buffer < maximo)
            	{
            		*pResultado = buffer;
            		retorno = 0;
            		fflush(stdin);
            	}
            	else
            	{
            		printf("%s", mensajeError);
            		fflush(stdin);
            	}

		    }



        }while(retorno == -1);

    return retorno;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/*
int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////
/*
int esNumericoFlotante(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}*/

//////////////////////////////////////////////////////////////////////////////////////////////////////

void getString(char nombre[], char* mensaje,char* mensajeError)
{
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%[^\n]s", nombre);

    for(int i = 0;i<strlen(nombre);i++)
        {
    	nombre[i] = tolower((unsigned char) nombre[i]);

    			if(isdigit(nombre[i]))
				{
					printf("%s", mensajeError);
					fflush(stdin);
					scanf("%[^\n]s", nombre);
				}
        }
}

void getStringAlf(char nombre[], char* mensaje,char* mensajeError)
{
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%[^\n]s", nombre);

    for(int i = 0;i<strlen(nombre);i++)
    {
			if((isdigit(nombre[i]) && isalpha(nombre[i])))
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%[^\n]s", nombre);
		}
    }


}
//////////////////////////////////////////////////////////////////////////////////////////////////////

int getNumberInt(int* pResultado,char* mensaje, char* mensajeError,int minimo, int maximo)
{
	int retorno = -1;
	int buffer;
	char numeroRecibido[5];

    do{
       printf("%s", mensaje);
       fflush(stdin);
       scanf("%s",numeroRecibido);

        if( !(esEnteroValido(numeroRecibido)))
		{
			printf("%s", mensajeError);
			fflush(stdin);
		}
        else
        {
        	buffer = strtol(numeroRecibido, NULL, 10);

			if(buffer > minimo && buffer < maximo)
			{
				*pResultado = buffer;
				retorno = 0;
			}
			else
			{
				printf("%s", mensajeError);
				fflush(stdin);
			}
	    }


    }while(retorno == -1);

	return retorno;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////

float getNumberFloat(float *pResultado,char* mensaje, char* mensajeError,int minimo, int maximo)
{

	int retorno = -1;
	char numeroRecibido[10];
	float buffer;

	do{
	   printf("%s", mensaje);
	   fflush(stdin);
	   scanf("%s",numeroRecibido);

		if( !(esFlotanteValido(numeroRecibido)))
		{
			printf("%s", mensajeError);
			fflush(stdin);
		}
		else
		{
			buffer = strtol(numeroRecibido, NULL, 10);

			if(buffer > minimo && buffer < maximo)
			{
				*pResultado = buffer;
				retorno = 0;
			}
			else
			{
				printf("%s", mensajeError);
				fflush(stdin);
			}
		}


	}while(retorno == -1);

	return retorno;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

int getCaracter(char* pResultado,char* mensaje, char* mensajeError,char minimo, char maximo)
{
	int retorno = -1;
	char buffer;

		do{
			printf("%s", mensaje);
			scanf("%c",&buffer);

			if(buffer >= minimo && buffer <= maximo)
			{
				*pResultado = buffer;
				retorno = 0;
			}
			else
			{
				printf("%s", mensajeError);
			}
		}while(retorno == -1);

	return retorno;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

void CargarVectorEnteros(int numerosRecibidos[],int size)
{
    //carga secuencial

    for(int i = 0; i < size; i++)
    {
        printf("\n Ingrese numero: ");
        scanf("%d", &numerosRecibidos[i]);
    }
    //numerosRecibidos[i]=PedirEntero()
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

void CargarVectorFlotantes(float numerosRecibidos[],int size)
{
    //carga secuencial

    for(int i = 0; i < size; i++)
    {
        printf("\n Ingrese numero: ");
        scanf("%f", &numerosRecibidos[i]);
    }
    //numerosRecibidos[i]=PedirEntero()
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

void MostrarVector(int numerosRecibidos[],int size)
{
   //mostrar numeros ingresados
    for(int i = 0; i < size; i++)
    {
        printf(" ingreso: %d \n", numerosRecibidos[i]);
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////

float CalcularPromedio(int numeroUno,int numeroDos)
{
	float promedio;

	promedio= ((float)(numeroUno + numeroDos)) /2;

	return promedio;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

int DeterminarParidad(int numeroRecibido)
{
   int resultado;
   resultado=0;

    if(numeroRecibido%2 == 0)
    {
        resultado=1;
    }

    return resultado;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

int DeterminarSigno(int numero,int signo)
{
    signo=0;

    if(numero<0)
    {
        signo = -1;
    }
    else
    {
       if(numero>0)
       {
        signo = 1;
       }
    }

    return signo;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

void MostrarResultadoEntero(char* mensaje, int resultado)
{
    printf("%s %d \n",mensaje,resultado);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

void MostrarResultadoFlotante(char* mensaje,float resultado)
{
	printf("%s %f \n",mensaje,resultado);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
