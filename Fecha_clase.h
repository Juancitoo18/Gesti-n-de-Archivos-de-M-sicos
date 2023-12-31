#ifndef FECHA_CLASE_H_INCLUDED
#define FECHA_CLASE_H_INCLUDED

///PROTOTIPOS
bool fechaValida (int d, int m, int a);

///CLASE FECHA:
class Fecha
{
private:
    int dia, mes, anio;
public:
    void Cargar();
    void Mostrar(){
        cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
    }

    ///sets()
    void setDia(int d){dia=d;}
    void setMes(int m){mes=m;}
    void setAnio(int a){anio=a;}

    ///gets()
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}
};

void Fecha::Cargar()
{
    int d,m,a;
    bool entra,veri=true;
    time_t t;
    struct tm *f;
    t=time(NULL);
    f=localtime(&t);
    while(veri){
    entra=true;
    while (entra==true)
    {
        cout<<"INGRESE EL DIA: "<<endl;
        cin>>d;
        if (d<=31 && d>=1){entra=false;}
        else{
            cout<<"---------------------------------------------------"<<endl;
            cout<<"EL DÍA INGRESADO NO ES VALIDO, INTENTE DE NUEVO:"<<endl;
        }
    }
    entra=true;
    while (entra==true)
    {
        cout<<"INGRESE EL MES: "<<endl;
        cin>>m;
        if (m<=12 && m>=1){
        switch(m)
        {
        case 4: case 6: case 9: case 11: if (d<=30 && d>=1) {entra=false;}
        case 2: if (d<=28 && d>=1) {entra=false;}
        }
        entra=false;
        }else{
            cout<<"---------------------------------------------------"<<endl;
            cout<<"EL MES INGRESADO NO ES VALIDO, INTENTE DE NUEVO:"<<endl;
        }
    }
    entra=true;
    while (entra==true)
    {
        cout<<"INGRESE EL AÑO: "<<endl;
        cin>>a;
        if (a<=2022 && a>=1000){entra=false;}
        else{
            cout<<"---------------------------------------------------"<<endl;
            cout<<"EL AÑO INGRESADO NO ES VALIDO, INTENTE DE NUEVO:"<<endl;
        }

    }
    if (a>f->tm_year+1900 || m>f->tm_mon+1 && a==f->tm_year+1900 || d>f->tm_mday && m==f->tm_mon+1 && a==f->tm_year+1900)
        {
            cout<<"------------------------------"<<endl;
            Error(9).print();
            cout<<"PARA REFERENCIA, FECHA ACTUAL:"<<endl;
            cout<<f->tm_mday<<"/"<<f->tm_mon+1<<"/"<<f->tm_year+1900<<endl;
            cout<<"----------"<<endl;
            veri=true;
        }
        else{
            setDia(d);
            setMes(m);
            setAnio(a);
            veri=false;
        }
    }
}

bool fechaValida (int d, int m, int a)
{
    time_t t;
    struct tm *f;
    t=time(NULL);
    f=localtime(&t);

    if (d>31 && d<1){return false;}
    if (m>12 && m<1){return false;}
    else
    {
        switch(m)
        {
        case 4: case 6: case 9: case 11: if (d>30 && d<1) {return false;}
        case 2: if (d>28 && d<1) {return false;}
        }
    }
    if (a>2022){return false;}
    return true;
}
#endif // FECHA_CLASE_H_INCLUDED
