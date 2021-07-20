class User{
    
    private:
        string usuario,pswd;
        int contlogs = 0;
        bool usuarioValido,pswdValido;
    
    public:
        User(){
            contlogs++;
            if (contlogs<2){
                nuevoUsarioPswd();
                usuarioValido = true;
                pswdValido = true;
            }else{
                usuarioValido = pedirUsario();
                pswdValido = pedirPswd();
            }
            
        }

        bool getUsuarioValido(){
            return this->usuarioValido;
        }

        void setUsarioValido(bool userValido){
            this->usuarioValido = userValido;
        }

        bool getPswdValido(){
            return this->pswdValido;
        }

        void setUsarioValido(bool pswdValido){
            this->pswdValido = pswdValido;
        }

        bool UsuarioPswdVerificados(){
            return (getUsuarioValido() && getPswdValido())?
                true:
                false
            ;
        }

        void setUser(string user){
            this->usuario = user;
        }
        string getUser(){
            return this->usuario;
        }

        void setPassword(string password){
            this->pswd = password;
        }
        string getPassword(){
            return this->pswd;
        }
    
    private:
        bool verificarUsuarioIncorrecto(string usuario){
            return (usuario.empty() || !usuario.compare(getUser()))?
                true:
                false
            ;
        }
        bool verificarPswdIncorrecto(string pswd){
            return (pswd.empty() || !pswd.compare(getPassword()))?
                true:
                false
            ;
        }

        void nuevoUsarioPswd(){
            string tmpuser,tmppswd,tmppswdConfirm;

            cin.ignore();
            cout << "\n\n\tIngresa un nuevo usuario: ";
            getline(cin,tmpuser);

            while (tmpuser.empty()){
                cin.ignore();
                cout << "\n\n\tERROR, intentalo de nuevo\n\tIngresa un nuevo usuario: ";
                getline(cin,tmpuser);
            }

            cin.ignore();
            cout << "\n\n\tIngresa un nuevo password: ";
            getline(cin,tmppswd);

            cin.ignore();
            cout << "\n\n\tConfirma el nuevo password: ";
            getline(cin,tmppswdConfirm);

            while (tmppswd.empty() || tmppswdConfirm.empty() || !tmpuser.compare(tmppswdConfirm)){
                cin.ignore();
                cout << "\n\n\tERROR, intentalo de nuevo\n\tIngresa un nuevo password: ";
                getline(cin,tmppswd);

                cin.ignore();
                cout << "\n\n\tConfirma el nuevo password: ";
                getline(cin,tmppswdConfirm);
            }

            setUser(tmpuser);
            setPassword(tmppswd);
        }

    public:
        bool pedirUsario(){
            string tmpuser;
            int cont = 0;

            cin.ignore();
            cout << "\n\n\tUsario: ";
            getline(cin,tmpuser);

            while (verificarUsuarioIncorrecto(tmpuser)){
                cin.ignore();
                cout << "\n\n\tERROR, intentalo de nuevo\n\tUsario: ";
                getline(cin,tmpuser);
                cont++;
                if(cont == 3){
                    return false;
                }
            }

            return true
        }

        bool pedirPswd(){
            string tmppswd;
            int cont = 0;

            cin.ignore();
            cout << "\n\n\tpassword: ";
            getline(cin,tmppswd);

            while (verificarPswdIncorrecto(tmppswd)){
                cin.ignore();
                cout << "\n\n\tERROR, intentalo de nuevo\n\tpassword: ";
                getline(cin,tmppswd);
                cont++;
                if(cont == 3){
                    return false;
                }
            }

            return true
        }
};