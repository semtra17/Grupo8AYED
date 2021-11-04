#include <iostream>
#include <fstream>
#include<stdlib.h>
#include <string.h>
#include "Lista.h"
#include <sstream>
#include "Funciones.h"
#include "ListaSimpEnl.h"
#include "Vino.h"
#include "Usuario.h"
#include "SeleccionMensual.h"

using namespace std;



int main()
{

//    ListaUsuario* LISTA_USUARIOS = nuevaListaUsuario();
//    cargarListaUsuarioDesdeArchivo(LISTA_USUARIOS);
//    printListaUsuario(LISTA_USUARIOS);

//    ListaVinos * LISTA_VINOS = nuevaListaVinos();
//    cargarListaVinosDesdeArchivo(LISTA_VINOS);
//    printListaVinos(LISTA_VINOS);

//
//    ListaSelecciones *LISTA_SELECCION_MENSUAL = nuevaListaSelecciones();
//    cargarListaSeleccionesDesdeArchivo(LISTA_SELECCION_MENSUAL);
//    printListaSelecciones(LISTA_SELECCION_MENSUAL);
//
//    void * puntero1 = crearUsuario("12345","Luciano Assefh", 23, "Jejox y Jejax");
//    void * puntero2 = crearUsuario("12345","Luciano Assefh", 23, "Jejox y Jejax");
//    cout << (((Usuario *) puntero1)->id_usuario == ((Usuario *) puntero2)->id_usuario) << endl;
//    Usuario * u = crearUsuario("12345","Luciano Assefh", 23, "Jejox y Jejax");
//    Usuario * u1 = crearUsuario("12345","Luciano Assefh", 23, "Jejox y Jejax");
//    cout << (u == u1) << endl;
//        ListaSimpEnl * LISTA_USUARIOS = newListSimpEnl();
//        cargarListaUsuarioDesdeArchivo(LISTA_USUARIOS);
//        printListaUsuario(LISTA_USUARIOS);
//        printUsuario(findUsuarioById(LISTA_USUARIOS, "55178"));
//        ListaSimpEnl * LISTA_VINOS = newListSimpEnl();
//        cargarListaVinoDesdeArchivo(LISTA_VINOS);
//        printListaVino( LISTA_VINOS);
//        Vino *v = (Vino *) LISTA_VINOS->head->data;
//        cout << v->idVino.length() << endl;
//        removeVinoByIdFromList(LISTA_VINOS,"81633");
//        printVino(findVinoById(LISTA_VINOS, "81633"));
//        printListaVino( LISTA_VINOS);

        ListaSimpEnl * LISTA_SELECCION_MENSUAL = newListSimpEnl();
        cargarListaSelDesdeArchivo(LISTA_SELECCION_MENSUAL);
        printListaSelecMen(LISTA_SELECCION_MENSUAL);











}

