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
            ram.clear();
        }

        void configuracionInicial(){
            int cont, res ;
            res = t.verificar(1,2,"\n\n\tPresiona (1) para iniciar la configuracion inicial o (2) para salir");
            while(res == 1){
                CLEAR();
                this->sizePagina = t.verificar(1,64,"\n\n\tIngresa el tamanio en kB que van llevar cada marco de pagina (minimo 1 kB, maximo 64 kB): ");
                this->numPaginas = getProcesos()/this->sizePagina;
                cout << "\n\n\tLa memoria principal fue divida en " << this->numPaginas << " marcos de pagina" << endl;

                res = t.verificar(1,2,"\n\n\tPresiona (1) para volver configurar o (2) para confirmar");
            }
            paginarRAM();
        }
        bool asignarProceso(int marcosLibres, int resto, int proceso){
            if(marcosLibres < 1) return false;
            
            vector <Pagina> :: iterator i;

            for ( i = ram.begin() ; i != ram.end(); ++i){
                if((*i).getOcupada() == false){
                    (*i).ingresarProceso(proceso);
                    (*i).ingresarProceso(resto);
                    return true;
                    // aqui me quedo, ya no aguanto
                }
            }
            


        }

        void paginarRAM(){
            int i;
            for(i=0;i<this->numPaginas;i++){
                Pagina tmp(this->sizePagina);
                ram.push_back(tmp);
            }
        
        }

        void simulacion(){
            int res, marcosLibres,tmpProceso = 0, tmpResto;
            res = t.verificar(1,2,"\n\n\tPresiona (1) para iniciar la simulacion o (2) para salir");
            while(res == 1){
                marcosLibres = this->numPaginas;
                CLEAR();
                limpiarRAM();
                while(true){
                    CLEAR();
                    t.showRAM(ram,1);
                    cout << "\n\n\tMarcos disponibles: " << marcosLibres << "\tProceso interior ingresado: " << tmpProceso << " kB" << endl;
                    tmpProceso = t.verificar(1,1024,"\n\n\tIngresa un proceso en kB: ");
                    marcosLibres -= (int)(tmpProceso/this->sizePagina);
                    tmpResto = tmpProceso % this->sizePagina;
                    if(tmpResto > 0)
                        marcosLibres --;
                    if(marcosLibres < 1){
                        cout << "\n\n\tMemoria insuficiente" << endl;
                        break;
                    }
                }
                cout << "\n\n\tResultados" << endl;
                t.showRAM(ram,1);
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