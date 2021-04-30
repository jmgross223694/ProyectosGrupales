#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include "rlutil.h"
#include "abonos.h"
#include "archivo_abonos.h"
using namespace std;

Abono::Abono()
{
    codigo=-1;
    strcpy(nombre,"VACIO");
    costo=0;
    interes=0;
    estado=false;
}
void Abono::setCodigo(int aux)
{
    codigo=aux;
}
void Abono::setNombre(char *cad)
{
    strcpy(nombre,cad);
}
void Abono::setCosto(float aux)
{
    costo=aux;
}
void Abono::setInteres(float aux)
{
    interes=aux;
}
void Abono::setEstado(bool aux)
{
    estado=aux;
}
int Abono::getCodigo()
{
    return codigo;
}
char* Abono::getNombre()
{
    return nombre;
}
float Abono::getCosto()
{
    return costo;
}
float Abono::getInteres()
{
    return interes;
}
bool Abono::getEstado()
{
    return estado;
}
void Abono::cargar()
{
    int n;
    char cad[30];
    float aux;
    ArchivoAbonos archivoAbonos;
    cout<<"------------INGRESO DE NUEVO ABONO------------"<<endl<<endl;
    n=archivoAbonos.contarRegistros();
    setCodigo(n+1);
    cin.ignore();
    cout<<"Nombre: ";
    cin.getline(cad,30);
    setNombre(cad);
    cout<<"Costo: $";
    cin>>aux;
    setCosto(aux);
    cout<<"Interés (%): ";
    cin>>aux;
    setInteres(aux);
    setEstado(true);
}
void Abono::mostrar()
{
    cout<<"-----------------------------------";
    cout<<endl<<"Código : "<<getCodigo();
    cout<<endl<<"Nombre : "<<getNombre();
    cout<<endl<<"Costo  : $"<<getCosto();
    cout<<endl<<"Interés: "<<getInteres();
    cout<<" %";
    cout<<endl<<"Estado : ";
    if(getEstado()==true) cout<<"Habilitado";
    else cout<<"Inhabilitado";
    cout<<endl<<"-----------------------------------"<<endl;
}
bool Abono::modificar(int cod)
{
    Abono abono;
    ArchivoAbonos archivoAbonos;
    int pos=archivoAbonos.buscarPorCodigo(cod), campo;
    char cad[30];
    abono=archivoAbonos.leer(pos);
    rlutil::cls();
    cout<<"1-Nombre"<<endl<<"2-Costo"<<endl<<"3-Interés"<<endl<<"4-Estado"<<endl;
    cout<<"-----------------------"<<endl<<"0-Volver al menú Abonos"<<endl;
    cout<<"¿Qué desea modificar? ";
    cin>>campo;
    cin.ignore();
    while(campo!=1 && campo!=2 && campo!=3 && campo!=4 && campo!=0)
    {
        cout<<"N° de campo inválido. >";
        cin>>campo;
    }
    rlutil::cls();
    switch(campo)
    {
    case 1:
    {
        cout<<"Nuevo nombre: ";
        cin.getline(cad,30);
        abono.setNombre(cad);
    }
    break;
    case 2:
    {
        cout<<"Nuevo costo: $";
        float costo;
        cin>>costo;
        abono.setCosto(costo);
    }
    break;
    case 3:
    {
        cout<<"Nuevo interés (%): ";
        float aux;
        cin>>aux;
        abono.setInteres(aux);
    }
    break;
    case 4:
    {
        if(abono.getEstado()==true)
        {
            cout<<"¿Deshabilitar en sistema?"<<endl;
            cout<<"1-SI / 0-NO: ";
            int confirmacion;
            cin>>confirmacion;
            while(confirmacion!=1 && confirmacion!=0)
            {
                cout<<"Reintente. >";
                cin>>confirmacion;
            }
            if(confirmacion==1)
            {
                abono.setEstado(false);
            }
            else
            {
                return false;
            }
        }
        else if(abono.getEstado()==false)
        {
            cout<<"¿Habilitar en sistema?"<<endl;
            cout<<"1-SI / 0-NO: ";
            int confirmacion;
            cin>>confirmacion;
            while(confirmacion!=1 && confirmacion!=0)
            {
                cout<<"Reintente. >";
                cin>>confirmacion;
            }
            if(confirmacion==1)
            {
                abono.setEstado(true);
            }
            if(confirmacion==0)return false;
        }
    }
    break;
    case 0:
    {
        return false;
    }
    break;
    }
    archivoAbonos.sobreescribir(abono,pos);
    return true;
}
bool Abono::validarCadenaVacia(char *cad)
{
    if(cad[0]=='\0')
    {
        cout<<"El nombre no puede quedar vacío.\r";
        Sleep(1500);
        cout<<"                                 \r";
        cout<<"Reintente >";
        return false;
    }
    return true;
}
