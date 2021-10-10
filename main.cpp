#include <iostream>
#include <fstream>
#include<stdlib.h>
#include <string.h>
#include "Lista.h"
#include "ListaUsuario.h"
#include "ListaVinos.h"
#include "ListaSelecciones.h"
#include "SeleccionMensual.h"
#include <sstream>
#include "Funciones.h"

using namespace std;



int main()
{

//    ListaUsuario* LISTA_USUARIOS = nuevaListaUsuario();
//    cargarListaUsuarioDesdeArchivo(LISTA_USUARIOS);
//    printListaUsuario(LISTA_USUARIOS);

//    ListaVinos * LISTA_VINOS = nuevaListaVinos();
//    cargarListaVinosDesdeArchivo(LISTA_VINOS);
//    printListaVinos(LISTA_VINOS);


    ListaSelecciones *LISTA_SELECCION_MENSUAL = nuevaListaSelecciones();
    cargarListaSeleccionesDesdeArchivo(LISTA_SELECCION_MENSUAL);
    printListaSelecciones(LISTA_SELECCION_MENSUAL);

















}

