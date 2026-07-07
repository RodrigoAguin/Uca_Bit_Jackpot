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
string figuras[] = {"🍒", "7", "💎", "🍇","🍉"}, slot [3];
int totalF = 5;

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
cout <<azul <<"\n--- Indicaciones ---\n" <<reset;
    indicacionesTM();
    jugar();
    cin >> play;
if(play == 's' || play == 'S')
    {
      do{
        cout << "\n¿Cuánto desea apostar? Sus fondos son: " <<fondos <<": ";
        cin >> apuesta;
        if(apuesta>fondos ||apuesta<=0){
        cout<<"\nApuesta inválida, intente de nuevo.\n";
        }
        }
        while(apuesta>fondos ||apuesta<=0);
        do{
         cout<<azul <<"Presione "<<reset <<rojo <<"1" <<reset <<azul <<" para girar: " <<reset;
         cin>>opc;
        }
        while(opc!=1);
         cout<<amarillo <<"\n!?!---TRAGAMONEDAS---!?!" <<reset;
         for (int i = 0; i < 3; i++)
         {
            int random=numeroRandom(0,totalF-1);
            slot[i]=figuras[random];
            cout<<"\n[" <<slot[i] <<"]\n" ;
            Sleep(700);
         }
if(slot[0]=="7" && slot[1]=="7" && slot[2]=="7"){
cout<<"JACKPOT"
<<"\nGANASTE " <<apuesta*2;
fondos=(fondos+apuesta*2);
}
else if (slot[0]==slot[1] && slot[1]==slot[2]){
cout<<"!!!Felicidades!!!"
<<"\nGANASTE " <<apuesta;
fondos=fondos+apuesta;
}
else if(slot[0]==slot[1] || slot[1]==slot[2] || slot[0]==slot[2]){
cout<<"\n!!Ganaste!! " <<apuesta/2;
fondos=fondos+(apuesta/2);
}
else{
    cout<<"\nSuerte a la próxima! :)";
    fondos=fondos-apuesta;
}
    }
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
