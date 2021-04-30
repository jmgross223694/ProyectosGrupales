#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include "actividades.h"
#include "archivo_actividades.h"
#include "actividades_por_cliente.h"
#include "archivo_actividades_por_cliente.h"
#include "rlutil.h"
using namespace std;

ActividadesCliente::ActividadesCliente()
{
    codigo=-1;
    dni=-1;
    fechaAlta.setDia(-1);
    fechaAlta.setMes(-1);
    fechaAlta.setAnio(-1);
    fechaBaja.setDia(-1);
    fechaBaja.setMes(-1);
    fechaBaja.setAnio(-1);
    estado=false;
}
void ActividadesCliente::setCodigo(int c)
{
    codigo = c;
}
void ActividadesCliente::setDni(int n)
{
    dni = n;
}
void ActividadesCliente::setFechaAlta(Fecha f)
{
    fechaAlta.setDia(f.getDia());
    fechaAlta.setMes(f.getMes());
    fechaAlta.setAnio(f.getAnio());
}
void ActividadesCliente::setFechaBaja(Fecha f)
{
    fechaBaja.setDia(f.getDia());
    fechaBaja.setMes(f.getMes());
    fechaBaja.setAnio(f.getAnio());
}
void ActividadesCliente::setEstado(bool e)
{
    estado = e;
}
int ActividadesCliente::getCodigo()
{
    return codigo;
}
int ActividadesCliente::getDni()
{
    return dni;
}
Fecha ActividadesCliente::getFechaAlta()
{
    return fechaAlta;
}
Fecha ActividadesCliente::getFechaBaja()
{
    return fechaBaja;
}
bool ActividadesCliente::getEstado()
{
    return estado;
}
bool ActividadesCliente::cargar(int dni, bool *fin)
{
    ArchivoActividadesCliente archivoActividadesCliente;
    ArchivoActividades archivoActividades;
    int n;
    Fecha f;
    cout<<"Código de actividad: ";
    cin>>n;
    while(archivoActividadesCliente.buscar_posicion_por_codigo_y_dni(n,dni)!=-1 && archivoActividades.buscarPosicionPorCodigo(n)!=-1)
    {
        cout<<endl<<"La actividad "<<n<<" ya existe para este cliente o no existe en el gimnasio.\r";
        Sleep(1500);
        cout<<"                                                                                  \r";
        cout<<"Reintente >";
        cin>>n;
    }
    setCodigo(n);
    setDni(dni);
    f=f.fechaActual();
    setFechaAlta(f);
    setEstado(true);
    cout<<endl<<"¿Desea agregar otra?"<<endl<<"1-SI / 0-NO: ";
    cin>>n;
    cout<<endl;
    while(n!=0 && n!=1)
    {
        cout<<"Reintente. >";
        cin>>n;
    }
    if(n==0)
    {
        *fin=true;
    }
    return *fin;
}
bool ActividadesCliente::cargar2(int codAct, int dni, bool *fin)
{
    ArchivoActividadesCliente archivoActividadesCliente;
    ArchivoActividades archivoActividades;
    int n;
    Fecha f;
    while(archivoActividadesCliente.buscar_posicion_por_codigo_y_dni(codAct,dni)!=-1 && archivoActividades.buscarPosicionPorCodigo(codAct)!=-1)
    {
        cout<<endl<<"La actividad "<<codAct<<" ya existe para este cliente o no existe en el gimnasio.\r";
        Sleep(1500);
        cout<<"                                                                                  \r";
        cout<<"Reintente >";
        cin>>codAct;
    }
    setCodigo(codAct);
    setDni(dni);
    f=f.fechaActual();
    setFechaAlta(f);
    setEstado(true);
    cout<<endl<<"¿Desea agregar otra?"<<endl<<"1-SI / 0-NO: ";
    cin>>n;
    cout<<endl;
    while(n!=0 && n!=1)
    {
        cout<<"Reintente. >";
        cin>>n;
    }
    if(n==0)
    {
        *fin=true;
    }
    return *fin;
}
void ActividadesCliente::mostrar()
{
    ArchivoActividades archivosActividades;
    Actividad actividad;
    actividad=archivosActividades.leer(archivosActividades.buscarPosicionPorCodigo(getCodigo()));
    cout<<"-----------------------------------";
    cout<<endl<<"Código     : "<<getCodigo();
    cout<<endl<<"Nombre     : "<<actividad.getNombre();
    cout<<endl<<"DNI Cliente: "<<getDni();
    if(getEstado()==true)
    {
        cout<<endl<<"Últ. Alta  : ";
        getFechaAlta().mostrar();
    }
    else
    {
        cout<<endl<<"Últ. Baja  : ";
        getFechaBaja().mostrar();
    }

    cout<<endl<<"Estado     : ";
    mostrarEstado(getEstado());
    cout<<endl<<"-----------------------------------"<<endl;
}
void ActividadesCliente::mostrarEstado(bool estado)
{
    if(estado==true)
    {
        cout<<"Habilitada";
    }
    else
    {
        cout<<"Inhabilitada";
    }
}
