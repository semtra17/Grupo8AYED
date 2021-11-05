#include "Menu.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include "SeleccionMensual.h"
#include "Usuario.h"
#include "Vino.h"
#include "RegistroVino.h"
#include "ItemRankingPerVarietal.h"
#include <sstream>
#include "Funciones.h"

using namespace std;

/******************************************************************************/
/* Implementacion de Primitivas */
void menu(int opcion, void * lista, void * aux){

        switch(opcion){
            case 0:
                cout << "Que tenga un buen dia, hasta luego..." << endl;
            break;
            case 1:

                while(opcion != 6){
                        cout << "\n =========MENU USUARIOS========" << endl;
                        cout << "   1 - Mostrar usuarios" << endl;
                        cout << "   2 - Buscar usuario" << endl;
                        cout << "   3 - Eliminar usuario" << endl;
                        cout << "   4 - Vaciar Lista Usuarios" << endl;
                        cout << "   5 - Cargar Lista Usuarios" << endl;
                        cout << "   6 - Volver" << endl;
                        cin >> opcion;
                        opcionesUsuario(opcion,lista);
                }
            break;
            case 2:
                  while(opcion != 6){
                    cout << "\n =========MENU VINOS========" << endl;
                    cout << "   1 - Mostrar vinos" << endl;
                    cout << "   2 - Buscar vino" << endl;
                    cout << "   3 - Eliminar vino" << endl;
                    cout << "   4 - Vaciar Lista Vinos" << endl;
                    cout << "   5 - Cargar Lista Vinos" << endl;
                    cout << "   6 - Volver" << endl;
                    cin >> opcion;
                    opcionesVino(opcion,lista);
                  }
            break;
            case 3:
                while(opcion != 6){

                    cout << "\n =========MENU SELECCION MENSUAL========" << endl;
                    cout << "   1 - Mostrar Selecciones mensuales" << endl;
                    cout << "   2 - Buscar Seleccion Mensual" << endl;
                    cout << "   3 - Eliminar Seleccion Mensual" << endl;
                    cout << "   4 - Vaciar Lista Usuarios" << endl;
                    cout << "   5 - Cargar Lista Usuarios" << endl;
                    cout << "   6 - Volver" << endl;
                    cin >> opcion;
                    opcionesSeleccionMen(opcion,lista);
                }

            break;
            case 4:
                while(opcion != 8){
                    cout << "\n =========MENU RANKING VINOS========" << endl;
                    cout << "   1 - Mostrar Lista de Registro de vinos" << endl;
                    cout << "   2 - Ordernar Ascendentemente por cantidad" << endl;
                    cout << "   3 - Ordernar Descendentemente por cantidad" << endl;
                    cout << "   4 - Mostrar Ranking Vinos del ultimo anio ascendentemente" << endl;
                    cout << "   5 - Mostrar Ranking Vinos del ultimo anio descententemente" << endl;
                    cout << "   6 - Obtener primer vino" << endl;
                    cout << "   7 - Obtener ultimo vino" << endl;
                    cout << "   8 - Volver" << endl;
                    cin >> opcion;
                    rankingVinos(opcion,(ListaDoblEnl* )lista);
                }
            break;
            case 5:
                while(opcion !=3){
                    cout << "\n =========MENU RANKING BODEGAS========" << endl;
                    cout << "   1 - Mostrar Ranking Bodegas del ultimo anio ascendentemente" << endl;
                    cout << "   2 - Mostrar Ranking Bodegas del ultimo anio descententemente" << endl;
                    cout << "   3 - Volver" << endl;
                    cin >> opcion;
                    rankingBodegas(opcion, lista, aux);
                }
            break;
             case 6:
                while(opcion !=5){
                    cout << "\n =========MENU RANKING DE VINOS POR VARIETALES========" << endl;
                    cout << "   1 - Mostrar Ranking de varietales" << endl;
                    cout << "   2 - Mostrar Ranking de varietales antiguos" << endl;
                    cout << "   3 - Mostrar Ranking de varietales medianos" << endl;
                    cout << "   4 - Mostrar Ranking de varietales jovenes" << endl;
                    cout << "   5 - Volver" << endl;
                    cin >> opcion;
                    rankingVarietal(opcion, lista, aux);
                }
            break;
            default:
                    cout << "La opcion ingresada es incorrecta, por favor intente nuevamente" << endl;
                    cin >> opcion;
                break;

        }



}



void opcionesUsuario(int opcion, void * lista){

//              1 - Mostrar
//              2 - Buscar  por id
//              3 - Eliminar
//              4 - Releer y cargar Lista
//              5 - Volver

    string dato;
    switch(opcion){
        case 6:

            break;
        case 1:
                printListaUsuario((ListaSimpEnl *) lista);
            break;
        case 2: {
                cout << "Ingrese el id del usuario (Sin espacios ni simbolos)" << endl;
                cin >> dato;
                Usuario * u = findUsuarioById((ListaSimpEnl *) lista,  dato);
                if(u != NULL){
                     printUsuario(u);
                }
                cout << "======================" << endl;
             }


            break;
        case 3:
                cout << "Ingrese el id del usuario (Sin espacios ni simbolos)" << endl;
                cin >> dato;
                removeUsuarioByIdFromList((ListaSimpEnl *) lista, dato );
                cout << "======================" << endl;
            break;

        case 4:
                 vaciarListaSimpEnl((ListaSimpEnl *) lista);
            break;
        case 5:
                cargarListaUsuarioDesdeArchivo( (ListaSimpEnl *)lista);
            break;
       default:
                cout << "La opcion ingresada es incorrecta, por favor intente nuevamente" << endl;
            break;
    }



}
void opcionesVino(int opcion, void * lista){
//              1 - Mostrar
//              2 - Buscar  por id
//              3 - Eliminar
//              4 - Releer y cargar Lista
//              5 - Volver
            string dato;
    switch(opcion){
        case 6:
            break;
        case 1:
                printListaVino((ListaSimpEnl *) lista);
            break;
        case 2: {
                cout << "Ingrese el id del Vino (Sin espacios ni simbolos)" << endl;
                cin >> dato;
                Vino * v = findVinoById((ListaSimpEnl *) lista,  dato);
                if(v != NULL){
                     printVino(v);
                }
                cout << "======================" << endl;
             }


            break;
        case 3:
                cout << "Ingrese el id del Vino que desea eliminar (Sin espacios ni simbolos)" << endl;
                cin >> dato;
                removeVinoByIdFromList((ListaSimpEnl *) lista, dato );
                cout << "======================" << endl;
            break;

        case 4:
               vaciarListaSimpEnl((ListaSimpEnl *) lista);
            break;

        case 5:
                cargarListaVinoDesdeArchivo( (ListaSimpEnl *)lista);
            break;

       default:
                cout << "La opcion ingresada es incorrecta, por favor intente nuevamente" << endl;
            break;
    }
}
void opcionesSeleccionMen(int opcion, void * lista){
    //              1 - Mostrar
    //              2 - Buscar  por id
    //              3 - Eliminar
    //              4 - Releer y cargar Lista
    //              5 - Volver
    string dato;
    switch(opcion){
        case 6:
            break;
        case 1:
                printListaSelecMen((ListaSimpEnl *) lista);
            break;
        case 2: {
                cout << "Ingrese el id de la Seleccion mensual (Sin espacios ni simbolos)" << endl;
                cin >> dato;
                SeleccionMensual * s = findSelecMenById((ListaSimpEnl *) lista,  dato);
                if(s != NULL){
                     printSelecMen(s);
                }
                cout << "======================" << endl;
             }


            break;
        case 3:
                cout << "Ingrese el id de la seleccion mensual que desea eliminar (Sin espacios ni simbolos)" << endl;
                cin >> dato;
                removeSelMenByIdFromList((ListaSimpEnl *) lista, dato );
                cout << "======================" << endl;
            break;

        case 4:
               vaciarListaSimpEnl((ListaSimpEnl *) lista);
            break;
         case 5:
            cargarListaSelDesdeArchivo( (ListaSimpEnl *)lista);
            break;

       default:
                cout << "La opcion ingresada es incorrecta, por favor intente nuevamente" << endl;
            break;
    }

}
void rankingVinos(int opcion, ListaDoblEnl *lista){
    switch(opcion){
        case 8:
            break;
        case 1:
                printListaRegistrosVinos(lista);
            break;
        case 2:
                ordenarRegistrosAsc(lista);
            break;
        case 3:
                ordenarRegistrosDes(lista);
            break;
        case 4:
                printRankingVinosPerYearAsc(lista);
            break;
        case 5:
                printRankingVinosPerYearDes(lista);
            break;
        case 6:
            printRegistroVino((RegistroVino *)lista->head->data);
            break;
        case 7:
            printRegistroVino( (RegistroVino *)lista->tail->data);
            break;




       default:
                cout << "La opcion ingresada es incorrecta, por favor intente nuevamente" << endl;
            break;
    }
}
void rankingBodegas(int opcion, void *lista, void* listaAux){
    //              1 - Mostrar
    //              2 - Buscar  por id
    //              3 - Eliminar
    //              4 - Releer y cargar Lista
    //              5 - Volver
    switch(opcion){
        case 3:
            break;
        case 1:
                printRankingBodegasPerYearAsc((ListaSimpEnl *) lista,(ListaSimpEnl *) listaAux, 2021);
            break;
        case 2:
                printRankingBodegasPerYearDes((ListaSimpEnl *) lista,(ListaSimpEnl *) listaAux,2021);
            break;



       default:
                cout << "La opcion ingresada es incorrecta, por favor intente nuevamente" << endl;
            break;
    }
}
void rankingVarietal(int opcion, void *lista, void* listaAux){

    //              1 - Mostrar
    //              2 - Buscar  por id
    //              3 - Eliminar
    //              4 - Releer y cargar Lista
    //              5 - Volver
    switch(opcion){
        case 5:
            break;
        case 1:
                rankingVinosTodasLasEdadesPerVarietal((ListaSimpEnl *) lista,(ListaSimpEnl *) listaAux);
            break;
        case 2:
                rankingVinosAntiguosPerVarietal((ListaSimpEnl *) lista,(ListaSimpEnl *) listaAux);
            break;
         case 3:
                rankingVinosMedianosPerVarietal((ListaSimpEnl *) lista,(ListaSimpEnl *) listaAux);
            break;
         case 4:
                rankingVinosJovenesPerVarietal((ListaSimpEnl *) lista,(ListaSimpEnl *) listaAux);
            break;


       default:
                cout << "La opcion ingresada es incorrecta, por favor intente nuevamente" << endl;
            break;
    }

}
