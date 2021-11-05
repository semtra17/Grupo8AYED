#include "ItemRankingPerVarietal.h"
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include "ListaDoblEnl.h"
#include "ListaSimpEnl.h"
#include "SeleccionMensual.h"
#include "Vino.h"

ItemRankingPerVarietal * crearItemRankingPerVarietal(string nombre, int cantidad){
    ItemRankingPerVarietal *item = new ItemRankingPerVarietal();
    item->nombre = nombre;
    item->cantidad = cantidad;
    return item;
}
string getNameItemRankingPerVarietal(ItemRankingPerVarietal* i){
    return i->nombre;
}
int getCantidadItemRankingPerVarietal(ItemRankingPerVarietal* i){
    return i->cantidad;
}
void setNameItemRankingPerVarietal(ItemRankingPerVarietal* i, string name){
    i->nombre = name;
}
void setCantidadItemRankingPerVarietal(ItemRankingPerVarietal* i, int cantidad){
    i->cantidad = cantidad;
}
void eliminarItemRankingPerVarietal(ItemRankingPerVarietal *i){
    delete(i);
}

NodoDobl* buscarRegistroVinoPorIdConListaVarietal(ListaDoblEnl* list, string idVino){
    NodoDobl* n = list->head;
    NodoDobl* temp = NULL;
    while (n != NULL) {
    ItemRankingPerVarietal * itemRegVarietal = (ItemRankingPerVarietal *) n->data;
      if(itemRegVarietal->nombre == idVino){
        temp = n;
      }
      n = n->nextNode;
    }
    return temp;
}


void contarVinoPerVarietal(ListaDoblEnl* list, Vino* vino){
    NodoDobl* nodoItemRankingPerVarietal = buscarRegistroVinoPorIdConListaVarietal(list, vino->idVino);
    if(nodoItemRankingPerVarietal != NULL){
        ((ItemRankingPerVarietal *)nodoItemRankingPerVarietal->data)->cantidad++;
    }else{
        void * rv = crearItemRankingPerVarietal(vino->idVino, 1);
        addDataToListDoblEnl(list, rv);
    }
}



void ordenarListaRankingPerVarietalDesc(ListaDoblEnl * lr){

    NodoDobl * nr = lr->head;
    while(nr != NULL){
    NodoDobl * nrs = nr->nextNode;

        while(nrs != NULL){
            if(((ItemRankingPerVarietal *)nr->data)->cantidad < ((ItemRankingPerVarietal *)nrs->data)->cantidad){
                ItemRankingPerVarietal * auxNodoRankingPerVarietal = (ItemRankingPerVarietal *)nrs->data;
                nrs->data = (ItemRankingPerVarietal *)nr->data;
                nr->data = auxNodoRankingPerVarietal;
            }
            nrs = nrs->nextNode;
        }
        nr = nr->nextNode;
    }

}

void rankingVinosTodasLasEdadesPerVarietal(ListaSimpEnl* listaSelecciones, ListaSimpEnl* listaVinos){
    ListaDoblEnl* rankingVinosJovenes = new ListaDoblEnl();
    ListaDoblEnl* rankingVinosMedianos = new ListaDoblEnl();
    ListaDoblEnl* rankingVinosViejos = new ListaDoblEnl();


    Nodo* currentNode = listaSelecciones->head;
    while(currentNode != NULL){
        //tambien hay que recorrer el array de IDs
        for(int i = 0; i < 5; i++){
            Vino* vino = findVinoById(listaVinos, ((SeleccionMensual *)currentNode->data)->idsVinos[i]);
            int anioCosecha;
            stringstream ss;
            ss << vino->anioCosecha;
            ss >> anioCosecha;
            int edad = 2021 - anioCosecha;
            if(edad < 30){
                contarVinoPerVarietal(rankingVinosJovenes, vino);
            }
            if(edad >30 && edad < 50){
                contarVinoPerVarietal(rankingVinosMedianos, vino);
            }
            if(edad > 50){
                contarVinoPerVarietal(rankingVinosViejos, vino);
            }
        }

        currentNode = currentNode->nextNode;
    }
    ordenarListaRankingPerVarietalDesc(rankingVinosJovenes);
    ordenarListaRankingPerVarietalDesc(rankingVinosMedianos);
    ordenarListaRankingPerVarietalDesc(rankingVinosViejos);

    cout << "VINOS MENORES A 30 ANIOS" << endl;
    printListaRankingPerVarietales(rankingVinosJovenes);

    cout << "VINOS MAYORES A 30 ANIOS Y MENORES QUE 50" << endl;
    printListaRankingPerVarietales(rankingVinosMedianos);

    cout << "VINOS MAYORES A 50 ANIOS" << endl;
    printListaRankingPerVarietales(rankingVinosViejos);
}
void rankingVinosAntiguosPerVarietal(ListaSimpEnl* listaSelecciones, ListaSimpEnl* listaVinos){
    ListaDoblEnl* rankingVinosViejos = new ListaDoblEnl();


    Nodo* currentNode = listaSelecciones->head;
    while(currentNode != NULL){
        //tambien hay que recorrer el array de IDs
        for(int i = 0; i < 5; i++){
            Vino* vino = findVinoById(listaVinos, ((SeleccionMensual *)currentNode->data)->idsVinos[i]);
            int anioCosecha;
            stringstream ss;
            ss << vino->anioCosecha;
            ss >> anioCosecha;
            int edad = 2021 - anioCosecha;
            if(edad > 50){
                contarVinoPerVarietal(rankingVinosViejos, vino);
            }
        }

        currentNode = currentNode->nextNode;
    }
    ordenarListaRankingPerVarietalDesc(rankingVinosViejos);

    cout << "VINOS MAYORES A 50 ANIOS" << endl;
    printListaRankingPerVarietales(rankingVinosViejos);
}

void rankingVinosJovenesPerVarietal(ListaSimpEnl* listaSelecciones, ListaSimpEnl* listaVinos){
    ListaDoblEnl* rankingVinosJovenes = new ListaDoblEnl();
    ListaDoblEnl* rankingVinosMedianos = new ListaDoblEnl();
    ListaDoblEnl* rankingVinosViejos = new ListaDoblEnl();


    Nodo* currentNode = listaSelecciones->head;
    while(currentNode != NULL){
        //tambien hay que recorrer el array de IDs
        for(int i = 0; i < 5; i++){
            Vino* vino = findVinoById(listaVinos, ((SeleccionMensual *)currentNode->data)->idsVinos[i]);
            int anioCosecha;
            stringstream ss;
            ss << vino->anioCosecha;
            ss >> anioCosecha;
            int edad = 2021 - anioCosecha;
            if(edad < 30){
                contarVinoPerVarietal(rankingVinosJovenes, vino);
            }
        }

        currentNode = currentNode->nextNode;
    }
    ordenarListaRankingPerVarietalDesc(rankingVinosJovenes);


    cout << "VINOS MENORES A 30 ANIOS" << endl;
    printListaRankingPerVarietales(rankingVinosJovenes);

}


void rankingVinosMedianosPerVarietal(ListaSimpEnl* listaSelecciones, ListaSimpEnl* listaVinos){

    ListaDoblEnl* rankingVinosMedianos = new ListaDoblEnl();



    Nodo* currentNode = listaSelecciones->head;
    while(currentNode != NULL){
        //tambien hay que recorrer el array de IDs
        for(int i = 0; i < 5; i++){
            Vino* vino = findVinoById(listaVinos, ((SeleccionMensual *)currentNode->data)->idsVinos[i]);
            int anioCosecha;
            stringstream ss;
            ss << vino->anioCosecha;
            ss >> anioCosecha;
            int edad = 2021 - anioCosecha;
            if(edad >30 && edad < 50){
                contarVinoPerVarietal(rankingVinosMedianos, vino);
            }

        }

        currentNode = currentNode->nextNode;
    }

    ordenarListaRankingPerVarietalDesc(rankingVinosMedianos);

    cout << "VINOS MAYORES A 30 ANIOS Y MENORES QUE 50" << endl;
    printListaRankingPerVarietales(rankingVinosMedianos);

}



void printNodoRankingPerVarietal(NodoDobl *nr){
   printItemRankingPerVarietal((ItemRankingPerVarietal *)nr->data);
}

void printListaRankingPerVarietales(ListaDoblEnl* list){

   NodoDobl* sm = list->head;
    while (sm != NULL) {
        printNodoRankingPerVarietal(sm);
        sm = sm->nextNode;
    }
}


void printItemRankingPerVarietal(ItemRankingPerVarietal *i){
    cout << "======================================" << endl;
    cout <<  "Nombre: " << getNameItemRankingPerVarietal(i) << endl;
    cout <<  "Cantidad: " << getCantidadItemRankingPerVarietal(i) << endl;
}




