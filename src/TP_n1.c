/*
 Name        : TP_^1^
 Author      : Tomas Gonzalez 1B
 */
#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int main(void)
{
	setbuf(stdout,NULL);
    int kilometrosRecibidos;
	int precioVueloAerolineas = 0;
	int precioVueloLatam = 0;

	float precioAerolineasTarjetaDebito;
	float precioAerolineasTarjetaCredito;
	float precioAerolineasBitcoin;
	float precioAerolineasUnitario;
	float precioLatamTarjetaDebito;
	float precioLatamTarjetaCredito;
	float precioLatamBitcoin;
	float precioLatamUnitario;
	int diferenciaDePrecio;

    int opcionesGenerales;
    int opcionesAerolineas;
    int respuestaGen;
    int respuestaAero;

    do{
        respuestaGen = utn_getnumero(&opcionesGenerales,"seleccione una de las opciones \n\n 1-Ingresar kilometros \n 2-Ingresar precio vuelos \n 3-Calcular costos \n 4-Informar resultados \n 5-Carga forzada de datos \n 6-Salir \n", "no es una opcion valida \n",1,6);
        if(respuestaGen == 0)
        {
            switch(opcionesGenerales)
            {
                case 1:
                kilometrosRecibidos = RecibirKm("ingrese kilometros: ", "error,dato no valido \n");
                break;
                case 2:
                respuestaAero = utn_getnumero(&opcionesAerolineas,"seleccione aerolinea \n\n 1-Aerolineas Argentinas \n 2-Latam \n","no es una opcion valida \n" ,1, 2);
                if(respuestaAero == 0)
                {
                    switch(opcionesAerolineas)
                    {
                        case 1:
                        precioVueloAerolineas = RecibirPrecioVuelos("ingresar precio de vuelo:","error, dato no valido \n");
                        break;
                        case 2:
                        precioVueloLatam = RecibirPrecioVuelos("ingresar precio de vuelo:","error,dato no valido \n");
                        break;
                    }
                }
                break;
                case 3:
                if(precioVueloAerolineas!=0 && precioVueloLatam!=0)
                {
					precioAerolineasTarjetaDebito = CalcularTarjetaDebito(precioVueloAerolineas);
					precioAerolineasTarjetaCredito = CalcularTarjetaCredito(precioVueloAerolineas);
					precioAerolineasBitcoin = CalcularBitcoin(precioVueloAerolineas);
					precioAerolineasUnitario = CalcularPrecioUnitario(precioVueloAerolineas,kilometrosRecibidos);
					precioLatamTarjetaDebito = CalcularTarjetaDebito(precioVueloLatam);
					precioLatamTarjetaCredito = CalcularTarjetaCredito(precioVueloLatam);
					precioLatamBitcoin = CalcularBitcoin(precioVueloLatam);
					precioLatamUnitario = CalcularPrecioUnitario(precioVueloLatam,kilometrosRecibidos);
					diferenciaDePrecio = CalcularDiferenciaPreciosIngresados(precioVueloAerolineas,precioVueloLatam);
                }
                break;
                case 4:
                if(precioVueloAerolineas!=0 && precioVueloLatam!=0)
                {
					MostrarResultadoEntero("\n KMs ingresados:",kilometrosRecibidos);
					MostrarResultadoEntero("\n Precio Aerolineas: $",precioVueloAerolineas);
					MostrarResultadoFlotante("a) Precio con tarjeta de debito: $",precioAerolineasTarjetaDebito);
					MostrarResultadoFlotante("b) Precio con tarjeta de credito: $",precioAerolineasTarjetaCredito);
					MostrarResultadoFlotante("c) Precio pagando con bitcoin: $",precioAerolineasBitcoin);
					MostrarResultadoFlotante("d) Mostrar precio unitario: $",precioAerolineasUnitario);
					MostrarResultadoEntero("\nPrecio latam: $",precioVueloLatam);
					MostrarResultadoFlotante("a) Precio con tarjeta de debito: $",precioLatamTarjetaDebito);
					MostrarResultadoFlotante("b) Precio con tarjeta de credito: $",precioLatamTarjetaCredito);
					MostrarResultadoFlotante("c) Precio pagando con bitcoin: $",precioLatamBitcoin);
					MostrarResultadoFlotante("d) Mostrar precio unitario: $",precioLatamUnitario);
					MostrarResultadoEntero("\nLa diferencia de precio es: $",diferenciaDePrecio);
                }
                break;
                case 5:
                kilometrosRecibidos = 7090;
                precioVueloAerolineas = 162965;
                precioVueloLatam = 159339;
                precioAerolineasTarjetaDebito = CalcularTarjetaDebito(precioVueloAerolineas);
                precioAerolineasTarjetaCredito = CalcularTarjetaCredito(precioVueloAerolineas);
                precioAerolineasBitcoin = CalcularBitcoin(precioVueloAerolineas);
                precioAerolineasUnitario = CalcularPrecioUnitario(precioVueloAerolineas,kilometrosRecibidos);
                precioLatamTarjetaDebito = CalcularTarjetaDebito(precioVueloLatam);
	            precioLatamTarjetaCredito = CalcularTarjetaCredito(precioVueloLatam);
	            precioLatamBitcoin = CalcularBitcoin(precioVueloLatam);
	            precioLatamUnitario = CalcularPrecioUnitario(precioVueloLatam,kilometrosRecibidos);
	            diferenciaDePrecio = CalcularDiferenciaPreciosIngresados(precioVueloAerolineas,precioVueloLatam);
	            MostrarResultadoEntero("\n KMs ingresados:",kilometrosRecibidos);
	            MostrarResultadoEntero("\nPrecio Aerolineas: $",precioVueloAerolineas);
	            MostrarResultadoFlotante("a) Precio con tarjeta de debito: $",precioAerolineasTarjetaDebito);
	            MostrarResultadoFlotante("b) Precio con tarjeta de credito: $",precioAerolineasTarjetaCredito);
	            MostrarResultadoFlotante("c) Precio pagando con bitcoin: $",precioAerolineasBitcoin);
	            MostrarResultadoFlotante("d) Mostrar precio unitario: $",precioAerolineasUnitario);
	            MostrarResultadoEntero("\nPrecio latam: $",precioVueloLatam);
	            MostrarResultadoFlotante("a) Precio con tarjeta de debito: $",precioLatamTarjetaDebito);
	            MostrarResultadoFlotante("b) Precio con tarjeta de credito: $",precioLatamTarjetaCredito);
	            MostrarResultadoFlotante("c) Precio pagando con bitcoin: $",precioLatamBitcoin);
	            MostrarResultadoFlotante("d) Mostrar precio unitario: $",precioLatamUnitario);
	            MostrarResultadoEntero("\nLa diferencia de precio es: $",diferenciaDePrecio);
                break;
            }
        }
    }while(opcionesGenerales!=6);

    return 0;
}
