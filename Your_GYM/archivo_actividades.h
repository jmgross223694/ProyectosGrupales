#ifndef ARCHIVO_ACTIVIDADES_H_INCLUDED
#define ARCHIVO_ACTIVIDADES_H_INCLUDED
#include "actividades.h"

class ArchivoActividades{
    public:
        void mostrarSinBajas(Actividad);
        void mostrarConBajas(Actividad);
        bool guardar(Actividad);
        Actividad leer(int);
        int buscarPosicionPorCodigo(int);
        void mostrarNombrePorPosicion(int);
        bool sobreescribir(Actividad, int);
        int contarRegistros();
        int contarRegistrosSinBajas();
        void mostrarTodas();
        bool validarExistenciaActividad(int);
        bool validarEstadoActividad(int);
        bool doBackup();
        bool restoreBackup();
};

#endif // ARCHIVO_ACTIVIDADES_H_INCLUDED
