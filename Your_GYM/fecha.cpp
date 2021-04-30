#include <iostream>
#include <cstring>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "fecha.h"

Fecha::Fecha()
{
    dia = -1;
    mes = -1;
    anio = -1;
}
void Fecha::setDia(int d)
{
    dia = d;
}
void Fecha::setMes(int m)
{
    mes = m;
}
void Fecha::setAnio(int a)
{
    anio = a;
}
int Fecha::getDia()
{
    return dia;
}
int Fecha::getMes()
{
    return mes;
}
int Fecha::getAnio()
{
    return anio;
}
Fecha Fecha::cargar()
{
    Fecha f;
    int d, m, a;
    cin >> d;
    validarDia(&d);
    cin >> m;
    validarMes(&m);
    cin >> a;
    validarAnio(&a);
    f.setDia(d);
    f.setMes(m);
    f.setAnio(a);
    return f;
}
void Fecha::mostrar()
{
    cout << dia << "/" << mes << "/" << anio;
}
Fecha Fecha::fechaActual()   ///Devuelve la fecha actual del sistema.
{
    Fecha f;
    time_t tiempo;
    struct tm *tmPtr;
    tiempo=time(NULL);
    tmPtr=localtime(&tiempo);
    f.setDia(tmPtr->tm_mday);
    f.setMes(tmPtr->tm_mon+1);
    f.setAnio(1900+tmPtr->tm_year);
    return f;

    /*
    time_t tiempo;
    char cad[80];
    struct tm *tmPtr;

    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);

    int dia_actual=tmPtr->tm_mday;
    int mes_actual=tmPtr->tm_mon+1;
    int anio_actual=1900+tmPtr->tm_year;
    */
}
void Fecha::validarDia(int *d)
{
    while (*d<1 || *d>31) //VALIDACIÓN DE NÚMERO DE DÍA
    {
        cout<<"Día inválido. Reintente >";
        cin>>*d;
    }
}
void Fecha::validarMes(int *m)
{
    while (*m<1 || *m>12) //VALIDACIÓN DE NÚMERO DE MES
    {
        cout<<"Mes inválido. Reintente >";
        cin>>*m;
    }
}
void Fecha::validarAnio(int *a)
{
    Fecha fActual=fActual.fechaActual();
    while (*a<1920 || *a>fActual.getAnio()) //VALIDACIÓN DE NÚMERO DE AÑO
    {
        cout<<"Año inválido. Reintente >";
        cin>>*a;
    }
}
Fecha Fecha::validarFechaCompleta(Fecha f) ///Valida la fecha recibidad como parametro.
{
    int d;

    //VALIDACION DE DIA DENTRO DEL MES INGRESADO Y AÑO BISIESTO
    switch (f.getMes())
    {
    case 2:
    {
        int res=anioBisiesto(f.getAnio());
        if (res==0)
        {
            while (f.getDia()>28 || f.getDia()<1)
            {
                cout<<"Día inválido. Reintente >";
                cin>>d;
                f.setDia(d);
            }
        }
        else
        {
            while(f.getDia()>29 || f.getDia()<1)
            {
                cout<<"Día inválido. Reintente >";
                cin>>d;
                f.setDia(d);
            }
        }
    }
    break;
    case 4:
    {
        while (f.getDia()>30 || f.getDia()<1)
        {
            cout<<"Día inválido. Reintente >";
            cin>>d;
            f.setDia(d);
        }
    }
    break;
    case 6:
    {
        while (f.getDia()>30 || f.getDia()<1)
        {
            cout<<"Día inválido. Reintente >";
            cin>>d;
            f.setDia(d);
        }
    }
    break;
    case 9:
    {
        while (f.getDia()>30 || f.getDia()<1)
        {
            cout<<"Día inválido. Reintente >";
            cin>>d;
            f.setDia(d);
        }
    }
    break;
    case 11:
    {
        while (f.getDia()>30 || f.getDia()<1)
        {
            cout<<"Día inválido. Reintente >";
            cin>>d;
            f.setDia(d);
        }
    }
    break;
    }
    //FIN DE VALIDACION DE DIA DENTRO DEL MES INGRESADO Y AÑO BISIESTO

    return f;
}
bool Fecha::anioBisiesto(int a)
{
    bool bandera;
    if(a%4==0 && a%100!=0 || a%400==0)
    {
        bandera=1;
    }
    else
    {
        bandera=0;
    }
    return bandera;
}
