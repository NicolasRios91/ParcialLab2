#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../inc/LinkedList.h"

typedef struct
{
    int id;
    char nombre[100];
    char apellido[100];
}ePiloto;


ePiloto* piloto_new();
ePiloto* Piloto_newParametros(char* Id,char* nombre,char* apellido);
int hardcodearPilotos(LinkedList* pArrayPilotos);


int Piloto_Get_Apellido(ePiloto* this,char* Apellido);

int Piloto_Get_Nombre(ePiloto* this,char* Nombre);

int Piloto_Get_Id(ePiloto* this,int* IdPiloto);
int Filtrar_Nombre (void*piloto,char* parametro);
