#include <iostream>
#include <fstream>
#include<stdlib.h>
#include <string.h>
#include "Lista.h"
#include "ListaUsuario.h"
#include "ListaVinos.h"
#include <sstream>
#include "Funciones.h"

using namespace std;



int main()
{

    ListaUsuario* LISTA_USUARIOS = nuevaListaUsuario();
    cargarListaUsuarioDesdeArchivo(LISTA_USUARIOS);
    printListaUsuario(LISTA_USUARIOS);

    ListaVinos * LISTA_VINOS = nuevaListaVinos();
    cargarListaVinosDesdeArchivo(LISTA_VINOS);
    printListaVinos(LISTA_VINOS);
















}

