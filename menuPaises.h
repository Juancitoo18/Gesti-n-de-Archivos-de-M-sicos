#ifndef MENUPAISES_H_INCLUDED
#define MENUPAISES_H_INCLUDED

///
void menuPaises();
int agregarPais();
int listarPaises();
int grabarRegistroPaises(Paises Paises);
int buscarPaisesID(int IDc=100000);
int listarPaisesID();
int borrarRegistroPaises();

void menuPaises(){
    int op,valorDevuelto;
    while(true){
        system("cls");
        cout<<"            MENU PAISES"<<endl;
        cout<<"-------------------------------------"<<endl;
        cout<<"1) AGREGAR PAIS."<<endl;
        cout<<"2) LISTAR PAIS POR ID."<<endl;
        cout<<"3) LISTAR TODOS LOS PAISES."<<endl;
        cout<<"4) ELIMINAR PAIS."<<endl;
        cout<<"-------------------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL."<<endl;
        cout<<"-------------------------------------"<<endl;
        cout<<"OPCIÓN: ";
        cin>>op;
        system("cls");
        switch(op){
            case 1:
            {
                if(agregarPais()==1)
                {
                    cout<<"---------------------------------------"<<endl;
                    cout<<"EL PAIS FUE AGREGADO CORRECTAMENTE.";
                }
                else
                {
                    cout<<"------------------------------------------------------------------------------"<<endl;
                    cout<<"HUBO UN ERROR EN LA CARGA DEL PAIS, REVISE LOS CAMPOS E INTENTE DE NUEVO.";
                }
            }
                break;
            case 2:
                {
                    valorDevuelto=listarPaisesID();
                    if(valorDevuelto==-1) cout<<"NO EXISTE EL ID, VUELVA A INTENTARLO CON UNO DIFERENTE.";
                }
                break;
            case 3:
                {
                    valorDevuelto=listarPaises();
                    switch(valorDevuelto){
                        case 1: cout<<"FIN DE LISTADO.";
                                break;
                        case -1:cout<<"NO SE PUDO ABRIR EL LISTADO.";
                                break;
                        case 0: cout<<"TODAVIA NO HAY REGISTROS DE PAISES.";
                                break;
                        };
                }
                break;
            case 4:
                {
                    if(borrarRegistroPaises()!=1) cout<<"HUBO UN ERROR EN LA ELIMINACIÓN DEL PAIS, REVISE LOS CAMPOS E INTENTE DE NUEVO."<<endl;
                    else cout<<"PAIS ELIMINADA."<<endl;
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


int agregarPais(){
    int valor;
    Paises obj;
    int encontro=buscarPaisesID();
    if(encontro==-2)
    {
        obj.Cargar();
        valor=obj.grabarEnDisco();
        return valor;
    }
    if(encontro==-1)
    {
        cout<<"EL ID YA EXISTE EN PAISES PERO FUE BORRADO."<<endl;
        return encontro;
    }
    cout<<"EL ID YA EXISTE EN PAISES."<<endl;
    return 0;
}

int listarPaises(){
    Paises reg;
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

int listarPaisesID(){
    int IDPa, pos;
    Paises obj;
    cout<<"INGRESE EL ID DE LA CANCION QUE QUIERA BUSCAR: ";
    cin>>IDPa;
    pos=buscarPaisesID(IDPa);
    if(pos<0) return -1;
    obj.leerDeDisco(pos);
    obj.Mostrar();
    return 1;
}

int buscarPaisesID(int IDc){
    Paises reg;
    int pos=0;
    while(reg.leerDeDisco(pos)==1)
    {
        if(reg.getIDP()==IDc)
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

int grabarRegistroPaises(Paises reg){
    FILE *p;
    int escribio;
    p=fopen("Paises.dat", "ab");
    if(p==NULL)return -1;
    escribio=fwrite(&reg, sizeof(Paises) ,1, p);
    fclose(p);
    return escribio;
}

int borrarRegistroPaises(){
    Paises reg;
    int pos=0, escribio;
    int ID;
    cout<<"INGRESE EL ID DEL PAIS QUE QUIERA BORRAR: ";
    cin>>ID;
    pos=buscarPaisesID(ID);
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




#endif // MENUPAISES_H_INCLUDED
