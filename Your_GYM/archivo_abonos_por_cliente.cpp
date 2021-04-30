#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include "rlutil.h"
#include "archivo_abonos.h"
#include "archivo_abonos_por_cliente.h"
#include "abonoCliente.h"
#include "fecha.h"
using namespace std;

bool ArchivoAbonosPorCliente::guardar(AbonoCliente abonoCliente)
{
    FILE *file;
    file=fopen("Archivos/AbonosPorCliente.dat","ab");
    if(file==NULL){return false;}
    if(fwrite(&abonoCliente,sizeof(AbonoCliente),1,file))
    {
        fclose(file);
        return true;
    }
    fclose(file);
    return false;
}
AbonoCliente ArchivoAbonosPorCliente::leer(int pos)
{
    FILE *file;
    file=fopen("Archivos/AbonosPorCliente.dat","rb");
    if(file!=NULL)
    {
        AbonoCliente abonoCliente;
        fseek(file,pos*sizeof(AbonoCliente),SEEK_SET);
        if(fread(&abonoCliente,sizeof(AbonoCliente),1,file)){return abonoCliente;}
    }
}
int ArchivoAbonosPorCliente::buscarPorDni_yPeriodoAbonado(int dni, int mesPagado, int anioPagado)
{
    FILE *file;
    file=fopen("Archivos/AbonosPorCliente.dat","rb");
    if(file==NULL){return -1;}
    AbonoCliente abonoCliente;
    int pos=0;
    while(fread(&abonoCliente,sizeof(AbonoCliente),1,file))
    {
        if(dni==abonoCliente.getDniCliente())
        {
            if(mesPagado==abonoCliente.getMesAbonado() && anioPagado==abonoCliente.getAnioAbonado())
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
void ArchivoAbonosPorCliente::mostrarTodos()
{
    FILE *file;
    file=fopen("Archivos/AbonosPorCliente.dat","rb");
    if(file==NULL){return;}
    AbonoCliente abonoCliente;
    cout<<"------------PAGOS DE CUOTA----------"<<endl<<endl;
    while(fread(&abonoCliente,sizeof(AbonoCliente),1,file))
    {
        abonoCliente.mostrar();
    }
    fclose(file);
}
void ArchivoAbonosPorCliente::mostrarTodosPorDni(int dni)
{
    FILE *file;
    file=fopen("Archivos/AbonosPorCliente.dat","rb");
    if(file==NULL){return;}
    AbonoCliente abonoCliente;
    cout<<"------------PAGOS DE CUOTA POR DNI----------"<<endl<<endl;
    cout<<"DNI: "<<dni<<endl<<endl;
    while(fread(&abonoCliente,sizeof(AbonoCliente),1,file))
    {
        if(dni==abonoCliente.getDniCliente()){abonoCliente.mostrar();}
    }
    fclose(file);
}
int ArchivoAbonosPorCliente::contarRegistros()
{
    FILE *file;
    file=fopen("Archivos/AbonosPorCliente.dat","rb");
    if(file==NULL){return 0;}
    AbonoCliente abonoCliente;
    int cont=0;
    while(fread(&abonoCliente,sizeof(AbonoCliente),1,file))
    {
        cont++;
    }
    fclose(file);
    return cont;
}
int ArchivoAbonosPorCliente::contarRegistrosPorDni(int dni)
{
    FILE *file;
    file=fopen("Archivos/AbonosPorCliente.dat","rb");
    if(file==NULL){return -1;}
    AbonoCliente abonoCliente;
    int cont=0;
    while(fread(&abonoCliente,sizeof(AbonoCliente),1,file))
    {
        if(dni==abonoCliente.getDniCliente()){cont++;}
    }
    fclose(file);
    return cont;
}
bool ArchivoAbonosPorCliente::sobreescribir(AbonoCliente abonoCliente, int pos)
{
    FILE *file;
    file=fopen("Archivos/AbonosPorCliente.dat","rb+");
    if (file==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo AbonosPorCliente");
        rlutil::cls();
        return false;
    }
    fseek(file,pos*sizeof(AbonoCliente),SEEK_SET);
    if(fwrite(&abonoCliente,sizeof(AbonoCliente),1,file))
    {
        fclose(file);
        return true;
    }
}
bool ArchivoAbonosPorCliente::doBackup()
{
    FILE *file1;
    file1=fopen("Archivos/AbonosPorCliente.dat","rb");
    if(file1==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo AbonosPorCliente");
        rlutil::cls();
        return false;
    }
    FILE *file2;
    file2=fopen("Archivos/Backup/AbonosPorCliente.bkp","wb");
    if(file2==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo AbonosPorCliente.bkp");
        rlutil::cls();
        fclose(file1);
        return false;
    }
    AbonoCliente abonoCliente;
    while(fread(&abonoCliente,sizeof(AbonoCliente),1,file1))
    {
        fwrite(&abonoCliente,sizeof(AbonoCliente),1,file2);
    }
    fclose(file1);
    fclose(file2);
    return true;
}
bool ArchivoAbonosPorCliente::restoreBackup()
{
    FILE *file1;
    file1=fopen("Archivos/Backup/AbonosPorCliente.bkp","rb");
    if(file1==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo AbonosPorCliente.bkp");
        rlutil::cls();
        return false;
    }
    FILE *file2;
    file2=fopen("Archivos/AbonosPorCliente.dat","wb");
    if(file2==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo AbonosPorCliente");
        rlutil::cls();
        fclose(file1);
        return false;
    }
    AbonoCliente abonoCliente;
    while(fread(&abonoCliente,sizeof(AbonoCliente),1,file1))
    {
        fwrite(&abonoCliente,sizeof(AbonoCliente),1,file2);
    }
    fclose(file1);
    fclose(file2);
    return true;
}
