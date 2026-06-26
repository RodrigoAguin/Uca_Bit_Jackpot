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
int rNum, apuesta, fondos = 1000;
char opcion, play;

int cartaUser[10], cartaCrupier[10], contadorCartas = 0, puntosUser = 0;
string figuras[4] = {"♠", "7", "♦", "$"}, slot [3];

int main (){
SetConsoleOutputCP(CP_UTF8);

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
    cout <<amarillo << "\n==============================\n" <<reset
    << "------- " << verde << "BLACK JACK" << reset << " ------"
    <<amarillo <<"\n==============================\n" <<reset;

    cout <<azul <<"\n--- Indicaciones ---\n" <<reset;
    indicacionesBJ();
    jugar();
    cin >> play;

    if(play == 's' || play == 'S')
    {
        do{
        cout << "¿Cuánto desea apostar? (Sus fondos son: " <<fondos <<") ";
        cin >> apuesta;
        if(apuesta>fondos ||apuesta<=0){
        cout<<"\nApuesta inválida, intente de nuevo.\n";
        }
        }
        while(apuesta>fondos ||apuesta<=0);

        //Agregando 2 cartas aleatorias al usuario
        cartaUser[0] = numeroRandom(1,9);
        Sleep(1000);
        cartaUser[1] = numeroRandom(1,9);
        Sleep(500);

        //Agregando 2 cartas aleatorias al Crupier
        cartaCrupier[0] = numeroRandom(1,9);
        Sleep(1000);
        cartaCrupier[1] = numeroRandom(1,9);

        contadorCartas = 2;
        puntosUser = cartaUser[0] + cartaUser[1];

        cout << "\nCartas del Crupier: \n"
        << cartaCrupier[0] <<" (?) \n";

        //Temporal: visualizar las 2 cartas del usuario
        cout <<"Tus cartas: " <<cartaUser[0] <<" " <<cartaUser[1];
    }

            break;
    
        case 'b':
        case 'B':
            //Tragamonedas           
    cout <<amarillo << "\n==============================\n" <<reset
    << "------- " << verde << "TRAGAMONEDAS" << reset << " ------"
    <<amarillo <<"\n==============================\n" <<reset;
    
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
    cout <<verde << "\n==============================\n" <<reset
    << "------- " << azul << "JACKPOT" << reset << " ------"
    <<verde <<"\n==============================\n" <<reset;
            break;
        default:
            //Error
            cout <<endl <<rojo <<"******    OPCIÓN INVÁLIDA    ******" <<reset <<endl;
            break;
            return 0;
}
    }
