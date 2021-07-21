class Herramientas{
    public:
        Herramientas(){}

        int verificar(int valorInicial, int valorFinal, string frase){
            string tmp;
            int opc;
            bool flag = true;

            CLEAR();
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

                CLEAR();
            } while (flag);
            

            return opc;
            
        } 
        
};
