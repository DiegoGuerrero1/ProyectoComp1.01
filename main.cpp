#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
//#include <conio.h>
//#include <windows.h>
#include <iomanip>


#include "Producto.h"
#include "Tienda.h"
#include "Usuario.h"
// #include "Grocery.h"

using namespace std;

//FUNCIONES MENU ADMIN Y MENU TRAB, TAMBIÉN SE PUEDE PASAR A OTRO CPP PARA HACER MAS FANCY EL MAIN ;D
int menuadmin(void){
cout << "Modo Administrador. Acciones disponibles: \n [1] Agregar Productos \n [2] Actualizar precios \n [3] Ver inventario \n [4] Venta \n Ingresa el número:" <<endl;	
}

int menutrab(void){
	cout << "Modo Empleado. Acciones disponibles: \n [1] Vender producto \n[2] Agregar Productos \n Ingresa la opcion: \n"<< endl;
}

int main() {
	//Declaración de variables
    int mode, fin, afin, tfin, intento = 0, i = 0;
    string pass;
    


    //Inicio del programa
do{
	system("cls");
    cout << "************ Bienvenido a Grocery  ************\n ¿Que modo deseas utilizar? \n [1] Administrador. \n [2] Trabajador.\n Ingresa el numero: " << endl;
    cin >> mode; cout << "\n";
    switch(mode) {
    
        case 1:
			//Solicitar contraseña para el modo administrador        
 			cout << "Ingrese la clave del usuario" << endl;
 			cin >> pass; cout << "\n";
 		
 		//Si se ingresa la contraseña equivocada 3 veces el programa te mete a modo Empleado automáticamente
		while  (pass != "grocerY" && intento < 2){
		system("cls");
		cout << "Clave incorrecta. \n Intente de nuevo: \n Quedan "<< 1 - intento + 1 << " intentos \n" << endl;
		intento++;
		cin >> pass; }
	
 		if (pass == "grocerY"){ 
 		do {
		 
 			//Lo primero que hace es limpiar la pantalla para mostrar el siguiente menú
 			system("cls");
			 
 			menuadmin();
	     	cin >> mode;
	     	
	    switch(mode){
		    case 1: 
		    system("cls");
		    cout << "Vender producto. \n";
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
		system("cls"); 
	    menutrab();
	    cin >> mode;
		switch (mode){
	
			
	    	case 1:
	    		system("cls");
	    	cout << "Vender producto";
	    	
	    	break;
	    
	    	case 2:
	    	system("cls");
	    	cout << "Agregar producto \n";
			
			break;	
		}
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