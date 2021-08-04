class Herramientas{
    public:
        Herramientas(){}

        int verificar(int valorInicial, int valorFinal, string frase){
            string tmp;
            int opc;
            bool flag = true;

            
            do{

                cout << frase <<"\n\t: ";
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
            cout <<"particion      kB"<<endl;
            cout <<"\t-----------------"<<endl;
            for(e = ram.begin() ; e != ram.end() ; ++e){
                cout << cont << "\t|\t" << *e << "\t|" << endl;
                cout <<"\t-----------------"<<endl;
                cont++;
            }
        }
        
        void showRAM(vector <Pagina> ram,int num){
            int i;
            cout <<"Pagina        kB"<<endl;
            cout <<"\t-----------------"<<endl;
            for(i = 0 ; i< ram.size() ; i++){
                cout << i+1 << "\t|\t" << (ram.at(i)).getProceso() << "\t|" << endl;
                cout <<"\t-----------------"<<endl;
            }
        }
        void showRAM(vector <ProcesoSegmento> ram,int num,int num2){
            int i;
            cout <<"Proceso        kB"<<endl;
            cout <<"\t-----------------"<<endl;
            for(i = 0 ; i< ram.size() ; i++){
                cout << i+1 << "\t|   \t" << (ram.at(i)).getProceso() << "\t|" << endl;
                cout << " \t|SD:\t " << (ram.at(i)).getDatos() << "\t|" << endl;
                cout << " \t|SC:\t " << (ram.at(i)).getCodigo() << "\t|" << endl;
                cout << " \t|SP:\t " << (ram.at(i)).getPila() << "\t|" << endl;
                cout <<"\t-----------------"<<endl;
            }
        }
        
};
