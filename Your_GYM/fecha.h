#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha{
    private:
        int dia, mes, anio;
    public:
        Fecha();
        int getDia();
        int getMes();
        int getAnio();
        void setDia(int);
        void setMes(int);
        void setAnio(int);
        Fecha cargar();
        void mostrar();
        Fecha fechaActual();
        void validarDia(int *);
        void validarMes(int *);
        void validarAnio(int *);
        Fecha validarFechaCompleta(Fecha f);
        bool anioBisiesto(int);
};

#endif // FECHA_H_INCLUDED
