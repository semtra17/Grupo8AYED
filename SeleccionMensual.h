#ifndef SELECCIONMENSUAL_H_INCLUDED
#define SELECCIONMENSUAL_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

struct SeleccionMensual{
    std::string idSelecMen;
    std::string mes;
    int anio;
    std::string idsVinos[6];
};


SeleccionMensual * crearSeleccionMensual(string idSelecMen, string mes, int anio, string idsVinos[6]);
SeleccionMensual * crearSeleccionMensual( string mes, int anio, string idsVinos[6]);


string getIdSelecMen(SeleccionMensual * s);
int getAnioSelecMen(SeleccionMensual *s);
string getMesSelecMen(SeleccionMensual *s);
string *getIdsVinos(SeleccionMensual *s);

void setIdSelecMen(SeleccionMensual *s,string idSelecMen);
void setMesSelecMen(SeleccionMensual *s, string mes);
void setAnioSelecMen(SeleccionMensual *s,int anio);
void setIdsVinos(SeleccionMensual *s,string idsVinos[6]);
void printSelecMen(SeleccionMensual *s);
void printIdsVinos(string idsVinos[6]);


#endif // SELECCIONMENSUAL_H_INCLUDED
