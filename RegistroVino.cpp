#include "RegistroVino.h"

#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <sstream>



RegistroVino * crearRegistroVino(string idVino, int cantidadSeleccionado){
    RegistroVino *rv = new RegistroVino();
    rv->idRegistroVino=idVino;
    rv->cantidadSeleccionado = cantidadSeleccionado;
    return rv;
}
string getIdRegistroVino(RegistroVino* rv){
    return rv->idRegistroVino;
}
int getCantidadRegistroVino(RegistroVino* rv){
    return rv->cantidadSeleccionado;
}
void setIdRegistroVino(RegistroVino *rv, string idRegistroVino){
    rv->idRegistroVino = idRegistroVino;
}
void setIdRegistroVino(RegistroVino *rv, int cantidadSeleccionado){
    rv->cantidadSeleccionado = cantidadSeleccionado;
}
void eliminarRegistroVino(RegistroVino *rv){
    delete(rv);

}



void printRegistroVino(RegistroVino *rv){
    cout << "======================================" << endl;
    cout <<  "idVino: " << getIdRegistroVino(rv) << endl;
    cout << "Cantidad: " << getCantidadRegistroVino(rv) << endl;
}
