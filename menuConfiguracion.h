#ifndef MENUCONFIGURACION_H_INCLUDED
#define MENUCONFIGURACION_H_INCLUDED

///PROTOTIPOS
void menuConfiguracion();
bool CopiaCanciones();
bool CopiaInterpretes();
bool CopiaGeneros();
bool CopiaPaises();
bool CopiaTipoInterprete();

bool restaurarCanciones();
bool restaurarInterpretes();
bool restaurarGenero();
bool restaurarPaises();
bool restaurarTipoInterprete();

///DESARROLLO
void menuConfiguracion(){
    int op;
    while(true){
        system("cls");
        cout<<"                              MENU REPORTES"<<endl;
        cout<<"------------------------------------------------------------------------------"<<endl;
        cout<<"1) COPIA DE SEGURIDAD DEL ARCHIVO CANIONES"<<endl;
        cout<<"2) COPIA DE SEGURIDAD DEL ARCHIVO INTERPRETES"<<endl;
        cout<<"3) COPIA DE SEGURIDAD DEL ARCHIVO GENEROS"<<endl;
        cout<<"4) COPIA DE SEGURIDAD DEL ARCHIVO PAISES"<<endl;
        cout<<"5) COPIA DE SEGURIDAD DEL ARCHIVO TIPO DE INTERPRETE"<<endl;
        cout<<"6) RESTAURAR EL ARCHIVO DE CANIONES"<<endl;
        cout<<"7) RESTAURAR EL ARCHIVO DE INTERPRETES"<<endl;
        cout<<"8) RESTAURAR EL ARCHIVO DE GENEROS"<<endl;
        cout<<"9) RESTAURAR EL ARCHIVO DE PAISES"<<endl;
        cout<<"10) RESTAURAR EL ARCHIVO DE TIPO DE INTERPRETE"<<endl;
        cout<<"------------------------------------------------------------------------------"<<endl;
        cout<<"0) VOLVER AL MENÚ PRINCIPAL"<<endl;
        cout<<"------------------------------------------------------------------------------"<<endl;
        cout<<"OPCIÓN: ";
        cin>>op;
        system("cls");
        switch(op){
            case 1: if(CopiaCanciones()==true){
                        cout<< "EL ARCHIVO FUE COPIADO EXITOSAMENTE"<<endl;
                    }
                break;
            case 2: if(CopiaInterpretes()==true){
                        cout<< "EL ARCHIVO FUE COPIADO EXITOSAMENTE"<<endl;
                    }
                break;
            case 3: if(CopiaGeneros()==true){
                        cout<< "EL ARCHIVO FUE COPIADO EXITOSAMENTE"<<endl;
                    }
                break;
            case 4: if(CopiaPaises()==true){
                        cout<< "EL ARCHIVO FUE COPIADO EXITOSAMENTE"<<endl;
                    }
                break;
            case 5: if(CopiaTipoInterprete()==true){
                        cout<< "EL ARCHIVO FUE COPIADO EXITOSAMENTE"<<endl;
                    }
                break;
            case 6: if(restaurarCanciones()==true){
                        cout<< "EL ARCHIVO FUE RESTAURADO EXITOSAMENTE"<<endl;
                    }
                break;
            case 7: if(restaurarInterpretes()==true){
                        cout<< "EL ARCHIVO FUE RESTAURADO EXITOSAMENTE"<<endl;
                    }
                break;
            case 8: if(restaurarGenero()==true){
                        cout<< "EL ARCHIVO FUE RESTAURADO EXITOSAMENTE"<<endl;
                    }
                break;
            case 9: if(restaurarPaises()==true){
                        cout<< "EL ARCHIVO FUE RESTAURADO EXITOSAMENTE"<<endl;
                    }
                break;
            case 10: if(restaurarTipoInterprete()==true){
                        cout<< "EL ARCHIVO FUE RESTAURADO EXITOSAMENTE"<<endl;
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

///copias de seguridad

bool CopiaCanciones()
{
    FILE *Copy;
    Cancion obj;
    int pos=0;
    Copy=fopen("cancion.bkp", "wb");
    if(Copy == NULL) return false;
    while(obj.leerDeDisco(pos)){
        fwrite(&obj,sizeof(Cancion),1,Copy);
        pos++;
    }
    fclose(Copy);
    return true;
}
bool CopiaInterpretes()
{
    FILE *Copy;
    Interprete reg;
    int pos=0;
    Copy=fopen("interprete.bkp", "wb");
    if(Copy == NULL) return false;
    while(reg.leerDeDisco(pos)){
        fwrite(&reg,sizeof(Interprete),1,Copy);
        pos++;
    }
    fclose(Copy);
    return true;
}
bool CopiaGeneros()
{
    FILE *Copy;
    Genero gen;
    int pos=0;
    Copy=fopen("genero.bkp", "wb");
    if(Copy == NULL) return false;
    while(gen.leerDeDisco(pos)){
        fwrite(&gen,sizeof(Genero),1,Copy);
        pos++;
    }
    fclose(Copy);
    return true;
}
bool CopiaPaises()
{
    Paises aux;
    int pos = 0;
    FILE *p;
    p=fopen("paises.bkp","wb");
    if(p== NULL) return false;
    while(aux.leerDeDisco(pos))
    {
        fwrite(&aux,sizeof (Paises),1,p);
        pos++;
    }
    fclose(p);
    return true;
}
bool CopiaTipoInterprete()
{
    TipoDeInter aux;
    int pos = 0;
    FILE *p;
    p=fopen("TipoDeInterprete.bkp","wb");
    if(p== NULL) return false;
    while(aux.leerDeDisco(pos))
    {
        fwrite(&aux,sizeof (TipoDeInter),1,p);
        pos++;
    }
    fclose(p);
    return true;
}

///

bool restaurarCanciones()
{
    Cancion aux;
    Cancion reg;
    FILE *p;
    p=fopen("cancion.bkp","rb");
    if(p == NULL) return false;

    FILE *c;
    c=fopen("cancion.dat","wb");
    if(p==NULL) return false;

    while(fread(&aux, sizeof(Cancion),1,p))
    {
     reg = aux ;
     fwrite(&reg,sizeof (Cancion),1,c);
    }
    fclose(c);
    fclose(p);
    return true;

}
bool restaurarInterpretes()
{
    Interprete aux;
    Interprete reg;
    FILE *p;
    p=fopen("interprete.bkp","rb");
    if(p== NULL) return false;

    FILE *c;
    c=fopen("interprete.dat","wb");
    if(p==NULL)return false;

    while(fread(&aux, sizeof(Interprete),1,p))
    {
     reg = aux ;
     fwrite(&reg,sizeof (Interprete),1,c);
    }
    fclose(c);
    fclose(p);
    return true;

}
bool restaurarGenero()
{
    Genero aux;
    Genero reg;
    FILE *p;
    p=fopen("genero.bkp","rb");
    if(p== NULL) return false;

    FILE *c;
    c=fopen("genero.dat","wb");
    if(p==NULL) return false;

    while(fread(&aux, sizeof(Genero),1,p))
    {
     reg = aux ;
     fwrite(&reg,sizeof (Genero),1,c);
    }
    fclose(c);
    fclose(p);
    return true;

}
bool restaurarPaises()
{
    Paises aux;
    Paises reg;
    FILE *p;
    p=fopen("paises.bkp","rb");
    if(p== NULL) return false;

    FILE *c;
    c=fopen("Paises.dat","wb");
    if(p==NULL) return false;

    while(fread(&aux, sizeof(Paises),1,p))
    {
     reg = aux ;
     fwrite(&reg,sizeof (Paises),1,c);
    }
    fclose(c);
    fclose(p);
    return true;

}
bool restaurarTipoInterprete()
{
    TipoDeInter aux;
    TipoDeInter reg;
    FILE *p;
    p=fopen("TipoDeInterprete.bkp","rb");
    if(p== NULL) return false;

    FILE *c;
    c=fopen("TipoDeInterprete.dat","wb");
    if(p==NULL) return false;

    while(fread(&aux, sizeof(TipoDeInter),1,p))
    {
     reg = aux ;
     fwrite(&reg,sizeof (TipoDeInter),1,c);
    }
    fclose(c);
    fclose(p);
    return true;

}

#endif // MENUCONFIGURACION_H_INCLUDED
