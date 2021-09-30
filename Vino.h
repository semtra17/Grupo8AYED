#ifndef VINO_H_INCLUDED
#define VINO_H_INCLUDED
#include <string>
using namespace std;
struct Vino{

    std::string idVino;
    std::string etiqueta;
    std::string  bodega;
    std::string  segmentoDelVino;
    std::string varietal;
    std::string anioCosecha;
    std::string terroir;

};


Vino *crearVino(string idVino, string etiqueta, string bodega, string segmentoDelVino, string varietal, string anioCosecha, string terroir);
Vino *crearVino(string etiqueta, string bodega, string segmentoDelVino, string varietal, string anioCosecha, string terroir);
string getIdVino(Vino *v);
string getEtiqueta(Vino *v);
string getBodega(Vino * v);
string getSegmentoDelVino(Vino *v);
string getVarietal(Vino *v);
string getTerroir(Vino *v);
string getAnioCosecha(Vino *v);

void setEtiqueta(Vino *v, string etiqueta);
void setBodega(Vino *v, string bodega);
void setIdVino(Vino *v, string idVino);
void setSegmentoDelVino(Vino *v, string segmentoDelVino);
void setVarietal(Vino *v, string varietal);
void setAnioCosecha(Vino *v, string anioCosecha);
void setTerroir(Vino *v, string terroir);



#endif // VINO_H_INCLUDED
