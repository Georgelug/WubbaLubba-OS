class ParticionamientoEstatico{
    // Atributos
    private:
        int so = 2048;
        int procesos = 2048;
        int RAM_total = so + procesos;

    public:
        int numParticiones;
        int maxSpace;
        int minSpace;
        Herramientas t;
        vector <int> ram;
        vector <int> tmpRam;
        vector <bool> ramFragmentada;
        vector <int> :: iterator elemento;

    // getters & setters
    public:
        ParticionamientoEstatico(){}

        void setSo(int so){
            this->so = so;
        }
        void setProcesos(int procesos){
            this->procesos = procesos;
        }

        int getSo(){
            return this->so;
        }
        int getProcesos(){
            return this->procesos;
        }

        void setMaxSpace(){
            int i;
            maxSpace = ram.front();

            for(i=0 ; i< (ram.size()) ; i++){
                if(maxSpace < ram.at(i)){
                    maxSpace = ram.at(i);
                }
            }

        }
        void setMinSpace(){
            int i;
            minSpace = ram.front();

            for(i=0 ; i< (ram.size()) ; i++){
                if(minSpace > ram.at(i)){
                    minSpace = ram.at(i);
                }
            }

        }


        void configuracionInicial(){
            int cont, res , tmpsize , tmpEspacio;
            res = t.verificar(1,2,"\n\n\tPresiona (1) para configurar las particiones o (2) para salir");
            while(res == 1){
                cont = 1;
                tmpEspacio = getProcesos();
                CLEAR();
                this->numParticiones = t.verificar(1,128,"\n\n\tNumero de particiones (minimo una, maximo 128): ");
                system("pause");
                CLEAR();
                cout << "\n\n\tIngresa en kB el espacio requerido para cada particion\n" << endl;
                
                while(cont < this->numParticiones){
                    cout << "\n\n\tParticion " << cont << "\n\n\tEspacio sin particionar disponible: " << tmpEspacio << endl;
                    tmpsize = t.verificar(1,tmpEspacio,"Ingresa en kB el espacio para esta particion: ");
                    tmpEspacio -= tmpsize;
                    ram.push_back(tmpsize);
                    ramFragmentada.push_back(false);
                    cont++;
                    if(tmpEspacio < 1){
                        break;
                    }
                }

                if(tmpEspacio > 0){
                    ram.push_back(tmpEspacio);
                    ramFragmentada.push_back(false);
                }

                t.showRAM(ram);

                res = t.verificar(1,2,"\n\n\tPresiona (1) para volver configurar las particiones o (2) para confirmar");
            }
            setMinSpace();
            setMaxSpace();
            
        }

        void limpiarRAM(){
            int i;
            tmpRam = ram;
            for(i=0 ; i< ramFragmentada.size() ;i++){
                ramFragmentada.at(i) = false;
            }
        }

        bool verificarRamOcupada(){
            vector <bool> :: iterator i;
            for(i = ramFragmentada.begin() ; i != ramFragmentada.end() ; ++i){
                
                if(*i == false) return false;
            }
            return true;
        }


        bool asignarProceso(int proceso){
            int i;
            if(verificarRamOcupada() == true) return false;

            for(i=0 ; i<tmpRam.size() ;i++){

                if(proceso <= tmpRam.at(i) && tmpRam.at(i) == maxSpace && ramFragmentada.at(i) == false){
                    tmpRam.at(i) -= proceso;
                    ramFragmentada.at(i) = true;
                    cout << "Proceso asignado a la particion " << i+1 << endl;
                    return true;
                }
            }

            for(i=0 ; i<tmpRam.size() ;i++){
                if(proceso <= tmpRam.at(i) && ramFragmentada.at(i) == false){
                    tmpRam.at(i) -= proceso;
                    ramFragmentada.at(i) = true;
                    cout << "Proceso asignado a la particion " << i+1 << endl;
                    return true;
                }
            }
            return false;
        }

        void simulacion(){
            int res, i, tmpProceso = 0;
            res = t.verificar(1,2,"\n\n\tPresiona (1) para iniciar la simulacion o (2) para salir");
            while(res == 1){

                CLEAR();
                limpiarRAM();
                for(i = 0 ; i< ram.size() ; i++){
                    CLEAR();
                    t.showRAM(tmpRam);
                    cout << "\n\t Proceso anterior ingresado: " << tmpProceso << " kB" << endl;
                    cout << "\n\n\tParticion " << i+1 << endl;
                    tmpProceso = t.verificar(0,2048,"Ingresa un proceso en kB: ");
                    cout << ((asignarProceso(tmpProceso) == true)? "Proceso ingresado a la RAM" : "Memoria insuficiente") << endl;
                    system("pause");
                    
                }
                t.showRAM(tmpRam);
                res = t.verificar(1,2,"\n\n\tPresiona (1) para reiniciar la simulacion o (2) para salir");
            }

        }

        void inicio(){
            int res;
            CLEAR();
            res = t.verificar(1,2,"\n\n\tPresiona (1) para iniciar el programa o (2) para salir");
            while(res == 1){
                CLEAR();
                cout << "\n\n\tPARTICIONAMIENTO ESTATICO";
                configuracionInicial();
                CLEAR();
                simulacion();
                CLEAR();
                res = t.verificar(1,2,"\n\n\tPresiona (1) para continuar en el programa o (2) para salir");
            }
        }
};