#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include <cmath>
using namespace std;

void CLEAR(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

#include "src/Pagina.cpp"
#include "src/ToolsAux.cpp"
#include "src/usuario.cpp"
#include "src/Segmentacion.cpp"
#include "src/Paginacion.cpp"
#include "src/ParticionamientoEstatico.cpp"
#include "src/ParticionamientoDinamico.cpp"
#include "src/metodosMemoria.cpp" 
#include "src/sistema.cpp"
#include "src/menu.cpp"

int main(){
    
    system("pause");
    CLEAR();

    // funcion menu, la cual abre el menu principal
    menu();

    return 0;
}
