#ifndef MOVIMIENTOS_DE_CAJA_H_INCLUDED
#define MOVIMIENTOS_DE_CAJA_H_INCLUDED
#include "fecha.h"

class MovimientoCaja{
    private:
        int id;
        char detalle[100];
        float monto;
        bool entrada;
        bool salida;
        bool pagoParcial;
        bool pagoTotal;
        Fecha fecha;
    public:
        MovimientoCaja();
        void setId(int);
        void setDetalle(char *);
        void setMonto(float);
        void setEntrada(bool);
        void setSalida(bool);
        void setPagoParcial(bool);
        void setPagoTotal(bool);
        void setFecha(Fecha);
        int getId();
        char* getDetalle();
        float getMonto();
        bool getEntrada();
        bool getSalida();
        bool getPagoParcial();
        bool getPagoTotal();
        Fecha getFecha();
        void cargarIngreso();
        void cargarAbonoCliente(char *, char *, float, bool, bool, Fecha);
        void cargarSalida();
        void mostrar();
        bool modificar(int);
        bool validarCadenaVacia(char *);
};


#endif // MOVIMIENTOS_DE_CAJA_H_INCLUDED
