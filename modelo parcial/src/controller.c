#include "controller.h"




int controller_loadFromText(char* path, LinkedList* pArrayListVuelos)
{
    int ret=0;
    FILE* archivo;
    ll_clear(pArrayListVuelos);
    archivo = fopen(path,"r");
    if (pArrayListVuelos!=NULL && archivo!=NULL)
    {
        parser_VueloFromText(archivo,pArrayListVuelos);
        ret=1;
    }
    fclose(archivo);
return ret;
}

int controller_parser_PilotoFromText(char* path, LinkedList* pArrayPilotos)
{
    int ret=0;
    FILE* archivo;
    ll_clear(pArrayPilotos);
    archivo = fopen(path,"r");
    if (pArrayPilotos!=NULL && archivo!=NULL)
    {
        parser_PilotoFromText(archivo,pArrayPilotos);
        ret=1;
    }
    fclose(archivo);
return ret;
}





int controller_ListVuelos(LinkedList* pArrayListVuelos,LinkedList* pArrayListPilotos)//vuelo,avion,piloto,fecha,destino,pasajeros,despegue,llegada
{
    int vuelo,avion,piloto,pasajeros,salida,llegada;
    int dia;
    int mes;
    int anio;
    char destino[100];
    int i;
    int j;
    int control;
    int ret=0;
    int r;
    Vuelo* auxVuelo;

    ePiloto* auxPiloto;
    char auxNombre[100];
    char auxApellido[100];
    char NombreCompleto[100];
    int len;

    control = ll_isEmpty(pArrayListVuelos);
    if(control ==0)
    {
        len = ll_len(pArrayListVuelos);
        printf("ID VUELO    ID AVION        PILOTO          FECHA        DESTINO    PASAJEROS    SALIDA     LLEGADA\n\n");
        for (i=0;i<len;i++)
        {
            auxVuelo = ll_get(pArrayListVuelos,i);

            Vuelo_getIdVuelo(auxVuelo,&vuelo);
            Vuelo_getIdAvion(auxVuelo,&avion);
            Vuelo_getIdPiloto(auxVuelo,&piloto);
            Vuelo_getPasajeros(auxVuelo,&pasajeros);
            Vuelo_gethoraDespegue(auxVuelo,&salida);
            Vuelo_gethoraLlegada(auxVuelo,&llegada);
            dia = auxVuelo->dia;
            mes = auxVuelo->mes;
            anio = auxVuelo->anio;
            Vuelo_getdestino(auxVuelo,destino);
            for (j=0;j<ll_len(pArrayListPilotos);j++)
            {
                auxPiloto = piloto_new();
                auxPiloto = ll_get(pArrayListPilotos,j);

               if (piloto == auxPiloto->id)
              {
                    Piloto_Get_Nombre(auxPiloto,auxNombre);
                    Piloto_Get_Apellido(auxPiloto,auxApellido);
                    strcpy(NombreCompleto,auxNombre);
                    strcat(NombreCompleto," ");
                    strcat(NombreCompleto,auxApellido);
                    printf("%5d %10d %20s %5d/%d/%d %13s %8d %10d %10d\n",vuelo,avion,NombreCompleto,dia,mes,anio,destino,pasajeros,salida,llegada);
                    break;
              }

           }
            ret =1;
        }
    }
    return ret;
}


int Controller_ListPilotos(LinkedList* this)
{
    int ret = 0;
    ePiloto* auxPiloto;
    char auxNombre[100];
    char auxApellido[100];
    int id;
    int control;
    int i;
    control = ll_isEmpty(this);
    if(control ==0)
    {

        printf("ID Piloto ||  NOMBRE || APELLIDO\n\n");
        for (i=0;i<ll_len(this);i++)
        {
            auxPiloto = ll_get(this,i);

            Piloto_Get_Id(auxPiloto,&id);
            Piloto_Get_Nombre(auxPiloto,auxNombre);
            Piloto_Get_Apellido(auxPiloto,auxApellido);
            printf(" %d %18s %10s\n",id,auxNombre,auxApellido);
            ret = 1;
        }

    }

    return ret;
}

int controller_savePilotos(char* path, LinkedList* pArrayListPiloto)
{
    ePiloto* aux = piloto_new();
    int ret =0;
    int i;
    int id;
    char nombre[100];
    char apellido[100];
    FILE* archivo;
    archivo = fopen(path,"w");

    if (archivo!=NULL && pArrayListPiloto !=NULL)
    {
        fprintf(archivo, "id,NOMBRE,APELLIDO\n");
        for (i=0;i<ll_len(pArrayListPiloto);i++)
        {
        aux = ll_get(pArrayListPiloto,i);
        Piloto_Get_Id(aux,&id);
        Piloto_Get_Nombre(aux,nombre);
        Piloto_Get_Apellido(aux,&apellido);
        fprintf(archivo,"%d,%s,%s\n",id,nombre,apellido);
        }
        ret =1;
    }
    fclose(archivo);

return ret;
}


