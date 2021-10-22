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
using namespace std;
void agregarProducto();


int main(){
	//Declaración de variables
    int mode, fin, afin, tfin, intento = 0, i = 0;
    string pass;
    
int  vfin, wfin, id;
string nombre, caducidad;
float precio, total, cantidad;


    //Inicio del programa
do{
    system("cls");
    cout << "************ Bienvenido a Grocery  ************\n ¿Que modo deseas utilizar?\n[1] Administrador.\n[2] Trabajador\nIngresa el numero: " << endl;
    cin >> mode; cout << "\n";
     
    switch(mode) {
    
        case 1:
			//Solicitar contraseña para el modo administrador        
 			cout << "Ingrese la clave del usuario" << endl;
 			cin >> pass; cout << "\n";
 		
 			//Se tienen 3 oportunidades para ingresar la contraseña correcta 
		while  (pass != "grocerY" && intento < 2){
		system("cls");
		cout << "Clave incorrecta.\nIntente de nuevo:\nQuedan "<< 2 - intento  << " intentos \n" << endl;
		intento++;
		cin >> pass; }	
		
 		if (pass == "grocerY"){
 		do {
            
 			//Lo primero que hace es limpiar la pantalla para mostrar el siguiente menú
 			system("cls");
 			cout << "Modo Administrador. Acciones disponibles:\n[1] Agregar Productos\n[2] Actualizar precios\n[3] Ver inventario\n[4] Venta\n Ingresa la opcion:";
	     	cin >> mode;
	     	
	    switch(mode){
            
		    case 1: 
		    system("cls");
		    cout << "Agregar producto. \n";
		    do{
			
	    	 cout << "Ingresa el nombre del producto sin espacios:\n"; 
    		cin >> nombre; cout <<endl;
    		cout << "Ingresa su id: \n";
    		cin >> id; cout <<endl;
    		cout <<"Fecha de caducidad: \n";
    		cin >> caducidad; cout <<endl;

    		cout << "*Producto creado* \n id: "<<id<<" Nombre: " << nombre<< " Caducidad: "<< caducidad << endl; 
    		cout << "¿Desea agregar otro producto? (Ingrese 1 para si y 0 para no.)\n"; cin >> wfin;
		   } while (wfin==1); 
			cout << "Presiona 1 para volver al menu anterior: \n"<< endl;
			cin >> afin;
			break;
			
		    case 2:
		    	system("cls");
			    cout << "Actualizar precios. \n " << endl; //Y aquí va a estar el modo de agregar, que tomaremos de la clase Tienda
				cout << "Presiona 1 para volver al menu anterior: ";
				cin >> afin;
				break; 
			    
			
			case 3:
				system("cls");
				cout << "Ver inventario. \n";
				cout << "Presiona 1 para volver al menu anterior: ";
				cin >> afin;
				break;
		
			case 4:
				cout << "Vender producto \n";
	    	do { system("cls");

 			cout<<"\nIngrese el nombre del producto a vender: "<<endl;
			 cin>>nombre;	
			 cout<<"\nIngrese el precio del producto: "<<endl;
			 cin>>precio;
			 cout<<"\nIngrese la cantidad del producto a vender: "<<endl;
			 cin>>cantidad;
	
			 total = precio * cantidad;

			 cout<<"Producto vendido :) Ingreso de: " <<total<< "\n\n¿Desea vender otro elemento? (Ingrese 1 para si y 0 para no.)"<<endl;
			 cin>>vfin;
		
	} while (vfin==1);
				cout << "Presiona 1 para volver al menu anterior ";
				cin >> afin;
				
				break;
		    
			default: 
		    system("cls");
			    cout << "Opcion no disponible. \n" << endl;
				cout << "Presiona 1 para volver al menu anterior ";
				cin >> afin; 
				
				break;
	    	} 
		} while (afin == 1);
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
	    	do{
			
	    	 cout << "Ingresa el nombre del producto sin espacios:\n"; 
    		cin >> nombre; cout <<endl;
    		cout << "Ingresa su id: \n";
    		cin >> id; cout <<endl;
    		cout <<"Fecha de caducidad: \n";
    		cin >> caducidad; cout <<endl;

    		cout << "*Producto creado* \n id: "<<id<<" Nombre: " << nombre<< " Caducidad: "<< caducidad << endl; 
    		cout << "¿Desea agregar otro producto? (Ingrese 1 para si y 0 para no.)\n"; cin >> wfin;
		   } while (wfin==1); 
		    cout << "\n Presiona 1 para volver al menu anterior: "; cin >> tfin;
	    	break;
	    	
	    	case 2:
	    	cout << "Vender producto \n";
	    	do { system("cls");

 			cout<<"\nIngrese el nombre del producto a vender: "<<endl;
			 cin>>nombre;	
			 cout<<"\nIngrese el precio del producto: "<<endl;
			 cin>>precio;
			 cout<<"\nIngrese la cantidad del producto a vender: "<<endl;
			 cin>>cantidad;
	
			 total = precio * cantidad;

			 cout<<"Producto vendido :) Ingreso de: " <<total<< "\n\n¿Desea vender otro elemento? (Ingrese 1 para si y 0 para no.)"<<endl;
			 cin>>vfin;
		
	} while (vfin==1);
	    	cout << "Presiona 1 para volver al menu anterior: ";
				cin >> tfin;
			
			break;	
			
			default: 
			cout << "Opcion no disponible.\n Si desea volver a intentarlo presione 1\n";
			cin >> tfin;
		}
	} while (tfin==1);
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


