string Bienvenida(){
    return "\n\n\tWubbaLubba-OS verion 1.0.0\n\n\tCopyleft 2021 Autor: Jorge Luis Esparza Fuentes\n\n\tEl uso de este sistema operativo queda libre a todo usuario sin fines de lucro\n\nqueda prohibida su venta o distribucion";
}

string Instrucciones(){
    return "clear: limpiar pantalla\n\nh: instrucciones\n\np: ejecutar programa (por el momento solo se puede ejecutar la verificacion de los metodos de administracion de memoria)\n\n\t se puede agregar las siguientes opciones:\n\n\te: verificar particionamiento estatico\n\n\td: verificar particionamiento dinamico\n\n\tp: verificar paginacion\n\n\ts: verificar segmentacion\n\n\tEjemplo de uso: W => Users => thisUser: p-p (en este caso se ejecuta el programa verificar paginacion)\n\nNOTA: por lo el momento solo estan disponibles esas instrucciones para esta version de WubbaLubba-OS ya que es solo una demo";
}

void menu(){
    int respuesta,opcion;
    string instruccion;
    Herramientas funcionesAuxiliaresMenu;
    CLEAR();
    cout << Bienvenida();
    cout << "\n\n\tBienvenido, espere un momento";
    cout << "\n\nIngresando a la terminal..."<<endl;
    system("pause");
    CLEAR();
    User thisUser;
    string ruta = "W => Users => "+thisUser.getUser();
    CLEAR();
    respuesta = funcionesAuxiliaresMenu.verificar(1,2,"\n\n\tPresiona (1) o (2) para ingresar a tu WubbaLubba-OS: ");
    while(respuesta == 1 && thisUser.UsuarioPswdVerificados()){
        CLEAR();
        cout << Instrucciones();
        cout << ruta << ": ";
        cin.ignore();
        getline(cin,instruccion);
                
        respuesta = funcionesAuxiliaresMenu.verificar(1,2,"\n\n\tPresiona (1) o (2) para ingresar a tu WubbaLubba-OS: ");
    }
    cout << "\n\n\tSaliendo";
}

