class Herramientas{
    public:
        Herramientas(){}

        int verificar(int valorInicial, int valorFinal, string frase){
            int opc;
            CLEAR();
            cin.ignore();
            cout << frase <<endl;
            cin >> opc;
            while (opc < valorInicial || opc > valorFinal){
                CLEAR();
                cin.ignore();
                cout <<"\n\n\tEror,intentalo de nuevo \n\n"<< frase <<endl;
                cin >> opc;
            }
            
        } 
        
        int checarBuffer(string buff){
            char arr[2];
            int i;
            if(buff.empty())
                return -1;

            for ( i = 0; i < buff.lenght(); i++){
                if(buff[i]!='-')
                    arr[i] = buff[i];
            }

            return ((arr[0] == 'h') ? 
                    0:
                        (arr[0] == 'p') ?
                        (arr[1] == 'e') ?
                        1:
                            (arr[1] == 'd') ?
                            2:
                                (arr[1] == 'p') ?
                                3:
                                    (arr[1] == 's') ?
                                    4:
                                        -1:-1);
        }

        void leerBuffer(string ruta){
            string instruccion;
            string salto = "\n";
            do{
                cin.ignore();
                cout << ruta << ": ";
                getline(cin,instruccion);
            }while(instruccion.compare(salto))

        }
};
