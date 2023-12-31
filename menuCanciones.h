#ifndef MENUCANCIONES_H_INCLUDED
#define MENUCANCIONES_H_INCLUDED

///PROTOTIPOS
void menuCanciones();
int agregarCancion();
int listarCanciones();
int grabarRegistroCancion(Cancion cancion);
int buscarCancionID(int IDc=100000);
int listarCancionID();
int borrarRegistro();
int modificarFecha();

///DESARROLLO
void menuCanciones(){
    int op, valorDevuelto;
    while(true){
        system("cls");
        cout<<"       MENÚ CANCIONES"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"1) AGREGAR CANCIÓN."<<endl;
        cout<<"2) LISTAR CANCION POR ID."<<endl;
        cout<<"3) LISTAR TODAS LAS CANCIONES."<<endl;
        cout<<"4) MODIFICAR FECHA DE ESTRENO."<<endl;
        cout<<"5) ELIMINAR CANCIÓN."<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"0) VOLVER AL MENÚ PRINCIPAL."<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"OPCIÓN: ";
        cin>>op;
        system("cls");
        switch(op){
            case 1:
            {
                if(agregarCancion()==1)
                {
                    cout<<"---------------------------------------"<<endl;
                    cout<<"LA CANCIÓN FUE AGREGADA CORRECTAMENTE.";
                }
                else
                {
                    cout<<"------------------------------------------------------------------------------"<<endl;
                    cout<<"HUBO UN ERROR EN LA CARGA DE LA CANCIÓN, REVISE LOS CAMPOS E INTENTE DE NUEVO.";
                }
            }
                break;
            case 2:
                {
                    valorDevuelto=listarCancionID();
                    if(valorDevuelto==-1) cout<<"NO EXISTE EL ID, VUELVA A INTENTARLO CON UNO DIFERENTE.";
                }
                break;
            case 3:
                {
                    valorDevuelto=listarCanciones();
                    switch(valorDevuelto){
                        case 1: cout<<"FIN DE LISTADO.";
                                break;
                        case -1:cout<<"NO SE PUDO ABRIR EL LISTADO.";
                                break;
                        case 0: cout<<"TODAVIA NO HAY REGISTROS DE CANCIONES.";
                                break;
                    };
                }
                break;
            case 4:
                {
                    if(modificarFecha()==1)cout<<"FECHA MODIFICADA.";
                    else cout<<"HUBO UN ERROR EN LA MODIFICACIÓN DE LA FECHA, REVISE LOS CAMPOS E INTENTE DE NUEVO.";
                }
                break;
            case 5:
                {
                    if(borrarRegistro()!=1) cout<<"HUBO UN ERROR EN LA ELIMINACIÓN DE LA CANCIÓN, REVISE LOS CAMPOS E INTENTE DE NUEVO."<<endl;
                    else cout<<"CANCIÓN ELIMINADA."<<endl;
                }
                break;
            case 0: return;
                break;
            default: cout<<"OPCIÓN INCORRECTA, VUELVA A INTENTARLO."<<endl;
                break;
        }
        cout <<endl;
        system("pause");
    }
}

int agregarCancion(){
    int valor;
    Cancion obj;
    int encontro=buscarCancionID();
    if(encontro==-2)
    {
        obj.Cargar();
        valor=obj.grabarEnDisco();
        return valor;
    }
    if(encontro==-1)
    {
        cout<<"EL ID YA EXISTE EN CANCIONES PERO FUE BORRADO."<<endl;
        return encontro;
    }
    cout<<"EL ID YA EXISTE EN CANCIONES."<<endl;
    return 0;
}

int listarCanciones(){
    Cancion reg;
    int leyo=0, pos=0;
    while(reg.leerDeDisco(pos)==1)
    {
        reg.Mostrar();
        leyo=1;
        pos++;
        cout<<endl;
    }
    return leyo;
}

int listarCancionID(){
    int IDca, pos;
    Cancion obj;
    cout<<"INGRESE EL ID DE LA CANCION QUE QUIERA BUSCAR: ";
    cin>>IDca;
    pos=buscarCancionID(IDca);
    if(pos<0) return -1;
    obj.leerDeDisco(pos);
    obj.Mostrar();
    return 1;
}

int buscarCancionID(int IDc){
    Cancion reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1)
    {
        if(reg.getID()==IDc)
        {
            if(reg.getEstado()==true)
            {
                return pos;//Existe.
            }
            else return -1;//Existe pero esta borrado.
        }
        pos++;
    }
    return -2; //No existe el id.
}

int grabarRegistroCancion(Cancion reg){
    FILE *p;
    int escribio;
    p=fopen("cancion.dat", "ab");
    if(p==NULL)return -1;
    escribio=fwrite(&reg, sizeof(Cancion) ,1, p);
    fclose(p);
    return escribio;
}

int borrarRegistro(){
    Cancion reg;
    int pos=0, escribio;
    int ID;
    cout<<"INGRESE EL ID DE LA CANCION QUE QUIERA BORRAR: ";
    cin>>ID;
    pos=buscarCancionID(ID);
    if(pos>=0)
    {
        reg.leerDeDisco(pos);
        reg.setEstado(false);
        escribio=reg.modificarEnDisco(pos);
    }
    else
    {
        cout<<"NO EXISTE EL ID"<<endl;
        return -2;
    }
    return escribio;
}

int modificarFecha(){
    Cancion reg;
    Fecha obj;
    int ID, pos=0, escribio;
    cout<<"INGRESE EL ID DE LA CANCION A LA QUE LE QUIERA MODIFICAR LA FECHA: ";
    cin>>ID;
    pos=buscarCancionID(ID);
    if(pos==-1){cout<<"EL ID EXISTE PERO ESTA BORRADO."<<endl;}
    if(pos==-2){cout<<"NO EXISTE EL ID."<<endl;}
    if(pos>=0)
    {
        reg.leerDeDisco(pos);
        cout<<"INGRESE LA NUEVA FECHA: ";
        obj.Cargar();
        reg.setFechaDeEstreno(obj);
        escribio=reg.modificarEnDisco(pos);
        return escribio;
    }
return -1;
}

#endif // MENUCANCIONES_H_INCLUDED
