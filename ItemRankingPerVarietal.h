#ifndef ITEMRANKINGPERVARIETAL_H_INCLUDED
#define ITEMRANKINGPERVARIETAL_H_INCLUDED
#include "ItemRankingPerVarietal.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

struct ItemRankingPerVarietal{
   string nombre;
   int cantidad;
};

ItemRankingPerVarietal* crearItemRankingPerVarietal(string nombre, int cantidad);
string getNameItemRankingPerVarietal(ItemRankingPerVarietal* i);
int getCantidadItemRankingPerVarietal(ItemRankingPerVarietal* i);
void setNameItemRankingPerVarietal(ItemRankingPerVarietal* i, string name);
void setCantidadItemRankingPerVarietal(ItemRankingPerVarietal* i, int cantidad);
void eliminarItemRankingPerVarietal(ItemRankingPerVarietal *i);
void printItemRankingPerVarietal(ItemRankingPerVarietal *i);
#endif // LISTAREGISTROVINO_H_INCLUDED
