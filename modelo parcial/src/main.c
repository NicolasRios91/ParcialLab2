/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Controller.h"

/* PRMIERO LAS ESTRUCTURAS, VER EL ARCHIVO
    HACER EL PARSER Y LOS GETERS PARA EL NEW_PÀRAMETROS
    IMPRIMIR LA LISTA, RELACIONAR SI LO PIDE
    */

    //filtrado por nombre
int main(void)
{
    int control;
    int control2;
    char* nombre[100];
    LinkedList* miLista;
    LinkedList* Copia;
    LinkedList* Pilotos;
    miLista = ll_newLinkedList();
    Pilotos = ll_newLinkedList();
    //hardcodearPilotos(Pilotos);
    //controller_savePilotos("Pilotos.csv",Pilotos);
    int opcion;

    do
    {
        system("cls");
        printf("   Menu:\n");
        printf("1. Cargar Vuelos y pilotos\n");
        printf("2. Mostrar Vuelos\n");
        printf("3. Mostrar Cantidad de pasajeros\n");
        printf("4. Mostrar Cantidad de pasajeros a Irlanda\n");
        printf("5. Filtrar vuelos cortos\n");
        printf("6. Mostrar vuelos a Portugal\n");
        printf("7. Filtrar vuelos de Alex Lifeson\n");
        printf("8. Filtrar por nombre\n");
        printf("9. Salir\n\n");
        printf("Elija una opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            control = controller_loadFromText("Vuelos.csv",miLista);
            control2 = controller_parser_PilotoFromText("Pilotos.csv",Pilotos);
            if (control ==1 && control2 ==1)
            {
                printf("Se cargo la lista\n");
            }
            else
            {
                printf("No se cargo la lista\n");
            }
            getch();
            break;
        case 2:
            control = controller_ListVuelos(miLista,Pilotos);
            if (control !=1)
            {
                printf("No se cargo la lista o esta vacia\n");
            }
            getch();
            break;
        case 3:
            control = ll_count(miLista,Cant_Pasajeros);
            printf("Cantidad de pasajeros: %d\n",control);
            getch();
            break;
        case 4:
            control = ll_count(miLista,Pasajeros_Irlanda);
            printf("Pasajeros a Irlanda: %d\n",control);
            getch();
            break;
        case 5:
            Copia = ll_filter(miLista,Filtrar_Vuelos_Cortos);
            if (Copia!=NULL && ll_len(Copia)>0)
            {
                 controller_ListVuelos(Copia,Pilotos);
            }
            else
            {
                printf("No hay vuelos cortos\n");
            }
            printf("\nPresione una tecla para continuar...");
            getch();
            break;
        case 6:
            Copia = ll_filter(miLista,Filtrar_Vuelos_Portugal);
            if (Copia!=NULL && ll_len(Copia)>0)
            {
                 controller_ListVuelos(Copia,Pilotos);
            }
            printf("\nPresione una tecla para continuar...");
            getch();
            break;
        case 7:
            Copia = ll_filter(miLista,Filtra_Alex);
            if (Copia!=NULL && ll_len(Copia)>0)
            {
                controller_ListVuelos(Copia,Pilotos);
            }

            printf("\nPresione una tecla para continuar...");
            getch();
            break;
        case 8:
            printf("Ingrese el nombre del piloto que quiere filtrar: ");
            fflush(stdin);
            fgets(nombre,100,stdin);
            nombre[strlen(nombre)-1]='\0';
            Copia = ll_filter_parametro(Pilotos,Filtrar_Nombre,nombre);
            Controller_ListPilotos(Copia);
            getch();
            break;
        }
    }while(opcion !=9);

    return 0;
}

































