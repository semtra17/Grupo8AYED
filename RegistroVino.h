#ifndef REGISTROVINO_H_INCLUDED
#define REGISTROVINO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "ListaDoblEnl.h"

using namespace std;
struct RegistroVino{

    string idRegistroVino;
    int cantidadSeleccionado;
};

RegistroVino * crearRegistroVino(string idVino, int cantidadSeleccionado);
string getIdRegistroVino(RegistroVino* rv);
int getCantidadRegistroVino(RegistroVino* rv);
void setIdRegistroVino(RegistroVino *rv, string idRegistroVino);
void setIdRegistroVino(RegistroVino *rv, int cantidadSeleccionado);
void eliminarRegistroVino(RegistroVino *rv);
void printRegistroVino(RegistroVino *rv);
void ordenarRegistrosAsc(ListaDoblEnl * lr);
void ordenarRegistrosDes(ListaDoblEnl * lr);



#endif // REGISTROVINO_H_INCLUDED
