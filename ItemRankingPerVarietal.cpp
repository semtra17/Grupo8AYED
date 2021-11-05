#include "ItemRankingPerVarietal.h"
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <sstream>

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

void printItemRankingPerVarietal(ItemRankingPerVarietal *i){
    cout << "======================================" << endl;
    cout <<  "Nombre: " << getNameItemRankingPerVarietal(i) << endl;
    cout <<  "Cantidad: " << getCantidadItemRankingPerVarietal(i) << endl;
}


