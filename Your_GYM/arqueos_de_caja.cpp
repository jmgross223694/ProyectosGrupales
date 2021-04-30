#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "rlutil.h"
#include "arqueos_de_caja.h"

using namespace std;

ArqueoDeCaja::ArqueoDeCaja()
{
    fecha.setDia(-1);
    fecha.setMes(-1);
    fecha.setAnio(-1);
    saldo=-999999;
}
void ArqueoDeCaja::setFecha(Fecha f)
{
    fecha.setDia(f.getDia());
    fecha.setMes(f.getMes());
    fecha.setAnio(f.getAnio());
}
void ArqueoDeCaja::setSaldo(float aux)
{
    saldo=aux;
}
Fecha ArqueoDeCaja::getFecha()
{
    return fecha;
}
float ArqueoDeCaja::getSaldo()
{
    return saldo;
}
void ArqueoDeCaja::cargar(Fecha f, float aux)
{
    setFecha(f);
    setSaldo(aux);
}
void ArqueoDeCaja::mostrar()
{
    cout<<"-------------------------";
    cout<<endl<<"Fecha: ";
    getFecha().mostrar();
    cout<<endl<<"Saldo: "<<getSaldo();
    cout<<endl<<"-------------------------"<<endl;
}
/*bool ArqueoDeCaja::modificar()
{

}
*/
