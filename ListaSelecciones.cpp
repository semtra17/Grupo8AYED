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
            }else{
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
//        idSeleccionMen = eliminarEspacios(auxIdSelecMen);
    idSeleccionMen = auxIdSelecMen;

    getline(ss, auxMes, '-');
//        mes = eliminarEspacios(auxMes);
    mes = auxMes;

    getline(ss, auxAnio, '-');
    anio = stoi(auxAnio);

    for(int i =0; i <= 5; i++){
          getline(ss, auxIdsVinos[i], '-');
          idsVinos[i] = stringToNumber(auxIdsVinos[i]);
    }

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
//new code for extract

struct NodoRegistroVino{
  std::string idVino;
  int cantidadSeleccionado;
  NodoRegistroVino* SiguienteNodoRegistroVino;
};

struct ListaRegistroVino
{
	NodoRegistroVino* primerNodoRegistroVino;
};

ListaRegistroVino* newListaRegistroVino(){
	ListaRegistroVino *list = new ListaRegistroVino();
	list->primerNodoRegistroVino = NULL;
	return list;
}

NodoRegistroVino* newNodoRegistroVino(string idVino){
	NodoRegistroVino *node = new NodoRegistroVino();
	node->idVino = idVino;
	node->cantidadSeleccionado = 1;
    node->SiguienteNodoRegistroVino = NULL;
	return node;
}

NodoRegistroVino* buscarRegristoVinoPorId(ListaRegistroVino* list, string idVino){
    NodoRegistroVino* n = list->primerNodoRegistroVino;
    NodoRegistroVino* temp = NULL;
    while (n != NULL) {
      if(n->idVino == idVino){
        temp = n;
      }
      n = n->SiguienteNodoRegistroVino;
    }
    return temp;
}

void linkToNext(NodoRegistroVino* currentNode, NodoRegistroVino* nodeToAdd){
	if (currentNode->SiguienteNodoRegistroVino == NULL){
		currentNode->SiguienteNodoRegistroVino = nodeToAdd;
	}else{
	 	linkToNext(currentNode->SiguienteNodoRegistroVino, nodeToAdd);
	}
}

void addNodeToList(ListaRegistroVino* list, NodoRegistroVino* nodeToAdd){
  if(list->primerNodoRegistroVino == NULL){
    list->primerNodoRegistroVino = nodeToAdd;
  }else{
    linkToNext(list->primerNodoRegistroVino, nodeToAdd);
  }
}

void agregarNodoRegistro(ListaRegistroVino* list, string idVino){
  NodoRegistroVino* nuevowNodoRegistroVinoNdo = newNodoRegistroVino(idVino);
  addNodeToList(list, nuevowNodoRegistroVinoNdo);
}

void contarVino(ListaRegistroVino* list, string idVino){
  NodoRegistroVino* nodoRegistroVino = buscarRegristoVinoPorId(list, idVino);
  //cout <<  "NodoRegistroVino: " << nodoRegistroVino->idVino << endl;
  if(nodoRegistroVino != NULL){
    nodoRegistroVino->cantidadSeleccionado++;
  }else{
    agregarNodoRegistro(list, idVino);
  }
}

void printRegistroVino(NodoRegistroVino *r){
    cout << "======================================" << endl;
    cout <<  "idVino: " << r->idVino << endl;
    cout << "Cantidad: " << r->cantidadSeleccionado << endl;
}

void sortRankingVinos(ListaRegistroVino* list){
    NodoRegistroVino* sm = list->primerNodoRegistroVino;
    bool changed = true;
    while(changed == true){
        changed = false;
        cout << "changed" << endl;
        while (sm->SiguienteNodoRegistroVino != NULL) {
            cout << "Cantidad: " << sm->cantidadSeleccionado << endl;
            NodoRegistroVino* siguienteNodoRegistroVino = sm->SiguienteNodoRegistroVino;
            if(sm->cantidadSeleccionado < siguienteNodoRegistroVino->cantidadSeleccionado){
                cout << "1: " << sm->cantidadSeleccionado << endl;
                cout << "2: " << siguienteNodoRegistroVino->cantidadSeleccionado << endl;
                NodoRegistroVino* temp;
                temp = siguienteNodoRegistroVino;
                siguienteNodoRegistroVino = sm;
                sm = temp;
                changed = true;
            }
            sm = sm->SiguienteNodoRegistroVino;
        }
    }
}

void printRankingVinosPerYear(ListaRegistroVino* list){
    NodoRegistroVino* sm = list->primerNodoRegistroVino;
    while (sm != NULL) {
        printRegistroVino(sm);
        sm = sm->SiguienteNodoRegistroVino;
    }
}

void rankingVinosPerYear(ListaSelecciones* list, int year){
  ListaRegistroVino* listaRegistroVino = newListaRegistroVino();
  NodoSeleccion* node = list->primerSeleccion;

  while(node != NULL){
    SeleccionMensual* seleccionMensual = node->elementoSeleccion;
    if(seleccionMensual->anio == year){
      for(int i = 0; i <= 5; i++){
        contarVino(listaRegistroVino, seleccionMensual->idsVinos[i]);
      }
    }
    node = node->sigSeleccion;
  }
    sortRankingVinos(listaRegistroVino);
    printRankingVinosPerYear(listaRegistroVino);
}

void rankingGeneralDeVinosUltimoYear(ListaSelecciones* list){
    rankingVinosPerYear(list, 2021);
}
