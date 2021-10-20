#include <iostream>
#include <string>
#include <vector>
#include <array>

// #include "Grocery.h"

using namespace std;

int main() {
    int mode;
    string pass;
    cout << "************ Bienvenido a Grocery 0.01 ************\n ¿Qué modo deseas utilizar? \n [1] Administrador. \n [2] Trabajador.\n Ingresa el número: " << endl;
    cin >> mode;
    switch(mode) {
        case 1:
 			cout << "Ingrese la contrasena del administrador" << endl;
 			cin >> pass;
 			while  (pass != "grocerY"){
		cout << "Contraseña incorrecta. \n Intente de nuevo: \n" << endl;
		cin >> pass; 
	}
 			if (pass == "grocerY"){ 
 	
            cout << "Acciones disponibles: \n [1] Agregar Productos \n [2] Actualizar precios \n [3] Ver inventario \n [4] Venta \n Ingresa el número:" <<endl;
	     cin >> mode;
	    switch(mode){
		    case 1: 
			    cout << "Agregar producto \n" << endl; //Aquí van los métodos 
			    break;
		    case 2:
			    cout << "Actualizar precios: \n" << endl; //Y aquí va a estar el modo de agregar, que tomaremos de la clase Tienda
			    break; 
			case 3:
				cout << "Inventario: \n" << endl;
				break;
			case 4:
				cout << "Venta \n" << endl;
		    default: 
			    cout << "Seleccione una opcion correcta\n" << endl ; 
				    break;
	    } //llave final del switch de administrador
 
} //llave final del if

break;

        case 2: 
	    cout << "[1] Vender producto \n[2] Agregar Productos \n Ingresa la opcion: \n"<< endl;
	    cin >> mode;
	    switch (mode){
	    	case 1:
	    		cout << "Vender producto";
	    		break;
	    	case 2:
	    		cout << "Agregar producto";
	    		break;
		}
		break; 
	    
	    
        default :
            cout << "Por el momento solo estan esas opciones disponibles :)"<< endl;
    }
    return 0;

}