#ifndef ARQUEOS_DE_CAJA_H_INCLUDED
#define ARQUEOS_DE_CAJA_H_INCLUDED
#include "fecha.h"

class ArqueoDeCaja{
    private:
        Fecha fecha;
        float saldo;
    public:
        ArqueoDeCaja();
        void setFecha(Fecha);
        void setSaldo(float);
        Fecha getFecha();
        float getSaldo();
        void cargar(Fecha, float);
        void mostrar();
        //bool modificar();
};

#endif // ARQUEOS_DE_CAJA_H_INCLUDED
