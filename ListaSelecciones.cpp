
#include "Funciones.h"
#include "ListaSelecciones.h"
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include "SeleccionMensual.h"



void printListaSelecciones(ListaSelecciones* list){

    NodoSeleccion* sm = list->primerSeleccion;
    while (sm != NULL) {
        printSelecMen(sm->elementoSeleccion);
        sm = sm->sigSeleccion;
    }

}
void cargarListaSeleccionesDesdeArchivo(ListaSelecciones* list){
    NodoSeleccion* ultimoNodo;
    NodoSeleccion* anteriorNodo;


       ifstream archivo;
    string line = "";

    archivo.open("eleccion_test.txt",ios::in);//Abrimos el archivo en modo lectura

    while(!archivo.eof()){//mientras NO sea el final del archivo, recorrelo

        while(getline(archivo,line)){


            ultimoNodo=cargarNodoSeleccionConArchivo(line) ;

            if(list->tamanioLista==0){

                list->primerSeleccion=ultimoNodo;
            }
            else{

                anteriorNodo->sigSeleccion=ultimoNodo;
            }

                list->tamanioLista++;
                anteriorNodo=ultimoNodo;
            }


    }

    archivo.close();


}
NodoSeleccion* cargarNodoSeleccionConArchivo(string line){


        string auxIdSelecMen;
        string auxAnio;
        string auxMes;
        string auxIdsVinos[6];

        string idSeleccionMen;
        int anio = 0;
        string mes;
        string idsVinos[6];



        stringstream ss(line);
        getline(ss, auxIdSelecMen, '-');
        idSeleccionMen = eliminarEspacios(auxIdSelecMen);

        getline(ss, auxMes, '-');
        mes = eliminarEspacios(auxMes);

        getline(ss, auxAnio, '-');
        anio = stoi(auxAnio);

        for(int i =0; i< 5; i++){
              getline(ss, auxIdsVinos[i], '-');
              idsVinos[i] = eliminarEspacios(auxIdsVinos[i]);
        }

        getline(ss, auxIdsVinos[6], ';');
        idsVinos[6] = eliminarEspacios(idsVinos[6]);


        SeleccionMensual *sm = crearSeleccionMensual(idSeleccionMen,mes,anio,idsVinos);


        NodoSeleccion * ns = new NodoSeleccion();
        ns->elementoSeleccion = sm;
        ns->sigSeleccion = NULL;




    return ns;
}

NodoSeleccion* nuevoNodoSeleccion(SeleccionMensual* s){
    NodoSeleccion* nodoSeleccion = new NodoSeleccion();
    nodoSeleccion->elementoSeleccion = s;
    nodoSeleccion->sigSeleccion = NULL;
    return nodoSeleccion;

}



ListaSelecciones* nuevaListaSelecciones(){

    ListaSelecciones* lista = new ListaSelecciones();
    lista->primerSeleccion = NULL;
    lista->tamanioLista = 0 ;
    return lista;
}

void linkToNextNodoSeleccion(NodoSeleccion* currentNode, NodoSeleccion* nodeToAdd){

    if (currentNode->sigSeleccion == NULL){
		currentNode->sigSeleccion = nodeToAdd;
	}else{
	 	linkToNextNodoSeleccion(currentNode->sigSeleccion, nodeToAdd);
	}
}
void agregarNodoSeleccion(ListaSelecciones* list, NodoSeleccion* nodeToAdd){

    if(list->primerSeleccion == NULL){
            list->primerSeleccion = nodeToAdd;
            list->tamanioLista++;
     }else{
            linkToNextNodoSeleccion(list->primerSeleccion, nodeToAdd);
            list->tamanioLista++;
      }
}

void agregarSeleccion(ListaSelecciones* list, SeleccionMensual * seleccionToAdd){

    NodoSeleccion* node = nuevoNodoSeleccion(seleccionToAdd);
    agregarNodoSeleccion(list, node);

}
NodoSeleccion* findSelcMenById(ListaSelecciones* list, string idSeleccion){
      NodoSeleccion* sm = list->primerSeleccion;
      NodoSeleccion* temp;
      while (sm != NULL) {
        if(sm->elementoSeleccion->idSelecMen == idSeleccion){
          temp = sm;
        }
        sm =sm->sigSeleccion;
      }
      return temp;
}
void removeNode(ListaSelecciones* list, NodoSeleccion* nodeToRemove){

    NodoSeleccion* tempSeleccNode = nodeToRemove;
    NodoSeleccion* tempPreviousNode = NULL;

    NodoSeleccion* sm = list->primerSeleccion;

    while (sm != NULL) {
        if(sm->sigSeleccion == nodeToRemove){
          tempPreviousNode = sm;
        }
        sm = sm->sigSeleccion;
    }
      tempPreviousNode->sigSeleccion = tempSeleccNode;

      delete nodeToRemove;



}

void removeSelecMen(ListaSelecciones* list, SeleccionMensual *s){

    NodoSeleccion* nodeToRemove = findSelcMenById(list, s->idSelecMen);
    removeNode(list, nodeToRemove);


}
