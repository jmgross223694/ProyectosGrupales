#ifndef ABONOCLIENTE_H_INCLUDED
#define ABONOCLIENTE_H_INCLUDED
#include "fecha.h"

class AbonoCliente{
    private:
        int dniCliente;
        char nombres[50];
        char apellidos[50];
        float monto;
        bool pagoParcial;
        bool pagoTotal;
        int mesAbonado;
        int anioAbonado;
        Fecha fechaPago;
    public:
        AbonoCliente();
        void setDniCliente(int);
        void setNombres(char *);
        void setApellidos(char *);
        void setMonto(float);
        void setPagoParcial(bool);
        void setPagoTotal(bool);
        void setMesAbonado(int);
        void setAnioAbonado(int);
        void setFechaPago(Fecha);
        int getDniCliente();
        char* getNombres();
        char* getApellidos();
        float getMonto();
        bool getPagoParcial();
        bool getPagoTotal();
        int getMesAbonado();
        int getAnioAbonado();
        Fecha getFechaPago();
        bool cargar();
        void mostrar();
        bool modificar(int, int, int);
        bool validarCadenaVacia(char *);
};

#endif // ABONOCLIENTE_H_INCLUDED
