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
do {
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

        //Visualizar cartas del crupier
        cout <<azul << "\nCartas del Crupier: \n" <<reset
        << cartaCrupier[0] <<" (?) \n";

        do{
        //Visualizar las 2 cartas del usuario
        cout <<amarillo <<"\nTus cartas son: " <<reset <<endl;
        
        for(int i = 0; i < contadorCartas; i++){
            cout << cartaUser[i] <<" ";
        }
        //Visualizar puntos del usuario
        cout <<endl <<amarillo <<"\nTus puntos son: " <<reset <<puntosUser <<endl;
        
        //Robar o plantarse
        cout <<anaranjado <<"\nOpciones: "<<reset <<endl 
        <<"1. Robar una carta \n2. Plantarse" <<endl
        <<"\nElija una opción: " <<endl;
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
                break;
            deafult:
                break;
        }

        }
        while(puntosUser < 21 && opc == 1);
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
            cout <<amarillo << "\n==============================\n" <<reset
    << "------- " << verde << "JACKPOT" << reset << " ------"
    <<amarillo <<"\n==============================\n" <<reset;

    cout <<azul <<"\n--- Indicaciones ---\n" <<reset;
    indicacionesJP();
    jugar();
    cin >> play;

    if(play == 'S' || play == 's')
    {
            cout<< azul<<"\nIngrese un numero del 1 al 20:"<<reset;
            cin>> opc;

            if (opc>=1 && opc<=20)
            {
                //Mostrar una cuenta regresiva
                cout<< azul <<"\nEl numero ganador se revelara en...\n"<<reset;
                for(int i= 5; i >= 1; i--)
                {
                    cout <<i<<endl;
                }

                //Generar el numero random
                rNum = numeroRandom(1,20);
                cout<<azul<<"\nEl numero ganador es:"<< rNum<<reset<<endl;

                //Hacer la comparacion de numeros
                if(opc == rNum)
                {
                    fondos = fondos*2;
                    cout<<verde<<"\nGANASTE EL PREMIO GORDO! Tus creditos se han duplicado."<<reset<<endl;
                    cout<<verde<<"Tus fondos actuales son: "<<fondos<<reset<<endl;
                }
                else{
                    fondos=0;
                    cout<<rojo<<"\nPrediste todos tus creditos."<<reset<<endl;
                    cout<<rojo<<"\nMejor suerte a la proxima!"<<reset<<endl;
                    cout<<rojo<<"Tus fondos actuales son: "<<fondos<<reset<<endl;
                }
             }   //Preguntas si quiere seguir jugando
                do {
                    cout<<azul<<"\nDesea seguir jugando?"<<reset<<endl;
                    cout<<"1. Seguir jugando"<<endl;
                    cout<<"2. Salir"<<endl;
                    cout<<"Elige: ";
                    cin>> opc;

                    if(opc !=1 && opc !=2)
                    {
                        cout<<rojo<< "\nOpcion no valida. Vuelva a intentar."<<reset<<endl;
                    }
                 }
                 while(opc !=1 && opc!=2);

                //Si quiere seguir jugando
                if(opc==1){
                    menuPrincipal();
                }
                else{
                    ofstream archivo;
                    archivo.open("progreso.txt");

                    if(archivo.is_open())
                    {
                        archivo<<fondos;
                        archivo.close();
                    }
                    cout<<azul<<"\n¡GRACIAS POR JUGAR! Vuelva pronto."<<reset<<endl;
                    return 0;
                }

            
} break;
        default:
            //Error
            cout <<endl <<rojo <<"******    OPCIÓN INVÁLIDA    ******" <<reset <<endl;
            break;

            
}
}while(true);
return 0; }
    