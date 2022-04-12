/*
 * biblioteca.c
 * Author: Tomas Gonzalez
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "biblioteca.h"

int utn_getnumero(int* pResultado,char* mensaje, char* mensajeError,int minimo, int maximo)
{
    int retorno = -1;
    int buffer;

        do{
            printf("%s", mensaje);
            scanf("%d",&buffer);

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

///////////////////////////////////////////////////////////////////////////////

int RecibirKm(char* mensaje,char* mensajeError)
{
	int ingresoKilometros;

			printf("%s",mensaje);
			scanf("%d",&ingresoKilometros);
		    while(ingresoKilometros<0)
			{
		    	printf("%s", mensajeError);
		    	printf("%s",mensaje);
		    	scanf("%d",&ingresoKilometros);
			}

	    return ingresoKilometros;
}

///////////////////////////////////////////////////////////////////////////////

int RecibirPrecioVuelos(char* mensaje,char* mensajeError)
{
	int ingresoPrecioVuelos;

    	printf("%s",mensaje);
    	scanf("%d",&ingresoPrecioVuelos);
    	while(ingresoPrecioVuelos<0)
    	{
    		printf("%s", mensajeError);
    		printf("%s",mensaje);
    		scanf("%d",&ingresoPrecioVuelos);
    	}

		return ingresoPrecioVuelos;
}

///////////////////////////////////////////////////////////////////////////////

float CalcularTarjetaDebito(int precioVuelo)
{
    int porcentajeDescuento = 10;
    float descuento;
    float precioDescuentoFinal;

    descuento = precioVuelo * ((float)porcentajeDescuento/100);
    precioDescuentoFinal = precioVuelo - descuento;

    return precioDescuentoFinal;
}

///////////////////////////////////////////////////////////////////////////////

float CalcularTarjetaCredito(int precioVuelo)
{
    int porcentajeInteres = 25;
    float aumento;
    float precioAumentoFinal;

    aumento = precioVuelo * ((float)porcentajeInteres/100);
    precioAumentoFinal = precioVuelo + aumento;

    return precioAumentoFinal;
}

///////////////////////////////////////////////////////////////////////////////

float CalcularBitcoin(int precioVuelo)
{
    float unBtc = 4606954.55;
    float precioFinalBtc;
    float paseBtc;

    paseBtc = ((float)(1/unBtc));
    precioFinalBtc = precioVuelo*paseBtc;

    return precioFinalBtc;
}

///////////////////////////////////////////////////////////////////////////////

float CalcularPrecioUnitario(int precioVuelo, int cantidadKm)
{
    float precioUnitarioKm;

    precioUnitarioKm = ((float)precioVuelo / cantidadKm);

    return precioUnitarioKm;
}

///////////////////////////////////////////////////////////////////////////////

float CalcularDiferenciaPreciosIngresados(int precioVuelo, int precioVueloDos)
{
    int diferenciaDePrecio;

    if(precioVuelo > precioVueloDos)
    {
    	diferenciaDePrecio = precioVuelo - precioVueloDos;
    }
    else
    {
    	diferenciaDePrecio = precioVueloDos - precioVuelo;
    }

    return diferenciaDePrecio;
}

///////////////////////////////////////////////////////////////////////////////

void MostrarResultadoEntero(char* mensaje, int resultado)
{
    printf("%s %d \n",mensaje,resultado);
}

///////////////////////////////////////////////////////////////////////////////

void MostrarResultadoFlotante(char* mensaje,float resultado)
{
    printf("%s %f \n",mensaje,resultado);
}

///////////////////////////////////////////////////////////////////////////////
