#include <iostream>
// #include "Grocery.h"

using namespace std;


int main() {
    int mode;

    cout << "************ Bienvenido a Grocery 0.01 ************\n ¿Qué modo deseas utilizar? \n [1] Administrador. \n [2] Trabajador.\n Ingresa el número: " << endl;
    cin >> mode;
    switch(mode) {
        case 1:

            cout << "Acciones disponibles: \n [1] Agregar Productos \n [2] Actualizar precios \n [3] Ver inventario \n [4] Venta \n Ingresa el número:" <<endl;
	     cin >> mode;

	    switch(mode){
		    case 1:
			    cout << "Pues ya aquí va estar implementados los métodos \n" << endl;
			    break;
		    case 2:
			    cout << "Y aquí va a estar el modo de agregar, que tomaremos de la clase Teienda \n" << endl;
			    break;
		    default:
			    cout << "Esas todavía no están jeje" << endl ;
				    break;
	    }

        case 2:
	    cout << "[1] Vender producto \n[2] Agregar Productos \n Ingresa la opción: La verdad no se si esta forma sea la mejor, con muchos switchs pero si quieren pueden cambiarlo \n"<< endl;
	    break;
        default :
            cout << "Por el momento sólo están esas opciones disponibles :)"<< endl;
    }
    return 0;

}

