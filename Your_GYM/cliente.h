#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include "fecha.h"
#include "actividades_por_cliente.h"

class Cliente{
    private:
        int numSocio;
        int dni;
        char names[50];
        char surnames[50];
        Fecha nacimiento;
        Fecha alta;
        int abono;
        bool aptoMedico;
        Fecha fechaAptoMedico;
        //char afecciones[100];
        bool estado;
    public:
        Cliente();
        void setNumSocio(int);
        void setDni(int);
        void setNames(char *);
        void setSurnames(char *);
        void setNacimiento(Fecha);
        void setAlta(Fecha);
        void setAbono(int);
        void setAptoMedico(bool);
        void setFechaAptoMedico(Fecha);
        //void setAfecciones(char *);
        void setEstado(bool);
        int getNumSocio();
        int getDni();
        char* getNames();
        char* getSurnames();
        Fecha getNacimiento();
        Fecha getAlta();
        int getAbono();
        int getAptoMedico();
        Fecha getFechaAptoMedico();
        //char* getAfecciones();
        bool getEstado();
        void cargar();
        void mostrar();
        bool contarDigitosDni(int);
        bool validarCadenaVacia(char *);
        bool modificar(int);
        void mostrarEstado(bool);
};

#endif // CLIENTE_H_INCLUDED
