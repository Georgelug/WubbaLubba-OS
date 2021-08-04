class ProcesoSegmento{
    private:
        float proceso;
        float datos;
        float codigo;
        float pila;
    public:
        ProcesoSegmento(float proceso){
            this->proceso = proceso;
            this->datos = proceso*0.4;
            this->codigo = proceso*0.5;
            this->pila = proceso*0.1;
        }

        //getters
        float getProceso(){ return this->proceso; }
        float getDatos(){ return this->datos; }
        float getCodigo(){ return this->codigo; }
        float getPila(){ return this->pila; }

};