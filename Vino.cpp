#include "Vino.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include "Funciones.h"
#include "ListaSimpEnl.h"
using namespace std;

//------------------------------------------------------------
//CONSTUCTOR
Vino *crearVino(string idVino, string etiqueta, string bodega, string segmentoDelVino, string varietal, string anioCosecha,string terroir){
    Vino *v = new Vino();
    setIdVino(v, idVino);
    setEtiqueta(v,etiqueta);
    setBodega(v, bodega);
    setSegmentoDelVino(v, segmentoDelVino);
    setVarietal(v, varietal);
    setAnioCosecha(v, anioCosecha);
    setTerroir(v,terroir);


    return v;


}
//------------------------------------------------------------
//CONSTUCTOR
Vino *crearVino(string etiqueta, string bodega, string segmentoDelVino, string varietal, string anioCosecha, string terroir){

    Vino *v = new Vino();
    setEtiqueta(v,etiqueta);
    setBodega(v, bodega);
    setSegmentoDelVino(v, segmentoDelVino);
    setVarietal(v, varietal);
    setAnioCosecha(v, anioCosecha);

    return v;
}



void* cargarVinoConArchivo(string line){



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




        std::stringstream ss(line);
        getline(ss, auxIdVino, '-');
        idVino = eliminarEspaciosDelComienzo(auxIdVino);
        getline(ss, auxEtiqueta, '-');
        etiqueta = eliminarEspaciosDelComienzo(auxEtiqueta);

        getline(ss, auxBodega, '-');
        bodega = eliminarEspaciosDelComienzo(auxBodega);

        getline(ss, auxSegmento, '-');
        segmentoDelVino = eliminarEspaciosDelComienzo(auxSegmento);

        getline(ss, auxVarietal, '-');
        varietal = eliminarEspaciosDelComienzo(auxVarietal);

        getline(ss, auxAnioCosecha, '-');
        anioCosecha = eliminarEspaciosDelComienzo(auxAnioCosecha);


        getline(ss, auxTerroir, ';');
        terroir = eliminarEspaciosDelComienzo(auxTerroir);




        void *v =  crearVino(idVino,etiqueta,bodega,segmentoDelVino,varietal,anioCosecha,terroir);


        return v;

}
void cargarListaVinoDesdeArchivo(ListaSimpEnl* list){

    ifstream archivo;
    string line = "";

    archivo.open("catalogo_test.txt",ios::in);//Abrimos el archivo en modo lectura

    while(!archivo.eof()){//mientras NO sea el final del archivo, recorrelo

        while(getline(archivo,line)){
            addDataToList(list,cargarVinoConArchivo(line));
        }
    }

    archivo.close();


}




//------------------------------------------------------------
//DESTRUCTOR

void borrarVino(Vino *v){
    delete(v);
}


void removeVinoByIdFromList(ListaSimpEnl* list, string idVino){

     Nodo* tempPreviousNode = NULL;

      Nodo* n = list->head;
        Vino * head = (Vino *) list->head->data;
      while (n != NULL) {
        Vino * v = (Vino *)n->data;
        if(head->idVino == idVino){
            list->head = n->nextNode;
             cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
            cout << "Vino id: " << ((Vino* )n->data )->idVino << " eliminado" << endl;
             cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
            delete(n);
            n=NULL;
        }
        else if(v->idVino == idVino && head->idVino != idVino){

            tempPreviousNode->nextNode = n->nextNode != NULL ? n->nextNode : NULL;
             cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
            cout << "Vino id: " << ((Vino* )n->data )->idVino << " eliminado" << endl;
             cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
            delete(n);
            n=NULL;
        }
        if(n!=NULL){
            tempPreviousNode = n;
            n = n->nextNode;
        }
      }

}


//---------------------------------------------------------------------
//DESTRUCTOR

//PRE: Vino *v debe tener espacio de memoria reservada previamente
//POST: se libera el espacio de la memoria del Vino* v
void borrarVino(Vino *v);



//------------------------------------------------------------
//GETS

string getIdVino(Vino *v){
    return v->idVino;
}
string getEtiqueta(Vino *v){
    return v->etiqueta;
}
string getBodega(Vino * v){
    return v->bodega;
}
string getSegmentoDelVino(Vino *v){
    return v->segmentoDelVino;
}
string getVarietal(Vino *v){
    return v->varietal;
}
string getTerroir(Vino *v){
    return v->terroir;
}
string getAnioCosecha(Vino *v){
    return v->anioCosecha;
}

//------------------------------------------------------------
//SETS


void setEtiqueta(Vino *v, string etiqueta){
    v->etiqueta = etiqueta;

}
void setBodega(Vino *v, string bodega){
   v->bodega = bodega;
}
void setIdVino(Vino *v, string idVino){
    v->idVino = idVino;
}
void setSegmentoDelVino(Vino *v, string segmentoDelVino){
    v->segmentoDelVino =segmentoDelVino;
}
void setVarietal(Vino *v, string varietal){
    v->varietal = varietal;
}
void setAnioCosecha(Vino *v, string anioCosecha){
    v->anioCosecha = anioCosecha;
}
void setTerroir(Vino *v, string terroir){
    v->terroir = terroir;
}


//------------------------------------------------------------
//BUSCADOR
Vino * findVinoById(ListaSimpEnl* list, string idVino){
  Nodo* n = list->head;
  Nodo* temp;
  while (n != NULL) {
    Vino * v = (Vino *)n->data;
    if(v->idVino == idVino){
        return v;
    }
    n = n->nextNode;
  }
    return 0;
}





//------------------------------------------------------------
//UTILIDADES
void printVino(Vino *v){
    if(v!=NULL){
        cout << "========================" << endl;
        cout << "Id Vino: " << v->idVino << endl;
        cout << "Etiqueta: " << v->etiqueta << endl;
        cout << "Anio de cosecha: " << v->anioCosecha << endl;
        cout << "Segmento: " << v->segmentoDelVino << endl;
        cout << "Varietal: " << v->varietal << endl;
        cout << "Terroir: " << v->terroir << endl;

    }else{
        cout<< "Vino Vacio"<< endl;
    }


}


void printListaVino(ListaSimpEnl* list){
    if(list->head ==NULL){
        cout << "Lista vacia" << endl;
    }else{

        Nodo* n = list->head;
        while (n != NULL) {
            printVino((Vino*)n->data);
            n = n->nextNode;
        }
    }


}


