#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "rlutil.h"
#include "fecha.h"
#include "arqueos_de_caja.h"
#include "archivo_arqueos_de_caja.h"

using namespace std;

bool ArchivoArqueosDeCaja::guardar(ArqueoDeCaja arqueoDeCaja)
{
    FILE *file;
    file=fopen("Archivos/ArqueosCaja.dat","ab");
    if (file==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo ArqueosCaja");
        rlutil::cls();
        return false;
    }
    if(fwrite(&arqueoDeCaja,sizeof(ArqueoDeCaja),1,file))
    {
        fclose(file);
        return true;
    }
}
ArqueoDeCaja ArchivoArqueosDeCaja::leer(int pos)
{
    FILE *file;
    file=fopen("Archivos/ArqueosCaja.dat","rb");
    if(file==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo ArqueosCaja");
        rlutil::cls();
    }
    else
    {
        ArqueoDeCaja arqueoDeCaja;
        fseek(file,pos*sizeof(ArqueoDeCaja),0);
        if(fread(&arqueoDeCaja,sizeof(ArqueoDeCaja),1,file))
        {
            fclose(file);
            return arqueoDeCaja;
        }
    }
}
/*bool ArchivoArqueosDeCaja::sobreescribir(ArqueoDeCaja arqueoDeCaja, int pos)
{
    FILE *file;
    file=fopen("Archivos/ArqueosCaja.dat","rb+");
    if (file==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo ArqueosCaja");
        rlutil::cls();
        return false;
    }
    fseek(file,pos*sizeof(ArqueoDeCaja),SEEK_SET);
    if(fwrite(&arqueoDeCaja,sizeof(ArqueoDeCaja),1,file))
    {
        fclose(file);
        return true;
    }
}*/
int ArchivoArqueosDeCaja::buscarPorFechaCompleta(Fecha f)
{
    if(contarRegistros()!=0)
    {
        FILE *file;
        file=fopen("Archivos/ArqueosCaja.dat","rb");
        if(file==NULL)
        {
            rlutil::cls();
            rlutil::anykey("Error de lectura del archivo ArqueosCaja");
            rlutil::cls();
            return -1;
        }
        ArqueoDeCaja arqueoDeCaja;
        int pos=0, dia, mes, anio;
        while(fread(&arqueoDeCaja,sizeof(ArqueoDeCaja),1,file))
        {
            dia=arqueoDeCaja.getFecha().getDia();
            mes=arqueoDeCaja.getFecha().getMes();
            anio=arqueoDeCaja.getFecha().getAnio();
            if(f.getAnio()==anio && f.getMes()==mes && f.getDia()==dia)
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
        cout<<" No se puede realizar la búsqueda.\n El archivo ArqueosCaja está vacío."<<endl;
        return -1;
    }
}
float ArchivoArqueosDeCaja::calcularArqueoPorMesAnio(int mesRecibido, int anioRecibido)
{
    FILE *file;
    file=fopen("Archivos/ArqueosCaja.dat","rb");
    if(file==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo ArqueosCaja");
        rlutil::cls();
    }
    else
    {
        ArqueoDeCaja arqueoDeCaja;
        int mesArqueo, anioArqueo;
        float acu=0;
        while(fread(&arqueoDeCaja,sizeof(ArqueoDeCaja),1,file))
        {
            mesArqueo=arqueoDeCaja.getFecha().getMes();
            anioArqueo=arqueoDeCaja.getFecha().getAnio();
            if(mesRecibido==mesArqueo && anioRecibido==anioArqueo)
            {
                acu+=arqueoDeCaja.getSaldo();
            }
        }
        fclose(file);
        return acu;
    }
}
float ArchivoArqueosDeCaja::calcularArqueoPorAnio(int anioRecibido)
{
    FILE *file;
    file=fopen("Archivos/ArqueosCaja.dat","rb");
    if(file==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo ArqueosCaja");
        rlutil::cls();
    }
    else
    {
        ArqueoDeCaja arqueoDeCaja;
        int anioArqueo;
        float acu=0;
        while(fread(&arqueoDeCaja,sizeof(ArqueoDeCaja),1,file))
        {
            anioArqueo=arqueoDeCaja.getFecha().getAnio();
            if(anioRecibido==anioArqueo)
            {
                acu+=arqueoDeCaja.getSaldo();
            }
        }
        fclose(file);
        return acu;
    }
}
int ArchivoArqueosDeCaja::contarRegistros()
{
    FILE *file;
    file=fopen("Archivos/ArqueosCaja.dat","rb");
    if(file==NULL){return 0;}
    ArqueoDeCaja arqueoDeCaja;
    int cant=0;
    while(fread(&arqueoDeCaja,sizeof(ArqueoDeCaja),1,file))
    {
        cant++;
    }
    fclose(file);
    return cant;
}
void ArchivoArqueosDeCaja::mostrarMesCalculado(int mes)
{
    switch(mes)
    {
    case 1:
    {
        cout<<"Enero";
    }
    break;
    case 2:
    {
        cout<<"Febrero";
    }
    break;
    case 3:
    {
        cout<<"Marzo";
    }
    break;
    case 4:
    {
        cout<<"Abril";
    }
    break;
    case 5:
    {
        cout<<"Mayo";
    }
    break;
    case 6:
    {
        cout<<"Junio";
    }
    break;
    case 7:
    {
        cout<<"Julio";
    }
    break;
    case 8:
    {
        cout<<"Agosto";
    }
    break;
    case 9:
    {
        cout<<"Septiembre";
    }
    break;
    case 10:
    {
        cout<<"Octubre";
    }
    break;
    case 11:
    {
        cout<<"Noviembre";
    }
    break;
    case 12:
    {
        cout<<"Diciembre";
    }
    break;
    }
}
bool ArchivoArqueosDeCaja::doBackup()
{
    FILE *file1;
    file1=fopen("Archivos/ArqueosCaja.dat","rb");
    if(file1==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo ArqueosCaja");
        rlutil::cls();
        return false;
    }
    FILE *file2;
    file2=fopen("Archivos/Backup/ArqueosCaja.bkp","wb");
    if(file2==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo ArqueosCaja.bkp");
        rlutil::cls();
        fclose(file1);
        return false;
    }
    ArqueoDeCaja arqueoDeCaja;
    while(fread(&arqueoDeCaja,sizeof(ArqueoDeCaja),1,file1))
    {
        fwrite(&arqueoDeCaja,sizeof(ArqueoDeCaja),1,file2);
    }
    fclose(file1);
    fclose(file2);
    return true;
}
bool ArchivoArqueosDeCaja::restoreBackup()
{
    FILE *file1;
    file1=fopen("Archivos/Backup/ArqueosCaja.bkp","rb");
    if(file1==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo ArqueosCaja.bkp");
        rlutil::cls();
        return false;
    }
    FILE *file2;
    file2=fopen("Archivos/ArqueosCaja.dat","wb");
    if(file2==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo ArqueosCaja");
        rlutil::cls();
        fclose(file1);
        return false;
    }
    ArqueoDeCaja arqueoDeCaja;
    while(fread(&arqueoDeCaja,sizeof(ArqueoDeCaja),1,file1))
    {
        fwrite(&arqueoDeCaja,sizeof(ArqueoDeCaja),1,file2);
    }
    fclose(file1);
    fclose(file2);
    return true;
}
