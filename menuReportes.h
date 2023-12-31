#ifndef MENUREPORTES_H_INCLUDED
#define MENUREPORTES_H_INCLUDED
///Ejercicio:Recuperatorio Parcial 1
///Autor: Rios Juan
///Fecha: 17/11/2022

/*
  YO RINDO EL PRIMERO PERO HABIA AGREGADO LO NECESARIO POR LAS DUDAS
*/

///PROTOTIPOS
void menuReportes();
bool vaciar_archivo(const char *nombre);
void Punto1();
void mostrarPunto1();
void Punto2();
void Punto3();
void Punto4();

///DESARROLLO
void menuReportes(){
    int op;
    while(true){
        system("cls");
        cout<<"PUNTOS DEL RECUPERATORIO DEL PRIMER PARCIAL."<<endl;
        cout<<"------------------------------------------------------------------------------"<<endl;
        cout<<"1) PUNTO 1"<<endl;
        cout<<"2) PUNTO 2"<<endl;
        cout<<"3) PUNTO 3"<<endl;
        cout<<"4) PUNTO 4"<<endl;
        cout<<"------------------------------------------------------------------------------"<<endl;
        cout<<"0) VOLVER AL MENÚ PRINCIPAL"<<endl;
        cout<<"------------------------------------------------------------------------------"<<endl;
        cout<<"OPCIÓN: ";
        cin>>op;
        system("cls");
        switch(op){
            case 1:
                Punto1();
                    system("pause");
                break;
            case 2:
                Punto2();
                    system("pause");
                break;
            case 3:
                Punto3();
                    system("pause");
                break;
            case 4:
                Punto4();
                    system("pause");
                break;
            case 0: return;
                break;
            default: cout<<"OPCIÓN INCORRECTA, VUELVA A INTENTARLO"<<endl;
                break;
        }
    }
}
bool vaciar_archivo(const char *nombre)
{
    FILE *p;
    p=fopen(nombre,"wb");
    if(p==NULL) return false;
    fclose(p);
    return true;
}

/*
Punto 1
Dado un nombre de país que se ingresa por teclado generar un archivo con los intérpretes que pertenezcan a ese país.
Cada registro debe tener el siguiente formato:
Id de intérprete, nombre del intérprete y género musical principal de ese intérprete
Listar el archivo creado.
*/
class PaisXTeclado{
private:
    int ID;
    char Nombre[40];
    int Gen;
public:
   /// gets
    int getID(){return ID;}
    const char *getNombre(){return Nombre;}
    int getGenero(){return Gen;}
    /// sets
    void setID(int i){ID=i;}
    void setNombre(const char *n){strcpy(Nombre,n);}
    void setGenero(int g){Gen=g;}
    ///
    void Cargar(){
        cout<<"ID: ";
        cin>>ID;
        cout<<"NOMBRE DEL INTERPRETE: ";
        cargarCadena(Nombre,39);
        cout<<"GENERO: ";
        cin>>Gen;
    }
    void Mostrar(){
        cout<<"ID: ";
        cout<<ID<<endl;
        cout<<"NOMBRE DEL INTERPRETE: ";
        cout<<Nombre<<endl;
        cout<<"GENERO: ";
        cout<<Gen<<endl;
    }
    bool leerDeDisco(int pos){
        FILE *p;
        p=fopen("PaisTeclado.dat","rb");
        if(p==NULL) return false;
        fseek(p,pos*sizeof *this, 0);
        bool leyo=fread(this, sizeof *this, 1, p);
        fclose(p);
        return leyo;
    }
    bool grabarEnDisco(){
        FILE *p;
        p=fopen("PaisTeclado.dat","ab");
        if(p==NULL) return false;
        bool escribio=fwrite(this, sizeof *this, 1, p);
        fclose(p);
        return escribio;
    }

};
/*
Punto 1
Dado un nombre de país que se ingresa por teclado generar un archivo con los intérpretes que pertenezcan a ese país.
Cada registro debe tener el siguiente formato:
Id de intérprete, nombre del intérprete y género musical principal de ese intérprete
Listar el archivo creado.
*/
void Punto1(){
    Paises reg;
    PaisXTeclado obj;
    Interprete aux;
    vaciar_archivo("PaisTeclado.dat");
    int pos=0;
    char Nombrepais[30];
    cout<<"INGRESE NOMBRE DEL PAIS: ";
    cargarCadena(Nombrepais,29);
    while(reg.leerDeDisco(pos++)){
        int pos2=0;
        while(aux.leerDeDisco(pos2++)){
        if(strcmp(reg.getNombre(), Nombrepais) == 0){
            obj.setID(aux.getIDi());
            obj.setNombre(aux.getNombre());
            obj.setGenero(aux.getGeneroMP());
            obj.grabarEnDisco();
            }
        }
    }
    mostrarPunto1();
}

void mostrarPunto1(){
PaisXTeclado reg;
int pos=0;
while(reg.leerDeDisco(pos++)){
    reg.Mostrar();
}
}

/*
Punto2
Informar el/los género/s sin intérpretes.
*/
void Punto2(){
    Genero gen;
    Interprete Reg;
    int pos=0;
    cout<<"LOS GENEROS SIN INTERPRETES SON"<<endl;
    while(gen.leerDeDisco(pos++)){
        int pos2=0, Cant=0;
        while(Reg.leerDeDisco(pos2++)){
            if(gen.getIDg()==Reg.getGeneroMP()){
                    Cant++;
            }
        }
    if(Cant==0){
        gen.Mostrarr();
    }
    cout<<"NO HAY GENEROS SIN INTERPRETES"<<endl;
    }


}

/*
Punto 3
Dado un nombre de autor que se ingresa por teclado, listar las canciones de ese autor estrenadas antes del año 2010.
*/
void Punto3(){
    {
    Cancion reg;
    int PosY=0, cant=0;
    char Nombreautor[30];
    cout<<"INGRESE NOMBRE DEL AUTOR: ";
    cargarCadena(Nombreautor,29);
    cout<<"CANCION(ES) DEL AUTOR ESTRENADOS ANTES DE 2010: "<<endl;
    cout<<"----------------------------------"<<endl;
        while(reg.leerDeDisco(PosY++))
        {
            if ((strcmp(reg.getAutor(),Nombreautor)==0) && (reg.getFechaDeEstreno().getAnio()<2010))
            {
                cant++;
                reg.Mostrar();
                cout<<"--------------------"<<endl;
            }
        }
        if (cant==0)
        {
            cout<<"NO HAY NINGUNA CANCIÓN DE ESTE AUTOR QUE SEA ANTES DEL 2010"<<endl;
        }
    }
}


/*
Punto 4
Cargar y mostrar las canciones del archivo de Canciones que fueron estrenadas después del año 2020 usando un vector dinámico
*/
int contarRegistros(){
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

void Punto4(){
    Cancion *vec, reg;
    int tam=contarRegistros();
    vec = new Cancion[tam];
    if(vec==NULL)
    {
        cout<<"ERROR DE ASIGNACION DE MEMORIA"<<endl;
        return;
    }
    int i=0, pos=0;
    while(reg.leerDeDisco(pos++)){
        if(reg.getEstado() && reg.getFechaDeEstreno().getAnio()>2020){
            vec[i]=reg;
            i++;
    }
        }
    for(int i=0; i<tam; i++){
        vec[i].Mostrar();
        cout<<endl;
    }
    delete []vec;
}

#endif // MENUREPORTES_H_INCLUDED
