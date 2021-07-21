#include <iostream>
#include <cstring>
using namespace std;

void CLEAR(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

#include "src/sistema.cpp"
#include "src/ToolsAux.cpp"
#include "src/usuario.cpp"
#include "src/menu.cpp"

int main(){
    
    system("pause");
    CLEAR();

    // funcion menu, la cual abre el menu principal
    menu();

    return 0;
}
