#ifndef PAISES_H_INCLUDED
#define PAISES_H_INCLUDED
///

int contarRegistrosPaises();

class Paises{
private:
    int IDp;
    char Nombre[30];
    char NombreDelCont[30];
    bool Estado;
public:
    ///
    int getIDP(){return IDp;}
    const char *getNombre(){return Nombre;}
    const char *getNombreDelContinente(){return NombreDelCont;}
    bool getEstado(){return Estado;}
    ///
    void setID(int id){id=IDp;}
    void setNombre(const char *nom){strcpy(Nombre, nom);}
    void setAutor(const char *con){strcpy(NombreDelCont, con);}
    void setEstado(bool e){Estado=e;}
    ///
    int grabarEnDisco();
    int modificarEnDisco(int pos);
    int leerDeDisco(int pos);
    void Cargar();
    void Mostrar();
    ///
    int getByCodigoPais(int codigoABuscar) {
    int pos = 0;
    while(leerDeDisco(pos++)) {
        if(getIDP() == codigoABuscar) return pos;
    }
    return -1;
    }
};
void Paises::Cargar()
{
    int ID;
    cout<<"ID DEL PAIS: ";
    ID=contarRegistrosPaises();
    IDp=ID+1;
    cout<<IDp<<endl;
    cout<<"--------------------------"<<endl;
    cout<<"A CONTINUACIÓN, INGRESE:"<<endl;
    cout<<"--------------------------"<<endl;
    cout<<"NOMBRE: ";
    cargarCadena(Nombre,29);
    cout<<"NOMBRE DEL CONTINENTE AL QUE PERTENECE: ";
    cargarCadena(NombreDelCont,29);
    Estado=true;
}
void Paises::Mostrar()
{
    if(Estado==true)
    {
        cout<<"ID DEL PAIS: ";
        cout<<getIDP()<<endl;
        cout<<"NOMBRE: ";
        cout<<Nombre<<endl;
        cout<<"CONTINENTE: ";
        cout<<NombreDelCont<<endl;
    }
}

int Paises::grabarEnDisco()
{
    FILE *p;
    int escribio;
    p=fopen("Paises.dat", "ab");
    if(p==NULL)return -1;
    escribio=fwrite(this, sizeof(Paises),1, p);
    fclose(p);
    return escribio;
}

int Paises::modificarEnDisco(int pos)
{
    FILE *p;
    int escribio;
    p=fopen("Paises.dat", "rb+");
    if(p==NULL)return -1;
    fseek(p, sizeof(Paises)*pos, 0);
    escribio=fwrite(this, sizeof(Paises),1, p);
    fclose(p);
    return escribio;
}

int Paises::leerDeDisco(int pos)
{
    FILE *p;
    int leyo=0;
    p=fopen("Paises.dat", "rb");
    if(p==NULL)return -1;
    fseek(p, sizeof(Paises)*pos, 0);
    leyo=fread(this, sizeof(Paises),1, p);
    fclose(p);
    return leyo;
}

int contarRegistrosPaises(){
    int cantidad;
    FILE *f;
    Paises obj;
    f=fopen("Paises.dat","rb");
    if (f==NULL) {
        fclose(f);
        return 0;
    }
        fseek(f, 0, SEEK_END);
        cantidad= ftell(f)/sizeof obj;
    fclose(f);
    return cantidad;
}
#endif // PAISES_H_INCLUDED
