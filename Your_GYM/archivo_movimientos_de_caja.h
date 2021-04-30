#ifndef ARCHIVO_MOVIMIENTOS_DE_CAJA_H_INCLUDED
#define ARCHIVO_MOVIMIENTOS_DE_CAJA_H_INCLUDED
#include "movimientos_de_caja.h"

class ArchivoMovimientosCaja{
    public:
        bool guardar(MovimientoCaja);
        MovimientoCaja leer(int); //Recibe posicion
        int buscarPorId(int);
        void buscarPorMesAnio(int, int);
        int buscarPorDetalleFecha(char *, char *, Fecha);
        int contarRegistros();
        void mostrarTodos(int); //Recibe un entero que representa la cantidad de registros en archivo.
        bool doBackup();
        bool restoreBackup();
        bool sobreescribir(MovimientoCaja, int);
};

#endif // ARCHIVO_MOVIMIENTOS_DE_CAJA_H_INCLUDED
