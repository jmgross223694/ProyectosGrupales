#ifndef ARCHIVO_CLIENTES_H_INCLUDED
#define ARCHIVO_CLIENTES_H_INCLUDED

class ArchivoClientes{
    public:
        void mostrarSinBajas(Cliente);
        void mostrarConBajas(Cliente);
        bool guardar(Cliente);
        bool sobreescribir(Cliente, int);
        Cliente leer(int);
        void mostrarTodos();
        int buscarPorDNI(int);
        int buscarPorNombreApellido(char *, char *);
        int buscarPorNumSocio(int);
        int contarRegistros();
        int contarRegistrosSinBajas();
        bool validarExistenciaDni(int);
        void mostrarNombrePorDni(int);
        bool revisarFechasAptosMedicos();
        bool doBackup();
        bool restoreBackup();
};

#endif // ARCHIVO_CLIENTES_H_INCLUDED
