#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "rlutil.h"
#include "cliente.h"
#include "archivo_clientes.h"
#include "archivo_actividades.h"
#include "actividades.h"
#include "actividades_por_cliente.h"
#include "archivo_actividades_por_cliente.h"
#include "movimientos_de_caja.h"
#include "archivo_movimientos_de_caja.h"
#include "archivo_abonos.h"
#include "abonos.h"
#include "abonoCliente.h"
#include "archivo_abonos_por_cliente.h"
#include "reportes.h"
#include "arqueos_de_caja.h"
#include "archivo_arqueos_de_caja.h"

using namespace std;

Menu::welcome()
{
    cout<<"/--------------------------------\\"<<endl;
    cout<<"| Bienvenidos a                  |"<<endl;
    cout<<"|                                |"<<endl;
    cout<<"| YY    YY OOOOOO UU  UU RRRRRR  |"<<endl;
    cout<<"|  YY  YY  OO  OO UU  UU RR  RR  |"<<endl;
    cout<<"|    YY    OO  OO UU  UU RRRR    |"<<endl;
    cout<<"|    YY    OO  OO UU  UU RR RR   |"<<endl;
    cout<<"|    YY    OOOOOO UUUUUU RR  RR  |"<<endl;
    cout<<"|                                |"<<endl;
    cout<<"|    GGGGGG YY    YY MMM   MMM   |"<<endl;
    cout<<"|    GG      YY  YY  MM MMM MM   |"<<endl;
    cout<<"|    GG GGG    YY    MM  M  MM   |"<<endl;
    cout<<"|    GG  GG    YY    MM     MM   |"<<endl;
    cout<<"|    GGGGGG    YY    MM     MM   |"<<endl;
    cout<<"\\--------------------------------/"<<endl;
    cout<<"       by: Juan Gross & Joan Laino"<<endl;
    for(int i=0; i<8; i++)
    {
        cout<<endl;
    }
    cout<<"Cargando archivos necesarios"<<endl<<"Aguarde unos momentos...";
}
Menu::menuPrincipal()
{
    cout<<"/--------------------------------\\"<<endl;
    cout<<"|          MENU PRINCIPAL        |"<<endl;
    cout<<"|--------------------------------|"<<endl;
    cout<<"| 1 - Clientes                   |"<<endl;
    cout<<"| 2 - Actividades por cliente    |"<<endl;
    cout<<"| 3 - Actividades en gimnasio    |"<<endl;
    cout<<"| 4 - Movimientos de caja        |"<<endl;
    cout<<"| 5 - Abonos en gimnasio         |"<<endl;
    cout<<"| 6 - Pagos de cuota             |"<<endl;
    cout<<"| 7 - Consultas / Reportes       |"<<endl;
    cout<<"| 8 - Copia de seguridad         |"<<endl;
    cout<<"|--------------------------------|"<<endl;
    cout<<"| 0 - Salir del programa         |"<<endl;
    cout<<"\\--------------------------------/"<<endl;
}
Menu::switchMenuPrincipal(bool *salir)
{
    int op;
    menuPrincipal();
    cout<<"\n\nIngrese Opcion: ";
    cin>>op;
    rlutil::cls();
    switch(op)
    {
    case 1: ///Clientes.
    {
        rlutil::cls();
        bool volverMenuPrincipal=false;
        while(!volverMenuPrincipal)
        {
            rlutil::cls();
            switchSubMenuClientes(&volverMenuPrincipal);
        }
    }
    break;
    case 2: ///Actividades por cliente.
    {
        rlutil::cls();
        bool volverMenuPrincipal=false;
        while(!volverMenuPrincipal)
        {
            rlutil::cls();
            switchSubMenuActividadesPorCliente(&volverMenuPrincipal);
        }
    }
    break;
    case 3: ///Actividades en gimnasio.
    {
        rlutil::cls();
        bool volverMenuPrincipal=false;
        while(!volverMenuPrincipal)
        {
            rlutil::cls();
            switchSubMenuActividades(&volverMenuPrincipal);
        }

    }
    break;
    case 4: ///Movimientos de caja.
    {
        rlutil::cls();
        bool volverMenuPrincipal=false;
        while(!volverMenuPrincipal)
        {
            rlutil::cls();
            switchSubMenuCaja(&volverMenuPrincipal);
        }
    }
    break;
    case 5: ///Abonos en gimnasio.
    {
        rlutil::cls();
        bool volverMenuPrincipal=false;
        while(!volverMenuPrincipal)
        {
            rlutil::cls();
            switchSubMenuAbonos(&volverMenuPrincipal);
        }
    }
    break;
    case 6: ///Pagos de cuota.
    {
        rlutil::cls();
        bool volverMenuPrincipal=false;
        while(!volverMenuPrincipal)
        {
            rlutil::cls();
            switchSubMenuAbonosPorCliente(&volverMenuPrincipal);
        }
    }
    break;
    case 7: ///Reportes.
    {
        rlutil::cls();
        bool volverMenuPrincipal=false;
        while(!volverMenuPrincipal)
        {
            rlutil::cls();
            switchSubMenuReportes(&volverMenuPrincipal);
        }
    }
    break;
    case 8: ///Copia de seguridad.
    {
        rlutil::cls();
        bool volverMenuPrincipal=false;
        while(!volverMenuPrincipal)
        {
            rlutil::cls();
            switchSubMenuBackup(&volverMenuPrincipal);
        }
    }
    break;
    case 0: ///Salir del programa.
    {
        *salir=true;
    }
    break;
    default:
    {
        rlutil::anykey("Opcion incorrecta");
    }
    break;
    }
    rlutil::cls();
}
Menu::subMenuClientes()
{
    cout<<"/--------------------------------\\"<<endl;
    cout<<"|            CLIENTES            |"<<endl;
    cout<<"|--------------------------------|"<<endl;
    cout<<"| 1 - Nuevo ingreso              |"<<endl;
    cout<<"| 2 - Modificar                  |"<<endl;
    cout<<"| 3 - Buscar                     |"<<endl;
    cout<<"| 4 - Listar todos               |"<<endl;
    cout<<"|--------------------------------|"<<endl;
    cout<<"| 0 - Volver al menu principal   |"<<endl;
    cout<<"\\--------------------------------/"<<endl;

}
Menu::switchSubMenuClientes(bool *salir)
{
    Cliente cliente;
    ArchivoClientes archivoClientes;
    int op;
    subMenuClientes();
    cout<<"\n\nIngrese Opcion: ";
    cin>>op;
    rlutil::cls();
    switch(op)
    {
    case 1: ///Cargar un nuevo cliente.
    {
        rlutil::cls();
        cliente.cargar();
        if(archivoClientes.guardar(cliente)==true)
        {
            rlutil::cls();
            rlutil::anykey("Cliente guardado exitosamente");
        }
        else
        {
            rlutil::cls();
            rlutil::anykey("No se pudo guardar al cliente");
        }
        rlutil::cls();
    }
    break;
    case 2: ///Modificar un cliente.
    {
        rlutil::cls();
        if(archivoClientes.contarRegistros()!=0)
        {
            int dni;
            cout<<"DNI (solo números): ";
            cin>>dni;
            while(cliente.contarDigitosDni(dni)<7 && cliente.contarDigitosDni(dni)>8)
            {
                cout<<"DNI inválido. >";
                cin>>dni;
            }
            if(cliente.modificar(dni)==true)
            {
                rlutil::cls();
                rlutil::anykey("Cliente modificado exitosamente");
            }
            else
            {
                rlutil::cls();
                rlutil::anykey("No se modificó el cliente");
            }
        }
        else
        {
            rlutil::cls();
            rlutil::anykey("El archivo Clientes está vacío.");
            rlutil::cls();
            rlutil::anykey("No se modificó ningún cliente");
        }
    }
    break;
    case 3: ///Buscar un Cliente.
    {
        if(archivoClientes.contarRegistros()!=0)
        {
            bool volverSubMenuClientes=false;
            while(!volverSubMenuClientes)
            {
                rlutil::cls();
                switchSubMenuBuscarCliente(&volverSubMenuClientes);
            }
        }
        else
        {
            rlutil::cls();
            rlutil::anykey("El archivo Clientes está vacío.");
            rlutil::cls();
        }
    }
    break;
    case 4: ///Mostrar todos los clientes.
    {
        rlutil::cls();
        int cant=archivoClientes.contarRegistros();
        if(cant!=0)
        {
            cout<<"Cantidad total de clientes en archivo: "<<cant<<endl<<endl;
            archivoClientes.mostrarTodos();
        }
        else
        {
            cout<<"El archivo de clientes está vacío.";
        }
        rlutil::anykey();
    }
    break;
    case 0: ///Volver al menu principal.
    {
        *salir=true;
    }
    break;
    default:
    {
        rlutil::anykey("Opcion incorrecta");
    }
    break;
    }
    rlutil::cls();
}
Menu::subMenuBuscarCliente()
{
    cout<<"/--------------------------------\\"<<endl;
    cout<<"|         BUSCAR CLIENTE         |"<<endl;
    cout<<"|--------------------------------|"<<endl;
    cout<<"| 1 - Por número de socio        |"<<endl;
    cout<<"| 2 - Por nombre y apellido      |"<<endl;
    cout<<"| 3 - Por DNI                    |"<<endl;
    cout<<"|--------------------------------|"<<endl;
    cout<<"| 0 - Volver al menu CLIENTES    |"<<endl;
    cout<<"\\--------------------------------/"<<endl;
}
Menu::switchSubMenuBuscarCliente(bool *salir)
{
    Cliente cliente;
    ArchivoClientes archivoClientes;
    int op;
    subMenuBuscarCliente();
    cout<<"\n\nIngrese Opcion: ";
    cin>>op;
    rlutil::cls();
    switch(op)
    {
    case 1: ///Buscar cliente por número de socio.
    {
        int pos, numSocio, cantidadClientes=archivoClientes.contarRegistros();
        cout<<"------------BUSCAR CLIENTE POR NÚMERO DE SOCIO------------"<<endl<<endl;
        cout<<"Número de socio: ";
        cin>>numSocio;
        while(numSocio<1 || numSocio>cantidadClientes)
        {
            rlutil::cls();
            cout<<"------------BUSCAR CLIENTE POR NÚMERO DE SOCIO------------"<<endl<<endl;
            cout<<"Número de socio inexistente. Reintente >";
            cin>>numSocio;
        }
        pos=archivoClientes.buscarPorNumSocio(numSocio);
        cliente=archivoClientes.leer(pos);
        cout<<endl;
        cliente.mostrar();
        rlutil::anykey();
    }
    break;
    case 2: ///Buscar cliente por nombre y apellido.
    {
        cin.ignore();
        int pos;
        char names[50], surnames[50];
        cout<<"------------BUSCAR CLIENTE POR NOMBRES Y APELLIDOS------------"<<endl<<endl;
        cout<<"Nombres: ";
        cin.getline(names,50);
        while(cliente.validarCadenaVacia(names)==false)
        {
            cin.getline(names,50);
        }
        cout<<endl<<"Apellidos: ";
        cin.getline(surnames,50);
        while(cliente.validarCadenaVacia(surnames)==false)
        {
            cin.getline(surnames,50);
        }
        pos=archivoClientes.buscarPorNombreApellido(names,surnames);
        int reintentos=0;
        while(pos<0 && *salir==false)
        {
            if(reintentos<2)
            {
                rlutil::cls();
                cout<<"------------BUSCAR CLIENTE POR NOMBRES Y APELLIDOS------------"<<endl<<endl;
                cout<<"Los datos ingresados están incompletos o no existen en el archivo.";
                Sleep(1500);
                cout<<"                                                     \r";
                cout<<endl<<"Nombre completo: ";
                cin.getline(names,50);
                while(cliente.validarCadenaVacia(names)==false)
                {
                    cin.getline(names,50);
                }
                cout<<endl<<"Apellido completo: ";
                cin.getline(surnames,50);
                while(cliente.validarCadenaVacia(surnames)==false)
                {
                    cin.getline(surnames,50);
                }
                pos=archivoClientes.buscarPorNombreApellido(names,surnames);
                reintentos++;
            }
            else
            {
                rlutil::cls();
                cout<<"Demasiados intentos incorrectos. Se saldrá de la búsqueda actual.";
                Sleep(1000);
                *salir=true;
            }
        }
        if(pos!=-1 && pos!=-2)
        {
            cliente=archivoClientes.leer(pos);
            cout<<endl;
            cliente.mostrar();
            rlutil::anykey();
        }
    }
    break;
    case 3: ///Buscar cliente por DNI.
    {
        int pos, dni;
        cout<<"------------BUSCAR CLIENTE POR DNI------------"<<endl<<endl;
        cout<<"DNI (solo números): ";
        cin>>dni;
        while(archivoClientes.validarExistenciaDni(dni)==false)
        {
            rlutil::cls();
            cout<<"------------BUSCAR CLIENTE POR DNI------------"<<endl<<endl;
            cout<<"DNI inexistente. Reintente (solo números)>";
            cin>>dni;
        }
        pos=archivoClientes.buscarPorDNI(dni);
        if(pos>=0)
        {
            cliente=archivoClientes.leer(pos);
            cout<<endl;
            cliente.mostrar();
            rlutil::anykey();
        }
    }
    break;
    case 0: ///Volver al sub menu CLIENTES.
    {
        *salir=true;
    }
    break;
    default:
    {
        rlutil::anykey("Opcion incorrecta");
    }
    break;
    }
    rlutil::cls();
}
Menu::subMenuCamposCliente()
{
    cout<<" 1 - DNI"<<endl;
    cout<<" 2 - Nombres"<<endl;
    cout<<" 3 - Apellidos"<<endl;
    cout<<" 4 - Fecha de nacimiento"<<endl;
    cout<<" 5 - Actividades"<<endl;
    cout<<" 6 - Tipo de abono"<<endl;
    cout<<" 7 - Apto médico"<<endl;
    cout<<" 8 - Fecha de revisión médica"<<endl;
    cout<<" 9 - Estado en sistema"<<endl;
    cout<<" ---------------------------"<<endl;
    cout<<" 0 - Volver al menú Clientes"<<endl;
}
Menu::subMenuActividadesPorCliente()
{
    cout<<"/--------------------------------\\"<<endl;
    cout<<"|    ACTIVIDADES POR CLIENTE     |"<<endl;
    cout<<"|--------------------------------|"<<endl;
    cout<<"| 1 - Buscar por DNI             |"<<endl;   ///PIDE UN DNI Y MUESTRA TODAS LAS ACTIVIDADES activas e inactivas (con sus fechas de alta y baja), de ese cliente, junto con su nombre y apellido, dni y numero de socio
    cout<<"| 2 - Listar todas               |"<<endl;   ///MUESTRA todos los registros del archivo ActividadesPorCliente.dat.
    cout<<"|--------------------------------|"<<endl;
    cout<<"| 0 - Volver al menú principal   |"<<endl;
    cout<<"\\--------------------------------/"<<endl;
}
Menu::switchSubMenuActividadesPorCliente(bool *salir)
{
    int op;
    subMenuActividadesPorCliente();
    ArchivoActividadesCliente archivoActividadesCliente;
    cout<<"\n\nIngrese Opcion: ";
    cin>>op;
    rlutil::cls();
    switch(op)
    {
    case 1: ///Mostrar todas las actividades y los datos (nombre, apellido, dni y numero de socio), de un cliente.
    {
        rlutil::cls();
        archivoActividadesCliente.mostrarTodasPorDni();
        rlutil::anykey();
    }
    break;
    case 2: ///Mostrar todas las actividades por cliente cargadas.
    {
        rlutil::cls();
        archivoActividadesCliente.mostrarTodas();
        rlutil::anykey();
    }
    break;
    case 0: ///Volver al menu principal.
    {
        *salir=true;
    }
    break;
    default:
    {
        rlutil::anykey("Opcion incorrecta");
    }
    break;
    }
    rlutil::cls();
}
Menu::subMenuActividades()
{
    cout<<"/--------------------------------\\"<<endl;
    cout<<"|    ACTIVIDADES EN GIMNASIO     |"<<endl;
    cout<<"|--------------------------------|"<<endl;
    cout<<"| 1 - Nuevo ingreso              |"<<endl;
    cout<<"| 2 - Modificar                  |"<<endl;
    cout<<"| 3 - Listar todas               |"<<endl;
    cout<<"|--------------------------------|"<<endl;
    cout<<"| 0 - Volver al menú principal   |"<<endl;
    cout<<"\\--------------------------------/"<<endl;
}
Menu::switchSubMenuActividades(bool *salir)
{
    ArchivoActividades archivoActividades;
    int op;
    subMenuActividades();
    cout<<"\n\nIngrese Opcion: ";
    cin>>op;
    rlutil::cls();
    switch(op)
    {
    case 1: ///Cargar una nueva actividad.
    {
        Actividad actividad;
        rlutil::cls();
        actividad.cargar();
        if(archivoActividades.guardar(actividad)==true)
        {
            rlutil::cls();
            rlutil::anykey("Actividad guardada exitosamente");
        }
        else
        {
            rlutil::cls();
            rlutil::anykey("No se guardó la actividad");
        }
    }
    break;
    case 2: ///Modificar una actividad.
    {
        rlutil::cls();
        Actividad actividad;
        if(archivoActividades.contarRegistros()!=0)
        {
            archivoActividades.mostrarTodas();
            int cod;
            cout<<"Código de actividad: ";
            cin>>cod;
            while(archivoActividades.validarExistenciaActividad(cod)==false)
            {
                cout<<"Código inválido. >";
                cin>>cod;
            }
            if(actividad.modificar(cod)==true)
            {
                rlutil::cls();
                rlutil::anykey("Actividad modificada exitosamente");
            }
            else
            {
                rlutil::cls();
                rlutil::anykey("No se modificó ninguna actividad");
            }
        }
        else
        {
            rlutil::cls();
            rlutil::anykey("El archivo Actividades esta vacío.");
            rlutil::cls();
            rlutil::anykey("No se modificó ninguna actividad");
        }
    }
    break;
    case 3: ///Mostrar todas las actividades cargadas.
    {
        rlutil::cls();
        ArchivoActividades archivoActividades;
        archivoActividades.mostrarTodas();
        rlutil::anykey();
    }
    break;
    case 0: ///Volver al menu principal.
    {
        *salir=true;
    }
    break;
    default:
    {
        rlutil::anykey("Opcion incorrecta");
    }
    break;
    }
    rlutil::cls();
}
Menu::subMenuBackup()
{
    cout<<"/--------------------------------\\"<<endl;
    cout<<"|        COPIA DE SEGURIDAD      |"<<endl;
    cout<<"|--------------------------------|"<<endl;
    cout<<"| 1 - REALIZAR                   |"<<endl;
    cout<<"|    1.Clientes                  |"<<endl;
    cout<<"|    2.Actividades por cliente   |"<<endl;
    cout<<"|    3.Actividades               |"<<endl;
    cout<<"|    4.Movimientos de caja       |"<<endl;
    cout<<"|    5.Abonos                    |"<<endl;
    cout<<"|    6.Pagos de cuotas           |"<<endl;
    cout<<"|    7.Arqueos de caja           |"<<endl;
    cout<<"|                                |"<<endl;
    cout<<"| 2 - RESTAURAR                  |"<<endl;
    cout<<"|    1.Clientes                  |"<<endl;
    cout<<"|    2.Actividades por cliente   |"<<endl;
    cout<<"|    3.Actividades               |"<<endl;
    cout<<"|    4.Movimientos de caja       |"<<endl;
    cout<<"|    5.Abonos                    |"<<endl;
    cout<<"|    6.Pagos de cuotas           |"<<endl;
    cout<<"|    7.Arqueos de caja           |"<<endl;
    cout<<"|--------------------------------|"<<endl;
    cout<<"| 0 - Volver al menú principal   |"<<endl;
    cout<<"\\--------------------------------/"<<endl;
}
Menu::switchSubMenuBackup(bool *salir)
{
    int op;
    subMenuBackup();
    cout<<"\n\nIngrese primer Opcion: ";
    cin>>op;
    switch(op)
    {
    case 1:
    {
        ///REALIZAR COPIA DE SEGURIDAD.
        cout<<"Ingrese segunda Opcion: ";
        cin>>op;
        rlutil::cls();
        switch(op)
        {
        case 1:
        {
            ArchivoClientes archivoClientes;
            if(archivoClientes.doBackup()==true)
            {
                rlutil::cls();
                rlutil::anykey("Copia de seguridad realizada correctamente.");
                rlutil::cls();
            }
            else
            {
                rlutil::cls();
                rlutil::anykey("Copia de seguridad NO realizada.");
                rlutil::cls();
            }
        }
        break;
        case 2:
        {
            ArchivoActividadesCliente archivoActividadesCliente;
            if(archivoActividadesCliente.doBackup()==true)
            {
                rlutil::cls();
                rlutil::anykey("Copia de seguridad realizada correctamente.");
                rlutil::cls();
            }
            else
            {
                rlutil::cls();
                rlutil::anykey("Copia de seguridad NO realizada.");
                rlutil::cls();
            }
        }
        break;
        case 3:
        {
            ArchivoActividades archivoActividades;
            if(archivoActividades.doBackup()==true)
            {
                rlutil::cls();
                rlutil::anykey("Copia de seguridad realizada correctamente.");
                rlutil::cls();
            }
            else
            {
                rlutil::cls();
                rlutil::anykey("Copia de seguridad NO realizada.");
                rlutil::cls();
            }
        }
        break;
        case 4:
        {
            ArchivoMovimientosCaja archivoMovimientosCaja;
            if(archivoMovimientosCaja.doBackup()==true)
            {
                rlutil::cls();
                rlutil::anykey("Copia de seguridad realizada correctamente.");
                rlutil::cls();
            }
            else
            {
                rlutil::cls();
                rlutil::anykey("Copia de seguridad NO realizada.");
                rlutil::cls();
            }
        }
        break;
        case 5:
        {
            ArchivoAbonos archivoAbonos;
            if(archivoAbonos.doBackup()==true)
            {
                rlutil::cls();
                rlutil::anykey("Copia de seguridad realizada correctamente.");
                rlutil::cls();
            }
            else
            {
                rlutil::cls();
                rlutil::anykey("Copia de seguridad NO realizada.");
                rlutil::cls();
            }
        }
        break;
        case 6:
        {
            ArchivoAbonosPorCliente archivoAbonosPorCliente;
            if(archivoAbonosPorCliente.doBackup()==true)
            {
                rlutil::cls();
                rlutil::anykey("Copia de seguridad realizada correctamente.");
                rlutil::cls();
            }
            else
            {
                rlutil::cls();
                rlutil::anykey("Copia de seguridad NO realizada.");
                rlutil::cls();
            }
        }
        break;
        case 7:
        {
            ArchivoArqueosDeCaja archivoArqueosDeCaja;
            if(archivoArqueosDeCaja.doBackup()==true)
            {
                rlutil::cls();
                rlutil::anykey("Copia de seguridad realizada correctamente.");
                rlutil::cls();
            }
            else
            {
                rlutil::cls();
                rlutil::anykey("Copia de seguridad NO realizada.");
                rlutil::cls();
            }
        }
        break;
        default:
        {
            rlutil::anykey("Opcion incorrecta");
        }
        break;
        }
    }
    break;
    case 2:
    {
        ///RESTAURAR COPIA DE SEGURIDAD.
        cout<<"Ingrese segunda Opcion: ";
        cin>>op;
        rlutil::cls();
        switch(op)
        {
        case 1:
        {
            ArchivoClientes archivoClientes;
            if(archivoClientes.restoreBackup()==true)
            {
                rlutil::cls();
                rlutil::anykey("Copia de seguridad restaurada correctamente.");
                rlutil::cls();
            }
            else
            {
                rlutil::cls();
                rlutil::anykey("Copia de seguridad NO restaurada.");
                rlutil::cls();
            }
        }
        break;
        case 2:
        {
            ArchivoActividadesCliente archivoActividadesCliente;
            if(archivoActividadesCliente.restoreBackup()==true)
            {
                rlutil::cls();
                rlutil::anykey("Copia de seguridad restaurada correctamente.");
                rlutil::cls();
            }
            else
            {
                rlutil::cls();
                rlutil::anykey("Copia de seguridad NO restaurada.");
                rlutil::cls();
            }
        }
        break;
        case 3:
        {
            ArchivoActividades archivoActividades;
            if(archivoActividades.restoreBackup()==true)
            {
                rlutil::cls();
                rlutil::anykey("Copia de seguridad restaurada correctamente.");
                rlutil::cls();
            }
            else
            {
                rlutil::cls();
                rlutil::anykey("Copia de seguridad NO restaurada.");
                rlutil::cls();
            }
        }
        break;
        case 4:
        {
            ArchivoMovimientosCaja archivoMovimientosCaja;
            if(archivoMovimientosCaja.restoreBackup()==true)
            {
                rlutil::cls();
                rlutil::anykey("Copia de seguridad restaurada correctamente.");
                rlutil::cls();
            }
            else
            {
                rlutil::cls();
                rlutil::anykey("Copia de seguridad NO restaurada.");
                rlutil::cls();
            }
        }
        break;
        case 5:
        {
            ArchivoAbonos archivoAbonos;
            if(archivoAbonos.restoreBackup()==true)
            {
                rlutil::cls();
                rlutil::anykey("Copia de seguridad restaurada correctamente.");
                rlutil::cls();
            }
            else
            {
                rlutil::cls();
                rlutil::anykey("Copia de seguridad NO restaurada.");
                rlutil::cls();
            }
        }
        break;
        case 6:
        {
            ArchivoAbonosPorCliente archivoAbonosPorCliente;
            if(archivoAbonosPorCliente.restoreBackup()==true)
            {
                rlutil::cls();
                rlutil::anykey("Copia de seguridad restaurada correctamente.");
                rlutil::cls();
            }
            else
            {
                rlutil::cls();
                rlutil::anykey("Copia de seguridad NO restaurada.");
                rlutil::cls();
            }
        }
        break;
        case 7:
        {
            ArchivoArqueosDeCaja archivoArqueosDeCaja;
            if(archivoArqueosDeCaja.restoreBackup()==true)
            {
                rlutil::cls();
                rlutil::anykey("Copia de seguridad restaurada correctamente.");
                rlutil::cls();
            }
            else
            {
                rlutil::cls();
                rlutil::anykey("Copia de seguridad NO restaurada.");
                rlutil::cls();
            }
        }
        break;
        default:
        {
            rlutil::cls();
            rlutil::anykey("Opcion incorrecta");
        }
        break;
        }
    }
    break;
    case 0:
    {
        *salir=true;
    }
    break;
    default:
    {
        rlutil::cls();
        rlutil::anykey("Opcion incorrecta");
    }
    break;
    }
    rlutil::cls();
}
Menu::subMenuCaja()
{
    cout<<"/--------------------------------\\"<<endl;
    cout<<"|       MOVIMIENTOS DE CAJA      |"<<endl;
    cout<<"|--------------------------------|"<<endl;
    cout<<"| 1 - Nuevo ingreso              |"<<endl;
    cout<<"| 2 - Modificar                  |"<<endl;
    cout<<"| 3 - Buscar                     |"<<endl;
    cout<<"| 4 - Listar Todos               |"<<endl;
    cout<<"| 5 - Arqueo de caja             |"<<endl;
    cout<<"|--------------------------------|"<<endl;
    cout<<"| 0 - Volver al menú principal   |"<<endl;
    cout<<"\\--------------------------------/"<<endl;
}
Menu::switchSubMenuCaja(bool *salir)
{
    MovimientoCaja movimientoCaja;
    ArchivoMovimientosCaja archivoMovimientosCaja;
    int op;
    subMenuCaja();
    cout<<"\n\nIngrese opción: ";
    cin>>op;
    rlutil::cls();
    switch(op)
    {
    case 1:
    {
        ///Cargar nuevo movimiento de caja.
        subMenuCargarMovimientoCaja();
        cout<<endl<<"Ingrese tipo de movimiento: ";
        int op2;
        cin>>op2;
        while(op2!=1 && op2!=2)
        {
            cout<<"Opción inválida\r";
            Sleep(1500);
            cout<<"               \r";
            cout<<"Reintente >";
            cin>>op2;
        }
        rlutil::cls();
        if(op2==1)
        {
            movimientoCaja.cargarIngreso();
        }
        else
        {
            movimientoCaja.cargarSalida();
        }
        if(archivoMovimientosCaja.guardar(movimientoCaja)==true)
        {
            rlutil::cls();
            rlutil::anykey("Movimiento de caja guardado exitosamente");
        }
        else
        {
            rlutil::cls();
            rlutil::anykey("No se pudo guardar el movimiento de caja");
        }
    }
    break;
    case 2:
    {
        ///Modificar movimiento de caja.
        rlutil::cls();
        int cant=archivoMovimientosCaja.contarRegistros();
        if(cant!=0)
        {
            int id;
            cout<<"ID: ";
            cin>>id;
            while(id<1 || id>cant)
            {
                cout<<"ID inválido\r";
                Sleep(1500);
                cout<<"           \r";
                cout<<"Reintente >";
                cin>>id;
            }
            if(movimientoCaja.modificar(id)==true)
            {
                rlutil::cls();
                rlutil::anykey("Movimiento de caja modificado exitosamente");
            }
            else
            {
                rlutil::cls();
                rlutil::anykey("No se modificó el movimiento de caja");
            }
        }
        else
        {
            rlutil::cls();
            rlutil::anykey("El archivo MovimientosCaja está vacío.");
            rlutil::cls();
            rlutil::anykey("No se modificó ningun movimiento de caja");
        }
    } break;
    case 3:
    {
        ///Buscar movimiento de caja.
        if(archivoMovimientosCaja.contarRegistros()!=0)
        {
            bool volverSubMenuMovimientos=false;
            while(!volverSubMenuMovimientos)
            {
                rlutil::cls();
                switchSubMenuBuscarMovimientoCaja(&volverSubMenuMovimientos);
            }
        }
        else
        {
            rlutil::cls();
            rlutil::anykey("El archivo MovimientosCaja está vacío.");
            rlutil::cls();
        }
    }
    break;
    case 4:
    {
        ///Mostrar todos los movimientos de caja.
        rlutil::cls();
        int cant=archivoMovimientosCaja.contarRegistros();
        if(cant>0)
        {
            cout<<"Cantidad total de registros en archivo: "<<cant<<endl<<endl;
            archivoMovimientosCaja.mostrarTodos(cant);
        }
        else
        {
            cout<<"El archivo de MovimientosCaja está vacío.";
        }
        rlutil::anykey();
    }
    break;
    case 5:
    {
        ///Arqueo de caja.
        ArchivoArqueosDeCaja archivoArqueosDeCaja;
        cout<<"                         ARQUEO DE CAJA     "<<endl<<endl;
        if(archivoArqueosDeCaja.contarRegistros()==0)
        {
            rlutil::cls();
            rlutil::anykey("El archivo ArqueosCaja está vacío.");
            rlutil::cls();
        }
        else
        {
            cout<<" ¿Desea ejecutarlo para la fecha actual o una fecha anterior?"<<endl;
            cout<<" 1(Actual) / 2(Anterior) / 0(Volver al menu anterior): ";
            int op;
            cin>>op;
            while(op!=1 && op!=2 && op!=0)
            {
                cout<<"Opción incorrecta\r";
                Sleep(1500);
                cout<<"                 \r";
                cout<<"Reintente >";
                cin>>op;
            }
            Fecha fecha;
            if(op==2)
            {
                cout<<" Fecha: ";
                fecha=fecha.cargar();
                while(archivoArqueosDeCaja.buscarPorFechaCompleta(fecha)!=-1)
                {
                    cout<<"Ya existe un arqueo de caja para la fecha ingresada.\r";
                    Sleep(2000);
                    cout<<"                                                    \r";
                    cout<<"Reintente >";
                    fecha=fecha.cargar();
                }
            }
            else if(op==1)
            {
                fecha=fecha.fechaActual();
                if(archivoArqueosDeCaja.buscarPorFechaCompleta(fecha)!=-1)
                {
                    rlutil::anykey("Ya existe un arqueo de caja para la fecha ingresada.");
                    exit;
                }
            }
            if(op!=0)
            {
                Reporte reporte;
                float dineroEnSistema=reporte.calcularDineroEnSistemaPorFecha(fecha);
                if(dineroEnSistema==-1)
                {
                    rlutil::cls();
                    rlutil::anykey("Error de lectura del archivo MovimientosCaja");
                }
                else
                {
                    rlutil::cls();
                    cout<<"     ARQUEO DE CAJA     "<<endl<<endl;
                    cout<<endl<<" Dinero según sistema: $"<<dineroEnSistema;
                    cout<<endl<<" Dinero en caja: $";
                    float dineroEnCaja;
                    cin>>dineroEnCaja;
                    float diferenciaCaja=dineroEnCaja-dineroEnSistema;
                    cout<<endl<<" Para el día ";
                    fecha.mostrar();
                    if(diferenciaCaja==0){cout<<" no hubo diferencias de caja.";}
                    if(diferenciaCaja<0){cout<<" hubo un faltante de caja.";}
                    if(diferenciaCaja>0){cout<<" hubo un sobrante de caja.";}
                    cout<<endl<<" Saldo= $"<<diferenciaCaja;
                    rlutil::anykey();
                    ArqueoDeCaja arqueoDeCaja;
                    arqueoDeCaja.cargar(fecha,diferenciaCaja);
                    if(archivoArqueosDeCaja.guardar(arqueoDeCaja)==true)
                    {
                        rlutil::cls();
                        rlutil::anykey("Arqueo de caja guardado exitosamente.");
                        rlutil::cls();
                    }
                    else
                    {
                        rlutil::cls();
                        rlutil::anykey("No se pudo guardar el arqueo de caja.");
                        rlutil::cls();
                    }
                }
            }
        }
    }
    break;
    case 0:
    {
        *salir=true;
    }
    break;
    default:
    {
        rlutil::cls();
        rlutil::anykey("Opcion incorrecta");
    }
    break;
    }
    rlutil::cls();
}
Menu::subMenuCargarMovimientoCaja()
{
    cout<<"/--------------------------------\\"<<endl;
    cout<<"|        CARGAR MOVIMIENTO       |"<<endl;
    cout<<"|--------------------------------|"<<endl;
    cout<<"| 1 - Ingreso                    |"<<endl;
    cout<<"| 2 - Salida                     |"<<endl;
    cout<<"\\--------------------------------/"<<endl;
}
Menu::subMenuCamposMovimientosCaja()
{
    cout<<" 1 - Detalle"<<endl;
    cout<<" 2 - Monto ($)"<<endl;
    cout<<" 3 - Tipo de movimiento (ingreso / salida)"<<endl;
    cout<<" 4 - Tipo de pago (parcial / total)"<<endl;
    cout<<" 5 - Fecha de movimiento"<<endl;
    cout<<"------------------------------------------"<<endl;
    cout<<" 0 - Volver al menú movimientos"<<endl;
}
Menu::subMenuBuscarMovimientoCaja()
{
    cout<<"/--------------------------------\\"<<endl;
    cout<<"|        BUSCAR MOVIMIENTO       |"<<endl;
    cout<<"|--------------------------------|"<<endl;
    cout<<"| 1 - Por ID                     |"<<endl;
    cout<<"| 2 - Por Mes y Año              |"<<endl;
    cout<<"|--------------------------------|"<<endl;
    cout<<"| 0 - Volver al menú MOVIMIENTOS |"<<endl;
    cout<<"\\--------------------------------/"<<endl;
}
Menu::subMenuArqueosDeCaja()
{
    cout<<"/----------------------------------------------\\"<<endl;
    cout<<"|                ARQUEOS DE CAJA               |"<<endl;
    cout<<"|----------------------------------------------|"<<endl;
    cout<<"| 1 - Buscar de un dia en particular           |"<<endl;
    cout<<"| 2 - Calcular de un mes y año en particular   |"<<endl;
    cout<<"| 3 - Calcular de un año en particular         |"<<endl;
    cout<<"|----------------------------------------------|"<<endl;
    cout<<"| 0 - Volver al menu MOVIMIENTOS DE CAJA       |"<<endl;
    cout<<"\\---------------------------------------------/"<<endl;
}
Menu::switchSubMenuBuscarMovimientoCaja(bool *salir)
{
    MovimientoCaja movimientoCaja;
    ArchivoMovimientosCaja archivoMovimientosCaja;
    int op;
    subMenuBuscarMovimientoCaja();
    cout<<"\n\nIngrese Opción: ";
    cin>>op;
    rlutil::cls();
    switch(op)
    {
    case 1: ///Buscar movimiento por ID.
    {
        int pos, id, cantidadMovimientos=archivoMovimientosCaja.contarRegistros();
        cout<<"------------BUSCAR MOVIMIENTO DE CAJA POR ID------------"<<endl<<endl;
        cout<<"ID: ";
        cin>>id;
        while(id<1 || id>cantidadMovimientos)
        {
            rlutil::cls();
            cout<<"------------BUSCAR MOVIMIENTO DE CAJA POR ID------------"<<endl<<endl;
            cout<<"ID inexistente. Reintente >";
            cin>>id;
        }
        pos=archivoMovimientosCaja.buscarPorId(id);
        movimientoCaja=archivoMovimientosCaja.leer(pos);
        cout<<endl;
        movimientoCaja.mostrar();
        rlutil::anykey();
    }
    break;
    case 2: ///Buscar movimiento por Año y Mes.
    {
        Fecha f=f.fechaActual();
        int mes, anio;
        cout<<"------------BUSCAR MOVIMIENTO DE CAJA POR AÑO Y MES------------"<<endl<<endl;
        cout<<"Año: ";
        cin>>anio;
        while(anio<2000 || anio>f.getAnio())
        {
            rlutil::cls();
            cout<<"------------BUSCAR MOVIMIENTO DE CAJA POR AÑO Y MES------------"<<endl<<endl;
            cout<<"Año inválido. Reintente >";
            cin>>anio;
        }
        cout<<endl<<"Mes: ";
        cin>>mes;
        while(mes<1 || mes>12)
        {
            cout<<endl<<"Mes inválido. Reintente >";
            cin>>mes;
        }
        archivoMovimientosCaja.buscarPorMesAnio(mes,anio);
        rlutil::anykey();
    }
    break;
    case 0: ///Volver al menu movimientos de caja.
    {
        *salir=true;
    }
    break;
    default:
    {
        rlutil::cls();
        rlutil::anykey("Opción incorrecta.");
    }
    break;
    }
    rlutil::cls();
}
Menu::subMenuAbonos()
{
    cout<<"/--------------------------------\\"<<endl;
    cout<<"|       ABONOS EN GIMNASIO       |"<<endl;
    cout<<"|--------------------------------|"<<endl;
    cout<<"| 1 - Nuevo ingreso              |"<<endl;
    cout<<"| 2 - Modificar                  |"<<endl;
    cout<<"| 3 - Buscar                     |"<<endl;
    cout<<"| 4 - Listar todos               |"<<endl;
    cout<<"|--------------------------------|"<<endl;
    cout<<"| 0 - Volver al menú principal   |"<<endl;
    cout<<"\\--------------------------------/"<<endl;
}
Menu::switchSubMenuAbonos(bool *salir)
{
    ArchivoAbonos archivoAbonos;
    int op;
    subMenuAbonos();
    cout<<"\n\nIngrese Opción: ";
    cin>>op;
    rlutil::cls();
    switch(op)
    {
    case 1: ///Cargar nuevo abono.
    {
        rlutil::cls();
        Abono abono;
        abono.cargar();
        if(archivoAbonos.guardar(abono))
        {
            rlutil::cls();
            rlutil::anykey("Abono guardado exitosamente");
        }
        else
        {
            rlutil::cls();
            rlutil::anykey("No se pudo guardar el abono");
        }
    }
    break;
    case 2: ///Modificar abono.
    {
        Abono abono;
        rlutil::cls();
        if(archivoAbonos.contarRegistros()!=0)
        {
            int cod;
            cout<<"Código: ";
            cin>>cod;
            while(archivoAbonos.buscarPorCodigo(cod)==-1)
            {
                cout<<"Código inexistente\r";
                Sleep(1500);
                cout<<"                  \r";
                cout<<"Reintente >";
                cin>>cod;
            }
            if(abono.modificar(cod)==true)
            {
                rlutil::cls();
                rlutil::anykey("Abono modificado exitosamente");
            }
            else
            {
                rlutil::cls();
                rlutil::anykey("No se modificó el abono");
            }
        }
        else
        {
            rlutil::cls();
            rlutil::anykey("El archivo Abonos está vacío.");
            rlutil::cls();
            rlutil::anykey("No se modificó ningún abono");
        }
    }
    break;
    case 3: ///Buscar abono.
    {
        if(archivoAbonos.contarRegistros()==0)
        {
            rlutil::anykey("El archivo de abonos está vacío.");
        }
        else
        {
            bool volverSubMenuAbonos=false;
            while(!volverSubMenuAbonos)
            {
                rlutil::cls();
                switchSubMenuBuscarAbono(&volverSubMenuAbonos);
            }
        }
    }
    break;
    case 4: ///Mostrar todos los abonos.
    {
        rlutil::cls();
        if(archivoAbonos.contarRegistros()==0)
        {
            rlutil::anykey("El archivo de abonos está vacío.");
        }
        else
        {
            cout<<"Cantidad total de abonos en archivo: "<<archivoAbonos.contarRegistros()<<endl<<endl;
            archivoAbonos.mostrarTodos();
            rlutil::anykey();
        }
    }
    break;
    case 0: ///Volver al menu principal.
    {
        *salir=true;
    }
    break;
    default:
    {
        rlutil::cls();
        rlutil::anykey("Opción incorrecta.");
    }
    break;
    }
    rlutil::cls();
}
Menu::subMenuBuscarAbono()
{
    cout<<"/------------------------------\\"<<endl;
    cout<<"|         BUSCAR ABONO         |"<<endl;
    cout<<"|------------------------------|"<<endl;
    cout<<"| 1 - Por código               |"<<endl;
    cout<<"| 2 - Por nombre               |"<<endl;
    cout<<"|------------------------------|"<<endl;
    cout<<"| 0 - Volver al menu ABONOS    |"<<endl;
    cout<<"\\------------------------------/"<<endl;
}
Menu::switchSubMenuBuscarAbono(bool *salir)
{
    ArchivoAbonos archivoAbonos;
    int op;
    subMenuBuscarAbono();
    cout<<"\n\nIngrese Opcion: ";
    cin>>op;
    rlutil::cls();
    switch(op)
    {
    case 1: ///Buscar abono por código.
    {
        Abono abono;
        int pos, codigo, cantidadAbonos=archivoAbonos.contarRegistros();
        cout<<"------------BUSCAR ABONO POR CÓDIGO------------"<<endl<<endl;
        cout<<"Código: ";
        cin>>codigo;
        while(codigo<1 || codigo>cantidadAbonos)
        {
            rlutil::cls();
            cout<<"------------BUSCAR ABONO POR CÓDIGO------------"<<endl<<endl;
            cout<<"Código inexistente\r";
            Sleep(1500);
            cout<<"                  \r";
            cout<<"Reintente >";
            cin>>codigo;
        }
        pos=archivoAbonos.buscarPorCodigo(codigo);
        abono=archivoAbonos.leer(pos);
        cout<<endl;
        abono.mostrar();
        rlutil::anykey();
    }
    break;
    case 2: ///Buscar abono por nombre.
    {
        Abono abono;
        cin.ignore();
        int pos;
        char nombre[30];
        cout<<"------------BUSCAR ABONO POR NOMBRE------------"<<endl<<endl;
        cout<<"Nombre: ";
        cin.getline(nombre,50);
        while(abono.validarCadenaVacia(nombre)==false)
        {
            cin.getline(nombre,50);
        }
        pos=archivoAbonos.buscarPorNombre(nombre);
        int reintentos=0;
        while(pos<0 && *salir==false)
        {
            if(reintentos<2)
            {
                rlutil::cls();
                cout<<"------------BUSCAR ABONO POR NOMBRE------------"<<endl<<endl;
                cout<<"Nombre incompleto o inexistente en archivo.\r";
                Sleep(1500);
                cout<<"                                           \r";
                cout<<endl<<"Nombre: ";
                cin.getline(nombre,50);
                while(abono.validarCadenaVacia(nombre)==false)
                {
                    cin.getline(nombre,50);
                }
                pos=archivoAbonos.buscarPorNombre(nombre);
                reintentos++;
            }
            else
            {
                rlutil::cls();
                cout<<"Demasiados intentos incorrectos. Se saldrá de la búsqueda actual.";
                Sleep(1500);
                *salir=true;
            }
        }
        if(pos!=-1 && pos!=-2)
        {
            abono=archivoAbonos.leer(pos);
            cout<<endl;
            abono.mostrar();
            rlutil::anykey();
        }
    }
    break;
    case 0: ///Volver al sub menu ABONOS.
    {
        *salir=true;
    }
    break;
    default:
    {
        rlutil::anykey("Opcion incorrecta");
    }
    break;
    }
    rlutil::cls();
}
Menu::subMenuAbonosPorCliente()
{
    cout<<"/-------------------------------------------\\"<<endl;
    cout<<"|               PAGOS DE CUOTA              |"<<endl;
    cout<<"|-------------------------------------------|"<<endl;
    cout<<"| 1 - Nuevo ingreso                         |"<<endl;
    cout<<"| 2 - Modificar                             |"<<endl;
    cout<<"| 3 - Buscar por DNI y período abonado      |"<<endl;
    cout<<"| 4 - Listar todos a partir de un DNI       |"<<endl;
    cout<<"| 5 - Listar todos los pagos registrados    |"<<endl;
    cout<<"|-------------------------------------------|"<<endl;
    cout<<"| 0 - Volver al menú principal              |"<<endl;
    cout<<"\\-------------------------------------------/"<<endl;
}
Menu::subMenuCamposAbonoCliente()
{
    cout<<" 1 - DNI"<<endl;
    cout<<" 2 - Nombres"<<endl;
    cout<<" 3 - Apellidos"<<endl;
    cout<<" 4 - Monto $"<<endl;
    cout<<" 5 - Tipo de pago"<<endl;
    cout<<" 6 - Período abonado"<<endl;
    cout<<" 0 - Volver al menú Pago Cuota"<<endl;
}
Menu::switchSubMenuAbonosPorCliente(bool *salir)
{
    int op;
    subMenuAbonosPorCliente();
    cout<<"\n\nIngrese Opcion: ";
    cin>>op;
    rlutil::cls();
    ArchivoAbonosPorCliente archivoAbonosPorCliente;
    switch(op)
    {
    case 1: ///Registrar nuevo pago de cuota para un cliente.
    {
        rlutil::cls();
        AbonoCliente abonoCliente;
        if(abonoCliente.cargar()==false)
        {
            rlutil::cls();
            rlutil::anykey("No se pudo registrar el pago de la cuota.");
            rlutil::cls();
            return 0;
        }
        cout<<endl<<"Cliente: "<<abonoCliente.getNombres()<<" "<<abonoCliente.getApellidos();
        cout<<endl<<endl<<"El monto total a abonar es: $"<<abonoCliente.getMonto();
        cout<<endl<<endl<<"¿Confirma pago? 1(Si) / 0(No): ";
        int op;
        cin>>op;
        while(op!=1 && op!=0)
        {
            cout<<"Opción inválida\r";
            Sleep(1500);
            cout<<"               \r";
            cout<<"Reintente >";
            cin>>op;
        }
        if(op==1)
        {
            ArchivoAbonosPorCliente archivoAbonosPorCliente;
            if(archivoAbonosPorCliente.guardar(abonoCliente))
            {
              rlutil::cls();
              ArchivoMovimientosCaja archivoMovimientosCaja;
              MovimientoCaja movimientoCaja;
              movimientoCaja.cargarAbonoCliente(abonoCliente.getNombres(),abonoCliente.getApellidos(),abonoCliente.getMonto(),abonoCliente.getPagoTotal(),abonoCliente.getPagoParcial(),abonoCliente.getFechaPago());
              if(archivoMovimientosCaja.guardar(movimientoCaja))
              {
                rlutil::anykey("El pago de la cuota se registro correctamente");
              }
              rlutil::cls();
              return 0;
            }
            else
            {
              rlutil::cls();
              rlutil::anykey("No se registró el pago de la cuota.");
              rlutil::cls();
              return 0;
            }
        }
        else
        {
            rlutil::cls();
            rlutil::anykey("No se registró el pago de la cuota.");
            rlutil::cls();
            return 0;
        }
    }
    break;
    case 2: ///Modificar pago de cuota.
    {
        rlutil::cls();
        AbonoCliente abonoCliente;
        if(archivoAbonosPorCliente.contarRegistros()!=0)
        {
            int dni, mesPagado, anioPagado;
            cout<<"DNI: ";
            cin>>dni;
            cout<<"Mes abonado: ";
            cin>>mesPagado;
            cout<<"Año abonado: ";
            cin>>anioPagado;
            if(abonoCliente.modificar(dni,mesPagado,anioPagado)==true)
            {
                rlutil::cls();
                rlutil::anykey("Pago de cuota modificado exitosamente");
            }
            else
            {
                rlutil::cls();
                rlutil::anykey("No se modificó ningun pago de cuota");
            }
        }
        else
        {
            rlutil::cls();
            rlutil::anykey("El archivo AbonosPorCliente está vacío.");
            rlutil::cls();
            rlutil::anykey("No se modificó ningun pago de cuota");
        }
    }
    break;
    case 3: ///Buscar pago de cuota a partir del dni de un cliente y período abonado (mes y año).
    {
        if(archivoAbonosPorCliente.contarRegistros()==0)
        {
            rlutil::cls();
            rlutil::anykey("El archivo AbonosPorCliente está vacío.");
            rlutil::cls();
        }
        else
        {
            rlutil::cls();
            int dni, mes, anio;
            Fecha fecha;
            cout<<"----------PAGO DE CUOTA-----------";
            cout<<endl<<endl<<"DNI: ";
            cin>>dni;
            ///VALIDAR QUE EL DNI EXISTA EN EL GIMNASIO
            cout<<"Período abonado:";
            cout<<endl<<"Mes: ";
            cin>>mes;
            fecha.validarMes(&mes);
            cout<<"Año: ";
            cin>>anio;
            fecha.validarAnio(&anio);
            AbonoCliente abonoCliente;
            int pos=archivoAbonosPorCliente.buscarPorDni_yPeriodoAbonado(dni,mes,anio);
            if(pos!=-1)
            {
                abonoCliente=archivoAbonosPorCliente.leer(pos);
                rlutil::cls();
                cout<<"DNI: "<<dni<<"  -  "<<"Período abonado: "<<mes<<" - "<<anio<<endl<<endl;
                abonoCliente.mostrar();
                rlutil::anykey();
            }
            rlutil::cls();
            rlutil::anykey("No se encontró ningún pago de cuota para el período ingresado.");
        }
    }
    break;
    case 4: ///Mostrar todos por DNI.
    {
        if(archivoAbonosPorCliente.contarRegistros()==0)
        {
            rlutil::cls();
            rlutil::anykey("El archivo AbonosPorCliente está vacío.");
            rlutil::cls();
        }
        else
        {
            rlutil::cls();
            int dni;
            cout<<"----------PAGOS DE CUOTA POR DNI-----------";
            cout<<endl<<endl<<"DNI: ";
            cin>>dni;
            cin.ignore();
            ArchivoClientes archivoClientes;
            int intentos=0;
            if(archivoClientes.contarRegistros()==0)
            {
                rlutil::cls();
                rlutil::anykey("El DNI ingresado no existe en el gimnasio.");
                rlutil::cls();
            }
            else
            {
                while(archivoClientes.buscarPorDNI(dni)==-1 && intentos<3)
                {
                    intentos++;
                    cout<<"El DNI ingresado no existe en el gimnasio\r";
                    Sleep(1500);
                    cout<<"                                         \r";
                    cout<<"Reintente >";
                    cin>>dni;
                }
                if(archivoClientes.buscarPorDNI(dni)!=-1)
                {
                    cout<<endl;
                    if(archivoAbonosPorCliente.contarRegistrosPorDni(dni)>0)
                    {
                        rlutil::cls();
                        archivoAbonosPorCliente.mostrarTodosPorDni(dni);
                        rlutil::anykey();
                    }
                    else
                    {
                        rlutil::cls();
                        rlutil::anykey("No existen pagos de cuota para el DNI ingresado");
                    }
                }
            }
        }
    }
    break;
    case 5: ///Mostrar todos los pagos de cuota.
    {
        rlutil::cls();
        if(archivoAbonosPorCliente.contarRegistros()>0)
        {
            archivoAbonosPorCliente.mostrarTodos();
            rlutil::anykey();
        }
        else
        {
            rlutil::cls();
            rlutil::anykey("El archivo AbonosPorCliente está vacío");
        }
    }
    break;
    case 0: ///Volver al menu principal.
    {
        *salir=true;
    }
    break;
    default:
    {
        rlutil::anykey("Opcion incorrecta");
    }
    break;
    }
    rlutil::cls();
}
Menu::subMenuReportes()
{
    cout<<"/----------------------------------------\\"<<endl;
    cout<<"|          CONSULTAS / REPORTES          |"<<endl;
    cout<<"|----------------------------------------|"<<endl;
    cout<<"| 1 - Consultar apto médico              |"<<endl;
    cout<<"| 2 - Consultar estado de cuotas por año |"<<endl;
    cout<<"| 3 - Reporte de ingresos por mes y año  |"<<endl;
    cout<<"| 4 - Reporte de arqueos de caja         |"<<endl;
    cout<<"|----------------------------------------|"<<endl;
    cout<<"| 0 - Volver al menú principal           |"<<endl;
    cout<<"\\----------------------------------------/"<<endl;
}
Menu::switchSubMenuReportes(bool *salir)
{
    int op;
    subMenuReportes();
    cout<<"\n\nIngrese Opcion: ";
    cin>>op;
    rlutil::cls();
    switch(op)
    {
    case 1:
    {
        ///CONSULTA 1.
        //Consultar apto médico.

        ArchivoClientes archivoClientes;
        if(archivoClientes.contarRegistros()==0)
        {
            rlutil::cls();
            rlutil::anykey("El archivo Clientes está vacío.");
            rlutil::cls();
        }
        else
        {
            cout<<"     CONSULTA DE APTO MÉDICO POR DNI     "<<endl<<endl;
            int dni, pos;
            cout<<"DNI: ";
            cin>>dni;
            pos=archivoClientes.buscarPorDNI(dni);
            Cliente cliente=archivoClientes.leer(pos);
            if(cliente.getAptoMedico()==true){rlutil::anykey("\n    Apto médico al día.");}
            else
            {
                if(pos!=-1){rlutil::anykey("\n     No tiene apto médico al día.");}
            }
        }
    }
    break;
    case 2:
    {
        ///CONSULTA 2
        //Consultar estado de cuotas por año

        ArchivoClientes archivoClientes;
        if(archivoClientes.contarRegistros()==0)
        {
            rlutil::cls();
            rlutil::anykey("El archivo Clientes está vacío.");
            rlutil::cls();
        }
        else
        {
            cout<<"     CONSULTA DE ESTADO ANUAL DE CUOTAS POR DNI     "<<endl<<endl;
            int dni, anio, pos, pos2;
            Cliente cliente;
            cout<<"DNI: ";
            cin>>dni;
            pos2=archivoClientes.buscarPorDNI(dni);
            while(cliente.contarDigitosDni(dni)==false || pos2==-1) ///VALIDAR FORMATO DNI Y EXISTENCIA EN ARCHIVO.
            {
                rlutil::cls();
                cout<<"DNI inválido o no existe en sistema\r";
                Sleep(1500);
                cout<<"                                   \r";
                cout<<"DNI >";
                cin>>dni;
                pos2=archivoClientes.buscarPorDNI(dni);
            }
            cout<<"Año: ";
            cin>>anio;
            Fecha fecha;
            fecha.validarAnio(&anio);
            cliente=archivoClientes.leer(pos2);
            if(anio<cliente.getAlta().getAnio())
            {
                rlutil::anykey("\n     El cliente no era socio del gimnasio durante el año ingresado");
            }
            else
            {
                int meses[12]={};
                bool mesesActivos[12];
                int anio2=cliente.getAlta().getAnio();
                if(anio==anio2)
                {
                    for(int i=0;i<12;i++)
                    {
                        mesesActivos[i]=false;
                    }
                }
                else if(anio>anio2)
                {
                    for(int i=0;i<12;i++)
                    {
                        mesesActivos[i]=true;
                    }
                }
                Reporte reporte;
                if(reporte.mostrarEstadoCuotasMensualesPorDniAnio(mesesActivos,meses,dni,anio)==false){exit;}
                rlutil::cls();
                reporte.mostrarEstadoCuotas(mesesActivos,meses,dni,anio,cliente.getNames(),cliente.getSurnames());
                rlutil::anykey();
            }
        }
    }
    break;
    case 3:
    {
        ///REPORTE 1.
        //Reporte de ingresos y egresos por mes y por año;

        ArchivoMovimientosCaja archivoMovimientosCaja;
        if(archivoMovimientosCaja.contarRegistros()==0)
        {
            rlutil::cls();
            rlutil::anykey("El archivo MovimientosCaja está vacío.");
            rlutil::cls();
        }
        else
        {
            int anio;
            cout<<"Año: ";
            cin>>anio;
            rlutil::cls();
            Fecha fecha;
            fecha.validarAnio(&anio);
            if(anio<2020){rlutil::anykey("\n    Año inválido. El gimnasio comenzo a operar en 2020");}
            else
            {
                float vecEntradas[12]={}, vecSalidas[12]={};
                Reporte reporte;
                reporte.calcularIngresosEgresosMensualesPorAnio(anio,vecEntradas,vecSalidas);
                reporte.mostrarBalanceMensualAnual(vecEntradas,vecSalidas,anio);
                rlutil::anykey();
            }
        }
    }
    break;
    case 4:
    {
        ///REPORTE 2.
        //Arqueos de caja.

        ArchivoArqueosDeCaja archivoArqueosDeCaja;
        if(archivoArqueosDeCaja.contarRegistros()==0)
        {
            rlutil::cls();
            rlutil::anykey("El archivo ArqueosCaja está vacío.");
            rlutil::cls();
        }
        else
        {
            int op;
            subMenuArqueosDeCaja();
            cout<<"\n\nIngrese Opcion: ";
            cin>>op;
            rlutil::cls();
            ArchivoArqueosDeCaja archivoArqueosDeCaja;
            ArqueoDeCaja arqueoDeCaja;
            switch(op)
            {
            case 1: //Buscar arqueo de un dia en particular
            {
                Fecha fecha;
                cout<<"     BUSCAR ARQUEO DE CAJA DE UN DIA EN PARTICULAR     "<<endl<<endl;
                cout<<"Fecha: ";
                fecha=fecha.cargar();
                int pos=archivoArqueosDeCaja.buscarPorFechaCompleta(fecha);
                arqueoDeCaja=archivoArqueosDeCaja.leer(pos);
                arqueoDeCaja.mostrar();
                rlutil::anykey();
            }
            break;
            case 2: //Calcular arqueos de un mes en particular
            {
                int mes, anio;
                cout<<"     CALCULAR ARQUEOS DE CAJA DE UN MES EN PARTICULAR     "<<endl<<endl;
                cout<<"Mes: ";
                cin>>mes;
                cout<<"Año: ";
                cin>>anio;
                float saldo=archivoArqueosDeCaja.calcularArqueoPorMesAnio(mes,anio);
                rlutil::cls();
                cout<<"     CALCULAR ARQUEOS DE CAJA DE UN MES EN PARTICULAR     "<<endl<<endl;
                cout<<"El saldo de caja en el mes de ";
                archivoArqueosDeCaja.mostrarMesCalculado(mes);
                cout<<" del año "<<anio<<" es de $"<<saldo;
                rlutil::anykey();
            }
            break;
            case 3: //Calcular arqueos de un año en particular
            {
                cout<<"     CALCULAR ARQUEOS DE CAJA DE UN AÑO EN PARTICULAR     "<<endl<<endl;
                int anio;
                cout<<"Año: ";
                cin>>anio;
                float saldo=archivoArqueosDeCaja.calcularArqueoPorAnio(anio);
                rlutil::cls();
                cout<<"     CALCULAR ARQUEOS DE CAJA DE UN AÑO EN PARTICULAR     "<<endl<<endl;
                cout<<"El saldo de caja del año "<<anio<<" es de $"<<saldo;
                rlutil::anykey();
            }
            break;
            case 0:
            {
                exit;
            }
            break;
            default:
            {
                rlutil::anykey("Opcion incorrecta");
            }
            break;
            }
            rlutil::cls();
        }
    }
    break;
    case 0:
    {
        *salir=true;
    }
    break;
    default:
    {
        rlutil::anykey("Opcion incorrecta");
    }
    break;
    }
    rlutil::cls();
}

