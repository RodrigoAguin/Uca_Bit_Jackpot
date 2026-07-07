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
#define anaranjado "\033[38;5;214m"
#define reset "\033[0m"

using namespace std;

//  Variables:
int opc, rNum, apuesta, fondos = 1000;
char opcion, play;

int cartaUser[10], cartaCrupier[10], contadorCartas = 0, puntosUser = 0, puntosCrupier = 0;
string figuras[] = {"🍒", "7️", "💎", "🍇","🍉"}, slot [3];
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
        cout << "\n¿Cuánto desea apostar? (Sus fondos son: " <<fondos <<"): ";
        cin >> apuesta;
        if(apuesta>fondos ||apuesta<=0){
        cout<<rojo <<"\nApuesta inválida, intente de nuevo.\n" <<reset;
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

        //Visualizar cartas del crupier
        cout <<"------------------------------------------------------";
        cout <<azul << "\nCartas del Crupier: \n" <<reset
        << cartaCrupier[0] <<" (?) \n";

        do{
        //Visualizar las 2 cartas del usuario
        cout <<"\n------------------------------------------------------";
        cout <<amarillo <<"\nTus cartas son: " <<reset <<endl;
        
        for(int i = 0; i < contadorCartas; i++){
            cout << cartaUser[i] <<" ";
        }
        //Visualizar puntos del usuario
        cout <<endl <<amarillo <<"\nTus puntos son: " <<reset <<puntosUser <<endl;
        cout <<"------------------------------------------------------\n";
        
        //Robar o plantarse
        cout <<anaranjado <<"\nOpciones: "<<reset <<endl 
        <<"1. Robar una carta \n2. Plantarse" <<endl
        <<"\nElija una opción: ";
        //Usuario elije opcion
        cin >>opc;
        switch(opc)
        {
            case 1:
                //robar carta    
                contadorCartas++;
                for(int i = 0; i < contadorCartas; i++){
                    if(i == contadorCartas - 1)
                    {
                        cartaUser[i] = numeroRandom(1,9);

                        puntosUser = puntosUser + cartaUser[i];
                    }
                }
                break;
            case 2:
                //plantarse
                cout <<"\n------------------------------------------------------";
                cout <<amarillo <<"\nTe has plantado...\n" <<reset;
                break;
            default:
                //Error
                cout<<rojo <<"\nOpcion no válida, tiene que seleccionar una opcion\n"
                    <<"entre 1 (robar carta) y 2 (plantarse)." <<reset;
                
                    opc = 1;
                break;
        }

        }
        while(puntosUser < 21 && opc == 1);

        //comparando si el usuario perdio o gano
        if (puntosUser <= 21)
        {
            contadorCartas = 2;
            puntosCrupier = cartaCrupier[0] + cartaCrupier[1];
            
            //jugada del crupier
            while(puntosCrupier < 17)
            {
                contadorCartas++;

                //tomando carta nueva
                for(int i = 0; i < contadorCartas; i++)
                {
                    if(i == contadorCartas - 1)
                    {
                        cartaCrupier[i] = numeroRandom(1, 9);

                        puntosCrupier = puntosCrupier + cartaCrupier[i];
                    }
                }
            }

            cout <<azul << "\n\nEl Crupier ha decidido plantarse...\n" <<reset <<endl;

            //Caso: empate
            if(puntosUser == puntosCrupier)
            {
                cout <<anaranjado << "Empate!!\n"
                    <<"Ganaste: "<<reset <<apuesta/2;
                
                fondos = fondos + (apuesta/2);
            }
            //Caso: Perdiste (crupier gana por puntos)
            else if(puntosUser < puntosCrupier && puntosCrupier <= 21)
            {
                cout <<anaranjado <<"El Crupier gana, mejor suerte a la próxima.\n"
                    <<"Perdiste: " <<reset <<apuesta;

                fondos = fondos - apuesta;
            }
            //Caso: Ganaste
            else
            {
                cout <<anaranjado << "Ganaste!!!\n"
                    << "Recibiste: " <<reset <<apuesta;
                
                fondos = fondos + apuesta;
            }
        }
        //Caso: perdiste (usuario se pasa de 21 puntos)
        else
        {
            cout <<anaranjado <<"Casi lo logras, sigue intentando.\n"
                << "Perdiste: " <<reset <<apuesta;

            fondos = fondos - apuesta;
        }
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
            Sleep(1000);
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