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

struct RegistroBodega {
    string bodega;
};

RegistroVino * crearRegistroVino(string idVino, int cantidadSeleccionado);
string getIdRegistroVino(RegistroVino* rv);
int getCantidadRegistroVino(RegistroVino* rv);
void setIdRegistroVino(RegistroVino *rv, string idRegistroVino);
void setIdRegistroVino(RegistroVino *rv, int cantidadSeleccionado);
void eliminarRegistroVino(RegistroVino *rv);
void ordenarRegistrosAsc(ListaDoblEnl * lr);
void ordenarRegistrosDes(ListaDoblEnl * lr);
ListaDoblEnl * rankingVinosPerYear(ListaSimpEnl* listaVinos, int year);
void printRankingVinosPerYearDes(ListaDoblEnl* listaRegistros);
void printRankingVinosPerYearAsc(ListaDoblEnl* listaRegistros);
void printRegistroVino(RegistroVino *rv);
void printListaRegistrosVinos(ListaDoblEnl* listaRegistros);
void printNodoRegistroVino(NodoDobl *rv);
void printRankingBodegasPerYearAsc(ListaSimpEnl* listaSelecciones, ListaSimpEnl * listVinos, int year);
void printRankingBodegasPerYearDes(ListaSimpEnl* listaSelecciones, ListaSimpEnl * listVinos, int year);
void printListaBodegaAsc(ListaDoblEnl* list);
void printListaBodegaDes(ListaDoblEnl* list);

#endif // REGISTROVINO_H_INCLUDED
