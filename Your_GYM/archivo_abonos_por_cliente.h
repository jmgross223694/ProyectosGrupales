#ifndef ARCHIVO_ABONOS_POR_CLIENTE_H_INCLUDED
#define ARCHIVO_ABONOS_POR_CLIENTE_H_INCLUDED
#include "abonoCliente.h"

class ArchivoAbonosPorCliente{
    public:
        bool guardar(AbonoCliente);
        AbonoCliente leer(int);
        int buscarPorDni_yPeriodoAbonado(int, int, int);
        void mostrarTodos();
        void mostrarTodosPorDni(int);
        int contarRegistros();
        int contarRegistrosPorDni(int);
        bool sobreescribir(AbonoCliente, int);
        bool doBackup();
        bool restoreBackup();
};

#endif // ARCHIVO_ABONOS_POR_CLIENTE_H_INCLUDED
