#include "listavuelo.h"

Vuelo* new_Vuelo()
{
    Vuelo* miVuelo;
    miVuelo = (Vuelo*) malloc(sizeof(Vuelo));
    return miVuelo;
}


Vuelo* Vuelo_newParametros(char* IdVuelo,char* idAvion,char* idPiloto,char* dia,char* mes,char* anio,char* destino,char* cantPasajeros,char* horaDespegue,char* horaLlegada)
{
    Vuelo* miVuelo = new_Vuelo();
    if (miVuelo !=NULL)
    {
        miVuelo->idVuelo = atoi(IdVuelo);
        miVuelo->idAvion = atoi(idAvion);
        miVuelo->idPiloto = atoi(idPiloto);
        miVuelo->dia = atoi(dia);
        miVuelo->mes = atoi(mes);
        miVuelo->anio = atoi(anio);
        strcpy(miVuelo->destino,destino);
        miVuelo->cantPasajeros = atoi(cantPasajeros);
        miVuelo->horaDespegue = atoi(horaDespegue);
        miVuelo->horaLlegada = atoi(horaLlegada);
    }
    return miVuelo;
}



int Vuelo_getIdVuelo(Vuelo* this,int* IdVuelo)
{
    int retorno = 0;
    if (this!=NULL && IdVuelo!=NULL)
    {
        *IdVuelo = this->idVuelo;
        retorno = 1;
    }
    return retorno;
}

int Vuelo_getIdAvion(Vuelo* this,int* IdAvion)
{
    int retorno = 0;
    if (this!=NULL && IdAvion!=NULL)
    {
        *IdAvion = this->idAvion;
        retorno = 1;
    }
    return retorno;
}

int Vuelo_getIdPiloto(Vuelo* this,int* idPiloto)
{
    int retorno = 0;
    if (this!=NULL && idPiloto!=NULL)
    {
        *idPiloto = this->idPiloto;
        retorno = 1;
    }
    return retorno;
}


int Vuelo_getPasajeros(Vuelo* this,int* cantPasajeros)
{
    int retorno = 0;
    if (this!=NULL && cantPasajeros!=NULL)
    {
        *cantPasajeros = this->cantPasajeros;
        retorno = 1;
    }
    return retorno;
}

int Vuelo_gethoraDespegue(Vuelo* this,int* horaDespegue)
{
    int retorno = 0;
    if (this!=NULL && horaDespegue!=NULL)
    {
        *horaDespegue = this->horaDespegue;
        retorno = 1;
    }
    return retorno;
}


int Vuelo_gethoraLlegada(Vuelo* this,int* horaLlegada)
{
    int retorno = 0;
    if (this!=NULL && horaLlegada!=NULL)
    {
        *horaLlegada = this->horaLlegada;
        retorno = 1;
    }
    return retorno;
}

/*
int Vuelo_getFecha(Vuelo* this,char* fecha)
{
    int retorno=0;

    if(this!=NULL)
    {
        strcpy(fecha, this->fecha);
        retorno=1;
    }
    return retorno;
}
*/

int Vuelo_getdestino(Vuelo* this,char* destino)
{
    int retorno=0;

    if(this!=NULL)
    {
        strcpy(destino,this->destino);
        retorno=1;
    }
    return retorno;
}



int Pasajeros_Irlanda (void* V1)
{
    Vuelo* miVuelo;
    miVuelo = (Vuelo*)V1;
    int cont=0;
    char destino[100];
    Vuelo_getdestino(miVuelo,destino);
    if (strcmp(destino,"Irlanda")==0)
    {
        cont = miVuelo->cantPasajeros;
    }
    return cont;
}

int Cant_Pasajeros(void*V1)
{
    Vuelo* miVuelo;
    miVuelo = (Vuelo*)V1;
    return miVuelo->cantPasajeros;
}



int Filtrar_Vuelos_Cortos(void*v1)
{
    Vuelo* miVuelo;
    miVuelo = (Vuelo*)v1;
    int ret =0;
    int salida;
    int llegada;
    Vuelo_gethoraDespegue(miVuelo,&salida);
    Vuelo_gethoraLlegada(miVuelo,&llegada);
    int duracion;
    duracion = llegada - salida;
    if (duracion <3)
    {
        ret = 1;
    }
    return ret;
}

int Filtrar_Vuelos_Portugal(void*v1)
{
    Vuelo* miVuelo;
    miVuelo = (Vuelo*)v1;
    int ret =0;
    char destino[100];
    Vuelo_getdestino(miVuelo,destino);
    if (strcmp(destino,"Portugal")==0)
    {
        ret = 1;
    }
    return ret;
}

int Filtra_Alex (void*v1)
{
    Vuelo* miVuelo;
    miVuelo = (Vuelo*)v1;
    int ret =1;
    int id;
    Vuelo_getIdPiloto(miVuelo,&id);
    if (id == 1)//1 es el de alex
    {
        ret = 0;
    }
    return ret;
}
