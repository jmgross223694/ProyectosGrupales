#ifndef ACTIVIDADES_POR_CLIENTE_H_INCLUDED
#define ACTIVIDADES_POR_CLIENTE_H_INCLUDED
#include "fecha.h"

class ActividadesCliente{
    private:
        int codigo;
        int dni;
        Fecha fechaAlta;
        Fecha fechaBaja;
        bool estado;
    public:
        ActividadesCliente();
        void setCodigo(int);
        void setDni(int);
        void setFechaAlta(Fecha);
        void setFechaBaja(Fecha);
        void setEstado(bool);
        int getCodigo();
        int getDni();
        Fecha getFechaAlta();
        Fecha getFechaBaja();
        bool getEstado();
        bool cargar(int,bool *);
        bool cargar2(int,int,bool *);
        void mostrar();
        bool modificar(int);
        void mostrarEstado(bool);
};

#endif // ACTIVIDADES_POR_CLIENTE_H_INCLUDED
