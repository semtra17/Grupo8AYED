#ifndef SELECCIONMENSUAL_H_INCLUDED
#define SELECCIONMENSUAL_H_INCLUDED

struct SeleccionMensual{
    int idUsuario;
    char mes[12];
    int anio;
    int idsVinos[6];
};


SeleccionMensual * crearSeleccionMensual(int idUsuario, char mes[12], int anio, int idsVinos[6]);

int getIdUsuarioDeSelecMen(SeleccionMensual * s);
int getAnio(SeleccionMensual *s);
int getIdsVinos(SeleccionMensual *s);
char *getMes(SeleccionMensual *s);

void setIdUsuario(SeleccionMensual *s,int idUsuario);
void setMes(SeleccionMensual *s, char mes[12]);
void setAnio(SeleccionMensual *s,int anio);
void setIdsVinos(SeleccionMensual *s,int idsVinos[6]);




#endif // SELECCIONMENSUAL_H_INCLUDED
