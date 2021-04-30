#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include "rlutil.h"
#include "abonoCliente.h"
#include "fecha.h"
#include "cliente.h"
#include "archivo_clientes.h"
#include "archivo_abonos.h"
#include "abonos.h"
#include "archivo_abonos_por_cliente.h"
#include "abonoCliente.h"
#include "archivo_actividades.h"
#include "actividades.h"
#include "archivo_actividades_por_cliente.h"
#include "actividades_por_cliente.h"
#include "archivo_movimientos_de_caja.h"
#include "movimientos_de_caja.h"
#include "menu.h"
using namespace std;

AbonoCliente::AbonoCliente()
{
    dniCliente=-1;
    strcpy(nombres,"VACIO");
    strcpy(apellidos,"VACIO");
    monto=0;
    pagoParcial=false;
    pagoTotal=false;
    mesAbonado=0;
    anioAbonado=0;
    fechaPago.setDia(-1);
    fechaPago.setMes(-1);
    fechaPago.setAnio(-1);
}
void AbonoCliente::setDniCliente(int dni)
{
    dniCliente=dni;
}
void AbonoCliente::setNombres(char *cad)
{
    strcpy(nombres,cad);
}
void AbonoCliente::setApellidos(char *cad)
{
    strcpy(apellidos,cad);
}
void AbonoCliente::setMonto(float total)
{
    monto=total;
}
void AbonoCliente::setPagoParcial(bool aux)
{
    pagoParcial=aux;
}
void AbonoCliente::setPagoTotal(bool aux)
{
    pagoTotal=aux;
}
void AbonoCliente::setMesAbonado(int mes)
{
    mesAbonado=mes;
}
void AbonoCliente::setAnioAbonado(int anio)
{
    anioAbonado=anio;
}
void AbonoCliente::setFechaPago(Fecha f)
{
    fechaPago.setDia(f.getDia());
    fechaPago.setMes(f.getMes());
    fechaPago.setAnio(f.getAnio());
}
int AbonoCliente::getDniCliente()
{
    return dniCliente;
}
char* AbonoCliente::getNombres()
{
    return nombres;
}
char* AbonoCliente::getApellidos()
{
    return apellidos;
}
float AbonoCliente::getMonto()
{
    return monto;
}
bool AbonoCliente::getPagoParcial()
{
    return pagoParcial;
}
bool AbonoCliente::getPagoTotal()
{
    return pagoTotal;
}
int AbonoCliente::getMesAbonado()
{
    return mesAbonado;
}
int AbonoCliente::getAnioAbonado()
{
    return anioAbonado;
}
Fecha AbonoCliente::getFechaPago()
{
    return fechaPago;
}
bool AbonoCliente::cargar()
{
    int dni, mes, anio, aux;
    Fecha fecha;
    cout<<"DNI: ";
    cin>>dni;
    ArchivoClientes archivoClientes;
    int posCliente=archivoClientes.buscarPorDNI(dni);
    if(posCliente==-1){return false;} ///Significa que el dni no fue encontrado en archivo cliente.dat.
    cout<<endl<<"Tipo de pago 1(Total) / 0(Parcial): ";
    cin>>aux;
    while(aux!=1 && aux!=0)
    {
        cout<<"Tipo de pago inválido\r";
        Sleep(1500);
        cout<<"                     \r";
        cout<<"Reintente >";
        cin>>aux;
    }
    if(aux==1)
    {
        setPagoTotal(true);
        setPagoParcial(false);
    }
    else
    {
        setPagoParcial(true);
        setPagoTotal(false);
    }
    cout<<endl<<"Período a abonar.";
    cout<<endl<<"Mes: ";
    cin>>mes;
    fecha.validarMes(&mes);
    cout<<"Año: ";
    cin>>anio;
    fecha.validarAnio(&anio);

    ///VALIDAR EN ESTE PUNTO QUE EL PERIODO ABONADO NO SE REPITA EN ARCHIVO PARA ESTE DNI.

    setDniCliente(dni);
    setMesAbonado(mes);
    setAnioAbonado(anio);
    fecha=fecha.fechaActual();
    setFechaPago(fecha);
    Cliente cliente=archivoClientes.leer(posCliente);
    setNombres(cliente.getNames());
    setApellidos(cliente.getSurnames());
    int codAbono=cliente.getAbono();
    ArchivoAbonos archivoAbonos;
    int posAbono=archivoAbonos.buscarPorCodigo(codAbono);
    Abono abono=archivoAbonos.leer(posAbono);
    float montoCuota, precioActividadesCliente=0, precioAbonoCliente=abono.getCosto();
    int tam;
    ArchivoActividadesCliente archivoActividadesCliente;
    FILE *file1;
    file1=fopen("Archivos/ActividadesPorCliente.dat","rb");
    if(file1==NULL){return false;}
    ActividadesCliente actividadesCliente;
    while(fread(&actividadesCliente,sizeof(ActividadesCliente),1,file1))
    {
        if(dni==actividadesCliente.getDni() && actividadesCliente.getEstado()==true)
        {
            int codAct=actividadesCliente.getCodigo();
            FILE *file2;
            file2=fopen("Archivos/Actividades.dat","rb");
            if(file2==NULL)
            {
                fclose(file1);
                return false;
            }
            Actividad actividad;
            while(fread(&actividad,sizeof(Actividad),1,file2))
            {
                if(codAct==actividad.getCodigo())
                {
                    precioActividadesCliente+=actividad.getCosto();
                }
            }
            fclose(file2);
        }
    }
    fclose(file1);
    montoCuota=precioAbonoCliente+precioActividadesCliente;
    setMonto(montoCuota);
    if(aux==0)
    {
        cout<<"Ingreso manual del monto: $";
        cin>>montoCuota;
        setMonto(montoCuota);
    }
    return true;
}
void AbonoCliente::mostrar()
{
    cout<<"-----------------------------------";
    cout<<endl<<"Dni            : "<<getDniCliente();
    cout<<endl<<"Nombres        : "<<getNombres();
    cout<<endl<<"Apellidos      : "<<getApellidos();
    cout<<endl<<"Monto          : $"<<getMonto();
    if(getPagoParcial()==true){cout<<endl<<"Tipo de pago   : Parcial";}
    else if(getPagoTotal()==true){cout<<endl<<"Tipo de pago   : Total";}
    else{cout<<endl<<"Tipo de pago   : -";}
    cout<<endl<<"Período abonado: "<<getMesAbonado()<<"/"<<getAnioAbonado();
    cout<<endl<<"Fecha de pago  : ";
    getFechaPago().mostrar();
    cout<<endl<<"-----------------------------------"<<endl<<endl;
}
bool AbonoCliente::modificar(int dni, int mesPagado, int anioPagado) ///Buscar pago de cuota por dni de cliente y período abonado.
{
    Menu menu;
    char cad[50];
    ArchivoAbonosPorCliente archivoAbonosPorCliente;
    int campo, pos=archivoAbonosPorCliente.buscarPorDni_yPeriodoAbonado(dni,mesPagado,anioPagado);
    if(pos==-1){return false;}
    AbonoCliente abonoCliente=archivoAbonosPorCliente.leer(pos);
    cout<<endl;
        abonoCliente.mostrar();
        cout<<endl;
        ///MOSTRAR CAMPOS A MODIFICAR.
        menu.subMenuCamposAbonoCliente();
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
            abonoCliente.setDniCliente(n);
        }
        break;
        case 2:
        {
            //Nombres.
            cout<<"Nuevo/s nombre/s: ";
            cin.getline(cad,50);
            while(validarCadenaVacia(cad)==false)
            {
                cin.getline(cad,50);
            }
            abonoCliente.setNombres(cad);
        }
        break;
        case 3:
        {
            //Apellidos.
            cout<<"Nuevo/s apellido/s: ";
            cin.getline(cad,50);
            while(validarCadenaVacia(cad)==false)
            {
                cin.getline(cad,50);
            }
            abonoCliente.setApellidos(cad);
        }
        break;
        case 4:
        {
            //Monto.
            float montoNuevo;
            cout<<"Nuevo monto: $";
            cin>>montoNuevo;
            abonoCliente.setMonto(montoNuevo);
        }
        break;
        case 5:
        {
            //Tipo de pago.
            int aux;
            cout<<"Nuevo tipo de pago 1(total)/0(parcial): ";
            cin>>aux;
            while(aux!=1 && aux!=0)
            {
                cout<<"Tipo de pago inválido\r";
                Sleep(1500);
                cout<<"                     \r";
                cout<<"Reintente >";
                cin>>aux;
            }
            if(aux==1)
            {
                abonoCliente.setPagoTotal(true);
                abonoCliente.setPagoParcial(false);
            }
            else
            {
                abonoCliente.setPagoParcial(true);
                abonoCliente.setPagoTotal(false);
            }
        }
        break;
        case 6:
        {
            //Período abonado.
            int mes, anio;
            Fecha fecha;
            cout<<"Nuevo período abonado.";
            cout<<endl<<"Mes: ";
            cin>>mes;
            fecha.validarMes(&mes);
            cout<<"Año: ";
            cin>>anio;
            fecha.validarAnio(&anio);
            abonoCliente.setMesAbonado(mes);
            abonoCliente.setAnioAbonado(anio);
        }
        break;
        case 0:
        {
            //Volver al menú Pago de cuotas.
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
        archivoAbonosPorCliente.sobreescribir(abonoCliente,pos);

        ///Se modifica el movimiento de caja correspondiente con los datos actualizados.
        ArchivoMovimientosCaja archivoMovimientosCaja;
        int pos2=archivoMovimientosCaja.buscarPorDetalleFecha(abonoCliente.getNombres(),abonoCliente.getApellidos(),abonoCliente.getFechaPago());
        MovimientoCaja movimientoCaja=archivoMovimientosCaja.leer(pos2);
        movimientoCaja.setMonto(abonoCliente.getMonto());
        movimientoCaja.setPagoParcial(abonoCliente.getPagoParcial());
        movimientoCaja.setPagoTotal(abonoCliente.getPagoTotal());
        movimientoCaja.setFecha(abonoCliente.getFechaPago());
        archivoMovimientosCaja.sobreescribir(movimientoCaja,pos2);

        return true;
}
bool AbonoCliente::validarCadenaVacia(char *cad)
{
    if(cad[0]=='\0')
    {
        cout<<"El valor no puede quedar vacío.\r";
        Sleep(1500);
        cout<<"                                           \r";
        cout<<"Reintente >";
        return false;
    }
    return true;
}
