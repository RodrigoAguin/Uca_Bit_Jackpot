#include "funciones.h"
#include <iostream>
#include <random>
#include <ctime>

using namespace std;
//Funciones

//Generar numero random
int numeroRandom (int randNum1, int randNum2){
    unsigned rand = time(nullptr);
    mt19937 nrandom(rand);
    uniform_int_distribution<int> distribucion(randNum1, randNum2);
    
    return distribucion(nrandom);
}

//Menus
void menuPrincipal ()
{
    cout << endl << "Menú de juegos: \n\n a. Black Jack \n b. Tragamonedas \n c. Jackpot (todo o nada)" << endl;
    cout <<"\nIntroduzca una opción: \n";
};

//Indicaciones Juegos
void indicacionesBJ ()
{
cout << "Se le entregarán 2 cartas a usted y 2 al crupier, si\n"
<< "sus cartas suman más de 21, pierde automáticamente,\n"
<< "si no, puede robar una carta del mazo para llegar lo más\n"
<< "cerca posible. Al final, cuando decida plantarse, tanto el\n"
<< "crupier como ustedmostrarán sus cartas, el que\n"
<< "se acerque más a 21 (o tenga 21) gana.\n";
}

void indicacionesJP()
{
    cout<< "Se le pedira un numero aleatorio del 1 al 20.\n"
    << "Si acierta, ganara el doble de TODOS sus creditos actuales.\n"
    << "Si falla, perdera todos sus creditos.\n";
}

//Decision jugar
void jugar ()
{
    cout << "\n¿Desea jugar? (S/N): ";
}