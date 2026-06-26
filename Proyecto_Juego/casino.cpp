#include <iostream>
#include <windows.h>
#include <fstream>
#include <random>
#include <ctime>
#include "funciones.h"

//  definicion de colores para cout
#define verde "\033[1;32m"
#define rojo "\033[1;31m"
#define amarillo "\033[1;33m"
#define azul "\033[1;34m"
#define reset "\033[0m"

using namespace std;

//  Variables:
int fondos = 1000;
char opcion;

int main (){
SetConsoleOutputCP(CP_UTF8);

ofstream archivo;

archivo.open("progreso.txt");

if (archivo.is_open()){
    archivo <<" " <<endl;
    archivo.close();
}

//Menú principal:
    cout <<verde << "\n==============================\n" <<reset
    << "------- " << azul << "UCA-BIT JACKPOT" << reset << " ------"
    <<verde <<"\n==============================\n" <<reset;

    cout << verde << "\nFondos: " << reset << fondos << endl;
    menuPrincipal();
    
    //Pidiendo opcion de juego
    cin >> opcion;

    switch(opcion)
    {
        case 'a':
        case 'A':
            //Black Jack

            break;
        
        case 'b':
        case 'B':
            //Tragamonedas

            break;
        
        case 'c':
        case 'C':
            //Jackpot

            break;
        default:
            //Error
            cout <<endl <<rojo <<"******    OPCIÓN INVÁLIDA    ******" <<reset <<endl;
            break;
    }
return 0;
}