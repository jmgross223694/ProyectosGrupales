#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "reportes.h"
#include "abonoCliente.h"
#include "archivo_movimientos_de_caja.h"

using namespace std;

bool Reporte::mostrarEstadoCuotasMensualesPorDniAnio(bool *mesesActivos, int *meses, int dni, int anio)
{
    FILE *file;
    file=fopen("Archivos/AbonosPorCliente.dat","rb");
    if(file==NULL){return false;}
    AbonoCliente abonoCliente;
    while(fread(&abonoCliente,sizeof(AbonoCliente),1,file))
    {
        if(dni==abonoCliente.getDniCliente() && anio==abonoCliente.getAnioAbonado())
        {
            if(abonoCliente.getPagoParcial()==true){meses[abonoCliente.getMesAbonado()-1]=2;}
            else if(abonoCliente.getPagoTotal()==true){meses[abonoCliente.getMesAbonado()-1]=1;}
            mesesActivos[abonoCliente.getMesAbonado()-1]=true;
        }
    }
    fclose(file);
    return true;
}
void Reporte::mostrarEstadoCuotas(bool *mesesActivos, int *meses, int dni, int anio, char *names, char *surnames)
{
    cout<<"------------------------------------"<<endl;
    cout<<"     DETALLE DE ABONO DE CUOTAS     "<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<" DNI: "<<dni<<endl;
    cout<<" Cliente: "<<names<<" "<<surnames<<endl;
    cout<<" Año: "<<anio<<endl;
    cout<<"------------------------------------"<<endl<<endl;
    cout<<" Meses:"<<endl<<endl;

    for(int i=0;i<12;i++)
    {
        if(mesesActivos[i]==true)
        {
            for(int x=0;x<12;x++)
            {
                mesesActivos[x]=true;
            }

            if(i<9){cout<<" 0";}
            else{cout<<" ";}
            cout<<i+1<<": ";
            if(meses[i]==0)
            {
                cout<<"No pagada";
            }
            else if(meses[i]==1)
            {
                cout<<"Pagada";
            }
            else if(meses[i]==2)
            {
                cout<<"Pagada parcialmente";
            }
            cout<<endl;
        }
    }
}
void Reporte::calcularIngresosEgresosMensualesPorAnio(int anio, float *vecEntradas, float *vecSalidas)
{
    FILE *file;
    file=fopen("Archivos/MovimientosCaja.dat","rb");
    if(file==NULL){return;}
    ArchivoMovimientosCaja archivoMovimientosCaja;
    MovimientoCaja movimientoCaja;
    while(fread(&movimientoCaja,sizeof(MovimientoCaja),1,file))
    {
        if(movimientoCaja.getFecha().getAnio()==anio)
        {
            if(movimientoCaja.getEntrada()==true){vecEntradas[movimientoCaja.getFecha().getMes()-1]+=movimientoCaja.getMonto();}
            else if(movimientoCaja.getSalida()==true){vecSalidas[movimientoCaja.getFecha().getMes()-1]+=movimientoCaja.getMonto();}
        }
    }
    fclose(file);
}
void Reporte::mostrarBalanceMensualAnual(float *vecEntradas, float *vecSalidas, int anio)
{
    float totalEntradas, totalSalidas, balance;
    for(int x=0;x<12;x++)
    {
        totalEntradas+=vecEntradas[x];
        totalSalidas+=vecSalidas[x];
    }
    balance=totalEntradas-totalSalidas;
    cout<<"---------------------------------------------------"<<endl;
    cout<<"          BALANCE MENSUAL Y ANUAL EN "<<anio<<endl;
    cout<<"---------------------------------------------------"<<endl;
    cout<<" Anual:"<<endl;
    cout<<" - Ingresos $"<<totalEntradas<<")"<<endl;
    cout<<" - Salidas  $"<<totalSalidas<<")"<<endl;
    cout<<" - Balance  $"<<balance<<")"<<endl;
    cout<<"---------------------------------------------------"<<endl<<endl;
    cout<<" Mensual:"<<endl;

    for(int i=0;i<12;i++)
    {
        if(i<9){cout<<" 0";}
        else{cout<<" ";}
        cout<<i+1<<": ";
        cout<<"Ingresos($"<<vecEntradas[i]<<")";
        cout<<" - Salidas($"<<vecSalidas[i]<<")";
        cout<<" - Balance($"<<vecEntradas[i]-vecSalidas[i]<<")";
        cout<<endl;
    }
}
float Reporte::calcularDineroEnSistemaPorFecha(Fecha fecha)
{
    FILE *file;
    file=fopen("Archivos/MovimientosCaja.dat","rb");
    if(file==NULL){return -1;}
    ArchivoMovimientosCaja archivoMovimientosCaja;
    MovimientoCaja movimientoCaja;
    int dia, mes, anio;
    float entradas=0, salidas=0, saldo;
    while(fread(&movimientoCaja,sizeof(MovimientoCaja),1,file))
    {
        dia=movimientoCaja.getFecha().getDia();
        mes=movimientoCaja.getFecha().getMes();
        anio=movimientoCaja.getFecha().getAnio();
        if(fecha.getAnio()==anio && fecha.getMes()==mes && fecha.getDia()==dia)
        {
            if(movimientoCaja.getEntrada()==true){entradas+=movimientoCaja.getMonto();}
            if(movimientoCaja.getSalida()==true){salidas+=movimientoCaja.getMonto();}
        }
    }
    fclose(file);
    saldo=entradas-salidas;
    return saldo;
}
