#include <stdio.h>
#include <string.h>
struct Direccion{

    char provincia[40];
    char localidad[40];
    char calle[40];
    int numero;


};

Direccion* crearDireccion(char provincia[40], char localidad[40], char calle[40], int numero);
int getNumero(Direccion *direccion);
char *getProvincia(Direccion *direccion);
char *getLocalidad(Direccion *direccion);
char *getCalle(Direccion *direccion);

void setNumero(Direccion *direccion, int numero);
void setProvincia(Direccion *direccion, char provincia[40]);
void setLocalidad(Direccion *direccion, char localidad[40]);
void setCalle(Direccion *direccion, char calle[40]);
