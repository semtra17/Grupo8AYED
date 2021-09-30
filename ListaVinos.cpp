#include "Vino.h"
#include "ListaVinos.h"
#include "Funciones.h"
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <sstream>

using namespace std;




void printListaVinos(ListaVinos* list){
    NodoVino *n = list->primerVino;
    while(n != NULL){
        Vino *v = n->elementoVino;
        cout << "=====================" << endl;
        cout << "IdVino: "  << getIdVino(v)  << endl;
        cout << "Etiqueta: " << getEtiqueta(v) << endl;
        cout << "Bodega: " << getBodega(v) << endl;
        cout << "Varietal: " << getVarietal(v) << endl;
        cout << "Año Cosecha: " << getAnioCosecha(v) << endl;
        cout << "Terroir: " << getTerroir(v) << endl;
        n = n->sigVino;
    }



}

void cargarListaVinosDesdeArchivo(ListaVinos* list){

    NodoVino* ultimoNodo;
    NodoVino* anteriorNodo;


    ifstream archivo;
    string line = "";

    archivo.open("catalogo_test.txt",ios::in);//Abrimos el archivo en modo lectura

    while(!archivo.eof()){//mientras NO sea el final del archivo, recorrelo

        while(getline(archivo,line)){


            ultimoNodo=cargarNodoVinoConArchivo(line) ;

            if(list->tamanioLista==0){

                list->primerVino=ultimoNodo;
            }
            else{

                anteriorNodo->sigVino=ultimoNodo;
            }

                list->tamanioLista++;
                anteriorNodo=ultimoNodo;
            }


    }

    archivo.close();






}
NodoVino* cargarNodoVinoConArchivo(string line){
        string auxIdVino;
        string auxEtiqueta;
        string auxBodega;
        string auxSegmento;
        string auxVarietal;
        string auxAnioCosecha;
        string auxAnioVino;
        string auxTerroir;


        string idVino;
        string etiqueta;
        string bodega;
        string segmentoDelVino;
        string varietal;
        string anioCosecha;
        string terroir;




        stringstream ss(line);
        getline(ss, auxIdVino, '-');
        idVino = eliminarEspacios(auxIdVino);
        getline(ss, auxEtiqueta, '-');
        etiqueta = eliminarEspacios(auxEtiqueta);

        getline(ss, auxBodega, '-');
        bodega = eliminarEspacios(auxBodega);

        getline(ss, auxSegmento, '-');
        segmentoDelVino = eliminarEspacios(auxSegmento);

        getline(ss, auxVarietal, '-');
        varietal = eliminarEspacios(auxVarietal);

        getline(ss, auxAnioCosecha, '-');
        anioCosecha = eliminarEspacios(auxAnioCosecha);


        getline(ss, auxTerroir, ';');
        terroir = eliminarEspacios(auxTerroir);


//        Vino *v = crearVino(idVino,auxEtiqueta,auxBodega,auxSegmento,auxVarietal,auxAnioCosecha,auxTerroir);
        Vino *v = crearVino(idVino,etiqueta,bodega,segmentoDelVino,varietal,anioCosecha,terroir);


        NodoVino* nv = new NodoVino();
        nv->elementoVino = v;
        nv->sigVino = NULL;




    return nv;

}

NodoVino* nuevoNodoVino(Vino* v){
    NodoVino* nv = new NodoVino();
    nv->elementoVino = v;
    nv->sigVino = NULL;
    return nv;

}

ListaVinos* nuevaListaVinos(){

    ListaVinos * lista = new ListaVinos();
    lista->primerVino = NULL;
    lista->tamanioLista = 0 ;
    return lista;


}

void linkToNextNodoVino(NodoVino* currentNode, NodoVino* nodeToAdd){
     if (currentNode->sigVino == NULL){
		currentNode->sigVino = nodeToAdd;
	}else{
	 	linkToNextNodoVino(currentNode->sigVino, nodeToAdd);
	}

}

void agregarNodoVino(ListaVinos* list, NodoVino* nodeToAdd){
     if(list->primerVino == NULL){
            list->primerVino = nodeToAdd;
            list->tamanioLista++;
     }else{
            linkToNextNodoVino(list->primerVino, nodeToAdd);
            list->tamanioLista++;
      }
}

void agregarVino(ListaVinos* list, Vino * vinoToAdd){

    NodoVino* node = nuevoNodoVino(vinoToAdd);
    agregarNodoVino(list, node);

}

NodoVino* findVinoById(ListaVinos* list, string idVino){

    NodoVino* nv = list->primerVino;
      NodoVino* temp;
      while (nv != NULL) {
        if(nv->elementoVino->idVino == idVino){
          temp = nv;
        }
        nv = nv->sigVino;
      }
      return temp;
}

void removeNode(ListaVinos* list, NodoVino* nodeToRemove){
      NodoVino* tempVinoNode = nodeToRemove;
    NodoVino* tempPreviousNode = NULL;

    NodoVino* nv = list->primerVino;

    while (nv != NULL) {
        if(nv->sigVino == nodeToRemove){
          tempPreviousNode = nv;
        }
        nv = nv->sigVino;
    }
      tempPreviousNode->sigVino = tempVinoNode;
      delete nodeToRemove;

}

void removeVino(ListaVinos* list, Vino *v){

    NodoVino* nodeToRemove = findVinoById(list, v->idVino);
    removeNode(list, nodeToRemove);

}





