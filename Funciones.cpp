#include "Funciones.h"
#include <cstring>
#include <iostream>
#include<string>



using namespace std;

string eliminarEspaciosDelComienzoYFinal(string cadena){
//        cout <<"Palabra a la cual se eliminaran los espacios : "<<  cadena << endl;
        int posComienzo = 0;
        int posFinal = 0;
        char letra;
        char auxCadena[40];
        char subCadena[40];
        char espacio = ' ';
        bool flag = false;
        string palabra;


        for(int i = 0; i< cadena.length(); i++) {
            letra = cadena[i];
            if(letra != espacio){
                posComienzo++;
                break;
            }

            posComienzo= i;
        }

//        cout << "Flag: " << cadena << endl;
        if(posComienzo != 0){
            for(int i = 0; i< cadena.length(); i++) {
                auxCadena[i] = cadena[posComienzo++];
            }
        }

//        cout << "Flag: " << auxCadena << endl;
//        cout << "Flag: " << auxCadena[0] << endl;

//        cout <<"Palabra ya limpia : "<<  auxCadena << endl;
        for(int i = strlen(auxCadena) - 1; i > 0 ; i--) {

                letra = auxCadena[i];
                if(letra != espacio){
                    break;
                }

                posFinal= i;
        }

         if(posFinal != 0 ){
            for(int i = 0; i<posFinal; i++) {
                subCadena[i] = auxCadena[i];
            }
        }
        palabra = subCadena;
//     cout <<"Palabra ya limpia : "<<  palabra << endl;



    return palabra;
}
