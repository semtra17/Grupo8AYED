#include "Funciones.h"
#include <cstring>
#include <sstream>
#include <iostream>
#include<string>



using namespace std;

string eliminarEspacios(string cadena){

    int posComienzo = -1, auxPosComienzo = 0;
    int posFinal = 0, auxPosFinal = 0;
    char espacio = ' ';
    char tab = '\t';
    char auxCadena[50] = " ";
    char auxCadena2[50] = " ";
    string palabra = " ";
    int i=0;
    while(i < cadena.length()){

         if((cadena[i] == espacio) || cadena[i] == tab){
            posComienzo++;

        }else if( cadena[i] != espacio){
            i = cadena.length() + 1;
        }
        i++;
    }


    auxPosComienzo = posComienzo;
    if(posComienzo >= 0){
         for(int i = 0; i< cadena.length() - (auxPosComienzo + 1);i++){
            fflush(stdin);
            auxCadena[i] = cadena[++posComienzo];
        }

        fflush(stdin);
        palabra.clear();
        palabra = auxCadena;
    }else{

       palabra = cadena;
    }

//    Codigo no terminado para eliminar espacios del final
//    i = strlen(auxCadena) - 1;
//
//    while( 0 < i){
//
//         if((cadena[i] == espacio) || cadena[i] == tab){
//            posFinal = i;
//
//        }else if( cadena[i] != espacio){
//            i = i - (i + 1);
//        }
//        i--;
//    }
//
//    if(posFinal <= 0){
//         for(int i = 0; i< posFinal;i++){
//            fflush(stdin);
//            auxCadena2[i] = auxCadena[i];
//        }
//        palabra = auxCadena2;
//    }




    return palabra;



}

string stringToNumber(string cadena){
  std::istringstream iss(cadena);
  std::string s;
  iss >> s;
  return s;
}
