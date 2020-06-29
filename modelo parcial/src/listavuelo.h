#include <stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    int idVuelo;
    int idAvion;
    int idPiloto;
    int dia;
    int mes;
    int anio;
    char* destino[100];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
}Vuelo;

Vuelo* new_Vuelo();
int Vuelo_getdestino(Vuelo* this,char* destino);
int Vuelo_getFecha(Vuelo* this,char* fecha);
int Vuelo_gethoraLlegada(Vuelo* this,int* horaLlegada);
int Vuelo_gethoraDespegue(Vuelo* this,int* horaDespegue);
int Vuelo_getPasajeros(Vuelo* this,int* cantPasajeros);
int Vuelo_getIdPiloto(Vuelo* this,int* idPiloto);
int Vuelo_getIdAvion(Vuelo* this,int* IdAvion);
int Vuelo_getIdVuelo(Vuelo* this,int* IdVuelo);

Vuelo* Vuelo_newParametros(char* IdVuelo,char* idAvion,char* idPiloto,char* dia,char* mes,char* anio,char* destino,char* cantPasajeros,char* horaDespegue,char* horaLlegada);

int Pasajeros_Irlanda (void* V1);
int Cant_Pasajeros(void* V1);
int Filtrar_Vuelos_Cortos(void* v1);
int Filtrar_Vuelos_Portugal(void*v1);
int Filtra_Alex (void*v1);
