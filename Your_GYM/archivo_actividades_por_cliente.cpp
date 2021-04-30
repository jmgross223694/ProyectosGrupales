#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include "cliente.h"
#include "actividades_por_cliente.h"
#include "rlutil.h"
#include "archivo_actividades_por_cliente.h"
#include "archivo_actividades.h"
using namespace std;

void ArchivoActividadesCliente::mostrarSinBajas(ActividadesCliente actividadesCliente)
{
    if(actividadesCliente.getEstado()==true)
    {
        actividadesCliente.mostrar();
    }
}
void ArchivoActividadesCliente::mostrarConBajas(ActividadesCliente actividadesCliente)
{
    actividadesCliente.mostrar();
}
void ArchivoActividadesCliente::mostrarTodas()  ///Muestra todas las actividades realizadas con los datos de los clientes que las ejecutan.
{
    if(contarRegistros()!=0)
    {
        FILE *file;
        file=fopen("Archivos/ActividadesPorCliente.dat","rb");
        if(file==NULL){return;}
        ActividadesCliente actividadesCliente;
        cout<<"------------ACTIVIDADES POR CLIENTE------------"<<endl<<endl;
        while(fread(&actividadesCliente,sizeof(ActividadesCliente),1,file))
        {
            actividadesCliente.mostrar();
        }
        fclose(file);
    }
    else
    {
        rlutil::cls();
        rlutil::anykey("El archivo ActividadesPorCliente está vacío");
        rlutil::cls();
        return;
    }
}
void ArchivoActividadesCliente::mostrarNombresEnCliente(int dniBuscado)  ///Muestra el nombre de las actividades realizadas por un cliente, cuyo DNI es recibido como parametro.
{
    FILE *file;
    file=fopen("Archivos/ActividadesPorCliente.dat","rb");
    if (file==NULL){return;}
    Actividad actividad;
    ActividadesCliente actividadesCliente;
    while(fread(&actividadesCliente,sizeof(ActividadesCliente),1,file))
    {
        if(dniBuscado==actividadesCliente.getDni() && actividadesCliente.getEstado()==true)
        {
            ArchivoActividades archivoActividades;
            int pos=archivoActividades.buscarPosicionPorCodigo(actividadesCliente.getCodigo());
            archivoActividades.mostrarNombrePorPosicion(pos);
        }
    }
    fclose(file);
}
void ArchivoActividadesCliente::mostrarTodasPorDni(int dniBuscado)
{
    FILE *file;
    file=fopen("Archivos/ActividadesPorCliente.dat","rb");
    if (file==NULL){return;}
    ActividadesCliente actividadesCliente;
    while(fread(&actividadesCliente,sizeof(ActividadesCliente),1,file))
    {
        if(dniBuscado==actividadesCliente.getDni() && actividadesCliente.getEstado()==true)
        {
            cout<<" "<<actividadesCliente.getCodigo();
            ArchivoActividades archivoActividades;
            int pos=archivoActividades.buscarPosicionPorCodigo(actividadesCliente.getCodigo());
            cout<<" ";
            archivoActividades.mostrarNombrePorPosicion(pos);
            cout<<endl;
            cout<<"-----------------"<<endl;
        }
    }
    fclose(file);
}
ActividadesCliente ArchivoActividadesCliente::leer(int pos)
{
    FILE *file;
    file=fopen("Archivos/ActividadesPorCliente.dat","rb");
    if(file==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo ActividadesPorCliente");
        rlutil::cls();
    }
    ActividadesCliente actividadesCliente;
    fseek(file,pos*sizeof(ActividadesCliente),0);
    if(fread(&actividadesCliente,sizeof(ActividadesCliente),1,file))
    {
        fclose(file);
        return actividadesCliente;
    }
}
int ArchivoActividadesCliente::buscar_posicion_por_codigo_y_dni(int cod, int dni)
{
    FILE *file;
    file=fopen("Archivos/ActividadesPorCliente.dat","rb");
    if(file==NULL){return -1;}
    int pos=0;
    ActividadesCliente actividadesCliente;
    while(fread(&actividadesCliente,sizeof(ActividadesCliente),1,file))
    {
        if(dni==actividadesCliente.getDni() && cod==actividadesCliente.getCodigo())
        {
            fclose(file);
            return pos;
        }
        pos++;
    }
    fclose(file);
    return -1;
}
bool ArchivoActividadesCliente::guardar(ActividadesCliente actividadesCliente)
{
    FILE *file;
    file=fopen("Archivos/ActividadesPorCliente.dat","ab");
    if (file==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo ActividadesPorCliente");
        rlutil::cls();
        return false;
    }
    if(fwrite(&actividadesCliente,sizeof(ActividadesCliente),1,file))
    {
        fclose(file);
        return true;
    }
}
bool ArchivoActividadesCliente::sobreescribir(ActividadesCliente actividadesCliente, int pos)
{
    FILE *file;
    file=fopen("Archivos/ActividadesPorCliente.dat","rb+");
    if (file==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo ActividadesPorCliente");
        rlutil::cls();
        return false;
    }
    fseek(file,pos*sizeof(ActividadesCliente),SEEK_SET);
    if(fwrite(&actividadesCliente,sizeof(ActividadesCliente),1,file))
    {
        fclose(file);
        return true;
    }
}
bool ArchivoActividadesCliente::doBackup()
{
    FILE *file1;
    file1=fopen("Archivos/ActividadesPorCliente.dat","rb");
    if(file1==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo ActividadesPorCliente");
        rlutil::cls();
        return false;
    }
    FILE *file2;
    file2=fopen("Archivos/Backup/ActividadesPorCliente.bkp","wb");
    if(file2==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo ActividadesPorCliente.bkp");
        rlutil::cls();
        fclose(file1);
        return false;
    }
    ActividadesCliente actividadesCliente;
    while(fread(&actividadesCliente,sizeof(ActividadesCliente),1,file1))
    {
        fwrite(&actividadesCliente,sizeof(ActividadesCliente),1,file2);
    }
    fclose(file1);
    fclose(file2);
    return true;
}
bool ArchivoActividadesCliente::restoreBackup()
{
    FILE *file1;
    file1=fopen("Archivos/Backup/ActividadesPorCliente.bkp","rb");
    if(file1==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo ActividadesPorCliente.bkp");
        rlutil::cls();
        return false;
    }
    FILE *file2;
    file2=fopen("Archivos/ActividadesPorCliente.dat","wb");
    if(file2==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo ActividadesPorCliente");
        rlutil::cls();
        fclose(file1);
        return false;
    }
    ActividadesCliente actividadesCliente;
    while(fread(&actividadesCliente,sizeof(ActividadesCliente),1,file1))
    {
        fwrite(&actividadesCliente,sizeof(ActividadesCliente),1,file2);
    }
    fclose(file1);
    fclose(file2);
    return true;
}
int ArchivoActividadesCliente::contarRegistros()
{
    FILE *file;
    file=fopen("Archivos/ActividadesPorCliente.dat","rb");
    if(file==NULL){return 0;}
    ActividadesCliente actividadesCliente;
    int con=0;
    while(fread(&actividadesCliente,sizeof(ActividadesCliente),1,file))
    {
        con++;
    }
    fclose(file);
    return con;
}
int ArchivoActividadesCliente::contarActividadesPorDni(int dni)
{
    FILE *file;
    file=fopen("Archivos/ActividadesPorCliente.dat","rb");
    if(file==NULL){return 0;}
    ActividadesCliente actividadesCliente;
    int con=0;
    while(fread(&actividadesCliente,sizeof(ActividadesCliente),1,file))
    {
        if(dni==actividadesCliente.getDni())
        {
            con++;
        }
    }
    fclose(file);
    return con;
}
void ArchivoActividadesCliente::mostrarTodasPorDni()
{
    FILE *file1, *file2;
    int dni;
    Actividad actividad;
    ArchivoActividades archivoActividades;
    Cliente cliente;
    ActividadesCliente actividadesCliente;
    ArchivoActividadesCliente archivoActividadesCliente;
    if(archivoActividadesCliente.contarRegistros()==0){rlutil::anykey("El archivo ActividadesPorCliente esta vacío.");}
    else
    {
        cout<<"Ingrese el DNI del cliente: ";
        cin>>dni;
        rlutil::cls();
        file1=fopen("Archivos/clientes.dat","rb");
        if(file1==NULL)
        {
            rlutil::cls();
            rlutil::anykey("Error de lectura del archivo Clientes");
            rlutil::cls();
            return;
        }
        cout<<"--------DATOS DEL CLIENTE------------";
        while(fread(&cliente,sizeof(Cliente),1,file1))
        {
            if(dni==cliente.getDni())
            {
                cout<<endl<<"N° Socio : "<<cliente.getNumSocio();
                cout<<endl<<"DNI      : "<<cliente.getDni();
                cout<<endl<<"Nombres  : "<<cliente.getNames();
                cout<<endl<<"Apellidos: "<<cliente.getSurnames();
            }
        }
        cout<<endl<<"------------------------------------";
        file2=fopen("Archivos/ActividadesPorCliente.dat","rb");
        if(file2==NULL)
        {
            rlutil::cls();
            rlutil::anykey("Error de lectura del archivo Actividades Por Cliente");
            rlutil::cls();
            fclose(file1);
            return;
        }
        cout<<endl<<endl<<"--------ACTIVIDADES REALIZADAS------"<<endl;
        while(fread(&actividadesCliente,sizeof(ActividadesCliente),1,file2))
        {
            if(dni==actividadesCliente.getDni())
            {
                int cod=actividadesCliente.getCodigo(), pos=archivoActividades.buscarPosicionPorCodigo(cod);
                actividad=archivoActividades.leer(pos);
                cout<<endl<<"Código    : "<<actividad.getCodigo();
                cout<<endl<<"Nombre    : "<<actividad.getNombre();
                if(actividadesCliente.getEstado()==true)
                {
                    cout<<endl<<"Alta desde: ";
                    actividadesCliente.getFechaAlta().mostrar();
                }
                else
                {
                    cout<<endl<<"Baja desde: ";
                    actividadesCliente.getFechaBaja().mostrar();
                }
                if(actividad.getEstado()==true)
                {
                    cout<<endl<<"Estado    : Activa en gimnasio";
                }
                else
                {
                    cout<<endl<<"Estado    : Inactiva en gimnasio";
                }
                //actividadesCliente.mostrarEstado(actividadesCliente.getEstado());
                cout<<endl<<"------------------------------------";
            }
        }
        fclose(file1);
        fclose(file2);
    }
}
