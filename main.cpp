/*
 * Authors: Damian Garcia, Diego Guerrero, Ivan Olvera
 * Contact: luisdamiangarcia@gmail.com , diegoguerrero@comunidad.unam.mx, 
 * Date: 20/10/21
 */
 //#include <curses.h>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <iomanip>

#include "Producto.h"
#include "Tienda.h"
#include "Usuario.h"


using namespace std;

int main() {
	//Declaración de variables
    int mode, fin, afin, tfin, intento = 0, i = 0;
    string pass;
    //objeto
    
    
    //Inicio del programa
do{
	//Limpia la pantalla cada vez que empieza el ciclo
	system("cls");
    cout << "************ Bienvenido a Grocery  ************\n ¿Que modo deseas utilizar? \n [1] Administrador. \n [2] Trabajador.\n Ingresa el numero: " << endl;
    cin >> mode; cout << "\n";
    switch(mode) {
    
        case 1:
			//Solicitar contraseña para el modo administrador        
 			cout << "Ingrese la clave del usuario" << endl;
 			cin >> pass; cout << "\n";
 		
 			//Se tienen 3 oportunidades para ingresar la contraseña correcta 
		while  (pass != "grocerY" && intento < 2){
		system("cls");
		cout << "Clave incorrecta. \n Intente de nuevo: \n Quedan "<< 2 - intento  << " intentos \n" << endl;
		intento++;
		cin >> pass; }	
		
 		if (pass == "grocerY"){ 
 		do {
 			//Lo primero que hace es limpiar la pantalla para mostrar el siguiente menú
 			system("cls");
 			cout << "Modo Administrador. Acciones disponibles:\n[1] Agregar Productos\n[2]Actualizar precios\n[3]Ver inventario\n[4]Venta\n Ingresa la opcion:"<<endl;
	     	cin >> mode;
	     	
	    switch(mode){
		    case 1: 
		    system("cls");
		    cout << "Agregar producto. \n";
		    cout << "Ingrese el nombre del producto";
		   
		 /*	Producto::setpName();
		    Producto.nombreProductoR;
			Product.getpName(); */
			
			cout << "Presiona 1 para volver al menu anterior: \n"<< endl;
			cin >> afin;
			break;
			
		    case 2:
		    	system("cls");
			    cout << "Actualizar precios: \n " << endl; //Y aquí va a estar el modo de agregar, que tomaremos de la clase Tienda
				cout << "Presiona 1 para volver al menu anterior: \n"<< endl;
				cin >> afin;
				break; 
			    
			
			case 3:
				system("cls");
				cout << "Ver inventario. \n";
				cout << "Presiona 1 para volver al menu anterior: \n"<< endl;
				cin >> afin;
				break;
		
			case 4:
				system("cls");
				cout << "Venta. \n" << endl;
				cout << "Presiona 1 para volver al menu anterior \n"<< endl;
				cin >> afin;
				
				break;
		    
			default: 
		    system("cls");
			    cout << "Opcion no disponible. \n" << endl;
				cout << "Presiona 1 para volver al menu anterior \n"<< endl;
				cin >> afin; 
				break;
	    	} }
	    	 while (afin == 1);
		} 
		break;

        case 2: //Modo empleado	
	do{
		
		system("cls"); 
	    cout << "Modo Empleado. Acciones disponibles:\n[1] Agregar producto \n[2] Vender Productos \nIngresa la opcion: \n"<< endl;
	    cin >> mode;
		switch (mode) { 
	
	    	case 1:
	    	system("cls");
	    	cout << "Agregar producto\n";
	    	 
			//Producto::setpName("");
			//cout << product.getId();
		    	cout << "\t Presiona 1 para volver al menu anterior \n"<< endl;
				cin >> tfin;
	    	break;
	    
	    	case 2:
	    	system("cls");
	    	cout << "Vender producto \n";
	    	cout << "Presiona 1 para volver al menu anterior \n"<< endl;
				cin >> tfin;
			
			break;	
			
			default: 
			cout << "Opcion no disponible.\n Si desea volver a intentarlo presione 1\n";
			cin >> tfin;
		}
	} while (tfin=1);
		break; 
	    
	    
        default:
            cout << "Por el momento solo estan esas opciones disponibles :)"<< endl;
			cout << "Presiona 1 para volver al menu anterior. \n";
			cin >> fin;   
    
	}
}
while (fin == 1);
return 0;

}
