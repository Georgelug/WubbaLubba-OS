#include <iostream>
using namespace std;


void CLEAR(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main(){
    string instruccion;
    string salto = "\n";
    CLEAR();
    // do{
    //     cin.ignore();
    //     cout << "\tintruccion" << ": ";
    //     getline(cin,instruccion);
    // }while(instruccion.empty() || !instruccion.compare("exit"));

    while(true){
        cout << "\tintruccion" << ": ";
        getline(cin,instruccion);
        cin.ignore();
        if(instruccion.compare("exit") == 0)
            break;
    }


    return 0;
}