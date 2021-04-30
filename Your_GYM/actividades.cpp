#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include "actividades.h"
#include "rlutil.h"
#include "archivo_actividades.h"
using namespace std;

Actividad::Actividad()
{
    codigo=-1;
    strcpy(nombre,"VACIO");
    costo=-1;
    estado=true;
}
void Actividad::setCodigo(int cod)
{
    codigo=cod;
}
void Actividad::setNombre(char *nom)
{
    strcpy(nombre,nom);
}
void Actividad::setCosto(float pu)
{
    costo=pu;
}
void Actividad::setEstado(bool bin)
{
    estado=bin;
}
int Actividad::getCodigo()
{
    return codigo;
}
char* Actividad::getNombre()
{
    return nombre;
}
float Actividad::getCosto()
{
    return costo;
}
bool Actividad::getEstado()
{
    return estado;
}
void Actividad::cargar()   ///Pide los datos necesarios para cargar una actividad al sistema.
{
    int n;
    char cad[50];
    float costo;
    ArchivoActividades archivoActividades;
    cout<<"------------INGRESO DE NUEVA ACTIVIDAD------------"<<endl<<endl;
    n=archivoActividades.contarRegistros();
    setCodigo(n+1);
    cin.ignore();
    cout<<"Nombre: ";
    cin.getline(cad,50);
    setNombre(cad);
    cout<<"Costo: $";
    cin>>costo;
    setCosto(costo);
    setEstado(true);
}
bool Actividad::modificar(int cod)  ///Modifica una actividad, a partir del codigo de dicha actividad, ingresado por teclado.
{
    FILE *file;
    file=fopen("Archivos/Actividades.dat","rb");
    if(file==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo Actividades");
        rlutil::cls();
        return false;
    }
    Actividad actividad;
    ArchivoActividades archivoActividades;
    int pos, campo;
    char cad[50];
    pos=archivoActividades.buscarPosicionPorCodigo(cod);
    rlutil::cls();
    fseek(file,pos*sizeof(Actividad),SEEK_SET);
    fread(&actividad,sizeof(Actividad),1,file);
    cout<<"1-Nombre"<<endl<<"2-Costo"<<endl<<"3-Estado"<<endl;
    cout<<"-----------------------"<<endl<<"0-Volver al menú Actividades"<<endl;
    cout<<"¿Qué desea modificar? ";
    cin>>campo;
    cin.ignore();
    while(campo!=1 && campo!=2 && campo!=3 && campo!=0)
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
        cin.getline(cad,50);
        actividad.setNombre(cad);
    }
    break;
    case 2:
    {
        cout<<"Nuevo costo: $";
        float costo;
        cin>>costo;
        actividad.setCosto(costo);
    }
    break;
    case 3:
    {
        if(actividad.getEstado()==true)
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
                actividad.setEstado(false);
            }
            else
            {
                fclose(file);
                return false;
            }
        }
        else if(actividad.getEstado()==false)
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
                actividad.setEstado(true);
            }
            if(confirmacion==0)
            {
                fclose(file);
                return false;
            }
        }
    }
    break;
    case 0:
    {
        fclose(file);
        return false;
    }
    break;
    }
    archivoActividades.sobreescribir(actividad,pos);
    fclose(file);
    return true;
}
void Actividad::mostrar()   ///Muestra una actividad.
{
    cout<<"-----------------------------------";
    cout<<endl<<"Código: "<<getCodigo();
    cout<<endl<<"Nombre: "<<getNombre();
    cout<<endl<<"Costo : $"<<getCosto();
    cout<<endl<<"Estado: ";
    mostrarEstado(getEstado());
    cout<<endl<<"-----------------------------------"<<endl;
}
void Actividad::mostrarEstado(bool estado)  ///Muestra el estado de una actividad, según el estado en sistema de la misma.
{
    if(estado==true)
    {
        cout<<"Habilitada";
    }
    else
    {
        cout<<"Deshabilitada";
    }
}
