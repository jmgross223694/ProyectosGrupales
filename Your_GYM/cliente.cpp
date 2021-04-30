#include <iostream>
#include <cstring>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "cliente.h"
#include "archivo_clientes.h"
#include "archivo_actividades.h"
#include "archivo_actividades_por_cliente.h"
#include "fecha.h"
#include "rlutil.h"
#include "actividades_por_cliente.h"
#include "actividades.h"
#include "menu.h"

Cliente::Cliente()
{
    numSocio=-1;
    dni=-1;
    strcpy(names,"vacio");
    strcpy(surnames,"vacio");
    nacimiento.setDia(-1);
    nacimiento.setMes(-1);
    nacimiento.setAnio(-1);
    alta.setDia(-1);
    alta.setMes(-1);
    alta.setAnio(-1);
    abono=-1;
    aptoMedico=false;
    //strcpy(afecciones,"vacio");
    estado=false;
}
void Cliente::setNumSocio(int n)
{
    numSocio=n;
}
void Cliente::setDni(int n)
{
    dni=n;
}
void Cliente::setNames(char *cad)
{
    strcpy(names,cad);
}
void Cliente::setSurnames(char *cad)
{
    strcpy(surnames,cad);
}
void Cliente::setNacimiento(Fecha f)
{
    nacimiento.setDia(f.getDia());
    nacimiento.setMes(f.getMes());
    nacimiento.setAnio(f.getAnio());
}
void Cliente::setAlta(Fecha f)
{
    alta.setDia(f.getDia());
    alta.setMes(f.getMes());
    alta.setAnio(f.getAnio());
}
void Cliente::setAbono(int n)
{
    abono=n;
}
void Cliente::setAptoMedico(bool e)
{
    aptoMedico=e;
}
void Cliente::setFechaAptoMedico(Fecha f)
{
    fechaAptoMedico.setDia(f.getDia());
    fechaAptoMedico.setMes(f.getMes());
    fechaAptoMedico.setAnio(f.getAnio());
}
//void Cliente::setAfecciones(char *cad){strcpy(afecciones,cad);}
void Cliente::setEstado(bool e)
{
    estado=e;
}
int Cliente::getNumSocio()
{
    return numSocio;
}
int Cliente::getDni()
{
    return dni;
}
char* Cliente::getNames()
{
    return names;
}
char* Cliente::getSurnames()
{
    return surnames;
}
Fecha Cliente::getNacimiento()
{
    return nacimiento;
}
Fecha Cliente::getAlta()
{
    return alta;
}
int Cliente::getAbono()
{
    return abono;
}
int Cliente::getAptoMedico()
{
    return aptoMedico;
}
Fecha Cliente::getFechaAptoMedico()
{
    return fechaAptoMedico;
}
//char* Cliente::getAfecciones(){return afecciones;}
bool Cliente::getEstado()
{
    return estado;
}
void Cliente::cargar()  ///Pide los datos necesarios para cargar un cliente al sistema.
{
    cout<<"------------INGRESO DE NUEVO CLIENTE------------"<<endl<<endl;
    int n;
    Fecha f;
    bool fin=false;
    ActividadesCliente actividadesCliente;
    ArchivoActividadesCliente archivoActividadesCliente;
    ArchivoClientes archivoClientes;
    n=archivoClientes.contarRegistros();
    setNumSocio(n+1);
    cout<<"DNI (sólo números): ";
    cin>>n;
    while(contarDigitosDni(n)==false)
    {
        cout<<"Formato DNI inválido. Reintente >";
        cin>>n;
    }
    if(numSocio>1)
    {
        while(archivoClientes.validarExistenciaDni(n)==true)
        {
            cout<<"El DNI ingresado ya existe en el sistema."<<endl<<"Reintente >";
            cin>>n;
            while(contarDigitosDni(n)==false)
            {
                cout<<"Formato DNI inválido."<<endl<<"Reintente >";
                cin>>n;
            }
        }
    }
    setDni(n);
    cin.ignore();
    char cad[50];
    cout<<endl<<"Nombre/s: ";
    cin.getline(cad,50);
    while(validarCadenaVacia(cad)==false)
    {
        cin.getline(cad,50);
    }
    setNames(cad);
    cout<<endl<<"Apellido/s: ";
    cin.getline(cad,50);
    while(validarCadenaVacia(cad)==false)
    {
        cin.getline(cad,50);
    }
    setSurnames(cad);
    cout<<endl<<"Fecha de Nacimiento: ";
    f=f.cargar();
    f=f.validarFechaCompleta(f);
    setNacimiento(f);
    f=f.fechaActual();
    setAlta(f);
    cout<<endl;
    while(!fin)
    {
        actividadesCliente.cargar(getDni(),&fin); ///CARGA LA/S ACTIVIDAD/ES QUE REALIZA UN CLIENTE;
        archivoActividadesCliente.guardar(actividadesCliente);
    }
    cout<<"Tipo de abono: ";
    cin>>n;
    setAbono(n);
    cout<<endl<<"Apto médico (1/0): ";
    cin>>n;
    while(n!=1 && n!=0)
    {
        cout<<"Valor inválido. >";
        cin>>n;
    }
    setAptoMedico(n);
    cout<<endl<<"Fecha de apto médico: ";
    f=f.cargar();
    f=f.validarFechaCompleta(f);
    setFechaAptoMedico(f);
    /*
    cout<<endl<<"Afecciones: ";
    cin.getline(cad,50);
    while(validarCadenaVacia(cad)==false)
    {
        cin.getline(cad,50);
    }
    setAfecciones(cad);
    */
    setEstado(true);
}
void Cliente::mostrar() ///Muestra un cliente.
{
    ArchivoActividadesCliente archivoActividadesCliente;
    cout<<"-----------------------------------";
    cout<<endl<<"N° Socio              : "<<getNumSocio();
    cout<<endl<<"DNI                   : "<<getDni();
    cout<<endl<<"Nombre                : "<<getNames();
    cout<<endl<<"Apellidos             : "<<getSurnames();
    cout<<endl<<"Fecha de nacimiento   : ";
    getNacimiento().mostrar();
    cout<<endl<<"Alta en sistema desde : ";
    getAlta().mostrar();
    cout<<endl<<"Actividades realizadas: ";
    archivoActividadesCliente.mostrarNombresEnCliente(getDni());
    cout<<endl<<"Tipo de abono         : "<<getAbono();
    cout<<endl<<"Apto médico           : ";
    if(getAptoMedico()==true){cout<<"Apto";}
    else{cout<<"NO apto";}
    cout<<endl<<"Última revisión médica: ";
    getFechaAptoMedico().mostrar();
    if(getAptoMedico()==false){cout<<" (Vencida)";}
    //cout<<endl<<"Afecciones            : "<<getAfecciones();
    cout<<endl<<"Estado en sistema     : ";
    mostrarEstado(getEstado());
//    cout<<getEstado()==true?"Activo":"Inactivo";  CONSULTAR CON ANGEL
    cout<<endl<<"-----------------------------------"<<endl<<endl;
}
bool Cliente::contarDigitosDni(int dni)  ///Cuenta las cifras que tiene el DNI ingresado por teclado.
{
    int cont=0;
    while(dni>0)
    {
        dni=dni/10;
        cont++;
    }
    if(cont<7 || cont>8)
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool Cliente::validarCadenaVacia(char *cad)
{
    if(cad[0]=='\0')
    {
        cout<<"El nombre no puede quedar vacío.\r";
        Sleep(1500);
        cout<<"                                           \r";
        cout<<"Reintente >";
        return false;
    }
    return true;
}
bool Cliente::modificar(int dni)  ///Modifica 1 cliente, a partir de un DNI ingresado por teclado.
{
    Cliente cliente;
    Menu menu;
    ArchivoClientes archivoClientes;
    int pos, campo;
    char cad[50];
    pos=archivoClientes.buscarPorDNI(dni);
    cliente=archivoClientes.leer(pos);
    ///MOSTRAR CLIENTE
    if(pos>=0)
    {
        cout<<endl;
        archivoClientes.mostrarConBajas(cliente);
        cout<<endl;
        ///MOSTRAR CAMPOS A MODIFICAR.
        menu.subMenuCamposCliente();
        ///FIN CAMPOS A MODIFICAR.
        cout<<endl<<"¿Qué desea modificar? ";
        cin>>campo;
        cin.ignore();
        rlutil::cls();
        switch(campo)
        {
        case 1:
        {
            //DNI.
            int n;
            cout<<"Nuevo DNI (solo números): ";
            cin>>n;
            while(contarDigitosDni(n)==false)
            {
                cout<<"DNI inválido. >";
                cin>>n;
            }
            cliente.setDni(n);
        }
        break;
        case 2:
        {
            //Nombres.
            cout<<"Nuevo/s nombre/s: ";
            cin.getline(cad,50);
            cliente.setNames(cad);
        }
        break;
        case 3:
        {
            //Apellidos.
            cout<<"Nuevo/s apellido/s: ";
            cin.getline(cad,50);
            cliente.setSurnames(cad);
        }
        break;
        case 4:
        {
            //Fecha de nacimiento.
            int d,m,a;
            Fecha f;
            cout<<"Nueva Fecha de Nacimiento: ";
            cin>>d>>m>>a;
            f=f.cargar();
            f=f.validarFechaCompleta(f);
            cliente.setNacimiento(f);
        }
        break;
        case 5:
        {
            /// 1) buscar y mostrar las actividades (solo estado = true) para el dni recibido como parametro.

            ArchivoClientes archivoClientes;
            ArchivoActividades archivoActividades;
            cout<<"Actividades realizadas por ";
            archivoClientes.mostrarNombrePorDni(dni);
            cout<<":"<<endl<<"-----------------"<<endl;
            ArchivoActividadesCliente archivoActividadesCliente;
            archivoActividadesCliente.mostrarTodasPorDni(dni);

            cout<<"Ingrese N° de actividad a modificar / agregar: ";
            int codAct;
            cin>>codAct;
            int pos2=archivoActividadesCliente.buscar_posicion_por_codigo_y_dni(codAct,dni);
            if(pos2!=-1)
            {
                ///Significa que la actividad existe para este cliente.
                ActividadesCliente actividadesCliente;
                actividadesCliente=archivoActividadesCliente.leer(pos2);
                if(actividadesCliente.getEstado()==true)
                {
                    cout<<endl<<"La actividad elegida, está actualmente activa.\n";
                    cout<<"¿Desea darla de baja para este cliente?\n\n";
                    cout<<"SI/NO (1/0): ";
                    int op;
                    cin>>op;
                    while(op!=1 && op!=0)
                    {
                        rlutil::anykey("Opción incorrecta");
                        cout<<endl<<"Reintente >";
                        cin>>op;
                    }
                    if(op==1)
                    {
                        Fecha f;
                        actividadesCliente.setEstado(false);
                        f=f.fechaActual();
                        actividadesCliente.setFechaBaja(f);
                        if(archivoActividadesCliente.sobreescribir(actividadesCliente,pos2)==true)
                        {
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    cout<<endl<<"La actividad elegida, está actualmente inactiva.\n";
                    cout<<"¿Desea darla de alta para este cliente?\n\n";
                    cout<<"SI/NO (1/0): ";
                    int op;
                    cin>>op;
                    while(op!=1 && op!=0)
                    {
                        rlutil::anykey("Opción incorrecta");
                        cout<<endl<<"Reintente >";
                        cin>>op;
                    }
                    if(op==1)
                    {
                        Fecha f;
                        actividadesCliente.setEstado(true);
                        f=f.fechaActual();
                        actividadesCliente.setFechaAlta(f);
                        if(archivoActividadesCliente.sobreescribir(actividadesCliente,pos2)==true)
                        {
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            else ///Acá entra solamente si esta actividad no existe en el archivo ActividadesPorCliente.
            {
                ///Si devuelve -1, la actividad nunca fue realizada por este cliente.
                ///Primero comprobamos que la actividad ingresada, exista en el gimnasio.

                int pos3=archivoActividades.buscarPosicionPorCodigo(codAct);
                if(pos3!=-1)
                {
                    Actividad actividad;
                    actividad=archivoActividades.leer(pos3);
                    if(actividad.getEstado()==true)
                    {
                        bool fin=false;
                        int codigo;
                        while(!fin)
                        {
                            codigo=codAct;
                            ActividadesCliente actividadesCliente;
                            actividadesCliente.cargar2(codigo,dni,&fin);
                            archivoActividadesCliente.guardar(actividadesCliente);
                            if(fin==false)
                            {
                                cout<<"Código de actividad: ";
                                cin>>codAct;
                            }
                        }
                        return true;
                    }
                    else
                    {
                        rlutil::cls();
                        rlutil::anykey("La actividad ingresada está inactiva en el gimnasio.\nPrimero deberá habilitarla desde la opción Actividades del menú principal.");
                        return false;
                    }
                }
                else
                {
                    rlutil::cls();
                    rlutil::anykey("La actividad ingresada no está registrada en el gimnasio.\nPrimero deberá cargarla desde la opción Actividades del menú principal.");
                    return false;
                }
            }
        }
        break;
        case 6:
        {
            //Membresía.
            int n;
            cout<<"Nuevo tipo de abono: ";
            cin>>n;
            cliente.setAbono(n);
        }
        break;
        case 7:
        {
            //Apto médico.
            int n;
            if(cliente.getAptoMedico()==true)
            {
                cout<<"¿Confirma BAJA de apto médico?";
                cout<<"(1-SI / 0-NO): ";
                cin>>n;
                while(n!=1 && n!=0)
                {
                    cout<<"Reintente. >";
                    cin>>n;
                }
                if(n==1)
                {
                    cliente.setAptoMedico(false);
                }
                else
                {
                    return false;
                }
            }
            else
            {
                cout<<"¿Confirma ALTA de alto médico?";
                cout<<"(1-SI / 0-NO): ";
                cin>>n;
                while(n!=1 && n!=0)
                {
                    cout<<"Reintente. >";
                    cin>>n;
                }
                if(n==1)
                {
                    cliente.setAptoMedico(true);
                }
                else
                {
                    return false;
                }
            }
        }
        break;
        case 8:
        {
            //Fecha de apto médico.
            Fecha f;
            cout<<"Nueva fecha de última revisión médica: ";
            f=f.cargar();
            cliente.setFechaAptoMedico(f);
        }
        break;
        case 9:
        {
            //Estado en sistema.
            if(cliente.getEstado()==1)
            {
                cout<<"¿Deshabilitar CLIENTE en sistema?"<<endl;
                cout<<"(1-SI / 0-NO): ";
                int confirmacion;
                cin>>confirmacion;
                while(confirmacion!=1 && confirmacion!=0)
                {
                    cout<<"Reintente. >";
                    cin>>confirmacion;
                }
                if(confirmacion==1)
                {
                    cliente.setEstado(false);
                }
                else
                {
                    return false;
                }
            }
            else
            {
                cout<<"¿Habilitar CLIENTE en sistema?"<<endl;
                cout<<"(1-SI / 0-NO): ";
                int confirmacion;
                cin>>confirmacion;
                while(confirmacion!=1 && confirmacion!=0)
                {
                    cout<<"Reintente. >";
                    cin>>confirmacion;
                }
                if(confirmacion==1)
                {
                    cliente.setEstado(true);
                }
                else
                {
                    return false;
                }
            }
        }
        break;
        case 0:
        {
            //Volver al menú Clientes.
            return false;
        }
        break;
        default:
        {
            rlutil::anykey("Opcion incorrecta");
            return false;
        }
        break;
        }
        archivoClientes.sobreescribir(cliente,pos);
        return true;
    }
    return false;
}
void Cliente::mostrarEstado(bool estado)   ///Muestra una palabra u otra, según estado de cliente en sistema.
{
    if(estado==true)
    {
        cout<<"Activo";
    }
    else
    {
        cout<<"Inactivo";
    }
}
