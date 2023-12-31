#ifndef CANCIONES_CLASE_H_INCLUDED
#define CANCIONES_CLASE_H_INCLUDED

///PROTOTIPOS
int contarRegistrosCanciones();

///CLASE CANCION:
class Cancion
{
private:
    int ID;
    char nombre[30],autor[30];
    int IDi;
    Fecha fechaDeEstreno;
    bool estado;
    float duracion;
    int genero;
public:
    ///gets()
    int getID(){return ID;}
    const char *getNombre(){return nombre;}
    const char *getAutor(){return autor;}
    int getIDi(){return IDi;}
    Fecha getFechaDeEstreno(){return fechaDeEstreno;}
    bool getEstado(){return estado;}
    float getduracion(){return duracion;}
    int getgenero(){return genero;}
    ///gets()
    void setID(int IDc){ID=IDc;}
    void setNombre(const char *nom){strcpy(nombre, nom);}
    void setAutor(const char *au){strcpy(autor, au);}
    void setIDi(int i){IDi=i;}
    void setEstado(bool e){estado=e;}
    void setFechaDeEstreno(Fecha f){fechaDeEstreno=f;}
    void setDuracion(float r){duracion=r;}
    void setGenero (int g){genero=g;}
    ///
    int grabarEnDisco();
    int modificarEnDisco(int pos);
    int leerDeDisco(int pos);
    void Cargar();
    void Mostrar();

};

void Cancion::Cargar()
{
    Interprete veri;
    bool entra;
    float d;
    int IDc,g;
    cout<<"ID DE LA CANCION: ";
    IDc=contarRegistrosCanciones();
    ID=IDc+1;
    cout<<ID<<endl;
    cout<<"--------------------------"<<endl;
    cout<<"A CONTINUACIÓN, INGRESE:"<<endl;
    cout<<"--------------------------"<<endl;
    cout<<"NOMBRE DE LA CANCIÓN: ";
    cargarCadena(nombre,29);
    cout<<"NOMBRE DEL ARTISTA O COMPOSITOR: ";
    cargarCadena(autor,29);
    //verificar si existe
    bool InterExistente = true;
    while(InterExistente){
    cout<<"ID INTRÉPERTE: ";
    cin>>IDi;
    if(veri.getByCodigo(IDi) == -1){
        Error(8).print();
    }else{InterExistente=false;}
    }
    cout<<"FECHA DE ESTRENO: "<<endl;
    fechaDeEstreno.Cargar();
    entra=true;
    while(entra==true)
    {
        cout<<"DURACIÓN DE LA CANCIÓN: ";
        cin>>d;
        if(d>0)
        {
            setDuracion(d);
            entra=false;
        }
        else
        {
            cout<<"-------------------------------------------------------------"<<endl;
            cout<<"LA DURACION NO PUEDE SER NEGATIVA, PORFAVOR INTENTE DE NUEVO."<<endl;
        }
    }
    entra=true;
    while(entra==true)
    {
        cout<<"GÉNERO DE LA CANCIÓN (1-10): ";
        cin>>g;
        ///if (g<=contarRegistrosGenero()){}
        if (g>0 && g<11)
        {
            setGenero(g);
            entra=false;
        }
        else
        {
            cout<<"--------------------------------------------------------- -"<<endl;
            cout<<"EL GENERO DEBE ESTAR ENTRE 1-10, PORFAVOR INTENTE DE NUEVO."<<endl;
        }
    }
}

void Cancion::Mostrar()
{
    if(estado==true)
    {
        cout<<"ID DE LA CANCION: ";
        cout<<getID()<<endl;
        cout<<"NOMBRE: ";
        cout<<nombre<<endl;
        cout<<"NOMBRE DEL ARTISTA O COMPOSITOR: ";
        cout<<autor<<endl;
        cout<<"ID INTRÉPERTE: ";
        cout<<IDi<<endl;
        cout<<"FECHA DE ESTRENO: ";
        fechaDeEstreno.Mostrar();
        cout<<"DURACION DE LA CANCIÓN: ";
        cout<<duracion<<endl;
        cout<<"GÉNERO DE LA CANCIÓN (1-10): ";
        cout<<genero<<endl;
    }
}

int Cancion::grabarEnDisco()
{
    FILE *p;
    int escribio;
    p=fopen("cancion.dat", "ab");
    if(p==NULL)return -1;
    escribio=fwrite(this, sizeof(Cancion),1, p);
    fclose(p);
    return escribio;
}

int Cancion::modificarEnDisco(int pos)
{
    FILE *p;
    int escribio;
    p=fopen("cancion.dat", "rb+");
    if(p==NULL)return -1;
    fseek(p, sizeof(Cancion)*pos, 0);
    escribio=fwrite(this, sizeof(Cancion),1, p);
    fclose(p);
    return escribio;
}

int Cancion::leerDeDisco(int pos)
{
    FILE *p;
    int leyo=0;
    p=fopen("cancion.dat", "rb");
    if(p==NULL)return -1;
    fseek(p, sizeof(Cancion)*pos, 0);
    leyo=fread(this, sizeof(Cancion),1, p);
    fclose(p);
    return leyo;
}

///DESARROLLO FUNCIONES

int contarRegistrosCanciones(){
    int cantidad;
    FILE *f;
    Cancion obj;
    f=fopen("cancion.dat","rb");
    if (f==NULL) {
        fclose(f);
        return 0;
    }
        fseek(f, 0, SEEK_END);
        cantidad= ftell(f)/sizeof obj;

    fclose(f);
    return cantidad;
}

#endif // CANCIONES_CLASE_H_INCLUDED
