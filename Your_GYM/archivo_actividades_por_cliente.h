#ifndef ARCHIVO_ACTIVIDADES_POR_CLIENTE_H_INCLUDED
#define ARCHIVO_ACTIVIDADES_POR_CLIENTE_H_INCLUDED
#include "actividades_por_cliente.h"

class ArchivoActividadesCliente{
    public:
        void mostrarSinBajas(ActividadesCliente);
        void mostrarConBajas(ActividadesCliente);
        void mostrarTodas();
        void mostrarNombresEnCliente(int);
        void mostrarTodasPorDni(int);
        ActividadesCliente leer(int);
        int buscar_posicion_por_codigo_y_dni(int, int);
        bool guardar(ActividadesCliente);
        bool sobreescribir(ActividadesCliente, int);
        bool doBackup();
        bool restoreBackup();
        int contarRegistros();
        int contarActividadesPorDni(int);
        void mostrarTodasPorDni(); ///Sobrecarga de "void mostrarTodasPorDni(int);".
};

#endif // ARCHIVO_ACTIVIDADES_POR_CLIENTE_H_INCLUDED
