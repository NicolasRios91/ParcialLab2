#include "piloto.h"


ePiloto* piloto_new()
{
    ePiloto* piloto;
    piloto = (ePiloto*)malloc(sizeof(ePiloto));
    return piloto;
}




int hardcodearPilotos(LinkedList* pArrayPilotos)
{

    ePiloto* miPiloto;
    int i;
    int id[10]={1,2,3,4,5,6,7,8,9,10};
    char nombre [10][100]={"Alex","Richard","John","Erwin","Stephen","Ana","Alex","Erwin","Dante","John"};
    char apellido[10][100]={"Lifeson","Bach","Kerry","Rommer","Coonts","Perez","Rodriguez","Gonzales","Fernandez","Romero"};
    for (i=0;i<10;i++)
    {
        miPiloto = piloto_new();
        miPiloto->id = id[i];
        strcpy(miPiloto->nombre,nombre[i]);
        strcpy(miPiloto->apellido,apellido[i]);
        ll_add(pArrayPilotos,miPiloto);
    }
}


int Piloto_Get_Id(ePiloto* this,int* IdPiloto)
{
    int retorno = 0;
    if (this!=NULL && IdPiloto!=NULL)
    {
        *IdPiloto = this->id;
        retorno = 1;
    }
    return retorno;
}


int Piloto_Get_Nombre(ePiloto* this,char* Nombre)
{
    int retorno=0;
    if(this!=NULL)
    {
        strcpy(Nombre,this->nombre);
        retorno=1;
    }
    return retorno;
}



int Piloto_Get_Apellido(ePiloto* this,char* Apellido)
{
    int retorno=0;
    if(this!=NULL)
    {
        strcpy(Apellido,this->apellido);
        retorno=1;
    }
    return retorno;
}


ePiloto* Piloto_newParametros(char* Id,char* nombre,char* apellido)
{
    ePiloto* miPiloto = piloto_new();
    if (miPiloto!=NULL)
    {
        miPiloto->id = atoi(Id);
        strcpy(miPiloto->nombre,nombre);
        strcpy(miPiloto->apellido,apellido);
    }
    return miPiloto;
}


int Filtrar_Nombre (void*piloto,char* parametro)
{
    ePiloto* miPiloto = (ePiloto*)piloto;
    char auxNombre[100];
    int ret =1;
    Piloto_Get_Nombre(miPiloto,auxNombre);

    if (strcmp(auxNombre,parametro) == 0)
    {
        ret = 0;
    }
    return ret;
}
