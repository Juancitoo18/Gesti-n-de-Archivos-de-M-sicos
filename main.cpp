#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <locale.h>
#include <ctime>

using namespace std;

#include "Errores.h"
#include "Paises.h"
#include "Fecha_clase.h"
#include "Tipo_de_Interprete.h"
#include "Genero_clase.h"
#include "Interpretes_clase.h"
#include "Canciones_clase.h"
#include "menuCanciones.h"
#include "menuInterpretes.h"
#include "menuGeneros.h"
#include "menuPaises.h"
#include "menuTipoDeInterpretes.h"
#include "menuReportes.h"
#include "menuConfiguracion.h"

int main()
{
    setlocale(LC_ALL, "");
    int op;
    while(true){
        system("cls");
        cout<<"       MEN� PRINCIPAL"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"1) MEN� CANCIONES."<<endl;
        cout<<"2) MEN� INT�RPRETES."<<endl;
        cout<<"3) MEN� G�NEROS."<<endl;
        cout<<"4) MEN� PAISES."<<endl;
        cout<<"5) MEN� TIPO DE INT�RPRETES."<<endl;
        cout<<"6) MEN� REPORTES."<<endl;
        cout<<"7) MEN� CONFIGURACI�N."<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"0) FIN DEL PROGRAMA."<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"OPCI�N: ";
        cin>>op;
        system("cls");
        switch(op){
            case 1: menuCanciones();
                break;
            case 2: menuInterpretes();
                break;
            case 3: menuGeneros();
                break;
            case 4: menuPaises();
                break;
            case 5: menuTipoDeInter();
                break;
            case 6: menuReportes();
                break;
            case 7: menuConfiguracion();
                break;
            case 0: cout<<"EL PROGRAMA HA FINALIZADO!"<<endl;
                    return 0;
                break;
            default: cout<<"OPCION INCORRECTA, VUELVA A INTENTARLO."<<endl;
                break;
        }
    }
    cout <<endl;
    return 0;
}
