#include <iostream>
#include <windows.h>
#include "funciones.h"
#include <fstream>
using namespace std;
int main (){
SetConsoleOutputCP(CP_UTF8);
ofstream archivo;
archivo.open("progreso.txt");
if (archivo.is_open()){
    archivo <<" " <<endl;
    archivo.close();
}
return 0;
}