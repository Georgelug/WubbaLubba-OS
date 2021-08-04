class Pagina{
    private:
        bool ocupada;
        int proceso; 
        int espacio;

    public:
        Pagina(int espacio){
            this->espacio = espacio;
            this->ocupada = false;
            this->proceso = 0;
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
        
        void vaciarPagina(int espacio){
            this->espacio = espacio;
            this->ocupada = false;
            this->proceso = 0;
        }
};
