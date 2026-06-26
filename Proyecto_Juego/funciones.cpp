#include "funciones.h"
#include <iostream>
#include <random>
#include <ctime>

using namespace std;
//Funciones

int numeroRandom (int randNum1, int randNum2){
    unsigned rand = time(nullptr);
    mt19937 nrandom(rand);
    uniform_int_distribution<int> distribucion(randNum1, randNum2);
    
    return distribucion(nrandom);
}

void menuPrincipal ()
{
    cout << endl << "Menú de juegos: \n\n a. Black Jack \n b. Tragamonedas \n c. Jackpot (todo o nada)" << endl;
    cout <<"\nIntroduzca una opción: \n";
};