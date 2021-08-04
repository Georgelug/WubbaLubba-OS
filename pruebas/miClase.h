#if !defined(_CIRCULO_H_)
#define _CIRCULO_H_

class Circulo{
    //Atributos
    private:
        double radio;
    //metodos
    public:
        // Constructors
        Circulo(){}
        
        Circulo(double radio){
            setRadio(radio);
        }

        // getters & setters
        double getRadio(){
            return radio;
        }
        void setRadio(double radio){
            radio=radio;
        }

        //otros metodos
        double perimento(){
            return radio*2*M_PI;
        }

        double area(){
            return M_PI*pow(radio,2);
        }

        void showData(){
            cout << "\n\n\tCirculo de radio r = " << radio <<"\n\n\tPerimetro= "<<perimento()<<"\n\n\tArea= "<<area()<<endl;
        }
        
};

#endif // _CIRCULO_H_