#ifndef ABONOS_H_INCLUDED
#define ABONOS_H_INCLUDED

class Abono{
    private:
        int codigo;
        char nombre[30];
        float costo;
        float interes;
        bool estado;
    public:
        Abono();
        void setCodigo(int);
        void setNombre(char *);
        void setCosto(float);
        void setInteres(float);
        void setEstado(bool);
        int getCodigo();
        char* getNombre();
        float getCosto();
        float getInteres();
        bool getEstado();
        void cargar();
        void mostrar();
        bool modificar(int);    ///FALTA CODEAR
        bool validarCadenaVacia(char *);
};

#endif // ABONOS_H_INCLUDED
