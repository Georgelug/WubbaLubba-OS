class Herramientas{
    public:
        Herramientas(){}

        int verificar(int valorInicial, int valorFinal, string frase){
            string tmp;
            int opc;
            bool flag = true;

            
            do{

                cout << frase <<endl;
                getline(cin,tmp);
                try{
                    opc = stoi(tmp);
                    if(opc < valorInicial || opc > valorFinal) 
                        throw exception();
                    else
                        flag = false;
                }
                catch(const std::exception& e){
                    flag = true;
                }

                
            } while (flag);
            

            return opc;
            
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
        
};
