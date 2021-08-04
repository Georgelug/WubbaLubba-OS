class Paginacion{
    private:
        int so = 1024;
        int procesos = 1024;

    public:
        vector <Pagina> ram;
        int sizePagina;
        int numPaginas;
        Herramientas t;
    
    public:

        Paginacion(){}

        // getters & setters
        int getSo(){ return this->so; }
        int getProcesos(){ return this->procesos; }
        void setSo(int so) { this->so = so; }
        void setProcesos(int procesos){ this->procesos = procesos; }

        // metodos
        void limpiarRAM(){
            int i;
            for(i= 0 ; i < this->ram.size() ; i++){
                this->ram.at(i).vaciarPagina(this-> sizePagina);
            }
        }

        void setSizePagina(int opc){
            this-> sizePagina = pow(2,(opc-1));
        }

        void configuracionInicial(){
            int cont, res ;
            res = t.verificar(1,2,"\n\n\tPresiona (1) para iniciar la configuracion inicial o (2) para salir");
            while(res == 1){
                CLEAR();
                setSizePagina(t.verificar(1,7,"\n\n\tIngresa un opcion del tamanio que van a llevar cada marco de pagina \n\n\t1) 1kB 2) 2kB \n\t3) 4kB 4) 8kB\n\t5) 16kB 6) 32kb\n\t7) 64kB"));
                this->numPaginas = getProcesos()/this->sizePagina;
                cout << "\n\n\tLa memoria principal fue divida en " << this->numPaginas << " marcos de pagina" << endl;

                res = t.verificar(1,2,"\n\n\tPresiona (1) para volver configurar o (2) para confirmar");
            }
            paginarRAM();
            t.showRAM(this->ram,1);
        }

        bool verificarRamOcupada(){
            int i;
            for(i = 0 ; i< ram.size() ; i++)
                if(ram.at(i).getOcupada() == false) return false;

            return true;
        }

        bool asignarProceso(int marcosLibres, int resto, int proceso, int numMarcosProceso){
            if(marcosLibres < 0 || verificarRamOcupada() == true) return false;
            int i;
            for(i = 0; i < ram.size() ; i++){
                if(ram.at(i).getOcupada() == false && numMarcosProceso > 0){
                    if(resto > 0 && numMarcosProceso == 1){
                        ram.at(i).ingresarProceso(resto);
                    }else{
                        ram.at(i).ingresarProceso(this->sizePagina);
                    }
                    numMarcosProceso--;
                }
            }
            return true;
        }

        void paginarRAM(){
            int i, cont = 0;
            for(i=0;i<this->numPaginas;i++){
                CLEAR();
                Pagina tmp(this->sizePagina);
                ram.push_back(tmp);
                cont++;
            }
            if(ram.empty()){
                cout << "\n\n\t RAM not found" << endl;
            }else{
                cout << "\n\n\tnumero total de paginas: " << ram.size() << endl;
                system("pause");
            }
            
        }

        void simulacion(){
            int res, marcosLibres,tmpProceso = 0, tmpResto, numMarcosProceso, espacioDisponible;
            bool flag = true;
            res = t.verificar(1,2,"\n\n\tPresiona (1) para iniciar la simulacion o (2) para salir");
            while(res == 1){
                marcosLibres = this->numPaginas;
                tmpProceso = 0;
                espacioDisponible = getProcesos(); 
                CLEAR();
                limpiarRAM();
                while(true){
                    CLEAR();
                    if(marcosLibres < 0 || flag == false){
                        cout << "\n\n\tMemoria insuficiente" << endl;
                        break;
                    }
                    t.showRAM(this->ram,1);
                    cout << "\n\n\tEspacio disponible"<< espacioDisponible <<" kB\tMarcos disponibles: " << marcosLibres << "\tProceso anterior ingresado: " << tmpProceso << " kB" << endl;
                    tmpProceso = t.verificar(1,1024,"\n\n\tIngresa un proceso en kB: ");
                    numMarcosProceso = (int)(tmpProceso/this->sizePagina);
                    marcosLibres -= numMarcosProceso;
                    tmpResto = tmpProceso % this->sizePagina;
                    if(tmpResto > 0){
                        marcosLibres --;
                        numMarcosProceso++;
                    }
                    flag = asignarProceso(marcosLibres, tmpResto, tmpProceso, numMarcosProceso);
                    espacioDisponible-= tmpProceso;
                    
                }
                cout << "\n\n\tResultados" << endl;
                t.showRAM(this->ram,1); // arreglar la impresion de la ram
                res = t.verificar(1,2,"\n\n\tPresiona (1) para reiniciar la simulacion o (2) para salir");
            }

        }

        void inicio(){
            int res;
            CLEAR();
            res = t.verificar(1,2,"\n\n\tPresiona (1) para iniciar el programa o (2) para salir");
            while(res == 1){
                CLEAR();
                cout << "\n\n\tPAGINACION";
                configuracionInicial();
                CLEAR();
                simulacion();
                CLEAR();
                res = t.verificar(1,2,"\n\n\tPresiona (1) para continuar en el programa o (2) para salir");
            }
        }


};