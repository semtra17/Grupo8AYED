#include "RegistroVino.h"
#include "ListaDoblEnl.h"
#include "ListaSimpEnl.h"
#include "SeleccionMensual.h"
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


NodoDobl* buscarRegistroVinoPorId(ListaDoblEnl* list, string idVino){


    NodoDobl* n = list->head;
    NodoDobl* temp = NULL;
    while (n != NULL) {
        if(getIdRegistroVino((RegistroVino *)n->data) == idVino){
            return n;
        }
        n = n->nextNode;
      }
        return temp;
}

void contarVino(ListaDoblEnl* list, string idVino){
  NodoDobl* nodoRegistroVino = buscarRegistroVinoPorId(list, idVino);
  if(nodoRegistroVino != NULL){
    ((RegistroVino *)nodoRegistroVino->data)->cantidadSeleccionado++;
  }else{
    RegistroVino * rv = crearRegistroVino(idVino, 1);
    addDataToListDoblEnl(list, rv);
  }
}


void ordenarRegistrosAsc(ListaDoblEnl * lr){
    NodoDobl * nr = lr->head;


    while(nr != NULL){
       NodoDobl * nrs = nr->nextNode;
        while(nrs != NULL){
                RegistroVino * rv = (RegistroVino * )nr->data;
                RegistroVino * nrv = (RegistroVino * )nrs->data;
            if( rv->cantidadSeleccionado < nrv->cantidadSeleccionado){
                RegistroVino * auxRegVino = nrv;
                nrs->data = nr->data;
                nr->data = auxRegVino;
            }
            nrs = nrs->nextNode;
        }
        nr = nr->nextNode;
    }


}
void ordenarRegistrosDes(ListaDoblEnl * lr){

    NodoDobl * nr = lr->head;
    while(nr != NULL){
    NodoDobl * nrs = nr->nextNode;

        while(nrs != NULL){
                RegistroVino * rv = (RegistroVino * )nr->data;
                RegistroVino * nrv = (RegistroVino * )nrs->data;
            if(rv->cantidadSeleccionado > nrv->cantidadSeleccionado){
                RegistroVino * auxRegVino = nrv;
                nrs->data = nr->data;
                nr->data = auxRegVino;
            }
            nrs = nrs->nextNode;
        }
        nr = nr->nextNode;
    }

}


ListaDoblEnl * rankingVinosPerYearDes(ListaSimpEnl* list, int year){
    ListaDoblEnl* LISTA_REGISTRO_VINO = newListaDoblEnl();
    Nodo* node = list->head;

  while(node != NULL){
    SeleccionMensual* seleccionMensual = ( SeleccionMensual*)node->data;
    if(seleccionMensual->anio == year){
      for(int i = 0; i < 5; i++){
        contarVino(LISTA_REGISTRO_VINO, seleccionMensual->idsVinos[i]);
      }
    }
    node = node->nextNode;
  }
    ordenarRegistrosAsc(LISTA_REGISTRO_VINO);
    return LISTA_REGISTRO_VINO;

}



void printRegistroVino(RegistroVino *rv){
    cout << "======================================" << endl;
    cout <<  "idVino: " << getIdRegistroVino(rv) << endl;
    cout << "Cantidad: " << getCantidadRegistroVino(rv) << endl;
}

