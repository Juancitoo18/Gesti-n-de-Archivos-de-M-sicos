#ifndef INTERPRETES_CLASE_H_INCLUDED
#define INTERPRETES_CLASE_H_INCLUDED

///PROTOTIPOS
int contarRegistrosIntepretes();
void cargarCadena(char *pal, int tam);

///CLASE INTERPRETE:
class Interprete
{
private:
    int IDi;
    char Nombre[40];
    int Nacionalidad;
    int TipoDeInt;
    int GeneroMP;
    Fecha fechaDeInicio;
    bool estado;
public:
    ///gets()
    int getIDi(){return IDi;}
    const char *getNombre(){return Nombre;}
    int getNacionalidad(){return Nacionalidad;}
    int getTipoDeInt(){return TipoDeInt;}
    int getGeneroMP(){return GeneroMP;}
    Fecha getFechaDeInicio(){return fechaDeInicio;}
    bool getEstado(){return estado;}
    ///Sets()
    void setNombre(const char *nom){strcpy(Nombre, nom);}
    void setNacionildad(int n){Nacionalidad=n;}
    void setTipoDeint(int t){TipoDeInt=t;}
    void setGeneroMP(int g){GeneroMP=g;}
    void setfechaDeInicio(Fecha fe){fechaDeInicio=fe;}
    void setEstado(bool e){estado=e;}
    ///
    int grabarEnDisco();
    int modificarEnDisco(int pos);
    int leerDeDisco(int pos);
    void Cargar();
    void Mostrar();
    ///
    int getByCodigo(int codigoABuscar) {
    int pos = 0;
    while(leerDeDisco(pos++)) {
        if(getIDi() == codigoABuscar) return pos;
    }
    return -1;
    }
};

void Interprete::Cargar()
{
    Paises veri;
    TipoDeInter aux;
    Genero reg;
    int IDin;
    cout<<"ID DEL INTERPRETE: ";
    IDin=contarRegistrosIntepretes();
    IDi=IDin+1;
    cout<<IDi<<endl;
    cout<<"--------------------------"<<endl;
    cout<<"A CONTINUACIÓN, INGRESE:"<<endl;
    cout<<"--------------------------"<<endl;
    cout<<"NOMBRE(PERSONA O GRUPO MUSICAL): ";
    cargarCadena(Nombre,39);
    ///verificar si exite
    bool PaisExistente = true;
    while(PaisExistente){
    cout<<"NACIONALIDAD: ";
    cin>>Nacionalidad;
    if(veri.getByCodigoPais(Nacionalidad) == -1){
        Error(10).print();
    }else{PaisExistente=false;}
    }
    ///verificar si exite
    bool TipoDeInterExistente = true;
    while(TipoDeInterExistente){
    cout<<"TIPO DE INTERPRETE: ";
    cin>>TipoDeInt;
    if(aux.getByCodigoTipoDeInter(TipoDeInt) == -1){
        Error(11).print();
    }else{TipoDeInterExistente=false;}
    }
    ///verificar si exite
    bool GeneroExistente = true;
    while(GeneroExistente){
    cout<<"GENERO MUSICAL PRINCIPAL: ";
    cin>>GeneroMP;
    if(reg.getByCodigoGenero(GeneroMP) == -1){
        Error(12).print();
    }else{GeneroExistente=false;}
    }
    cout<<"FECHA DE INICIO ACTIVIDAD: "<<endl;
    fechaDeInicio.Cargar();
}

void Interprete::Mostrar()
{
    if(estado==true){
    cout<<"ID DEL INTERPRETE: ";
    cout<<getIDi()<<endl;
    cout<<"NOMBRE(PERSONA O GRUPO MUSICAL): ";
    cout<<Nombre<<endl;
    cout<<"NACIONALIDAD: ";
    cout<<Nacionalidad<<endl;
    cout<<"TIPO DE INTERPRETE: ";
    cout<<TipoDeInt<<endl;
    cout<<"GENERO MUSICAL PRINCIPAL: ";
    cout<<GeneroMP<<endl;
    cout<<"FECHA DE INICIO ACTIVIDAD: ";
    fechaDeInicio.Mostrar();
    }
}

int Interprete::grabarEnDisco()
{
    FILE *p;
    int escribio;
    p=fopen("interprete.dat", "ab");
    if(p==NULL)return -1;
    escribio=fwrite(this, sizeof(Interprete),1, p);
    fclose(p);
    return escribio;
}

int Interprete::modificarEnDisco(int pos)
{
    FILE *p;
    int escribio;
    p=fopen("interprete.dat", "rb+");
    if(p==NULL)return -1;
    fseek(p, sizeof(Interprete)*pos, 0);
    escribio=fwrite(this, sizeof(Interprete),1, p);
    fclose(p);
    return escribio;
}

int Interprete::leerDeDisco(int pos)
{
    FILE *p;
    int leyo=0;
    p=fopen("interprete.dat", "rb");
    if(p==NULL)return -1;
    fseek(p, sizeof(Interprete)*pos, 0);
    leyo=fread(this, sizeof(Interprete),1, p);
    fclose(p);
    return leyo;
}

///DESARROLLO FUNCIONES:
int contarRegistrosIntepretes(){
    int cantidad;
    FILE *f;
    Interprete obj;
    f=fopen("interprete.dat","rb");
    if (f==NULL) {
        fclose(f);
        return 0;
    }
        fseek(f, 0, SEEK_END);
        cantidad= ftell(f)/sizeof obj;

    fclose(f);
    return cantidad;
}

#endif // INTERPRETES_CLASE_H_INCLUDED
