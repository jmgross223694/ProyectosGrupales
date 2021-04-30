#ifndef ARCHIVO_ABONOS_H_INCLUDED
#define ARCHIVO_ABONOS_H_INCLUDED
#include "abonos.h"

class ArchivoAbonos{
    public:
        bool guardar(Abono);
        bool sobreescribir(Abono, int);
        Abono leer(int);
        void mostrarTodos();
        int buscarPorCodigo(int);
        int buscarPorNombre(char *);
        int contarRegistros();
        bool doBackup();
        bool restoreBackup();
};


#endif // ARCHIVO_ABONOS_H_INCLUDED
