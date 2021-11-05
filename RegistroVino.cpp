#include "RegistroVino.h"
#include "ListaDoblEnl.h"
#include "ListaSimpEnl.h"
#include "SeleccionMensual.h"
#include "Vino.h"
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


ListaDoblEnl * rankingVinosPerYear(ListaSimpEnl* listaSelecciones, int year){
    ListaDoblEnl* LISTA_REGISTRO_VINO = newListaDoblEnl();
    Nodo* node = listaSelecciones->head;

  while(node != NULL){
    SeleccionMensual* seleccionMensual = ( SeleccionMensual*)node->data;
    if(seleccionMensual->anio == year){
      for(int i = 0; i < 5; i++){
        contarVino(LISTA_REGISTRO_VINO, seleccionMensual->idsVinos[i]);
      }
    }
    node = node->nextNode;
  }
    return LISTA_REGISTRO_VINO;

}







void printRankingVinosPerYearAsc(ListaDoblEnl* listaRegistros){
    ordenarRegistrosAsc(listaRegistros);
    cout << "==========================" << endl;
    cout << "Ranking de Vinos Ascendente" << endl;
    NodoDobl* sm = listaRegistros->head;
    int i = 1;
    while (sm != NULL) {
        printRegistroVino((RegistroVino*) sm->data);
        cout <<  "Puesto: " << i++ << endl;
        cout << "Index: " << sm->index << endl;
        sm = sm->nextNode;
    }
}
void printRankingVinosPerYearDes(ListaDoblEnl* listaRegistros){

    ordenarRegistrosDes(listaRegistros);
    cout << "==========================" << endl;
    cout << "Ranking de Vinos Descendente" << endl;
    NodoDobl* sm = listaRegistros->head;
    int i =  listaRegistros->tam;
    while (sm != NULL) {

        printRegistroVino((RegistroVino*) sm->data);
        cout <<  "Puesto: " << i-- << endl;
        cout << "Index: " << sm->index << endl;
        sm = sm->nextNode;
    }
}



void printRegistroVino(RegistroVino *rv){
    cout << "======================================" << endl;
    cout <<  "idVino: " << getIdRegistroVino(rv) << endl;
    cout << "Cantidad: " << getCantidadRegistroVino(rv) << endl;
}
void printNodoRegistroVino(NodoDobl *rv){
    printRegistroVino((RegistroVino *) rv->data);
    cout << "Index: " << rv->index << endl;
}

void printListaRegistrosVinos(ListaDoblEnl* list){

       NodoDobl* sm = list->head;
        while (sm != NULL) {
            printRegistroVino((RegistroVino*) sm->data);
            cout << "Index: " << sm->index << endl;
            sm = sm->nextNode;
    }

}


void printRankingBodegasPerYearAsc(ListaSimpEnl* listaSelecciones, ListaSimpEnl * listVinos, int year){
  ListaDoblEnl * lrv = rankingVinosPerYear(listaSelecciones,year);
  ordenarRegistrosAsc(lrv);
  ListaDoblEnl* listaBodega = newListaDoblEnl();
  NodoDobl* node = lrv->head;

  while(node != NULL){
    RegistroVino * v1 = (RegistroVino *)node->data;
    Vino * v = findVinoById(listVinos,v1->idRegistroVino);

    addDataToListDoblEnl(listaBodega, &v->bodega );

    node = node->nextNode;
  }
    cout << "==========================" << endl;
    cout << "Ranking de Bodegas Ascendente" << endl;
    printListaBodegaAsc(listaBodega);
}



void printRankingBodegasPerYearDes(ListaSimpEnl* listaSelecciones,ListaSimpEnl * listVinos, int year){
  ListaDoblEnl * lrv = rankingVinosPerYear(listaSelecciones,year);
  ordenarRegistrosDes(lrv);
  ListaDoblEnl* listaBodega = newListaDoblEnl();
  NodoDobl* node = lrv->head;

  while(node != NULL){
    RegistroVino * v1 = (RegistroVino *)node->data;
    Vino * v = findVinoById(listVinos,v1->idRegistroVino);
    addDataToListDoblEnl(listaBodega, &v->bodega );

    node = node->nextNode;
  }
    cout << "==========================" << endl;
    cout << "Ranking de Bodegas Ascendente" << endl;
    printListaBodegaDes(listaBodega);
}



void printListaBodegaAsc(ListaDoblEnl* list){
    NodoDobl* sm = list->head;
     int i = 1;
    while (sm != NULL) {
        cout << "Bodega: " << *((string*) sm->data)  << endl;
        cout << "Puesto: " << i++ << endl;
        sm = sm->nextNode;
         cout << "---------------------------" << endl;
    }
}
void printListaBodegaDes(ListaDoblEnl* list){
    NodoDobl* sm = list->head;
    int i = list->tam;
    while (sm != NULL) {
        cout << "Bodega: " << *((string*) sm->data)  << endl;
        cout << "Puesto: " << i-- << endl;
        sm = sm->nextNode;
        cout << "---------------------------" << endl;
    }
}






