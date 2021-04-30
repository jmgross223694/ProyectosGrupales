#include <iostream>
#include <cstring>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "cliente.h"
#include "archivo_clientes.h"
#include "fecha.h"
#include "rlutil.h"
#include "actividades_por_cliente.h"

void ArchivoClientes::mostrarSinBajas(Cliente cliente)  ///Muestra 1 solo cliente.
{
    if(cliente.getEstado()==true)
    {
        cliente.mostrar();
    }
}
void ArchivoClientes::mostrarConBajas(Cliente cliente)  ///Muestra 1 solo cliente.
{
    cliente.mostrar();
}
bool ArchivoClientes::guardar(Cliente cliente)  ///Guarda 1 Cliente nuevo en el archivo Clientes.dat.
{
    FILE *file;
    file=fopen("Archivos/Clientes.dat","ab");
    if (file==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo Clientes");
        rlutil::cls();
        return false;
    }
    if(fwrite(&cliente,sizeof(Cliente),1,file))
    {
        fclose(file);
        return true;
    }
}
bool ArchivoClientes::sobreescribir(Cliente cliente, int pos)  ///Sobreescribe 1 Cliente modificado.
{
    FILE *file;
    file=fopen("Archivos/clientes.dat","rb+");
    if (file==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo Clientes");
        rlutil::cls();
        return false;
    }
    fseek(file,pos*sizeof(Cliente),SEEK_SET);
    if(fwrite(&cliente,sizeof(Cliente),1,file))
    {
        fclose(file);
        return true;
    }
}
Cliente ArchivoClientes::leer(int pos)  ///Lee 1 Cliente especifico.
{
    Cliente cliente;
    if(pos!=-1 && pos!=-2)  ///pos=-1 (Cliente no encontrado en archivo) | pos=-2 (Archivo Clientes vacío).
    {
        FILE *file;
        file=fopen("Archivos/clientes.dat","rb");
        if(file==NULL)
        {
            rlutil::cls();
            rlutil::anykey("Error de lectura del archivo Clientes");
            rlutil::cls();
        }
        else
        {
            fseek(file,pos*sizeof(Cliente),0);
            if(fread(&cliente,sizeof(Cliente),1,file))
            {
                fclose(file);
                return cliente;
            }
        }
    }
    else if(pos==-1)
    {
        rlutil::cls();
        rlutil::anykey("El cliente no existe en el archivo.");
        rlutil::cls();
    }
}
void ArchivoClientes::mostrarTodos()  ///Muestra todos los clientes.
{
    FILE *file;
    file=fopen("Archivos/clientes.dat","rb");
    if(file==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo Clientes");
        rlutil::cls();
    }
    Cliente cliente;
    cout<<"---------------CLIENTES-------------"<<endl<<endl;
    while(fread(&cliente,sizeof(Cliente),1,file))
    {
        cliente.mostrar();
    }
    fclose(file);
}
int ArchivoClientes::buscarPorDNI(int dni)  ///Busca la posicion de 1 cliente dentro del archivo clientes.dat, a partir de un DNI ingresado por teclado.
{
    if(contarRegistros()!=0)
    {
        FILE *file;
        file=fopen("Archivos/clientes.dat","rb");
        if(file==NULL)
        {
            rlutil::cls();
            rlutil::anykey("Error de lectura del archivo Clientes");
            rlutil::cls();
            return -1;
        }
        Cliente cliente;
        int pos=0;
        while(fread(&cliente,sizeof(Cliente),1,file))
        {
            if(dni==cliente.getDni())
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
        cout<<" No se puede realizar la búsqueda.\n El archivo Clientes está vacío."<<endl;
        return -1;
    }
}
int ArchivoClientes::buscarPorNombreApellido(char *names, char *surnames)    ///Busca la posicion de 1 cliente dentro del archivo clientes.dat, a partir de un NOMBRE Y APELLIDO ingresado por teclado.
{
    if(contarRegistros()!=0)
    {
        FILE *file;
        file=fopen("Archivos/Clientes.dat","rb");
        if(file==NULL)
        {
            rlutil::cls();
            rlutil::anykey("Error de lectura de archivo Clientes");
            rlutil::cls();
            return -2;
        }
        Cliente cliente;
        int pos=0;
        while(fread(&cliente,sizeof(Cliente),1,file))
        {
            if(strcmp(cliente.getNames(),names)==0)
            {
                if(strcmp(cliente.getSurnames(),surnames)==0)
                {
                    fclose(file);
                    return pos;
                }
            }
            pos++;
        }
        fclose(file);
        return -1;
    }
    else
    {
        cout<<" No se puede realizar la búsqueda.\n El archivo Clientes está vacío."<<endl;
        return -2;
    }
}
int ArchivoClientes::buscarPorNumSocio(int num)    ///Busca la posicion de 1 cliente dentro del archivo clientes.dat, a partir de un NUMERO DE SOCIO ingresado por teclado.
{
    if(contarRegistros()!=0)
    {
        FILE *file;
        file=fopen("Archivos/Clientes.dat","rb");
        if(file==NULL)
        {
            rlutil::cls();
            rlutil::anykey("Error de lectura de archivo Clientes");
            rlutil::cls();
            return -2;
        }
        Cliente cliente;
        int pos=0;
        while(fread(&cliente,sizeof(Cliente),1,file))
        {
            if(num==cliente.getNumSocio())
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
        cout<<" No se puede realizar la búsqueda.\n El archivo Clientes está vacío."<<endl;
        return -2;
    }
}
int ArchivoClientes::contarRegistros()  ///Cuenta la cantidad de clientes dentro del archivo clientes.dat.
{
    FILE *file;
    file=fopen("Archivos/clientes.dat","rb");
    if(file==NULL){return 0;}
    Cliente cliente;
    int cont=0;
    while(fread(&cliente,sizeof(Cliente),1,file))
    {
        cont++;
    }
    fclose(file);
    return cont;
}
int ArchivoClientes::contarRegistrosSinBajas()  ///Cuenta la cantidad de clientes dentro del archivo clientes.dat.
{
    FILE *file;
    file=fopen("Archivos/clientes.dat","rb");
    if(file==NULL){return 0;}
    Cliente cliente;
    int cont=0;
    while(fread(&cliente,sizeof cliente,1,file))
    {
        if(cliente.getEstado()==1){cont++;}
    }
    fclose(file);
    return cont;
}
bool ArchivoClientes::validarExistenciaDni(int dni)  ///Busca en el archivo Clientes.dat el DNI ingresado por teclado.
{
    if(buscarPorDNI(dni)!=-1 && buscarPorDNI(dni)!=-2)
    {
        return true; ///EL DNI "si" EXISTE EN EL ARCHIVO CLIENTES.
    }
    return false;   ///EL DNI "no" EXISTE EN EL ARCHIVO CLIENTES.

}
void ArchivoClientes::mostrarNombrePorDni(int dni)
{
    FILE *file;
    file=fopen("Archivos/Clientes.dat","rb");
    if(file==NULL){return;}
    Cliente cliente;
    while(fread(&cliente,sizeof(Cliente),1,file))
    {
        if(dni==cliente.getDni())
        {
            cout<<cliente.getNames()<<" "<<cliente.getSurnames();
        }
    }
    fclose(file);
}
bool ArchivoClientes::revisarFechasAptosMedicos()
{
    Fecha fecha=fecha.fechaActual(), fecha2; ///Fecha2 es la fecha de vencimiento del apto médico.
    FILE *file;
    file=fopen("Archivos/Clientes.dat","rb");
    if(file==NULL)
    {
        return false;
    }
    Cliente cliente;
    int pos=0;
    while(fread(&cliente,sizeof(Cliente),1,file))
    {
        fecha2.setDia(cliente.getFechaAptoMedico().getDia());
        fecha2.setMes(cliente.getFechaAptoMedico().getMes());
        fecha2.setAnio(cliente.getFechaAptoMedico().getAnio()+1); ///Se le suma 1 al año del apto médico ya que su validez es anual.

        if(fecha.getAnio()>fecha2.getAnio())
        {
            cliente.setAptoMedico(false);
            cliente.setEstado(false);
            sobreescribir(cliente,pos);
        }
        else if(fecha.getAnio()==fecha2.getAnio())
        {
            if(fecha.getMes()>fecha2.getMes())
            {
                cliente.setAptoMedico(false);
                cliente.setEstado(false);
                sobreescribir(cliente,pos);
            }
            else if(fecha.getMes()==fecha2.getMes())
            {
                if(fecha.getDia()>=fecha2.getDia())
                {
                    cliente.setAptoMedico(false);
                    cliente.setEstado(false);
                    sobreescribir(cliente,pos);
                }
            }
        }
        pos++;
    }
    fclose(file);
    return true;
}
bool ArchivoClientes::doBackup()   ///Realiza un backup del archivo.
{
    FILE *file1;
    file1=fopen("Archivos/Clientes.dat","rb");
    if(file1==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo Clientes");
        rlutil::cls();
        return false;
    }
    FILE *file2;
    file2=fopen("Archivos/Backup/Clientes.bkp","wb");
    if(file2==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo Clientes.bkp");
        rlutil::cls();
        fclose(file1);
        return false;
    }
    Cliente cliente;
    while(fread(&cliente,sizeof(Cliente),1,file1))
    {
        fwrite(&cliente,sizeof(Cliente),1,file2);
    }
    fclose(file1);
    fclose(file2);
    return true;
}
bool ArchivoClientes::restoreBackup()   ///Restaura un backup del archivo.
{
    FILE *file1;
    file1=fopen("Archivos/Backup/Clientes.bkp","rb");
    if(file1==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo Clientes.bkp");
        rlutil::cls();
        return false;
    }
    FILE *file2;
    file2=fopen("Archivos/Clientes.dat","wb");
    if(file2==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo Clientes");
        rlutil::cls();
        fclose(file1);
        return false;
    }
    Cliente cliente;
    while(fread(&cliente,sizeof(Cliente),1,file1))
    {
        fwrite(&cliente,sizeof(Cliente),1,file2);
    }
    fclose(file1);
    fclose(file2);
    return true;
}
