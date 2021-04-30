#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include "rlutil.h"
#include "archivo_abonos.h"
#include "abonos.h"
using namespace std;

bool ArchivoAbonos::guardar(Abono abono)
{
    FILE *file;
    file=fopen("Archivos/Abonos.dat","ab");
    if(file==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura de archivo Abonos");
        rlutil::cls();
        return false;
    }
    if(fwrite(&abono,sizeof(Abono),1,file))
    {
        fclose(file);
        return true;
    }
}
bool ArchivoAbonos::sobreescribir(Abono abono, int pos)
{
    FILE *file;
    file=fopen("Archivos/Abonos.dat","rb+");
    if(file==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura de archivo Abonos");
        rlutil::cls();
        return false;
    }
    fseek(file,pos*sizeof(Abono),SEEK_SET);
    if(fwrite(&abono,sizeof(Abono),1,file))
    {
        fclose(file);
        return true;
    }
    else
    {
        fclose(file);
        return false;
    }
}
Abono ArchivoAbonos::leer(int pos)
{
    if(pos>=0)
    {
        FILE *file;
        file=fopen("Archivos/Abonos.dat","rb");
        if(file==NULL)
        {
            rlutil::cls();
            rlutil::anykey("Error de lectura de archivo Abonos");
            rlutil::cls();
        }
        Abono abono;
        fseek(file,pos*sizeof(Abono),SEEK_SET);
        if(fread(&abono,sizeof(Abono),1,file))
        {
            fclose(file);
            return abono;
        }
    }
    else if(pos==-1)
    {
        rlutil::cls();
        rlutil::anykey("El abono no existe en el archivo.");
        rlutil::cls();
    }
}
void ArchivoAbonos::mostrarTodos()
{
    FILE *file;
    file=fopen("Archivos/Abonos.dat","rb");
    if(file==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura de archivo Abonos");
        rlutil::cls();
        return;
    }
    Abono abono;
    while(fread(&abono,sizeof(Abono),1,file))
    {
        abono.mostrar();
    }
    fclose(file);
}
int ArchivoAbonos::buscarPorCodigo(int cod)
{
    FILE *file;
    file=fopen("Archivos/Abonos.dat","rb");
    if(file==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura de archivo Abonos");
        rlutil::cls();
        return -1;
    }
    Abono abono;
    int pos=0;
    while(fread(&abono,sizeof(Abono),1,file))
    {
        if(cod==abono.getCodigo())
        {
            fclose(file);
            return pos;
        }
        pos++;
    }
    fclose(file);
    return -1;
}
int ArchivoAbonos::buscarPorNombre(char *cad)
{
    FILE *file;
    file=fopen("Archivos/Abonos.dat","rb");
    if(file==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura de archivo Abonos");
        rlutil::cls();
        return -1;
    }
    Abono abono;
    int pos=0;
    while(fread(&abono,sizeof(Abono),1,file))
    {
        if(strcmp(abono.getNombre(),cad)==0)
        {
            fclose(file);
            return pos;
        }
        pos++;
    }
    fclose(file);
    return -1;
}
int ArchivoAbonos::contarRegistros()
{
    FILE *file;
    file=fopen("Archivos/Abonos.dat","rb");
    if(file==NULL)
    {
        return 0;
    }
    int cont=0;
    Abono abono;
    while(fread(&abono,sizeof(Abono),1,file))
    {
        cont++;
    }
    fclose(file);
    return cont;
}
bool ArchivoAbonos::doBackup()
{
    FILE *file1;
    file1=fopen("Archivos/Abonos.dat","rb");
    if(file1==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura de archivo Abonos");
        rlutil::cls();
        return false;
    }
    FILE *file2;
    file2=fopen("Archivos/Backup/Abonos.bkp","wb");
    if(file2==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo Abonos.bkp");
        rlutil::cls();
        fclose(file1);
        return false;
    }
    Abono abono;
    while(fread(&abono,sizeof(Abono),1,file1))
    {
        fwrite(&abono,sizeof(Abono),1,file2);
    }
    fclose(file1);
    fclose(file2);
    return true;
}
bool ArchivoAbonos::restoreBackup()
{
    FILE *file1;
    file1=fopen("Archivos/Backup/Abonos.bkp","rb");
    if(file1==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo Abonos.bkp");
        rlutil::cls();
        return false;
    }
    FILE *file2;
    file2=fopen("Archivos/Abonos.dat","wb");
    if(file2==NULL)
    {
        rlutil::cls();
        rlutil::anykey("Error de lectura del archivo Abonos");
        rlutil::cls();
        fclose(file1);
        return false;
    }
    Abono abono;
    while(fread(&abono,sizeof(Abono),1,file1))
    {
        fwrite(&abono,sizeof(Abono),1,file2);
    }
    fclose(file1);
    fclose(file2);
    return true;
}
