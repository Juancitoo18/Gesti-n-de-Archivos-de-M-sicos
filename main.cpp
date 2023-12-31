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
        cout<<"       MENÚ PRINCIPAL"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"1) MENÚ CANCIONES."<<endl;
        cout<<"2) MENÚ INTÉRPRETES."<<endl;
        cout<<"3) MENÚ GÉNEROS."<<endl;
        cout<<"4) MENÚ PAISES."<<endl;
        cout<<"5) MENÚ TIPO DE INTÉRPRETES."<<endl;
        cout<<"6) MENÚ REPORTES."<<endl;
        cout<<"7) MENÚ CONFIGURACIÓN."<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"0) FIN DEL PROGRAMA."<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"OPCIÓN: ";
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
