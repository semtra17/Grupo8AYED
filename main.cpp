#include <iostream>
#include <fstream>
#include<stdlib.h>
#include <string.h>
#include <sstream>
#include "Funciones.h"
#include "ListaSimpEnl.h"
#include "ListaDoblEnl.h"
#include "Vino.h"
#include "Usuario.h"
#include "RegistroVino.h"
#include "SeleccionMensual.h"
#include "ItemRankingPerVarietal.h"
#include "Menu.h"

using namespace std;



int main()
{


        ListaSimpEnl* LISTA_USUARIOS = newListSimpEnl();
        cargarListaUsuarioDesdeArchivo(LISTA_USUARIOS);
        ListaSimpEnl * LISTA_VINOS = newListSimpEnl();
        cargarListaVinoDesdeArchivo(LISTA_VINOS);
        ListaSimpEnl *LISTA_SELECCION_MENSUAL = newListSimpEnl();
        cargarListaSelDesdeArchivo(LISTA_SELECCION_MENSUAL);
        ListaDoblEnl * LISTA_REGISTRO = rankingVinosPerYear(LISTA_SELECCION_MENSUAL,2021);


   int opcion = -1;
        void *lista ;
        cout << "Bienvenido seleccione la opcion que desea ejecutar" << endl;
        cout << "Informacion obtenida desde Base de Datos." << endl;

        while( opcion!= 0){
            cout << "\n =========MENU PRINCIPAL========" << endl;
            cout << "1 - Opciones de usuario" << endl;
            cout << "2 - Opciones de Vino" << endl;
            cout << "3 - Opciones de Seleccion Mensual" << endl;
            cout << "4 - Ranking Vinos" << endl;
            cout << "5 - Ranking Bodegas" << endl;
            cout << "6 - Ranking Varietales" << endl;
            cout << "0 - Salir del sistema" << endl;
            cin >> opcion;
            switch(opcion){
                case 1:
                        menu(opcion,LISTA_USUARIOS,0);
                    break;
                case 2:
                        menu(opcion,LISTA_VINOS,0);
                    break;
                case 3:
                        menu(opcion,LISTA_SELECCION_MENSUAL, 0);
                    break;
                case 4:
                        menu(opcion,LISTA_REGISTRO,0);
                    break;
                case 5:
                    menu(opcion,LISTA_SELECCION_MENSUAL,LISTA_VINOS);
                break;
                case 6:
                    menu(opcion,LISTA_SELECCION_MENSUAL,LISTA_VINOS);
                break;
                }
        }









}

