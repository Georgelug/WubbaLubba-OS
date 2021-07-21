void menu(){
    Sistema sys;
    int respuesta,opcion;
    string instruccion;
    Herramientas funcionesAuxiliaresMenu;
    CLEAR();
    cout << sys.Bienvenida();
    cout << "\n\n\tBienvenido, espere un momento";
    cout << "\n\nIngresando a la terminal..."<<endl;
    system("pause");
    CLEAR();
    User thisUser;
    string ruta = "W => Users => "+thisUser.getUser();
    CLEAR();
    respuesta = funcionesAuxiliaresMenu.verificar(1,2,"\n\n\tPresiona (2) para salir o (1) para ingresar a tu WubbaLubba-OS: ");
    while(respuesta == 1 && thisUser.UsuarioPswdVerificados()){
        CLEAR();
        cout << "\n\n\t INSTRUCCIONES" << endl;
        cout << sys.Instrucciones();
        // cin.ignore();
        sys.leerBuffer(ruta);
        respuesta = funcionesAuxiliaresMenu.verificar(1,2,"\n\n\tPresiona (2) para salir o (1) para continuar en tu WubbaLubba-OS: ");
    }
    CLEAR();
    cout << "\n\n\tSaliendo";
}

