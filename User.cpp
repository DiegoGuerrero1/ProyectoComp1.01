//
// Created by guerrero on 10/23/21.
//

#include "User.h"
#include <string>

User::User(string userName, string userPassword, bool makeAdmin)
:name{userName}, password{userPassword}, admin{makeAdmin} {
    cout << "Usuario creado." <<"\nNombre: " <<userName << "\nAdministrador: "<< admin << endl;

}

void User::makeAdmin(char madmin) {
    switch (madmin) {
        case 's':
            setAdmin(true);
            cout << "El usuario " << getUsrName() <<" ahora es administrador" <<endl;
            break;
        case 'n':
            setAdmin(false);
            cout << "El usuario " << getUsrName() <<" es empleado" <<endl;
            break;
        case 'c':
            break;
        default:
            cout << "Opción no válida, asignando empleado " << endl;
            setAdmin(false);
            break;

    }

}

void User::setAdmin(bool sAdmin) {
    admin = sAdmin;

}

bool User::isThePasword(string testPassword) {
    if(testPassword==password){
        return true;
    }else{
        return false;
    }

}

std::string User::getUsrName() {
    return name;
}

void User::setuName(string userName) {
    name = userName;
}

void User::setPassword(string nPassword) {
    password = nPassword;
}

void User::editPassword() {
    std::string oldPassword;
    std::string newPassword;
    cout << "Ingresa la contraseña anterior" << endl;
    getline(cin, oldPassword);

    if(isThePasword(oldPassword)){
        cin.ignore();
        cout << "Ingresa la nueva contraseña" << endl;
        getline(cin, newPassword);
        setPassword(newPassword);
        cout <<"contraseña cambiada"<<endl;
    }else {
        cout << "Contraseña incorrecta" << endl;
    }
}

void User::editName() {
    std::string oldPassword;
    std::string newName;
    cout << "Ingresa la contraseña de la cuenta" << endl;
    getline(cin, oldPassword);
    if(isThePasword(oldPassword)){
        cin.ignore();
        cout << "Ingresa el nuevo nombre" << endl;
        getline(cin, newName);
        setuName(newName);
        cout <<"Nombre cambiado"<<endl;
    }else {
        cout << "Contraseña incorrecta" << endl;
    }
}

void User::setSold(char s) {
    if(s == 's'){
        moneyReceived = true;
    }else{
        moneyReceived = false;
    }
}

void User::llenarCarrito(vector<Product> inventario) {
    findProductbyId(inventario);
    cart = foundProducts;

}

bool User::isAdmin() {
    if(!admin){
        return false;
    }else{
        return true;
    };
}

void User::findProductbyName( vector<Product> inventario) {
    std::string nombre;
    cout << "Ingresa el nombre del producto" << endl;
    getline(cin, nombre);
    for(unsigned long i{0} ; i >= inventario.size() || i < 10000 ; i++){

        if ( inventario[i].getpName() == nombre){
            i = 10000;
            setFoundProduct(inventario[i]) ;         //Estaría bueno implementar una búsqueda más optimizada

        }else{
            clearFoundProduct();
            cout << "No se encontró ningún producto."<<endl;

        }

    }
}

void User::findProductbyId(vector<Product> inventarioAc) {
    int ser;
    std::vector<int>::iterator it;
    vector<int> searchId;

    cout << "Ingresar id del producto"<<endl;
    cin >> ser;
    // Iterator used to store the position
    // of searched element
    // Print Original Vector
    std::cout << "Inventario original :\n";
    for(int i=0; i<inventarioAc.size(); i++){
        std::cout << " " << inventarioAc[i].getpName();
        //generando un vector de enteros para poder buscar en el con los puros id
        searchId.push_back(inventarioAc[i].getId());
    }
    std::cout << "\n";
    // Element to be searched
    // std::find function call
    it = std::find(searchId.begin(), searchId.end(), ser);
    if (it != searchId.end())
    {
        clearFoundProduct(); //Por si queda alg[un producto ah[i
        std::cout << "Producto con id " << ser <<" encontrado en la posición: " ;
        std::cout << it - searchId.begin() << " (countando desde cero) \n" ;
        foundProducts.push_back(inventarioAc[it - searchId.begin()]);
    }
    else {
        std::cout << "Producto no encontrado.\n\n";
    }


}




    float User::sellProducts(vector<Product> inventarioB) {
        char agregarMas;
        char carritoVendido;
        while (true) {
            llenarCarrito(inventarioB);
            cout << "¿Agregar más productos al carrito? s:si, n:no" << endl;
            cin >> agregarMas;
            if (agregarMas != 's') {
                break;
            }
        }
        cout << "¿Pago recibido? s:si, n:no" << endl;
        cin >> carritoVendido;
        if (carritoVendido == 's') {
            for (unsigned int i{0}; i <= size(inventarioB); i++) {
                removeProductFound(inventarioB);

            }


        } else {
            cout << "Operación cancelada" << endl;
            vaciarCarrito();
        }
        return 0;
    }

void User::vaciarCarrito() {
  cart.clear();
}

void User::editPrice(vector<Product> inventario) {
    int idProducto;
    float nuevoPrecio;
    if (!isAdmin()){
        cout << "El usuario no es administrador"<< endl;
    }else{
        cout << "Por el momento sólo se puede reemplazar buscando por id \n Ingrese id: \n" << endl;
        cin >> idProducto;
        for (unsigned long i{0}; i >= inventario.size(); i++) {

            if (inventario[i].getId() == idProducto) {
                inventario[i].setPrice(nuevoPrecio);
                //Estaría bueno implementar una búsqueda más optimizada
                i = inventario.size();

            } else {
                clearFoundProduct();
                cout << "No se encontró ningún producto."<<endl;

            }
        }
    }
}

void User::setFoundProduct(Product producto) {
    foundProducts.push_back(producto) ;
}

void User::clearFoundProduct() {
    foundProducts.clear();

}

void User::removeProductFound(vector<Product> inventario) {
    Product productoVacio{0,"none","00/00/00", 0};
    findProductbyId(inventario);
    inventario[productoFoundIndex] = productoVacio;
    }

