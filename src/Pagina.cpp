class Pagina{
    private:
        bool ocupada = false;
        int proceso = 0; 
        int espacio;

    public:
        Pagina(int espacio){
            this->espacio = espacio;
        }

        // getters & setters
        int getProceso(){ return this->proceso; }
        void setProceso(int proceso){ this->proceso = proceso; }
        int getOcupada(){ return this-> ocupada; }
        void setOcupada(bool ocupada){ this-> ocupada = ocupada; }
        int getEspacio(){ return this->espacio; }
        void setEspacio(int espacio){ this->espacio = espacio; }

        // Metodos
        void ingresarProceso(int proceso){
            if(proceso > 0){
                this->proceso = proceso;
                this->espacio -= proceso;
                setOcupada(true);
            }
        }
};
