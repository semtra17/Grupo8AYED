#include "Direccion.h"



Direccion* crearDireccion(char provincia[40], char localidad[40], char calle[40], int numero){
    Direccion *direccion =  new Direccion();
    strcpy(direccion->provincia, provincia);
    strcpy(direccion->localidad, localidad );
    strcpy(direccion->calle, calle );
    direccion->numero= numero;
    return direccion;
}
int getNumero(Direccion *direccion){
    return direccion->numero;
}
char *getProvincia(Direccion *direccion){
    return direccion->provincia;
}
char *getLocalidad(Direccion *direccion){
    return direccion->localidad;
}
char *getCalle(Direccion *direccion){
    return direccion->calle;
}

void setNumero(Direccion *direccion, int numero){
      direccion->numero= numero;
}
void setProvincia(Direccion *direccion, char provincia[40]){
        strcpy(direccion->provincia, provincia );
}

void setLocalidad(Direccion *direccion, char localidad[40]){
    strcpy(direccion->localidad, localidad );
}

void setCalle(Direccion *direccion, char calle[40]){
    strcpy(direccion->calle, calle );
}
