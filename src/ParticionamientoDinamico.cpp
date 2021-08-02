class ParticionamientoDinamico{

    // atributos
    private:
        int so = 2048;
        int procesos = 2048;

    public:
        Herramientas t;
        vector <int> ram;
        vector <int> :: iterator elemento;

    public:
        //constructor
        ParticionamientoDinamico(){}

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

            ram.push_back(proceso);
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
                    t.showRAM(ram);
                    cout << "\n\n\tMemoria restante: " << tmpProcesos << " kB\tProceso interior ingresado: " << tmpProceso << " kB" << endl;
                    tmpProceso = t.verificar(1,2048,"\n\n\tIngresa un proceso en kB: ");
                    tmpProcesos -= tmpProceso;
                    flag = asignarProceso(tmpProceso, tmpProcesos);
                    if(flag == false || tmpProceso < 1){
                        cout << "\n\n\tMemoria insuficiente" << endl;
                        break;
                    }
                }
                cout << "\n\n\tResultados" << endl;
                t.showRAM(ram);
                res = t.verificar(1,2,"\n\n\tPresiona (1) para reiniciar la simulacion o (2) para salir");
            }

        }

        void inicio(){
            int res;
            CLEAR();
            res = t.verificar(1,2,"\n\n\tPresiona (1) para iniciar el programa o (2) para salir");
            while(res == 1){
                CLEAR();
                cout << "\n\n\tPARTICIONAMIENTO DINAMICO";
                simulacion();
                CLEAR();
                res = t.verificar(1,2,"\n\n\tPresiona (1) para continuar en el programa o (2) para salir");
            }
        }


};