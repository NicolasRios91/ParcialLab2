#include "parser.h"
#include "piloto.h"
#include "listavuelo.h"

int parser_VueloFromText(FILE* pFile, LinkedList* pArrayListVuelo)
{
    int ret=0;
    char a[500],b[500],c[500],d[500],e[500],f[500],g[500],h[500],i[500],j[500];
    int r;
    Vuelo* miVuelo;
    fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",a,b,c,d,e,f,g,h,i,j);
        while(!feof(pFile))
        {
            if(feof(pFile))
            {
                break;
            }
            r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^/]/%[^/]/%[^,],%[^,],%[^,],%[^,],%[^\n]\n",a,b,c,d,e,f,g,h,i,j);
            if (r==10)
            {
            miVuelo = Vuelo_newParametros(a,b,c,d,e,f,g,h,i,j);
            ll_add(pArrayListVuelo,miVuelo);
            ret =1;
            }
        }
    return ret;
}


int parser_PilotoFromText(FILE* pFile, LinkedList* pArrayListPiloto)
{
    int ret=0;
    char a[500],b[500],c[100];
    int r;
    ePiloto* miPiloto;
    fscanf(pFile,"%[^,],%[^,],%[^\n]\n",a,b,c);
        while(!feof(pFile))
        {
            if(feof(pFile))
            {
                break;
            }
            r = fscanf(pFile,"%[^,],%[^,],%[^\n]\n",a,b,c);
            if (r==3)
            {
            miPiloto = Piloto_newParametros(a,b,c);
            ll_add(pArrayListPiloto,miPiloto);
            ret =1;
            }
        }
    return ret;
}



