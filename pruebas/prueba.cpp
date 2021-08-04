#include <iostream>
#include <vector>
#include <iterator>
using namespace std;


void CLEAR(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void showRAM(vector <int> ram){
    vector <int> :: iterator e;
    int cont = 1;
    cout <<"particion      MB"<<endl;
    cout <<"\t-----------------"<<endl;
    for(e = ram.begin() ; e != ram.end() ; ++e){
        cout << cont << "\t|\t" << *e << "\t|" << endl;
        cout <<"\t-----------------"<<endl;
        cont++;
    }
}

int main(){
    cout << 2;

    return 0;
}