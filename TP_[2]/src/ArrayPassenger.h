/*
 * passenger.h
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#define LIBRE 0
#define OCUPADO 1

//ESTRUCTURA Y FUNCIONES PEDIDAS

/// @brief estructura de pasajeros solicitada
struct Passenger
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
};

///-----------------------------------------------------------------------------------------///

/// @brief funcion para inicializar el array de pasajeros en libre
/// @param listPassenger: array de la lista de pasajeros
/// @param len: tamaño del array
/// @return retorna -1 en caso de error y 0 si es exitoso
int initPassengers(struct Passenger listPassenger[],int len);

///-----------------------------------------------------------------------------------------///

/// @brief funcion para cargar array de a un pasajero
/// @param listPassenger: array de la lista de pasajeros
/// @param len: tamaño del array
/// @return retorna -1 en caso de error y 0 si es exitoso
int addPassenger(struct Passenger listPassenger[],int len);

///-----------------------------------------------------------------------------------------///

/// @brief funcion para comparar el id que se busca con un id existente
/// @param listPassenger: array de la lista de pasajeros
/// @param len: tamaño del array
/// @param id: id que se esta buscando
/// @return retorna -1 en caso de error y si encuentra el id lo retorna
int findPassengerById(struct Passenger listPassenger[],int len,int id);

///-----------------------------------------------------------------------------------------///

/// @brief funcion para eliminar un pasajero a traves del id
/// @param listPassenger: array de la lista de pasajeros
/// @param len: tamaño del array
/// @param id: id que se esta buscando
/// @return retorna -1 en caso de error y 0 si es exitoso
int removePassenger(struct Passenger listPassenger[],int len,int id);

///-----------------------------------------------------------------------------------------///

/// @brief funcion para ordenar a los pasajeros por apellido
/// @param listPassenger: array de la lista de pasajeros
/// @param len: tamaño del array
/// @param order: 1 en caso de orden up y 0 en caso de orden down
/// @return retorna -1 en caso de error y 0 si es exitoso
int sortPassengersByName(struct Passenger listPassenger[], int len,int order);

///-----------------------------------------------------------------------------------------///

/// @brief funcion para imprimir por consola la lista de pasajeros
/// @param listPassenger: array de la lista de pasajeros
/// @param len: tamaño del array
/// @return  retorna -1 en caso de error y 0 si es exitoso
int printPassengers(struct Passenger listPassenger[],int len);

///-----------------------------------------------------------------------------------------///

/// @brief funcion para ordenar a los pasajeros por codigo de vuelo
/// @param listPassenger: array de la lista de pasajeros
/// @param len: tamaño del array
/// @param order: 1 en caso de orden up y 0 en caso de orden down
/// @return retorna -1 en caso de error y 0 si es exitoso
int sortPassengerByFlyCode(struct Passenger listPassenger[],int len,int order);

///-----------------------------------------------------------------------------------------///

//FUNCIONES AGREGADAS

/// @brief funcion para realizar la carga de un pasajero
/// @return retorna un pasajero
struct Passenger Passenger_cargarUno();

///-----------------------------------------------------------------------------------------///

/// @brief funcion para ordenar el array por tipo de pasajero
/// @param listPassenger: array de la lista de pasajeros
/// @param len: tamaño del array
/// @param order: 1 en caso de orden up y 0 en caso de orden down
/// @return  retorna -1 en caso de error y 0 si es exitoso
int sortPassengersByTypePassenger( struct Passenger listPassenger[],int len,int order);

///-----------------------------------------------------------------------------------------///

/// @brief funcion para ordenar el array por el codigo de vuelo
/// @param listPassenger: array de la lista de pasajeros
/// @param len: tamaño del array
/// @return retorna -1 en caso de error y 0 si es exitoso
int sortPassengerByStatusFlight(struct Passenger listPassenger[],int len);

///-----------------------------------------------------------------------------------------///

/// @brief funcion para buscar el primer esoacio libre del array
/// @param listPassenger: array de la lista de pasajeros
/// @param len: tamaño del array
/// @return retorna -1 en caso de error o el lugar primer lugar del array libre
int passenger_findEmptySpace(struct Passenger listPassenger[],int len);

///-----------------------------------------------------------------------------------------///

/// @brief funcion para evitar que se pueda ingresar a las opciones sin antes haber ingresado al menos un pasajero
/// @param listPassenger: array de la lista de pasajeros
/// @param len: tamaño del array
/// @return retorna -1 en caso de error o el lugar primer lugar del array ocupado
int passenger_findOcSpace(struct Passenger listPassenger[],int len);

///-----------------------------------------------------------------------------------------///

/// @brief funcion para modificar cualquier campo de la estructura que el usuario desee a traves del id
/// @param listPassenger: array de la lista de pasajeros
/// @param len: tamaño del array
/// @param id: id que se esta buscando
/// @return retorna -1 en caso de error y 0 si es exitoso
int modificarPasajero(struct Passenger listPassenger[],int len,int id);

///-----------------------------------------------------------------------------------------///

/// @brief funcion para implementar la carga forzada de datos en el array
/// @param listPassenger: array de la lista de pasajeros
void cargaForzadaDatos(struct Passenger listPassenger[]);

///-----------------------------------------------------------------------------------------///

/// @brief funcion para mostrar un solo pasajero
/// @param aPassenger: variable de un solo pasajero
void informarPasajero(struct Passenger aPassenger);

///-----------------------------------------------------------------------------------------///

/// @brief funcion para mostrar el total de los precios, el promedio de los mismos y la cantidad
/// de pasajeros que superan el promedio
/// @param listPassenger: array de la lista de pasajeros
/// @param len: tamaño del array
void printTotalPromedioPrecios(struct Passenger listPassenger[],int len);

///-----------------------------------------------------------------------------------------///

/// @brief funcion para mostrar el informe completo con las modificaciones asignadas
/// @param listPassenger: array de la lista de pasajeros
/// @param len: tamaño del array
/// @return retorna -1 en caso de error y 0 si es exitoso
int informeDatos(struct Passenger listPassenger[],int len);

///-----------------------------------------------------------------------------------------///

#endif /* ARRAYPASSENGER_H_ */
