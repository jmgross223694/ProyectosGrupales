#ifndef ACTIVIDADES_H_INCLUDED
#define ACTIVIDADES_H_INCLUDED

class Actividad{
    private:
        int codigo;
        char nombre[50];
        float costo;
        bool estado;
    public:
        Actividad();
        void setCodigo(int);
        void setNombre(char *);
        void setCosto(float);
        void setEstado(bool);
        int getCodigo();
        char* getNombre();
        float getCosto();
        bool getEstado();
        void cargar();
        bool modificar(int);
        void mostrar();
        void mostrarEstado(bool);
};

#endif // ACTIVIDADES_H_INCLUDED
