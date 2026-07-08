#include "funciones.h"
#include <iostream>
#include <random>
#include <ctime>

// Definiendo colores para las funciones
#define verde "\033[1;32m"
#define rojo "\033[1;31m"
#define amarillo "\033[1;33m"
#define azul "\033[1;34m"
#define anaranjado "\033[38;5;214m"
#define reset "\033[0m"

using namespace std;
// Funciones

// Generar numero random
static mt19937 nrandom(time(nullptr));
int numeroRandom(int randNum1, int randNum2)
{
    uniform_int_distribution<int> distribucion(randNum1, randNum2);
    return distribucion(nrandom);
}

// Menus
void menuPrincipal()
{
    cout << amarillo << "\nMenú de juegos:\n"
         << reset << rojo << "\n a. Black Jack" << reset << verde << "\n b. Tragamonedas" << reset << azul << "\n c. Jackpot (todo o nada)\n"
         << reset;
    cout << "\nIntroduzca una opción: ";
};

// Indicaciones Juegos
void indicacionesBJ()
{
    cout << anaranjado << "\n--- Indicaciones ---\n"
         << reset;
    cout << "Se le entregarán 2 cartas a usted y 2 al crupier, si\n"
         << "sus cartas suman más de 21, pierde automáticamente,\n"
         << "si no, puede robar una carta del mazo para llegar lo más\n"
         << "cerca posible. Al final, cuando decida plantarse, tanto el\n"
         << "crupier como usted mostrarán sus cartas, el que\n"
         << "se acerque más a 21 (o tenga 21) gana.\n";
}

void indicacionesTM()
{
    cout << anaranjado << "\n--- Indicaciones ---\n"
         << reset;
    cout << "A continuación podrá girar la máquina, si\n"
         << "logra alinear 3 figuras iguales en fila, ganará\n"
         << "toda su apuesta, si logra alinear 2 figuras iguales,\n"
         << "ganará la mitad de su apuesta, sino, perderá su\n"
         << "apuesta.\n"
         << "\nNota: Si logra alinear los tres 7,\n"
         << "obtendrá el doble de su apuesta\n";
}

void indicacionesJP()
{
    cout << anaranjado << "\n--- Indicaciones ---\n"
         << reset;
    cout << "Se le pedira un numero aleatorio del 1 al 20.\n"
         << "Si acierta, ganara el doble de TODOS sus creditos actuales.\n"
         << "Si falla, perdera todos sus creditos.\n";
}

// Decision jugar
void jugar()
{
    cout << azul << "\n¿Desea jugar?" << "(" << reset << verde << "S" << reset << azul << "/" << reset << rojo << "N" << reset << azul << "): " << reset;
}

//
int pedirApuesta(int fondos)
{
    int apuesta;
    do
    {
        cout << "\n¿Cuánto desea apostar? (Sus fondos son: " << anaranjado << fondos << reset << "): ";
        cin >> apuesta;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
        }
        if (apuesta > fondos || apuesta <= 0)
        {
            cout << rojo << "\nApuesta inválida, intente de nuevo.\n"
                 << reset;
        }
    } while (apuesta > fondos || apuesta <= 0);
    return apuesta;
}
