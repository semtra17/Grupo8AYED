#ifndef REGISTROVINO_H_INCLUDED
#define REGISTROVINO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "ListaDoblEnl.h"
#include "ListaSimpEnl.h"

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
void ordenarRegistrosAsc(ListaDoblEnl * lr);
void ordenarRegistrosDes(ListaDoblEnl * lr);
ListaDoblEnl * rankingVinosPerYear(ListaSimpEnl* list, int year);
void printRankingVinosPerYearDes(ListaDoblEnl* list);
void printRankingVinosPerYearAsc(ListaDoblEnl* list);
void printRegistroVino(RegistroVino *rv);
void printListaRegistrosVinos(ListaDoblEnl* list);

#endif // REGISTROVINO_H_INCLUDED
