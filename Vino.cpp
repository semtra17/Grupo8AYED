#include "Vino.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
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
Vino *crearVino(string etiqueta, string bodega, string segmentoDelVino, string varietal, string anioCosecha, string terroir){

    Vino *v = new Vino();
    setEtiqueta(v,etiqueta);
    setBodega(v, bodega);
    setSegmentoDelVino(v, segmentoDelVino);
    setVarietal(v, varietal);
    setAnioCosecha(v, anioCosecha);

    return v;
}

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
