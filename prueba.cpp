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
    vector <int> numbers;
    vector <int> numbers2;
    vector <int> :: iterator elemento;
    int i;
    bool bandera = true;
    numbers.push_back(5);
    numbers.push_back(6);
    numbers.push_back(1);
    numbers.push_back(8);
    numbers.push_back(4);

    cout << endl;
    cout << "numbers1"<< endl;
    showRAM(numbers);

    numbers2 = numbers;

    cout << "numbers2"<< endl;
    showRAM(numbers2);
    numbers2.at(0) += 1;
    numbers2.at(1) -= 2;
    cout << "numbers1"<< endl;
    showRAM(numbers);
    cout << "numbers2" << endl;
    showRAM(numbers2);

    if(bandera == false) cout << "Que pedo";

    return 0;
}