#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include "rlutil.h"
#include "movimientos_de_caja.h"
#include "archivo_movimientos_de_caja.h"
using namespace std;

bool ArchivoMovimientosCaja::guardar(MovimientoCaja movimientoCaja)
{
    FILE *file;
    file=fopen("Archivos/MovimientosCaja.dat","ab");
    if (file==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo MovimientosCaja");
        rlutil::cls();
        return false;
    }
    if(fwrite(&movimientoCaja,sizeof(MovimientoCaja),1,file))
    {
        fclose(file);
        return true;
    }
}
MovimientoCaja ArchivoMovimientosCaja::leer(int pos)
{
    if(pos>=0)  ///pos=-1 (Movimiento de caja no encontrado en archivo) | pos=-2 (Archivo vacío).
    {
        FILE *file;
        file=fopen("Archivos/MovimientosCaja.dat","rb");
        if(file==NULL)
        {
            rlutil::cls();
            rlutil::anykey("Error de lectura del archivo MovimientosCaja");
            rlutil::cls();
        }
        MovimientoCaja movimientoCaja;
        fseek(file,pos*sizeof(MovimientoCaja),0);
        if(fread(&movimientoCaja,sizeof(MovimientoCaja),1,file))
        {
            fclose(file);
            return movimientoCaja;
        }
    }
    else if(pos==-1)
    {
        rlutil::cls();
        rlutil::anykey("El movimiento de caja no existe en el archivo.");
        rlutil::cls();
    }
}
int ArchivoMovimientosCaja::buscarPorId(int id)
{
    FILE *file;
    file=fopen("Archivos/MovimientosCaja.dat","rb");
    if(file==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura de archivo MovimientosCaja");
        rlutil::cls();
    }
    MovimientoCaja movimientoCaja;
    int pos=0;
    while(fread(&movimientoCaja,sizeof(MovimientoCaja),1,file))
    {
        if(id==movimientoCaja.getId())
        {
            fclose(file);
            return pos;
        }
        pos++;
    }
    fclose(file);
    return -1;
}
void ArchivoMovimientosCaja::buscarPorMesAnio(int mes, int anio)
{
    FILE *file;
    file=fopen("Archivos/MovimientosCaja.dat","rb");
    if(file==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura de archivo MovimientosCaja");
        rlutil::cls();
    }
    int pos=0;
    MovimientoCaja movimientoCaja;
    while(fread(&movimientoCaja,sizeof(MovimientoCaja),1,file))
    {
        if(mes==movimientoCaja.getFecha().getMes() && anio==movimientoCaja.getFecha().getAnio())
        {
            cout<<endl;
            movimientoCaja.mostrar();
            pos++;
        }
    }
    if(pos==0)
    {
        rlutil::anykey("No existen movimientos de caja para el período ingresado");
    }
    fclose(file);
}
int ArchivoMovimientosCaja::buscarPorDetalleFecha(char *nombres, char *apellidos, Fecha fechaPagado)
{
    FILE *file;
    file=fopen("Archivos/MovimientosCaja.dat","rb");
    if(file==NULL){return -1;}
    char cadFinal[15]="Pago cuota de ";
    strcat(cadFinal,nombres);
    strcat(cadFinal," ");
    strcat(cadFinal,apellidos);
    int pos=0;
    MovimientoCaja movimientoCaja;
    while(fread(&movimientoCaja,sizeof(MovimientoCaja),1,file))
    {
        if(strcmp(cadFinal,movimientoCaja.getDetalle())==0)
        {
            if(fechaPagado.getDia()==movimientoCaja.getFecha().getDia())
            {
                if(fechaPagado.getMes()==movimientoCaja.getFecha().getMes())
                {
                    if(fechaPagado.getAnio()==movimientoCaja.getFecha().getAnio())
                    {
                        fclose(file);
                        return pos;
                    }
                }
            }
        }
        pos++;
    }
    fclose(file);
    return -1;
}
int ArchivoMovimientosCaja::contarRegistros()
{
    FILE *file;
    file=fopen("Archivos/MovimientosCaja.dat","rb");
    if(file==NULL){return 0;}
    MovimientoCaja movimientoCaja;
    int cont=0;
    while(fread(&movimientoCaja,sizeof(MovimientoCaja),1,file))
    {
        cont++;
    }
    fclose(file);
    return cont;
}
void ArchivoMovimientosCaja::mostrarTodos(int cant) ///Muestra todos los clientes.
{
    MovimientoCaja movimientoCaja;
    cout<<"---------------Movimientos-------------"<<endl<<endl;
    for(int i=0;i<cant;i++)
    {
        movimientoCaja=leer(i);
        movimientoCaja.mostrar();
    }

}
bool ArchivoMovimientosCaja::doBackup()
{
    FILE *file1;
    file1=fopen("Archivos/MovimientosCaja.dat","rb");
    if(file1==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo MovimientosCaja");
        rlutil::cls();
        return false;
    }
    FILE *file2;
    file2=fopen("Archivos/Backup/MovimientosCaja.bkp","wb");
    if(file2==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo MovimientosCaja.bkp");
        rlutil::cls();
        fclose(file1);
        return false;
    }
    MovimientoCaja movimientoCaja;
    while(fread(&movimientoCaja,sizeof(MovimientoCaja),1,file1))
    {
        fwrite(&movimientoCaja,sizeof(MovimientoCaja),1,file2);
    }
    fclose(file1);
    fclose(file2);
    return true;
}
bool ArchivoMovimientosCaja::restoreBackup()
{
    FILE *file1;
    file1=fopen("Archivos/Backup/MovimientosCaja.bkp","rb");
    if(file1==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo MovimientosCaja.bkp");
        rlutil::cls();
        return false;
    }
    FILE *file2;
    file2=fopen("Archivos/MovimientosCaja.dat","wb");
    if(file2==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo MovimientosCaja");
        rlutil::cls();
        fclose(file1);
        return false;
    }
    MovimientoCaja movimientoCaja;
    while(fread(&movimientoCaja,sizeof(MovimientoCaja),1,file1))
    {
        fwrite(&movimientoCaja,sizeof(MovimientoCaja),1,file2);
    }
    fclose(file1);
    fclose(file2);
    return true;
}
bool ArchivoMovimientosCaja::sobreescribir(MovimientoCaja movimientoCaja, int pos)
{
    FILE *file;
    file=fopen("Archivos/MovimientosCaja.dat","rb+");
    if (file==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo MovimientosCaja");
        rlutil::cls();
        return false;
    }
    fseek(file,pos*sizeof(MovimientoCaja),SEEK_SET);
    if(fwrite(&movimientoCaja,sizeof(MovimientoCaja),1,file))
    {
        fclose(file);
        return true;
    }
}
