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
int fondos, opc, rNum, apuesta;
char opcion, play;
int cartaUser[10], cartaCrupier[10], contadorCartas = 0, puntosUser = 0, puntosCrupier = 0;
string figuras[] = {"🍒", "7", "💎", "🍇", "🍉"}, slot[3];
int totalF = 5;

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    ifstream leyendo_archivo;

    leyendo_archivo.open("progreso.txt");

    if (leyendo_archivo.is_open())
    {
        leyendo_archivo >> fondos;
        leyendo_archivo.close();
    }
    else
    {
        fondos = 1000;
    }
    do
    {
        // Menú principal:
        cout << verde << "\n==============================\n" << reset
             << "------- " << azul << "UCA-BIT JACKPOT" << reset << " ------"
             << verde << "\n==============================\n" << reset;

        cout << verde << "\nFondos: " << reset << anaranjado << fondos << reset << endl;
        menuPrincipal();

        // Pidiendo opcion de juego
        cin >> opcion;

        //Abriendo archivo para progreso
        ofstream guardando_archivo;
        guardando_archivo.open("progreso.txt");
        switch (opcion)
        {
        case 'a':
        case 'A':
            // Black Jack
            cout << amarillo << "\n==============================\n" << reset
                 << "--------- " << rojo << "BLACK JACK" << reset << " ---------"
                 << amarillo << "\n==============================\n" << reset;
            indicacionesBJ();
            jugar();
            cin >> play;

            if (play == 's' || play == 'S')
            {
                apuesta = pedirApuesta(fondos);

                // Agregando 2 cartas aleatorias al usuario
                cartaUser[0] = numeroRandom(1, 9);
                Sleep(1000);
                cartaUser[1] = numeroRandom(1, 9);
                Sleep(500);

                // Agregando 2 cartas aleatorias al Crupier
                cartaCrupier[0] = numeroRandom(1, 9);
                Sleep(1000);
                cartaCrupier[1] = numeroRandom(1, 9);

                contadorCartas = 2;
                puntosUser = cartaUser[0] + cartaUser[1];

                // Visualizar cartas del crupier
                cout << "------------------------------------------------------";
                cout << azul << "\nCartas del Crupier: \n"
                     << reset
                     << cartaCrupier[0] << " (?) \n";

                do
                {
                    // Visualizar las 2 cartas del usuario
                    cout << "\n------------------------------------------------------";
                    cout << amarillo << "\nTus cartas son: " << reset << endl;

                    for (int i = 0; i < contadorCartas; i++)
                    {
                        cout << cartaUser[i] << " ";
                    }
                    // Visualizar puntos del usuario
                    cout << endl
                         << amarillo << "\nTus puntos son: " << reset << puntosUser << endl;
                    cout << "------------------------------------------------------\n";

                    // Robar o plantarse
                    cout << anaranjado << "\nOpciones: " << reset << endl
                         << "1. Robar una carta \n2. Plantarse" << endl
                         << "\nElija una opción: ";
                    // Usuario elije opcion
                    cin >> opc;
                    switch (opc)
                    {
                    case 1:
                        // robar carta
                        contadorCartas++;
                        for (int i = 0; i < contadorCartas; i++)
                        {
                            if (i == contadorCartas - 1)
                            {
                                cartaUser[i] = numeroRandom(1, 9);

                                puntosUser = puntosUser + cartaUser[i];
                            }
                        }
                        break;
                    case 2:
                        // plantarse
                        cout << "\n------------------------------------------------------";
                        cout << amarillo << "\nTe has plantado...\n"
                             << reset;
                        break;
                    default:
                        // Error
                        cout << rojo << "\nOpcion no válida, tiene que seleccionar una opcion\n"
                             << "entre 1 (robar carta) y 2 (plantarse)." << reset;

                        opc = 1;
                        break;
                    }

                } while (puntosUser < 21 && opc == 1);

                // comparando si el usuario perdio o gano
                if (puntosUser <= 21)
                {
                    contadorCartas = 2;
                    puntosCrupier = cartaCrupier[0] + cartaCrupier[1];

                    // jugada del crupier
                    while (puntosCrupier < 17)
                    {
                        contadorCartas++;

                        // tomando carta nueva
                        for (int i = 0; i < contadorCartas; i++)
                        {
                            if (i == contadorCartas - 1)
                            {
                                cartaCrupier[i] = numeroRandom(1, 9);

                                puntosCrupier = puntosCrupier + cartaCrupier[i];
                            }
                        }
                    }

                    cout << azul << "\n\nEl Crupier ha decidido plantarse...\n"
                         << reset << endl;

                    // Caso: empate
                    if (puntosUser == puntosCrupier)
                    {
                        cout << anaranjado << "Empate!!\n"
                             << "Ganaste: " << reset << apuesta / 2;

                        fondos = fondos + (apuesta / 2);
                    }
                    // Caso: Perder (crupier gana por puntos)
                    else if (puntosUser < puntosCrupier && puntosCrupier <= 21)
                    {
                        cout << anaranjado << "El Crupier gana, mejor suerte a la próxima.\n"
                             << "Perdiste: " << reset << apuesta;

                        fondos = fondos - apuesta;
                    }
                    // Caso: Ganar
                    else
                    {
                        cout << anaranjado << "Ganaste!!!\n"
                             << "Recibiste: " << reset << apuesta;

                        fondos = fondos + apuesta;
                    }
                }
                // Caso: perdir (usuario se pasa de 21 puntos)
                else
                {
                    cout << anaranjado << "\nCasi lo logras, sigue intentando.\n"
                         << "Perdiste: " << reset << apuesta;

                    fondos = fondos - apuesta;
                }
            }
            //Guardando progreso
            if (guardando_archivo.is_open())
            {
                guardando_archivo << fondos;
            }

            break;

        case 'b':
        case 'B':
            // Tragamonedas
            cout << amarillo << "\n==============================\n" << reset
                 << "-------- " << verde << "TRAGAMONEDAS" << reset << " --------"
                 << amarillo << "\n==============================\n" << reset;
            indicacionesTM();
            jugar();
            cin >> play;
            if (play == 's' || play == 'S')
            {
               apuesta = pedirApuesta(fondos);
                do
                {
                    cout << azul << "Presione " << reset << rojo << "1" << reset << azul << " para girar: " << reset;
                    cin >> opc;
                } while (opc != 1);
                cout << amarillo << "\n!?!---TRAGAMONEDAS---!?!\n"
                     << reset;
                // Generando Slots random
                for (int i = 0; i < 3; i++)
                {
                    int random = numeroRandom(0, totalF - 1);
                    slot[i] = figuras[random];
                    cout << " [" << slot[i] << "] ";
                    Sleep(1000);
                }
                // Caso: Se muestra 3 número 7
                if (slot[0] == "7" && slot[1] == "7" && slot[2] == "7")
                {
                    cout << verde << "\n++JACKPOT++" << reset
                         << "\nGANASTE " << anaranjado << apuesta * 2 << reset;
                    fondos = (fondos + apuesta * 2);
                }
                // Caso2: Se muestra 3 Figuras iguales
                else if (slot[0] == slot[1] && slot[1] == slot[2])
                {
                    cout << verde << "\n!!!Felicidades!!!" << reset
                         << "\nGANASTE " << anaranjado << apuesta << reset;
                    fondos = fondos + apuesta;
                }
                // Caso3: Se muestra 2 figuras iguales
                else if (slot[0] == slot[1] || slot[1] == slot[2] || slot[0] == slot[2])
                {
                    cout << endl
                         << verde << "\n!!Ganaste!! " << reset << anaranjado << apuesta / 2 << reset;
                    fondos = fondos + (apuesta / 2);
                }
                // Caso4: Las figuras no coinciden
                else
                {
                    cout << anaranjado << "\nSuerte a la próxima! :)" << reset;
                    fondos = fondos - apuesta;
                }
            }
            //Guardando progreso
            if (guardando_archivo.is_open())
            {
                guardando_archivo << fondos;
            }

            break;

        case 'c':
        case 'C':
            // Jackpot
            cout << amarillo << "\n==============================\n" << reset
                 << "----------- " << azul << "JACKPOT" << reset << " ----------"
                 << amarillo << "\n==============================\n" << reset;
            indicacionesJP();
            jugar();
            cin >> play;

            if (play == 'S' || play == 's')
            {
                cout << azul << "\nIngrese un numero del 1 al 20: " << reset;
                cin >> opc;

                if (opc >= 1 && opc <= 20)
                {
                    // Mostrar una cuenta regresiva
                    cout << azul << "\nEl numero ganador se revelara en...\n"
                         << reset;
                    for (int i = 5; i >= 1; i--)
                    {
                        cout << i << endl;
                        Sleep(500);
                    }

                    // Generar el numero random
                    rNum = numeroRandom(1, 20);
                    cout << azul << "\nEl numero ganador es:" << reset << amarillo << rNum << reset << endl;

                    // Hacer la comparacion de números
                    if (opc == rNum)
                    {
                        cout << verde << "\nGANASTE EL PREMIO GORDO! Tus creditos se han duplicado." << reset << endl;
                        cout << verde << "Tus fondos actuales son: " << fondos * 2 << reset << endl;
                        fondos=fondos*2;
                    }
                    else
                    {
                        cout << rojo << "\nPerdiste todos tus creditos." << reset << endl;
                        cout << rojo << "\nMejor suerte a la proxima!" << reset << endl;
                        cout << rojo << "\nTus fondos actuales son: 0" << reset << endl;
                        fondos=0;
                    }
                }

            }
            if (guardando_archivo.is_open())
            {
                guardando_archivo << fondos;
            }
            break;
        default:
            // Error
            cout << endl
                 << rojo << "******    OPCIÓN INVÁLIDA    ******" << reset << endl;
            break;
        }
        guardando_archivo.close();

        // Preguntas si quiere seguir jugando
        do
        {
            cout << endl
                 << azul << "\nDesea seguir jugando?" << reset << endl;
            cout << "1. Seguir jugando" << endl;
            cout << "2. Salir" << endl;
            cout << "Elige: ";
            cin >> opc;

            if (opc != 1 && opc != 2)
            {
                cout << rojo << "\nOpcion no valida. Vuelva a intentar." << reset << endl;
            }
        } while (opc != 1 && opc != 2);

    } while (opc == 1);

    cout << amarillo << "\n¡GRACIAS POR JUGAR!" << reset
         << "Vuelva pronto. ";
    return 0;
}
