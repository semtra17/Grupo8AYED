#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "ListaDoblEnl.h"
/*
  PRE : opcion debe ser entero.
  POST: Activa menu de seleccion.
  Eleccion limitada de interaccion con el sistema
*/
void menu(int opcion, void * lista, void * aux);
/*
  PRE : opcion debe ser entero, lista debe estar cargada con struct Usuario.
  POST: Activa menu de seleccion para interaccion con operaciones de Usuarios.
*/
void opcionesUsuario(int opcion, void * lista);
/*
  PRE : opcion debe ser entero, lista debe estar cargada con struct Vino.
  POST: Activa menu de seleccion para interaccion con operaciones de Vinos.
*/
void opcionesVino(int opcion,  void * lista);
/*
  PRE : opcion debe ser entero, lista debe estar cargada con struct SeleccionMensual.
  POST: Activa menu de seleccion para interaccion con operaciones de SeleccionMensual.
*/
void opcionesSeleccionMen(int opcion,  void * lista);
/*
  PRE : opcion debe ser entero, lista debe estar cargada con struct ResgistroVino.
  POST: Activa menu de seleccion para interaccion con operaciones de Ranking de VInos.
*/
void rankingVinos(int opcion,  ListaDoblEnl * lista);
/*
  PRE : opcion debe ser entero, lista debe estar cargada con struct SeleccionMensual.
  PRE : opcion debe ser entero, listaAux debe estar cargada con struct Vino.
  POST: Activa menu de seleccion para interaccion con operaciones de Ranking de Bodegas.

*/
void rankingBodegas(int opcion, void * lista, void * listaAux);
/*
  PRE : opcion debe ser entero, lista debe estar cargada con struct SeleccionMensual.
  PRE : opcion debe ser entero, listaAux debe estar cargada con struct Vino.
  POST: Activa menu de seleccion para interaccion con operaciones de Ranking de Varietal.

*/
void rankingVarietal(int opcion, void * lista, void * listaAux);

#endif // MENU_H_INCLUDED
