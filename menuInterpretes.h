#ifndef MENUINTERPRETES_H_INCLUDED
#define MENUINTERPRETES_H_INCLUDED

///PROTOTIPOS
void menuInterpretes();
int agregarInterprete();
int listarInterpretes();
int grabarRegistroInterprete(Interprete interprete);
int buscarInterpreteID(int IDc=100000);
int listarInterpreteID();
int borrarRegistroInterprete();
int modificarGeneroInterprete();


///DESARROLLO
void menuInterpretes(){
    int op, ValorDevuelto;
    while(true){
        system("cls");
        cout<<"         MENU INTÉRPRETES"<<endl;
        cout<<"-------------------------------------"<<endl;
        cout<<"1) AGREGAR INTÉRPRETE."<<endl;
        cout<<"2) LISTAR INTÉRPRETE POR ID."<<endl;
        cout<<"3) LISTAR TODAS LOS INTÉRPRETES."<<endl;
        cout<<"4) MODIFICAR GÉNERO MUSICAL PRINCIPAL."<<endl;
        cout<<"5) ELIMINAR INTÉRPRETE."<<endl;
        cout<<"-------------------------------------"<<endl;
        cout<<"0) VOLVER AL MENÚ PRINCIPAL."<<endl;
        cout<<"-------------------------------------"<<endl;
        cout<<"OPCIÓN: ";
        cin>>op;
        system("cls");
        switch(op){
              case 1:
            {
                if(agregarInterprete()==1)
                {
                    cout<<"---------------------------------------"<<endl;
                    cout<<"EL INTERPRETE FUE AGREGADO CORRECTAMENTE.";
                }
                else
                {
                    cout<<"------------------------------------------------------------------------------"<<endl;
                    cout<<"HUBO UN ERROR EN LA CARGA DEL INTERPRETE, REVISE LOS CAMPOS E INTENTE DE NUEVO.";
                }
            }
                break;
            case 2:
                {
                    ValorDevuelto=listarInterpreteID();
                    if(ValorDevuelto==-1) cout<<"NO EXISTE EL ID, VUELVA A INTENTARLO CON UNO DIFERENTE.";
                }
                break;
            case 3:
                {
                    ValorDevuelto=listarInterpretes();
                    switch(ValorDevuelto){
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
                    if(modificarGeneroInterprete()==1)cout<<"GENERO MUSICAL PRINCIPAL MODIFICADA.";
                    else cout<<"HUBO UN ERROR EN LA MODIFICACIÓN DE LA FECHA, REVISE LOS CAMPOS E INTENTE DE NUEVO.";
                }
                break;
            case 5:
                {
                    if(borrarRegistroInterprete()!=1) cout<<"HUBO UN ERROR EN LA ELIMINACIÓN DEL INTERPRETE, REVISE LOS CAMPOS E INTENTE DE NUEVO."<<endl;
                    else cout<<"INTERPRETE ELIMINADA."<<endl;
                }
                break;
            case 0: return;
                break;
            default: cout<<"OPCIÓN INCORRECTA, VUELVA A INTENTARLO"<<endl;
                break;
        }
        cout <<endl;
        system("pause");
    }

}

int agregarInterprete(){
    int valor;
    Interprete obj;
    int encontro=buscarInterpreteID();
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
    cout<<"EL ID YA EXISTE EN INTERPRETES."<<endl;
    return 0;
}

int listarInterpretes(){
    Interprete reg;
    int leyo=0, pos=0;
    while(reg.leerDeDisco(pos)==1){
            reg.Mostrar();
            leyo=1;
            pos++;
            cout<<endl;
    }
    return leyo;
}

int listarInterpreteID(){
    int IDca, pos;
    Interprete obj;
    cout<<"INGRESE EL ID DEL INTERPRETE QUE QUIERA BUSCAR: ";
    cin>>IDca;
    pos=buscarInterpreteID(IDca);
    if(pos<0) return -1;
    obj.leerDeDisco(pos);
    obj.Mostrar();
    return 1;
}

int buscarInterpreteID(int IDc){
    Interprete reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1){
            if(reg.getIDi()==IDc){
                if(reg.getEstado()==true){
                    return pos;///Existe. No está borrado
                }
                else return -1; ///Existe pero esta borrado.
                }
            pos++;
            }
    return -2; ///No existe el id.
}

int grabarRegistroInterprete(Interprete reg){
    FILE *p;
    int escribio;
    p=fopen("interprete.dat", "ab");
    if(p==NULL)return -1;
    escribio=fwrite(&reg, sizeof(Interprete) ,1, p);
    fclose(p);
    return escribio;
}

int borrarRegistroInterprete(){
    Interprete reg;
    int pos=0, escribio;
    int ID;
    cout<<"INGRESE EL ID DEL INTERPRETE QUE QUIERA BORRAR: ";
    cin>>ID;
    pos=buscarInterpreteID(ID);
    if(pos>=0){
        reg.leerDeDisco(pos);
        reg.setEstado(false);
        escribio=reg.modificarEnDisco(pos);
    }
    else{
        cout<<"NO EXISTE EL ID"<<endl;
        return -2;
    }
    return escribio;
}

int modificarGeneroInterprete(){
    Interprete obj;
    int IDi, g, pos=0, escribio;
    bool entra=true;
    cout<<"INGRESE EL ID DEL INTERPRETE A LA QUE LE QUIERA MODIFICAR EL GENERO: ";
    cin>>IDi;
    pos=buscarInterpreteID(IDi);
    if(pos==-1){cout<<"EL ID EXISTE PERO ESTA ."<<endl;}
    if(pos==-2){cout<<"NO EXISTE EL ID."<<endl;}
    if(pos>=0){
    obj.leerDeDisco(pos);
    while(entra==true)
    {
        cout<<"GENERO MUSICAL PRINCIPAL(1-10): ";
        cin>>g;
        if (g>0 && g<11)
        {
            obj.setGeneroMP(g);
            entra=false;
        }
        else
        {
            cout<<"--------------------------------------------------------- -"<<endl;
            cout<<"EL GENERO DEBE ESTAR ENTRE 1-10, PORFAVOR INTENTE DE NUEVO."<<endl;
        }
    }
        escribio=obj.modificarEnDisco(pos);
    return escribio;
    }
return -1;
}

#endif // MENUINTERPRETES_H_INCLUDED
