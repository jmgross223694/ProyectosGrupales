#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include "rlutil.h"
#include "movimientos_de_caja.h"
#include "archivo_movimientos_de_caja.h"
#include "fecha.h"
#include "menu.h"
using namespace std;


MovimientoCaja::MovimientoCaja()
{
    strcpy(detalle,"VACIO");
    monto=0;
    entrada=false;
    salida=false;
    pagoParcial=false;
    pagoTotal=false;
    fecha.setDia(-1);
    fecha.setMes(-1);
    fecha.setAnio(-1);
}
void MovimientoCaja::setId(int i)
{
    id=i;
}
void MovimientoCaja::setDetalle(char *cad)
{
    strcpy(detalle,cad);
}
void MovimientoCaja::setMonto(float m)
{
    monto=m;
}
void MovimientoCaja::setEntrada(bool e)
{
    entrada=e;
}
void MovimientoCaja::setSalida(bool s)
{
    salida=s;
}
void MovimientoCaja::setPagoParcial(bool p)
{
    pagoParcial=p;
}
void MovimientoCaja::setPagoTotal(bool t)
{
    pagoTotal=t;
}
void MovimientoCaja::setFecha(Fecha f)
{
    fecha.setDia(f.getDia());
    fecha.setMes(f.getMes());
    fecha.setAnio(f.getAnio());
}
int MovimientoCaja::getId()
{
    return id;
}
char* MovimientoCaja::getDetalle()
{
    return detalle;
}
float MovimientoCaja::getMonto()
{
    return monto;
}
bool MovimientoCaja::getEntrada()
{
    return entrada;
}
bool MovimientoCaja::getSalida()
{
    return salida;
}
bool MovimientoCaja::getPagoParcial()
{
    return pagoParcial;
}
bool MovimientoCaja::getPagoTotal()
{
return pagoTotal;
}
Fecha MovimientoCaja::getFecha()
{
    return fecha;
}
void MovimientoCaja::cargarIngreso() /// Carga un ingreso de caja en el sistema.
{
    cout<<"------------INGRESO DE CAJA------------"<<endl<<endl;
    int i, m;
    char cad[50];
    Fecha f;
    ArchivoMovimientosCaja archivoMovimientosCaja;
    i=archivoMovimientosCaja.contarRegistros();
    setId(i+1);
    cin.ignore();
    cout<<"Detalle: ";
    cin.getline(cad,50);
    while(validarCadenaVacia(cad)==false)
    {
        cin.getline(cad,50);
    }
    setDetalle(cad);
    cout<<endl<<"Monto: $";
    cin>>m;
    setMonto(m);
    setEntrada(true);
    setSalida(false);
    cout<<endl<<"El pago es 1-Total / 2-Parcial: ";
    cin>>i;
    while(i!=1 && i!=2)
    {
        cout<<"Tipo de pago inválido\r";
        Sleep(1500);
        cout<<"                       \r";
        cout<<"Reintente >";
        cin>>i;
    }
    if(i=1)
    {
        setPagoTotal(true);
        setPagoParcial(false);
    }
    else
    {
        setPagoParcial(true);
        setPagoTotal(false);
    }
    f=f.fechaActual();
    setFecha(f);
}
void MovimientoCaja::cargarAbonoCliente(char *nombres, char *apellidos, float montoTotal, bool total, bool parcial, Fecha fechaPago) /// Carga un ingreso de caja para el pago de cuota de un cliente en el sistema.
{
    ArchivoMovimientosCaja archivoMovimientosCaja;
    int i=archivoMovimientosCaja.contarRegistros();
    setId(i+1);
    char cadFinal[15]="Pago cuota de ";
    strcat(cadFinal,nombres);
    strcat(cadFinal," ");
    strcat(cadFinal,apellidos);
    setDetalle(cadFinal);
    setMonto(montoTotal);
    setEntrada(true);
    setSalida(false);
    setPagoTotal(total);
    setPagoParcial(parcial);
    setFecha(fechaPago);
}
void MovimientoCaja::cargarSalida() /// Carga una salida de caja en el sistema.
{
    cout<<"------------SALIDA DE CAJA------------"<<endl<<endl;
    int i, m;
    char cad[50];
    Fecha f;
    ArchivoMovimientosCaja archivoMovimientosCaja;
    i=archivoMovimientosCaja.contarRegistros();
    setId(i+1);
    cin.ignore();
    cout<<"Detalle: ";
    cin.getline(cad,50);
    while(validarCadenaVacia(cad)==false)
    {
        cin.getline(cad,50);
    }
    setDetalle(cad);
    cout<<endl<<"Monto: $";
    cin>>m;
    setMonto(m);
    setEntrada(false);
    setSalida(true);
    cout<<endl<<"El pago es 1-Total / 2-Parcial: ";
    cin>>i;
    while(i!=1 && i!=2)
    {
        cout<<"Tipo de pago inválido\r";
        Sleep(1500);
        cout<<"                       \r";
        cout<<"Reintente >";
        cin>>i;
    }
    if(i=1)
    {
        setPagoTotal(true);
        setPagoParcial(false);
    }
    else
    {
        setPagoParcial(true);
        setPagoTotal(false);
    }
    f=f.fechaActual();
    setFecha(f);
}
void MovimientoCaja::mostrar() /// Muestra un movimiento de caja.
{
    cout<<"-----------------------------------";
    cout<<endl<<"ID            : "<<getId();
    cout<<endl<<"Detalle       : "<<getDetalle();
    cout<<endl<<"Monto         : $"<<getMonto();
    cout<<endl<<"Ingreso/Salida: ";
    if(getEntrada()==true)cout<<"Ingreso";
    else cout<<"Salida";
    cout<<endl<<"Total/Parcial : ";
    if(getPagoParcial()==true)cout<<"Parcial";
    else cout<<"Total";
    cout<<endl<<"Fecha         : ";
    getFecha().mostrar();
    cout<<endl<<"-----------------------------------"<<endl<<endl;
}
bool MovimientoCaja::modificar(int id)
{
    Menu menu;
    ArchivoMovimientosCaja archivoMovimientosCaja;
    int pos=archivoMovimientosCaja.buscarPorId(id);
    MovimientoCaja movimientoCaja;
    movimientoCaja=archivoMovimientosCaja.leer(pos);
    movimientoCaja.mostrar();
    cout<<endl;
    menu.subMenuCamposMovimientosCaja();
    int op, aux;
    char cad[100];
    cout<<endl<<"Ingrese opción: ";
    cin>>op;
    cin.ignore();
    rlutil::cls();
    switch(op)
    {
    case 1: ///DETALLE
    {
        cout<<"Ingrese nuevo detalle: ";
        cin.getline(cad,100);
        movimientoCaja.setDetalle(cad);
    }
    break;
    case 2: ///MONTO
    {
        cout<<"Ingrese nuevo monto: $";
        cin>>aux;
        movimientoCaja.setMonto(aux);
    }
    break;
    case 3: ///TIPO DE MOVIMIENTO (ingreso / salida)
    {
        cout<<" 1 - Ingreso"<<endl<<" 2 - Salida"<<endl<<endl<<"Elija nuevo tipo de ingreso: ";
        cin>>aux;
        while(aux!=1 && aux!=2)
        {
            cout<<"Opción incorrecta\r";
            Sleep(1500);
            cout<<"                 \r";
            cout<<"Reintente >";
            cin>>aux;
        }
        if(aux==1)
        {
            movimientoCaja.setEntrada(true);
            movimientoCaja.setSalida(false);
        }
        else
        {
            movimientoCaja.setEntrada(false);
            movimientoCaja.setSalida(true);
        }
    }
    break;
    case 4: ///TIPO DE PAGO (total / parcial)
    {
        cout<<" 1 - Total"<<endl<<" 2 - Parcial"<<endl<<endl<<"Elija nuevo tipo de pago: ";
        cin>>aux;
        while(aux!=1 && aux!=2)
        {
            cout<<"Opción incorrecta\r";
            Sleep(1500);
            cout<<"                 \r";
            cout<<"Reintente >";
            cin>>aux;
        }
        if(aux==1)
        {
            movimientoCaja.setPagoTotal(true);
            movimientoCaja.setPagoParcial(false);
        }
        else
        {
            movimientoCaja.setPagoTotal(false);
            movimientoCaja.setPagoParcial(true);
        }
    }
    break;
    case 5: ///FECHA
    {
        cout<<"Ingrese nueva fecha: ";
        Fecha f;
        f=f.cargar();
        movimientoCaja.setFecha(f);
    }
    break;
    case 0:
    {
        return false;
    }
    break;
    default:
    {
        rlutil::anykey("Opción incorrecta");
        return false;
    }
    break;
    }
    archivoMovimientosCaja.sobreescribir(movimientoCaja,pos);
    return true;
}
bool MovimientoCaja::validarCadenaVacia(char *cad)  ///Valida que una cadena de texto no sea vacía.
{
    if(cad[0]=='\0')
    {
        cout<<"El detalle no puede quedar vacío.\r";
        Sleep(1500);
        cout<<"                                 \r";
        cout<<"Reintente >";
        return false;
    }
    return true;
}
