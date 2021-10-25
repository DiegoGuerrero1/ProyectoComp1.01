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
    std::string nameSearch;
    std::vector<std::string>::iterator it;
    vector<string> onlyNames;

    cout << "Ingresar nombre del producto:\n"<<endl;
    getline(cin,nameSearch);
    std::cout << "Inventario original :\n";
    for(int i=0; i<inventario.size(); i++){
        std::cout << " " << inventario[i].getpName();
        //generando un vector de enteros para poder buscar en el con los puros id
        onlyNames.push_back(inventario[i].getpName());
    }
    std::cout << "\n";
    // Element to be searched
    // std::find function call
    it = std::find(onlyNames.begin(), onlyNames.end(), nameSearch);
    if (it != onlyNames.end())
    {
        clearFoundProduct(); //Por si queda alg[un producto ah[i
        std::cout << "Producto con id " << nameSearch << " encontrado en la posición: " ;
        std::cout << it - onlyNames.begin() << " (countando desde cero) \n" ;
        foundProducts.push_back(inventario[it - onlyNames.begin()]);
    }
    else {
        std::cout << "Producto no encontrado.\n\n";
    }

}

void User::findProductbyId(vector<Product> inventarioAc) { // No se si se podría crear una plantilla aquí, supongo que si.
    int idSearch;
    std::vector<int>::iterator it;
    vector<int> searchId;

    cout << "Ingresar id del producto\n"<<endl;
    cin>> idSearch;
    cout << "Inventario original :\n";
    for(int i=0; i<inventarioAc.size(); i++){
        cout << " " << inventarioAc[i].getpName();
        //generando un vector de enteros para poder buscar en el con los puros id
        searchId.push_back(inventarioAc[i].getId());
    }
    cout << "\n";
    // Element to be searched
    // std::find function call
    it = find(searchId.begin(), searchId.end(), idSearch);
    if (it != searchId.end())
    {
        clearFoundProduct(); //Por si queda alg[un producto ah[i
        cout << "Producto con id " << idSearch << " encontrado en la posición: " ;
        cout << it - searchId.begin() << " (countando desde cero) \n" ;
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
        for(int i = 0 ; i <= size(cart); i++){
             sellBill += cart[i].getPrice();
             cout << i << endl;
             cout << sellBill << endl;

        }
        cout << "Cuenta final: " << sellBill <<"$"<<endl;

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
        findProductbyId(inventario);
        cout << "Ingrese el nuevo precio: \n";
        cin >> nuevoPrecio;
        foundProducts[0].setPrice(nuevoPrecio);
        cout << "Precio de " << foundProducts[0].getpName() << " cambiado a: "<< foundProducts[0].getPrice() << endl;
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

void User::editUser() {
    int option;
    std::string newName;
    std::string newPassword;
    std::string oldPassword;
    cout << "*********** Editar Usuario *********** \n";
    cout << "Ingresa tu contraseña\n" << endl;
    cin.ignore();
    getline(cin, oldPassword);
    if (isThePasword(oldPassword)){
        cout << "¿Qué quieres cambiar? \n [1] Contraseña [2] Nombre de Usuario" << endl;
        cin >> option;
        switch (option) {
            case 1:
                cout << "Ingresa la nueva contraseña\n"<< endl ;
                cin.ignore();
                getline(cin, newPassword);
                password = newPassword;
                cout << "Contraseña cambiada exitosamente" <<endl;
                break;
            case 2:
                cout << "Ingresa el nuevo nombre\n"<< endl ;
                cin.ignore();
                getline(cin,newName);
                name = newName;
                cout << "Nombre cambiado exitosamente a " << name <<endl;
                break;
            default:
                cout << "Opción no válida\n" << endl;
                break;
        }
    } else{
        cout << "Contraseña incorrecta" <<endl;
    }

}

void User::addProducts(Product newProduct, vector<Product> inventory) {
    inventory.push_back(newProduct);
}

