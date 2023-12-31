#ifndef GENERO_CLASE_H_INCLUDED
#define GENERO_CLASE_H_INCLUDED

///PROTOTIPOS
int contarRegistrosGenero();
void cargarCadena(char *pal, int tam);

///CLASE GENERO:
class Genero
{
private:
    int IDg;
    char nombreg[40];
    int paisg, tipog;
    bool estadog;
public:
    ///gets()
    int getIDg(){return IDg;}
    const char *getNombreg(){return nombreg;}
    int getPaisg(){return paisg;}
    int getTipog(){return tipog;}
    bool getEstadog(){return estadog;}
    ///Sets()
    void setIDg(int ID){IDg=ID;}
    void setNombreg(const char *nom){strcpy(nombreg, nom);}
    void setPaisg(int p){paisg=p;}
    void setTipog(int t){tipog=t;}
    void setEstadog(bool e){estadog=e;}
    ///
    int grabarEnDisco();
    int modificarEnDisco(int pos);
    int leerDeDisco(int pos);
    void Cargar();
    void Mostrarr();
    ///
    int getByCodigoGenero(int codigoABuscar) {
    int pos = 0;
    while(leerDeDisco(pos++)) {
        if(getIDg() == codigoABuscar) return pos;
    }
    return -1;
    }
};


void Genero::Cargar()
{
    int ID;
    cout<<"ID DEL GÉNERO: ";
    ID=contarRegistrosGenero();
    IDg=ID+1;
    cout<<IDg<<endl;
    cout<<"--------------------------"<<endl;
    cout<<"A CONTINUACIÓN, INGRESE:"<<endl;
    cout<<"--------------------------"<<endl;
    cout<<"NOMBRE DEL GÉNERO: ";
    cargarCadena(nombreg,39);
    cout<<"PAÍS DE ORIGEN: ";
    cin>>paisg;
    cout<<"TIPO DE INSTRUMENTACIÓN: ";
    cin>>tipog;
    estadog=true;
}

void Genero::Mostrarr()
{
    if(estadog==true)
    {
        cout<<"ID DEL GÉNERO:";
        cout<<getIDg()<<endl;
        cout<<"NOMBRE: ";
        cout<<nombreg<<endl;
        cout<<"PAÍS DE ORIGEN: ";
        cout<<paisg<<endl;
        cout<<"TIPO DE INSTRUMENTACIÓN: ";
        cout<<tipog<<endl;
    }
}

int Genero::grabarEnDisco()
{
    FILE *p;
    int escribio;
    p=fopen("genero.dat", "ab");
    if(p==NULL)return -1;
    escribio=fwrite(this, sizeof(Genero),1, p);
    fclose(p);
    return escribio;
}

int Genero::modificarEnDisco(int pos)
{
    FILE *p;
    int escribio;
    p=fopen("genero.dat", "rb+");
    if(p==NULL)return -1;
    fseek(p, sizeof(Genero)*pos, 0);
    escribio=fwrite(this, sizeof(Genero),1, p);
    fclose(p);
    return escribio;
}

int Genero::leerDeDisco(int pos)
{
    FILE *p;
    int leyo=0;
    p=fopen("genero.dat", "rb");
    if(p==NULL)return -1;
    fseek(p, sizeof(Genero)*pos, 0);
    leyo=fread(this, sizeof(Genero),1, p);
    fclose(p);
    return leyo;
}

///DESARROLLO FUNCIONES
int contarRegistrosGenero(){
    int cantidad;
    FILE *f;
    Genero obj;
    f=fopen("genero.dat","rb");
    if (f==NULL) {
        fclose(f);
        return 0;
    }
        fseek(f, 0, SEEK_END);
        cantidad= ftell(f)/sizeof obj;

    fclose(f);
    return cantidad;
}

#endif // GENERO_CLASE_H_INCLUDED
