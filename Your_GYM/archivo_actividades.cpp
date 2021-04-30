#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include "actividades.h"
#include "rlutil.h"
#include "archivo_actividades.h"
using namespace std;

void ArchivoActividades::mostrarSinBajas(Actividad actividad) ///Muestra 1 sola actividad, solo si su estado en sistema es = true.
{
    if(actividad.getEstado()==true)
    {
        actividad.mostrar();
    }
}
void ArchivoActividades::mostrarConBajas(Actividad actividad) ///Muestra 1 sola actividad, sin contemplar su estado en sistema.
{
    actividad.mostrar();
}
bool ArchivoActividades::guardar(Actividad actividad)   ///Guarda una actividad nueva en el archivo actividades.dat.
{
    FILE *file;
    file=fopen("Archivos/Actividades.dat","ab");
    if (file==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo Actividades");
        rlutil::cls();
        return false;
    }
    if(fwrite(&actividad,sizeof(Actividad),1,file))
    {
        fclose(file);
        return true;
    }
}
Actividad ArchivoActividades::leer(int pos)   ///Lee una actividad, en la posición recibidad como parámetro.
{
    if(pos>=0)  ///pos=-1 (Actividad no encontrada en archivo)
    {
        FILE *file;
        file=fopen("Archivos/Actividades.dat","rb");
        if(file==NULL)
        {
            rlutil::cls();
            rlutil::anykey("Error de lectura del archivo Actividades");
            rlutil::cls();
        }
        Actividad actividad;
        fseek(file,pos*sizeof(Actividad),0);
        if(fread(&actividad,sizeof(Actividad),1,file))
        {
            fclose(file);
            return actividad;
        }
    }
    else if(pos==-1)
    {
        rlutil::cls();
        rlutil::anykey("La actividad no existe en el archivo.");
        rlutil::cls();
    }
}
bool ArchivoActividades::sobreescribir(Actividad actividad, int pos) ///Sobreescribe 1 actividad modificada.
{
    FILE *file;
    file=fopen("Archivos/Actividades.dat","rb+");
    if (file==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo Actividades");
        rlutil::cls();
        return false;
    }
    fseek(file,pos*sizeof(Actividad),0);
    if(fwrite(&actividad,sizeof(Actividad),1,file))
    {
        fclose(file);
        return true;
    }
}
int ArchivoActividades::contarRegistros()    ///Cuenta la cantidad de registros del archivo actividades.dat, sin contemplar su estado en sistema.
{
    Actividad actividad;
    FILE *file;
    file=fopen("Archivos/actividades.dat","rb");
    if(file==NULL)
    {
        return 0;
    }
    int cont=0;
    while(fread(&actividad,sizeof actividad,1,file))
    {
        cont++;
    }
    fclose(file);
    return cont;
}
int ArchivoActividades::contarRegistrosSinBajas()   ///Cuenta la cantidad de registros del archivo actividades.dat, solo si su estado en sistema es = true.
{
    Actividad actividad;
    FILE *file;
    file=fopen("Archivos/actividades.dat","rb");
    if(file==NULL)
    {
        return 0;
    }
    int cont=0;
    while(fread(&actividad,sizeof actividad,1,file))
    {
        if(actividad.getCodigo()==1)
        {
            cont++;
        }
    }
    fclose(file);
    return cont;
}
int ArchivoActividades::buscarPosicionPorCodigo(int codigo)  ///Busca la posicion de 1 actividad dentro del archivo actividades.dat, a partir de un codigo de actividad ingresado por teclado.
{
    Actividad actividad;
    if(contarRegistros()!=0)
    {
        FILE *file;
        file=fopen("Archivos/actividades.dat","rb");
        if(file==NULL)
        {
            rlutil::cls();
            rlutil::anykey("Error de lectura del archivo Actividades");
            rlutil::cls();
            return -1;
        }
        int pos=0;
        while(fread(&actividad,sizeof(Actividad),1,file))
        {
            if(codigo==actividad.getCodigo())
            {
                fclose(file);
                return pos;
            }
            pos++;
        }
        fclose(file);
        return -1;
    }
    else
    {
        rlutil::cls();
        rlutil::anykey("El archivo Actividades está vacío.");
        rlutil::cls();
    }
}
void ArchivoActividades::mostrarNombrePorPosicion(int pos)  ///Busca y muestra el nombre de una actividad, cuya posicion es recibida como parametro.
{
    Actividad actividad;
    if(contarRegistros()!=0)
    {
        FILE *file;
        file=fopen("Archivos/actividades.dat","rb");
        if(file==NULL)
        {
            rlutil::cls();
            rlutil::anykey("Error de lectura del archivo Actividades");
            rlutil::cls();
            return;
        }
        fseek(file,pos*sizeof(Actividad),SEEK_SET);
        fread(&actividad,sizeof(Actividad),1,file);
        if(actividad.getEstado()==true)
        {
            cout<<actividad.getNombre();
            cout<<". ";
        }
        fclose(file);
    }
    else
    {
        rlutil::cls();
        rlutil::anykey("El archivo Actividades está vacío.");
        rlutil::cls();
    }
}
void ArchivoActividades::mostrarTodas()  ///Muestra todos los registros del archivo actividades.dat.
{
    if(contarRegistros()!=0)
    {
        FILE *file;
        file=fopen("Archivos/actividades.dat","rb");
        if(file==NULL)
        {
            rlutil::cls();
            rlutil::anykey("Error de lectura del archivo Actividades");
            rlutil::cls();
        }
        Actividad actividad;
        cout<<"---------------Actividades-------------"<<endl<<endl;
        while(fread(&actividad,sizeof(Actividad),1,file))
        {
            mostrarConBajas(actividad);
        }
        fclose(file);
    }
    else
    {
        cout<<"El archivo Actividades está vacío."<<endl;
    }
}
bool ArchivoActividades::validarExistenciaActividad(int cod)    ///Valida si el código recibido como parametro, existe en el archivo actividades.dat.
{
    Actividad actividad;
    FILE *file;
    file=fopen("Archivos/actividades.dat","rb+");
    if (file==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo Actividades");
        rlutil::cls();
        return false;
    }
    while(fread(&actividad,sizeof(Actividad),1,file))
    {
        if(cod==actividad.getCodigo())
        {
            fclose(file);
            return true;
        }
    }
    fclose(file);
    return false;
}
bool ArchivoActividades::validarEstadoActividad(int cod)    ///Valida si una actividad esta habilitada o no en el sistema segun el codigo de la misma recibido como parametro.
{
    Actividad actividad;
    FILE *file;
    file=fopen("Archivos/actividades.dat","rb+");
    if (file==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo Actividades");
        rlutil::cls();
        return false;
    }
    while(fread(&actividad,sizeof(Actividad),1,file))
    {
        if(cod==actividad.getCodigo() && actividad.getEstado()==true)
        {
            fclose(file);
            return true;
        }
    }
    fclose(file);
    return false;
}
bool ArchivoActividades::doBackup()
{
    FILE *file1;
    file1=fopen("Archivos/Actividades.dat","rb");
    if(file1==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo Actividades");
        rlutil::cls();
        return false;
    }
    FILE *file2;
    file2=fopen("Archivos/Backup/Actividades.bkp","wb");
    if(file2==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo Actividades.bkp");
        rlutil::cls();
        fclose(file1);
        return false;
    }
    Actividad actividad;
    while(fread(&actividad,sizeof(Actividad),1,file1))
    {
        fwrite(&actividad,sizeof(Actividad),1,file2);
    }
    fclose(file1);
    fclose(file2);
    return true;
}
bool ArchivoActividades::restoreBackup()
{
    FILE *file1;
    file1=fopen("Archivos/Backup/Actividades.bkp","rb");
    if(file1==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo Actividades.bkp");
        rlutil::cls();
        return false;
    }
    FILE *file2;
    file2=fopen("Archivos/Actividades.dat","wb");
    if(file2==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo Actividades");
        rlutil::cls();
        fclose(file1);
        return false;
    }
    Actividad actividad;
    while(fread(&actividad,sizeof(Actividad),1,file1))
    {
        fwrite(&actividad,sizeof(Actividad),1,file2);
    }
    fclose(file1);
    fclose(file2);
    return true;
}
