#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

class Menu{
    public:
        welcome();
        menuPrincipal();
        switchMenuPrincipal(bool *);
        subMenuClientes();
        switchSubMenuClientes(bool *);
        subMenuBuscarCliente();
        subMenuCamposCliente();
        switchSubMenuBuscarCliente(bool *);
        subMenuActividades();
        switchSubMenuActividades(bool *);
        subMenuActividadesPorCliente();
        switchSubMenuActividadesPorCliente(bool *);
        subMenuBackup();
        switchSubMenuBackup(bool *);
        subMenuCaja();
        switchSubMenuCaja(bool *);
        subMenuCargarMovimientoCaja();
        subMenuCamposMovimientosCaja();
        subMenuBuscarMovimientoCaja();
        subMenuArqueosDeCaja();
        switchSubMenuBuscarMovimientoCaja(bool *);
        subMenuAbonos();
        switchSubMenuAbonos(bool *);
        subMenuBuscarAbono();
        switchSubMenuBuscarAbono(bool *);
        subMenuAbonosPorCliente();
        subMenuCamposAbonoCliente();
        switchSubMenuAbonosPorCliente(bool *);
        subMenuReportes();
        switchSubMenuReportes(bool *);    ///FALTA CODEAR
};

#endif // MENU_H_INCLUDED
