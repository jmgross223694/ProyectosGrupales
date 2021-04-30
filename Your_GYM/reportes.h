#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED
#include "fecha.h"

class Reporte{
    public:
        bool mostrarEstadoCuotasMensualesPorDniAnio(bool *, int *, int, int);
        void mostrarEstadoCuotas(bool *, int *, int, int, char *, char *);
        void calcularIngresosEgresosMensualesPorAnio(int, float *, float *);
        void mostrarBalanceMensualAnual(float *, float *, int);
        float calcularDineroEnSistemaPorFecha(Fecha);
};

#endif // REPORTES_H_INCLUDED
