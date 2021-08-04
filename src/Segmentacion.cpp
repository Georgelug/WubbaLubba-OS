class Segmentacion {

    // atributos
    private:
        int so = 1024;
        int procesos = 3072;

    public:
        Herramientas t;
        vector <ProcesoSegmento> ram;
        vector <ProcesoSegmento> :: iterator e;

    public:
        //constructor
        Segmentacion(){}

        // getters & setters
        int getSo(){ return this->so; }
        int getProcesos(){ return this->procesos; }
        void setSo(int so) { this->so = so; }
        void setProcesos(int procesos){ this->procesos = procesos; }

        //metodos
        void limpiarRAM(){
            ram.clear();
        }

        bool asignarProceso(int proceso , int tmpProcesos){
            if(tmpProcesos < 1) return false;

            ProcesoSegmento tmp(proceso);
            ram.push_back(tmp);
            return true;
        }

        void simulacion(){
            int res, tmpProceso, tmpProcesos, flag;
            res = t.verificar(1,2,"\n\n\tPresiona (1) para iniciar la simulacion o (2) para salir");
            while(res == 1){
                tmpProcesos = getProcesos();
                tmpProceso = 0;
                CLEAR();
                limpiarRAM();
                while(true){
                    CLEAR();
                    t.showRAM(ram,1,1);
                    cout << "\n\n\tMemoria restante: " << tmpProcesos << " kB\tProceso interior ingresado: " << tmpProceso << " kB" << endl;
                    tmpProceso = t.verificar(1,3072,"\n\n\tIngresa un proceso en kB: ");
                    tmpProcesos -= tmpProceso;
                    flag = asignarProceso(tmpProceso, tmpProcesos);
                    if(flag == false || tmpProceso < 1){
                        cout << "\n\n\tMemoria insuficiente" << endl;
                        break;
                    }
                }
                cout << "\n\n\tResultados" << endl;
                t.showRAM(ram,1,1);
                res = t.verificar(1,2,"\n\n\tPresiona (1) para reiniciar la simulacion o (2) para salir");
            }

        }

        void inicio(){
            int res;
            CLEAR();
            res = t.verificar(1,2,"\n\n\tPresiona (1) para iniciar el programa o (2) para salir");
            while(res == 1){
                CLEAR();
                cout << "\n\n\tSEGMENTACION";
                simulacion();
                CLEAR();
                res = t.verificar(1,2,"\n\n\tPresiona (1) para continuar en el programa o (2) para salir");
            }
        }


};