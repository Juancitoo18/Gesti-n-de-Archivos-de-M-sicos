#ifndef MENUTIPODEINTERPRETES_H_INCLUDED
#define MENUTIPODEINTERPRETES_H_INCLUDED

///
void menuTipoDeInter();
int agregarTipoDeInter();
int listarTipoDeInter();
int grabarRegistroTipoDeInter(TipoDeInter TipoDeInter);
int buscarTipoDeInterID(int IDc=100000);
int listarTipoDeInterID();
int borrarRegistroTipoDeInter();

void menuTipoDeInter(){
    int op,valorDevuelto;
    while(true){
        system("cls");
        cout<<"            MENU TIPO DE INTERPRETE"<<endl;
        cout<<"-------------------------------------"<<endl;
        cout<<"1) AGREGAR TIPO DE INTERPRETE."<<endl;
        cout<<"2) LISTAR TIPO DE INTERPRETE POR ID."<<endl;
        cout<<"3) LISTAR TODOS LOS TIPO DE INTERPRETES."<<endl;
        cout<<"4) ELIMINAR TIPO DE INTERPRETE."<<endl;
        cout<<"-------------------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL."<<endl;
        cout<<"-------------------------------------"<<endl;
        cout<<"OPCIÓN: ";
        cin>>op;
        system("cls");
        switch(op){
            case 1:
            {
                if(agregarTipoDeInter()==1)
                {
                    cout<<"---------------------------------------"<<endl;
                    cout<<"EL TIPO DE INTERPRETE FUE AGREGADO CORRECTAMENTE.";
                }
                else
                {
                    cout<<"------------------------------------------------------------------------------"<<endl;
                    cout<<"HUBO UN ERROR EN LA CARGA DEL TIPO DE INTERPRETE, REVISE LOS CAMPOS E INTENTE DE NUEVO.";
                }
            }
                break;
            case 2:
                {
                    valorDevuelto=listarTipoDeInterID();
                    if(valorDevuelto==-1) cout<<"NO EXISTE EL ID, VUELVA A INTENTARLO CON UNO DIFERENTE.";
                }
                break;
            case 3:
                {
                    valorDevuelto=listarTipoDeInter();
                    switch(valorDevuelto){
                        case 1: cout<<"FIN DE LISTADO.";
                                break;
                        case -1:cout<<"NO SE PUDO ABRIR EL LISTADO.";
                                break;
                        case 0: cout<<"TODAVIA NO HAY REGISTROS DE TIPO DE INTERPRETES.";
                                break;
                        };
                }
                break;
            case 4:
                {
                    if(borrarRegistroTipoDeInter()!=1) cout<<"HUBO UN ERROR EN LA ELIMINACIÓN DEL PAIS, REVISE LOS CAMPOS E INTENTE DE NUEVO."<<endl;
                    else cout<<"TIPO DE INTERPRETE ELIMINADA."<<endl;
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


int agregarTipoDeInter(){
    int valor;
    TipoDeInter obj;
    int encontro=buscarTipoDeInterID();
    if(encontro==-2)
    {
        obj.Cargar();
        valor=obj.grabarEnDisco();
        return valor;
    }
    if(encontro==-1)
    {
        cout<<"EL ID YA EXISTE EN TIPO DE INTERPRETES PERO FUE BORRADO."<<endl;
        return encontro;
    }
    cout<<"EL ID YA EXISTE EN TIPO DE INTERPRETES."<<endl;
    return 0;
}

int listarTipoDeInter(){
    TipoDeInter reg;
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

int listarTipoDeInterID(){
    int IDInt, pos;
    TipoDeInter obj;
    cout<<"INGRESE EL ID DE LA CANCION QUE QUIERA BUSCAR: ";
    cin>>IDInt;
    pos=buscarTipoDeInterID(IDInt);
    if(pos<0) return -1;
    obj.leerDeDisco(pos);
    obj.Mostrar();
    return 1;
}

int buscarTipoDeInterID(int IDc){
    TipoDeInter reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1)
    {
        if(reg.getIDinterprete()==IDc)
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

int grabarRegistroTipoDeInter(TipoDeInter reg){
    FILE *p;
    int escribio;
    p=fopen("TipoDeInterprete.dat", "ab");
    if(p==NULL)return -1;
    escribio=fwrite(&reg, sizeof(TipoDeInter) ,1, p);
    fclose(p);
    return escribio;
}

int borrarRegistroTipoDeInter(){
    TipoDeInter reg;
    int pos=0, escribio;
    int ID;
    cout<<"INGRESE EL ID DEL TIPO DE INTERPRETE QUE QUIERA BORRAR: ";
    cin>>ID;
    pos=buscarTipoDeInterID(ID);
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



#endif // MENUTIPODEINTERPRETES_H_INCLUDED
