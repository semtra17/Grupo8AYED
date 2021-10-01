#include "SeleccionMensual.h"
#include <iostream>

using namespace std;
//------------------------------------------------------------
//CONSTUCTOR

SeleccionMensual * crearSeleccionMensual(string idSelecMen, string mes, int anio, string idsVinos[6]){
    SeleccionMensual *sm = new SeleccionMensual();
    setIdSelecMen(sm,idSelecMen);
    setAnioSelecMen(sm,anio);
    setMesSelecMen(sm,mes);
    setIdsVinos(sm,idsVinos);

    return sm;
}
//SOBRECARGA DE METODOS
//------------------------------------------------------------
//CONSTUCTOR


SeleccionMensual * crearSeleccionMensual( string mes, int anio, string idsVinos[6]){

    SeleccionMensual *sm = new SeleccionMensual();
    setAnioSelecMen(sm,anio);
    setMesSelecMen(sm,mes);
    setIdsVinos(sm,idsVinos);

    return sm;
}
//------------------------------------------------------------
//GETS

string getIdSelecMen(SeleccionMensual * s){
    return s->idSelecMen;

}
int getAnioSelecMen(SeleccionMensual *s){
    return s->anio;
}
string getMesSelecMen(SeleccionMensual *s){
    return s->mes;

}
string * getIdsVinos(SeleccionMensual *s){
    return s->idsVinos;
}
//------------------------------------------------------------
//SETS

void setIdSelecMen(SeleccionMensual *s,string idSelecMen){

    s->idSelecMen = idSelecMen;
}
void setMesSelecMen(SeleccionMensual *s, string mes){
    s->mes = mes;
}
void setAnioSelecMen(SeleccionMensual *s,int anio){
    s->anio =anio;
}
void setIdsVinos(SeleccionMensual *s,string idsVinos[6]){
    for(int i = 0; i<6;i++){
        s->idsVinos[i] = idsVinos[i];
    }

}
//------------------------------------------------------------
//UTILIDADES

void printIdsVinos(string idsVinos[6]){
    cout << "Id de vinos de la seleccion mensual" << endl;
    for(int  i = 0; i< 6; i++){
        cout << idsVinos[i]  << "   ";
    }
    cout << endl;
}

void printSelecMen(SeleccionMensual *s){
    cout << "======================================" << endl;
    cout <<  "IdSeleccion: " << s->idSelecMen << endl;
    cout << "Mes: " << s->mes << "     Anio: " << s->anio << endl;
    printIdsVinos(s->idsVinos);
}



