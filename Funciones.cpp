#include "Funciones.h"
#include <cstring>
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

string eliminarEspaciosDelComienzoYFinal(string cadena){
    cout << "Palbra: "<< cadena << endl;
//        cout <<"Palabra a la cual se eliminaran los espacios : "<<  cadena << endl;
        int posComienzo = 0;
        int posFinal = 0;
        char letra;
        char auxCadena[40];
        char subCadena[40];
        char espacio = ' ';
        int i = 0, tamanio = 0, j= 0;

        string palabra;
//Elimino los espacios al principio de la cadena
        while(i < cadena.length()){

          if(cadena[i] != espacio){
                i = cadena.length() +  1;
            }
           posComienzo++;
        }

         for(int i = 0; i< cadena.length(); i++) {
            fflush(stdin);
            auxCadena[i] = cadena[posComienzo++];
        }

    cout << "Palbra: "<< auxCadena << endl;

//Elimino los espacios al final de la cadena
        tamanio = strlen(auxCadena) -1 ;
        while(j == 0){
          if(auxCadena[tamanio] != espacio){
                posFinal = tamanio;
                j = 1;
            }
           tamanio--;
        }

//        cout << "Palabra: "<< auxCadena[posFinal-5] << endl;
        for(int i = 0; i<=posFinal; i++) {
            subCadena[i] = auxCadena[i];
        }

        cout << "Palbra: "<< subCadena << endl;
        palabra = subCadena;




    return palabra;
}
