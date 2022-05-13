/*
 * input.c
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "input.h"

int utn_getnumero(int* pResultado,char* mensaje, char* mensajeError,int minimo, int maximo)
{
    int retorno = -1;
    int buffer;

        do{
            printf("%s", mensaje);
            fflush(stdin);
            if(scanf("%i",&buffer) != 1 || buffer < minimo || buffer > maximo)
            {
            	 printf("%s", mensajeError);
            	 fflush(stdin);
            }
            else
            {
				*pResultado = buffer;
				retorno = 0;
		    }


        }while(retorno == -1);

    return retorno;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////////////////////////////////////////

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
}
//////////////////////////////////////////////////////////////////////////////////////////////////////

int getInt(int* pResultado)
{
	int retorno = -1;
	char buffer[4000];
	scanf("%s",buffer);

	if(esNumerico(buffer))
	{
		retorno = 0;
		*pResultado = atoi(buffer);
	}

	return retorno;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

void getString(char nombre[], char* mensaje,char* mensajeError)
{
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%[^\n]s", nombre);
    while(esNumerico(nombre))
    {
    	printf("%s", mensajeError);
    	fflush(stdin);
    	scanf("%[^\n]s", nombre);
    }

}

//////////////////////////////////////////////////////////////////////////////////////////////////////

int getNumberInt(char* mensaje, char* mensajeError,int minimo, int maximo)
{
	int pResultado;

	printf("%s", mensaje);
	fflush(stdin);

	if(scanf("%d", &pResultado) != 1 || pResultado < minimo || pResultado > maximo  )
	{
		printf("%s", mensajeError);
		fflush(stdin);
		scanf("%d",&pResultado);
	}
	return pResultado;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////

float getNumberFloat(char* mensaje, char* mensajeError,int minimo, int maximo)
{

	float flotante;
	printf("%s", mensaje);
	fflush(stdin);

	if(scanf("%f", &flotante) != 1 || flotante < minimo || flotante > maximo)
	{
		printf("%s", mensajeError);
		fflush(stdin);
		scanf("%f", &flotante);
	}

	return flotante;
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
