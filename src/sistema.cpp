class Sistema{
    
    public:
        ParticionamientoEstatico partEst;
        ParticionamientoDinamico partDina;
        Paginacion pag;
        Segmentacion seg;
        Sistema(){}
        string Bienvenida(){
            return "\n\n\t\aWubbaLubba-OS verion 1.0.0\n\nCopyleft 2021 Autor: Jorge Luis Esparza Fuentes\n\nEl uso de este sistema operativo queda libre a todo usuario sin fines de lucro\n\nqueda prohibida su venta o distribucion\n\n";
        }

        string Instrucciones(){
            return "\n\n################################\n\nexit: salir del sistema\n\nclear: limpiar pantalla\n\nh: instrucciones\n\np: ejecutar programa (por el momento solo se puede ejecutar la verificacion de los metodos de administracion de memoria).\n\nSe puede agregar las siguientes opciones:\n\n\te: verificar particionamiento estatico\n\n\td: verificar particionamiento dinamico\n\n\tp: verificar paginacion\n\n\ts: verificar segmentacion\n\n\tEjemplo de uso: W => Users => thisUser: p-p (en este caso se ejecuta el programa verificar paginacion)\n\nNOTA: por lo el momento solo estan disponibles esas instrucciones para esta version de WubbaLubba-OS ya que es solo una demo \n\n\n";
        }

        int checarBuffer(string buff){
            int pos;

            if (buff.compare("clear")== 0)
                return -3;
            if (buff.compare("exit")== 0)
                return -2;
            if(buff.empty() || buff.compare("p")== 0 || buff.compare(" ") == 0)
                return -1;
            if(buff.compare("h") == 0) return 0;

            try{
                pos = buff.find("-");
                buff.replace(pos,1,""); 
            }catch(const std::exception& e){}
            
            if(buff[0] == 'p'){

                switch (buff[1]){

                    case 'e': return 1;
                    case 'd': return 2;
                    case 'p': return 3;
                    case 's': return 4;
                    default: return -1;

                }
            }
            return -1;

        }

            bool llamarFuncionesOpc(int opc){
                if( opc == -1 )
                    return false;
                switch (opc){
                    
                    case 0:
                        cout << "\n\n\t INSTRUCCIONES" << endl;
                        cout << Instrucciones() << endl;
                        break;
                    case 1:
                        cout << "\n\n\t Ingresando a PARTICIONAMIENTO ESTATICO"<< endl;
                        partEst.inicio();
                        break;
                    case 2:
                        cout << "\n\n\t Ingresando a PARTICIONAMIENTO DINAMICO"<< endl;
                        partDina.inicio();
                        break;
                    case 3:
                        cout << "\n\n\t Ingresando a PAGINACION"<< endl;
                        pag.inicio();
                        break;
                    case 4:
                        cout << "\n\n\t Ingresando a SEGMENTACION"<< endl;
                        seg.inicio();
                        break;
                }
                return true;
            }

            void leerBuffer(string ruta){
                string instruccion;
                int opciones;
                cin.ignore();

                while(true){
                    cout << "\n" <<ruta << ": ";
                    getline(cin,instruccion);
                    opciones = checarBuffer(instruccion);
                    if(!llamarFuncionesOpc(opciones)){
                        cout << "\nERROR, comando incorrecto" << endl;
                    }

                    if(instruccion.compare("clear") == 0){
                        CLEAR();
                    }

                    if(instruccion.compare("exit") == 0)
                        break;
                }

            }

};
