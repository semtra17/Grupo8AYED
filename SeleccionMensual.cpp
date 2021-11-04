#include "SeleccionMensual.h"
#include "Funciones.h"
#include <iostream>
#include <iostream>
#include <fstream>
#include<stdlib.h>
#include <string.h>
#include <sstream>


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



void* cargarSelMenConArchivo(string line){

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
    idSeleccionMen = eliminarEspaciosDelComienzo(auxIdSelecMen);

    getline(ss, auxMes, '-');
    mes = eliminarEspaciosDelComienzo(auxMes);

    getline(ss, auxAnio, '-');
    anio = stoi(auxAnio);

    for(int i =0; i <= 5; i++){
          getline(ss, auxIdsVinos[i], '-');
          idsVinos[i] = eliminarEspaciosDelComienzo(auxIdsVinos[i]);
    }

    void *sm = crearSeleccionMensual(idSeleccionMen,mes,anio,idsVinos);
    return sm;


}
void cargarListaSelDesdeArchivo(ListaSimpEnl* list){

    ifstream archivo;
    string line = "";

    archivo.open("eleccion_test.txt",ios::in);//Abrimos el archivo en modo lectura

    while(!archivo.eof()){//mientras NO sea el final del archivo, recorrelo

        while(getline(archivo,line)){
            addDataToList(list,cargarSelMenConArchivo(line));
        }
    }

    archivo.close();

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




//------------------------------------------------------
//BUSCADOR


SeleccionMensual * findSelecMenById(ListaSimpEnl* list, string idSelec){
 Nodo* tempPreviousNode = NULL;

      Nodo* n = list->head;
        SeleccionMensual * head = (SeleccionMensual *) list->head->data;
      while (n != NULL) {
        SeleccionMensual * s = (SeleccionMensual *)n->data;
        if(head->idSelecMen == idSelec){
            list->head = n->nextNode;
             cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
            cout << "SeleccionMensual id: " << ((SeleccionMensual* )n->data )->idSelecMen << " eliminado" << endl;
             cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
            delete(n);
            n=NULL;
        }
        else if(s->idSelecMen == idSelec && head->idSelecMen != idSelec){

            tempPreviousNode->nextNode = n->nextNode != NULL ? n->nextNode : NULL;
             cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
            cout << "SeleccionMensual id: " << ((SeleccionMensual* )n->data )->idSelecMen << " eliminado" << endl;
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

void printListaSelecMen(ListaSimpEnl* list){
    if(list->head == NULL){
        cout << "Lista vacia" << endl;

    }else{
         Nodo* n = list->head;
            while (n != NULL) {
            printSelecMen((SeleccionMensual*)n->data);
            n = n->nextNode;
        }
    }

}



