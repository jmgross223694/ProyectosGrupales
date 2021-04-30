#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "rlutil.h"
#include "cliente.h"
#include "fecha.h"
#include "menu.h"
#include "archivo_clientes.h"
#include "archivo_actividades_por_cliente.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    Menu menu;

    menu.welcome();
    Sleep(5000);

    ///REVISION DE VENCIMIENTOS DE APTOS MEDICOS

    ArchivoClientes archivoClientes;
    if(archivoClientes.revisarFechasAptosMedicos()==false)
    {
        rlutil::cls();
        cout<<"No se pudo chequear el vencimiento de aptos médicos."<<endl<<endl;
        cout<<"¿Desea continuar con la ejecución del programa de todas formas?";
        cout<<endl<<endl<<"1(SI) / 0(NO): ";
        int op;
        cin>>op;
        while(op!=1 && op!=0)
        {
            cout<<"Opción incorrecta\r";
            Sleep(1500);
            cout<<"                 \r";
            cout<<"Reintente >";
            cin>>op;
        }
        if(op==0){return 0;}
    }

    int claveAdmin=1234, clave;
    rlutil::cls();
    cout<<"Ingrese clave de ADMINISTRADOR (1234): ";
    cin>>clave;
    while(clave!=claveAdmin)
    {
        cout<<"Clave incorrecta. Reintente >";
        cin>>clave;
    }

    rlutil::cls();
    bool salir=false;
    while(!salir)
    {
        menu.switchMenuPrincipal(&salir);
    }
    return 0;
}

/*
-acomodar para mostrar todo en formato de tabla. (rlutil, iomanip, gotoxy)

-funciones itoa, atoi, atof, ftoa, (a= char, i= entero, f= float)

-strcat (concatenar)
*/
