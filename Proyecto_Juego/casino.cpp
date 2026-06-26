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
int rNum, fondos = 1000;
char opcion;

char figuras[4] = {'%', '7', '&', '$'}, slot [3];

int main (){
SetConsoleOutputCP(CP_UTF8);

    //randomizador

    

/*
    unsigned rand = time(nullptr);
    mt19937 nrandom(rand);
    uniform_int_distribution<int> distribucion(randNum1, randNum2);
    
    rNum = distribucion(nrandom);
*/
    ofstream archivo;

    archivo.open("progreso.txt");

    if (archivo.is_open())
    {
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
            
            slot[0] = figuras [numeroRandom(0, 3)];
            cout <<slot[0];
            Sleep(1000);
            slot[1] = figuras [numeroRandom(0, 3)];
            cout <<slot[1];
            Sleep(1000);
            slot[2] = figuras [numeroRandom(0, 3)];
            cout <<slot[2];

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