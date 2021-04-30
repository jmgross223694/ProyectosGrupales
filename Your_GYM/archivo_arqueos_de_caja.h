#ifndef ARCHIVO_ARQUEOS_DE_CAJA_H_INCLUDED
#define ARCHIVO_ARQUEOS_DE_CAJA_H_INCLUDED
#include "fecha.h"
#include "arqueos_de_caja.h"

class ArchivoArqueosDeCaja{
    public:
        bool guardar(ArqueoDeCaja);
        ArqueoDeCaja leer(int);
        //bool sobreescribir(ArqueoDeCaja, int);
        int buscarPorFechaCompleta(Fecha);
        float calcularArqueoPorMesAnio(int,int);
        float calcularArqueoPorAnio(int);
        int contarRegistros();
        void mostrarMesCalculado(int);
        bool doBackup();
        bool restoreBackup();
};

#endif // ARCHIVO_ARQUEOS_DE_CAJA_H_INCLUDED
