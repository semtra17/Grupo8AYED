#ifndef ITEMRANKINGPERVARIETAL_H_INCLUDED
#define ITEMRANKINGPERVARIETAL_H_INCLUDED


#include "ItemRankingPerVarietal.h"
#include "ListaSimpEnl.h"
#include "ListaDoblEnl.h"
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


void rankingVinosTodasLasEdadesPerVarietal(ListaSimpEnl* listSelecciones, ListaSimpEnl* listVinos );
void rankingVinosAntiguosPerVarietal(ListaSimpEnl* listSelecciones, ListaSimpEnl* listVinos );
void rankingVinosJovenesPerVarietal(ListaSimpEnl* listSelecciones, ListaSimpEnl* listVinos );
void rankingVinosMedianosPerVarietal(ListaSimpEnl* listSelecciones, ListaSimpEnl* listVinos );

void printNodoRankingPerVarietal(NodoDobl *nr);
void printListaRankingPerVarietales(ListaDoblEnl* list);
void printItemRankingPerVarietal(ItemRankingPerVarietal *i);
#endif // ITEMRANKINGPERVARIETAL_H_INCLUDED
