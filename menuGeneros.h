#ifndef MENUGENEROS_H_INCLUDED
#define MENUGENEROS_H_INCLUDED

///PROTOTIPOS
void menuGeneros();
int agregarGenero();
int listarGeneros();
int grabarRegistroGenero(Genero genero);
int buscarGeneroID(int IDc=100000);
int listarGenerosID();
int modificarGenero();

///DESARROLLO
void menuGeneros(){
    int op,valorDevuelto;
    while(true){
        system("cls");
        cout<<"            MENU GÉNEROS"<<endl;
        cout<<"-------------------------------------"<<endl;
        cout<<"1) AGREGAR GÉNERO."<<endl;
        cout<<"2) LISTAR GÉNERO POR ID."<<endl;
        cout<<"3) LISTAR TODOS LOS GÉNEROS."<<endl;
        cout<<"4) MODIFICAR TIPO DE INSTRUMENTACIÓN."<<endl;
        cout<<"-------------------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL."<<endl;
        cout<<"-------------------------------------"<<endl;
        cout<<"OPCIÓN: ";
        cin>>op;
        system("cls");
        switch(op){
            case 1:
                {
                if(agregarGenero()==1)
                {
                    cout<<"---------------------------------------"<<endl;
                    cout<<"EL GENERO FUE AGREGADO CORRECTAMENTE.";
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
                    valorDevuelto=listarGenerosID();
                    if(valorDevuelto==-1) cout<<"NO EXISTE EL ID, VUELVA A INTENTARLO CON UNO DIFERENTE.";
                }
                break;
                case 3:
                {
                    valorDevuelto=listarGeneros();
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
                    if(modificarGenero()==1)cout<<"TIPO DE INSTRUMENTACIÓN MODIFICADO.";
                    else cout<<"HUBO UN ERROR EN LA MODIFICACIÓN DE LA FECHA, REVISE LOS CAMPOS E INTENTE DE NUEVO.";
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

int agregarGenero(){
    int valor;
    Genero obj;
    int encontro=buscarGeneroID();
    if(encontro==-2)
    {
        obj.Cargar();
        valor=obj.grabarEnDisco();
        return valor;
    }
    if(encontro==-1)
    {
        cout<<"EL ID YA EXISTE EN GÉNEROS PERO FUE BORRADO."<<endl;
        return encontro;
    }
    cout<<"EL ID YA EXISTE EN GÉNEROS."<<endl;
    return 0;
}

int listarGeneros(){
    Genero reg;
    int leyo=0, pos=0;
    while(reg.leerDeDisco(pos)==1)
    {
        reg.Mostrarr();
        leyo=1;
        pos++;
        cout<<endl;
    }
    return leyo;
}

int listarGenerosID(){
    int IDge, pos;
    Genero obj;
    cout<<"INGRESE EL ID DEL GENERO QUE QUIERA BUSCAR: ";
    cin>>IDge;
    pos=buscarGeneroID(IDge);
    if(pos<0) return -1;
    obj.leerDeDisco(pos);
    obj.Mostrarr();
    return 1;
}

int buscarGeneroID(int ID){
    Genero reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1)
    {
        if(reg.getIDg()==ID)
        {
            if(reg.getEstadog()==true)
            {
                return pos;//Existe.
            }
            else return -1;//Existe pero esta borrado.
        }
        pos++;
    }
    return -2; //No existe el id.
}

int grabarRegistroGenero(Genero reg){
    FILE *p;
    int escribio;
    p=fopen("genero.dat", "ab");
    if(p==NULL)return -1;
    escribio=fwrite(&reg, sizeof(Genero) ,1, p);
    fclose(p);
    return escribio;
}

int modificarGenero(){
    Genero reg;
    int ID, t, pos=0, escribio;
    bool entra=true;
    cout<<"INGRESE EL ID DEL GENERO AL QUE QUIERA MODIFICAR EL TIPO : ";
    cin>>ID;
    pos=buscarCancionID(ID);
    if(pos==-1){cout<<"EL ID EXISTE PERO ESTA BORRADO."<<endl;}
    if(pos==-2){cout<<"NO EXISTE EL ID."<<endl;}
    if(pos>=0)
    {
        reg.leerDeDisco(pos);
    while(entra==true)
    {
        cout<<"TIPO DE INSTRUMENTACIÓN: ";
        cin>>t;
        if (t>0 && t<6)
        {
            reg.setTipog(t);
            entra=false;
        }
        else
        {
            cout<<"----------------------------------------------------------------------------"<<endl;
            cout<<"EL TIPO DE INSTRUMENTACIÓN DEBE ESTAR ENTRE 1-10, PORFAVOR INTENTE DE NUEVO."<<endl;
        }
    }
        escribio=reg.modificarEnDisco(pos);
        return escribio;
    }
return -1;
}

#endif // MENUGENEROS_H_INCLUDED
