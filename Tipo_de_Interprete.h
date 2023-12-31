#ifndef TIPO_DE_INTERPRETE_H_INCLUDED
#define TIPO_DE_INTERPRETE_H_INCLUDED

///
int contarRegistrosTipoDeInter();


class TipoDeInter{
private:
    int IDinter;
    char Nombre[40];
    bool Estado;
public:
     ///
    int getIDinterprete(){return IDinter;}
    const char *getNombre(){return Nombre;}
    bool getEstado(){return Estado;}
    ///
    void setIDinterprete(int id){id=IDinter;}
    void setNombre(const char *nom){strcpy(Nombre, nom);}
    void setEstado(bool e){Estado=e;}
    ///
    int grabarEnDisco();
    int modificarEnDisco(int pos);
    int leerDeDisco(int pos);
    void Cargar();
    void Mostrar();
    ///
    int getByCodigoTipoDeInter(int codigoABuscar) {
    int pos = 0;
    while(leerDeDisco(pos++)) {
        if(getIDinterprete() == codigoABuscar) return pos;
    }
    return -1;
    }
};

void TipoDeInter::Cargar()
{
    int ID;
    cout<<"ID DEL TIPO DE INTERPRETE: ";
    ID=contarRegistrosTipoDeInter();
    IDinter=ID+1;
    cout<<IDinter<<endl;
    cout<<"--------------------------"<<endl;
    cout<<"A CONTINUACIÓN, INGRESE:"<<endl;
    cout<<"--------------------------"<<endl;
    cout<<"NOMBRE(DESCRIPCIÓN DEL TIPO DE INTÉRPRETE): ";
    cargarCadena(Nombre,39);
    Estado=true;
}
void TipoDeInter::Mostrar()
{
    if(Estado==true)
    {
        cout<<"ID DEL TIPO DE INTERPRETE:  ";
        cout<<getIDinterprete()<<endl;
        cout<<"NOMBRE: ";
        cout<<Nombre<<endl;
    }
}

int TipoDeInter ::grabarEnDisco()
{
    FILE *p;
    int escribio;
    p=fopen("TipoDeInterprete.dat", "ab");
    if(p==NULL)return -1;
    escribio=fwrite(this, sizeof(TipoDeInter),1, p);
    fclose(p);
    return escribio;
}

int TipoDeInter::modificarEnDisco(int pos)
{
    FILE *p;
    int escribio;
    p=fopen("TipoDeInterprete.dat", "rb+");
    if(p==NULL)return -1;
    fseek(p, sizeof(TipoDeInter)*pos, 0);
    escribio=fwrite(this, sizeof(TipoDeInter),1, p);
    fclose(p);
    return escribio;
}

int TipoDeInter::leerDeDisco(int pos)
{
    FILE *p;
    int leyo=0;
    p=fopen("TipoDeInterprete.dat", "rb");
    if(p==NULL)return -1;
    fseek(p, sizeof(TipoDeInter)*pos, 0);
    leyo=fread(this, sizeof(TipoDeInter),1, p);
    fclose(p);
    return leyo;
}

int contarRegistrosTipoDeInter(){
    int cantidad;
    FILE *f;
    TipoDeInter obj;
    f=fopen("TipoDeInterprete.dat","rb");
    if (f==NULL) {
        fclose(f);
        return 0;
    }
        fseek(f, 0, SEEK_END);
        cantidad= ftell(f)/sizeof obj;
    fclose(f);
    return cantidad;
}
#endif // TIPO_DE_INTERPRETE_H_INCLUDED
