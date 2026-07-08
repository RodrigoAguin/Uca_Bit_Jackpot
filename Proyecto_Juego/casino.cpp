#include <iostream>
#include <windows.h>
#include <fstream>
#include <random>
#include <ctime>
#include "funciones.h"

// Definición de colores para cout
#define verde "\033[1;32m"
#define rojo "\033[1;31m"
#define amarillo "\033[1;33m"
#define azul "\033[1;34m"
#define anaranjado "\033[38;5;214m"
#define reset "\033[0m"

using namespace std;

// Variables globales (Tu código original)
int opc, rNum, apuesta;
float fondos = 1000;
char opcion, play;

int cartaUser[10], cartaCrupier[10], contadorCartas = 0, puntosUser = 0, puntosCrupier = 0;
string figuras[] = {"🍒", "7️", "💎", "🍇", "🍉"}, slot[3];
int totalF = 5;

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    // =========================================================================
    // CAPA 1: CARGA DE DATOS (Al arrancar el programa)
    // =========================================================================
    ifstream archivoEntrada("progreso.txt");
    if (archivoEntrada.is_open())
    {
        archivoEntrada >> fondos; 
        archivoEntrada.close();
    }

    char jugarDeNuevo = 's';

    // =========================================================================
    // CAPA 2: BUCLE PRINCIPAL DE JUEGO (Game Loop)
    // =========================================================================
    do
    {
        cout << verde << "\n==============================\n"
             << reset
             << "------- " << azul << "UCA-BIT JACKPOT" << reset << " ------"
             << verde << "\n==============================\n"
             << reset;

        cout << verde << "\nFondos Disponibles: " << reset << anaranjado << "$" << fondos << reset << endl;
        menuPrincipal();

        cin >> opcion;

        switch (opcion)
        {
        case 'a':
        case 'A':
            // -----------------------------------------------------------------
            // JUEGO: BLACK JACK
            // -----------------------------------------------------------------
            puntosUser = 0;
            puntosCrupier = 0;

            cout << amarillo << "\n==============================\n"
                 << reset
                 << "------- " << verde << "BLACK JACK" << reset << " ------"
                 << amarillo << "\n==============================\n"
                 << reset;

            cout << azul << "\n--- Indicaciones ---\n"
                 << reset;
            indicacionesBJ();
            cout << azul << "\n¿Desea jugar?" << "(" << reset << verde << "S" << reset << azul << "/" << reset << rojo << "N" << reset << azul << "): " << reset;
            cin >> play;

            if (play == 's' || play == 'S')
            {
                do
                {
                    cout << "\n¿Cuánto desea apostar? (Sus fondos son: " << fondos << "): ";
                    cin >> apuesta;
                    if (apuesta > fondos || apuesta <= 0)
                    {
                        cout << rojo << "\nApuesta inválida, intente de nuevo.\n"
                             << reset;
                    }
                } while (apuesta > fondos || apuesta <= 0);

                cartaUser[0] = numeroRandom(1, 9);
                Sleep(1000);
                cartaUser[1] = numeroRandom(1, 9);
                Sleep(500);

                cartaCrupier[0] = numeroRandom(1, 9);
                Sleep(1000);
                cartaCrupier[1] = numeroRandom(1, 9);

                contadorCartas = 2;
                puntosUser = cartaUser[0] + cartaUser[1];

                cout << "------------------------------------------------------";
                cout << azul << "\nCartas del Crupier: \n"
                     << reset
                     << cartaCrupier[0] << " (?) \n";

                do
                {
                    cout << "\n------------------------------------------------------";
                    cout << amarillo << "\nTus cartas son: " << reset << endl;

                    for (int i = 0; i < contadorCartas; i++)
                    {
                        cout << cartaUser[i] << " ";
                    }
                    cout << endl
                         << amarillo << "\nTus puntos son: " << reset << puntosUser << endl;
                    cout << "------------------------------------------------------\n";

                    cout << anaranjado << "\nOpciones: " << reset << endl
                         << "1. Robar una carta \n2. Plantarse" << endl
                         << "\nElija una opción: ";
                    cin >> opc;
                    switch (opc)
                    {
                    case 1:
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
                        cout << "\n------------------------------------------------------";
                        cout << amarillo << "\nTe has plantado...\n"
                             << reset;
                        break;
                    default:
                        cout << rojo << "\nOpcion no válida, tiene que seleccionar una opcion\n"
                             << "entre 1 (robar carta) y 2 (plantarse)." << reset;
                        opc = 1;
                        break;
                    }

                } while (puntosUser < 21 && opc == 1);

                if (puntosUser <= 21)
                {
                    contadorCartas = 2;
                    puntosCrupier = cartaCrupier[0] + cartaCrupier[1];

                    while (puntosCrupier < 17)
                    {
                        contadorCartas++;
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

                    if (puntosUser == puntosCrupier)
                    {
                        cout << anaranjado << "Empate!!\n"
                             << "Ganaste: " << reset << apuesta / 2 << endl;
                        fondos = fondos + (apuesta / 2);
                    }
                    else if (puntosUser < puntosCrupier && puntosCrupier <= 21)
                    {
                        cout << anaranjado << "El Crupier gana, mejor suerte a la próxima.\n"
                             << "Perdiste: " << reset << apuesta << endl;
                        fondos = fondos - apuesta;
                    }
                    else
                    {
                        cout << anaranjado << "Ganaste!!!\n"
                             << "Recibiste: " << reset << apuesta << endl;
                        fondos = fondos + apuesta;
                    }
                }
                else
                {
                    cout << anaranjado << "Casi lo logras, sigue intentando (Te pasaste de 21).\n"
                         << "Perdiste: " << reset << apuesta << endl;
                    fondos = fondos - apuesta;
                }
            }
            break;

        case 'b':
        case 'B':
            // -----------------------------------------------------------------
            // JUEGO: TRAGAMONEDAS
            // -----------------------------------------------------------------
            cout << amarillo << "\n==============================\n" << reset
                 << "------- " << verde << "TRAGAMONEDAS" << reset << " ------"
                 << amarillo << "\n==============================\n" << reset;
            cout << azul << "\n--- Indicaciones ---\n" << reset;
            indicacionesTM();
            cout << azul << "\n¿Desea jugar?" << "(" << reset << verde << "S" << reset << azul << "/" << reset << rojo << "N" << reset << azul << "): " << reset;
            cin >> play;
            if (play == 's' || play == 'S')
            {
                do
                {
                    cout << "\n¿Cuánto desea apostar? Sus fondos son: " << anaranjado << fondos << reset << ": ";
                    cin >> apuesta;
                    if (apuesta > fondos || apuesta <= 0)
                    {
                        cout << rojo << "\nApuesta inválida, intente de nuevo.\n"
                             << reset;
                    }
                } while (apuesta > fondos || apuesta <= 0);
                do
                {
                    cout << azul << "Presione " << reset << rojo << "1" << reset << azul << " para girar: " << reset;
                    cin >> opc;
                } while (opc != 1);
                cout << amarillo << "\n!?!---TRAGAMONEDAS---!?!\n"
                     << reset;

                for (int i = 0; i < 3; i++)
                {
                    int random = numeroRandom(0, totalF - 1);
                    slot[i] = figuras[random];
                    cout << " [" << slot[i] << "] ";
                    Sleep(700);
                }

                if (slot[0] == "7️" && slot[1] == "7️" && slot[2] == "7️")
                {
                    cout << verde << "\n++JACKPOT++" << reset
                         << "\nGANASTE " << anaranjado << apuesta * 2 << reset << endl;
                    fondos = (fondos + apuesta * 2);
                }
                else if (slot[0] == slot[1] && slot[1] == slot[2])
                {
                    cout << verde << "\n!!!Felicidades!!!" << reset
                         << "\nGANASTE " << anaranjado << apuesta << reset << endl;
                    fondos = fondos + apuesta;
                }
                else if (slot[0] == slot[1] || slot[1] == slot[2] || slot[0] == slot[2])
                {
                    cout << verde << "\n!!Ganaste!! " << reset << anaranjado << apuesta / 2 << reset << endl;
                    fondos = fondos + (apuesta / 2);
                }
                else
                {
                    cout << azul << "\nSuerte a la próxima! :)\n" << reset;
                    fondos = fondos - apuesta;
                }
            }
            break;

        case 'c':
        case 'C':
            // -----------------------------------------------------------------
            // JUEGO NUEVO: RULETA DE LA FORTUNA "JACKPOT"
            // -----------------------------------------------------------------
            cout << verde << "\n=====================================\n" << reset
                 << "--- " << amarillo << "👑 MEGA JACKPOT ROULETTE 👑" << reset << " ---"
                 << verde << "\n=====================================\n" << reset;
            
            cout << azul << "Alinea tu suerte. Elige un sector de riesgo:\n" << reset
                 << "1. Sector Verde (Probabilidad: 50% | Paga: 2x)\n"
                 << "2. Sector Rojo  (Probabilidad: 35% | Paga: 3x)\n"
                 << "3. " << amarillo << "SECTOR GOLDEN JACKPOT" << reset << " (Probabilidad: 5% | Paga: " << anaranjado << "15x" << reset << ")\n"
                 << "\n¿Desea probar su suerte? (S/N): ";
            cin >> play;

            if (play == 's' || play == 'S')
            {
                do
                {
                    cout << "\n¿Cuánto deseas apostar? (Fondos: " << fondos << "): ";
                    cin >> apuesta;
                    if (apuesta > fondos || apuesta <= 0) {
                        cout << rojo << "Monto inválido.\n" << reset;
                    }
                } while (apuesta > fondos || apuesta <= 0);

                do
                {
                    cout << "\nSelecciona tu sector destino (1, 2 o 3): ";
                    cin >> opc;
                } while (opc < 1 || opc > 3);

                cout << amarillo << "\nGirando la ruleta ancestral...";
                for(int i = 0; i < 4; i++) { cout << " 🎡"; Sleep(500); }
                cout << reset << endl;

                // Generación del porcentaje del 1 al 100
                int resultadoRuleta = numeroRandom(1, 100);

                // Determinación del sector en el que cae la ruleta de forma interna
                int sectorGanador = 0;
                if (resultadoRuleta <= 50) {
                    sectorGanador = 1; // Cayó en Verde
                    cout << verde << "\n[La ruleta se detuvo en: SECTOR VERDE]\n" << reset;
                } else if (resultadoRuleta <= 85) {
                    sectorGanador = 2; // Cayó en Rojo
                    cout << rojo << "\n[La ruleta se detuvo en: SECTOR ROJO]\n" << reset;
                } else if (resultadoRuleta <= 90) {
                    sectorGanador = 4; // Casa gana por defecto (Cero del Casino)
                    cout << azul << "\n[La ruleta se detuvo en: SECTOR AZUL (CASA)]\n" << reset;
                } else {
                    sectorGanador = 3; // ¡JACKPOT!
                    cout << amarillo << "\n[✨ LA RULETA SE DETUVO EN EL ULTRA JACKPOT GOLDEN ✨]\n" << reset;
                }

                // Verificación de ganancias
                if (opc == sectorGanador)
                {
                    if (sectorGanador == 1) {
                        cout << verde << "¡Acertaste! Duplicas tu apuesta. +" << apuesta * 2 << reset << endl;
                        fondos = fondos + (apuesta * 2);
                    } else if (sectorGanador == 2) {
                        cout << verde << "¡Gran jugada! Triplicas tu dinero. +" << apuesta * 3 << reset << endl;
                        fondos = fondos + (apuesta * 3);
                    } else if (sectorGanador == 3) {
                        cout << amarillo << "¡💥 DIOS MÍO, CONSEGUISTE EL MULTIPLICADOR 15X! 💥 +" << apuesta * 15 << reset << endl;
                        fondos = fondos + (apuesta * 15);
                    }
                }
                else
                {
                    cout << rojo << "Tu predicción falló. Perdiste tu apuesta de: " << apuesta << reset << endl;
                    fondos = fondos - apuesta;
                }
            }
            break;

        default:
            cout << endl
                 << rojo << "****** OPCIÓN INVÁLIDA    ******" << reset << endl;
            break;
        }

        // =====================================================================
        // CAPA 3: VALIDACIÓN DE BANCARROTA Y CONTROL DE REPETICIÓN
        // =====================================================================
        if (fondos <= 0)
        {
            cout << rojo << "\n=============================================" << reset;
            cout << rojo << "\n ¡Te has quedado sin fondos! Fin de tu saldo.\n" << reset;
            cout << rojo << "=============================================\n" << reset;
            break; 
        }

        cout << azul << "\n¿Desea regresar al menú principal? (" << reset << verde << "S" << reset << azul << "/" << reset << rojo << "N" << reset << azul << "): " << reset;
        cin >> jugarDeNuevo;

    } while (jugarDeNuevo == 's' || jugarDeNuevo == 'S');

    // =========================================================================
    // CAPA 4: GUARDADO DE PROGRESO (Justo antes de apagar el programa)
    // =========================================================================
    ofstream archivoSalida("progreso.txt");
    if (archivoSalida.is_open())
    {
        archivoSalida << fondos; 
        archivoSalida.close();
        cout << verde << "\n[Progreso guardado automáticamente en progreso.txt]\n" << reset;
    }

    cout << azul << "\n¡Gracias por jugar en UCA-BIT JACKPOT! Vuelve pronto.\n\n" << reset;
    return 0;
}
