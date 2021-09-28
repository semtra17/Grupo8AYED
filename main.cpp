#include <iostream>
#include <fstream>
#include<stdlib.h>
#include<string>
#include "Lista.h"
#include "ListaUsuario.h"
#include <sstream>
#include "Funciones.h"

using namespace std;



int main()
{

    ListaUsuario* LISTA_USUARIOS = nuevaListaUsuario();
    cargarListaUsuarioDesdeArchivo(LISTA_USUARIOS);
    printListaUsuario(LISTA_USUARIOS);

//    string palabra;
//    string jejox = "	San Martin 549, La Puerta, Catamarca            ";
//    jejox = eliminarEspaciosDelComienzoYFinal(jejox);









}

