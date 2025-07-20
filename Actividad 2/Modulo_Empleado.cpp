#include <iostream>
#include <string>

using namespace std;

const int MAX_PRODUCTOS = 200;
const int DATOS_POR_PRODUCTO = 3;

int main() {

    // Definimos las variables 

    double productos[MAX_PRODUCTOS][DATOS_POR_PRODUCTO];
    int numProductos;
    char opcion;
    string descuentoStr;

    // Establecemos un ciclo do while para que el programa se ejecute hasta que el usuario ingrese "s" para satisfacer

    do {

        // Leemos el número de productos que el usuario desea agregar a la lista

        cout << "¿Cuántos productos desea calcular? ";
        cin >> numProductos;

        // Limpiamos la entrada del usuario, se utiliza un maximo de entradas para evitar errores y consumo de memoria

        if (numProductos > MAX_PRODUCTOS) {
            cout << "El número máximo de productos es " << MAX_PRODUCTOS << ". Se usará este valor." << endl;
            numProductos = MAX_PRODUCTOS;
        }

        // Ingresar productos del usuario

        for (int i = 0; i < numProductos; i++) {
            cout << "Producto " << i + 1 << ":" << endl;
            cout << "Cantidad: ";
            cin >> productos[i][0];
            cout << "Valor unitario: ";
            cin >> productos[i][1];
            cout << "Porcentaje de descuento (incluya el símbolo %): ";
            cin >> descuentoStr;

            // Comprobar que el descuento sea un número entre 0 y 100 para establecer el porcentaje de descuento junto  con el smbolo %

            productos[i][2] = stod(descuentoStr.substr(0, descuentoStr.length() - 1));
        }

        // Mostrar productos, trabajomos con la librería string para que se vea mas estetico la salida del programa

        cout << "\nInformación ingresada:" << endl;
        cout << "Producto     Cantidad     Valor unitario     Porcentaje descuento" << endl;

        for (int i = 0; i < numProductos; i++) {
            // Formatear y alinear producto para que se vea mejor 
            cout << i + 1;
            for (int j = 0; j < 12 - to_string(i + 1).length(); j++) cout << " ";

            // Formatear y alinear cantidad para que concida con el encabezado 
            int cantEntero = (int)(productos[i][0] * 100 + 0.5);
            string cantStr = to_string(cantEntero / 100) + "." + (cantEntero % 100 < 10 ? "0" : "") + to_string(cantEntero % 100);
            cout << cantStr;
            for (int j = 0; j < 13 - cantStr.length(); j++) cout << " ";

            // Formatear y alinear valor unitario
            int valorEntero = (int)(productos[i][1] * 100 + 0.5);
            string valorStr = to_string(valorEntero / 100) + "." + (valorEntero % 100 < 10 ? "0" : "") + to_string(valorEntero % 100);
            cout << valorStr;
            for (int j = 0; j < 20 - valorStr.length(); j++) cout << " ";

            // Formatear y alinear porcentaje de descuento
            cout << productos[i][2] << "%" << endl;
        }

        // Creamos otro ciclo do while para preguntar al empleado si desea realizar otra acción

        do {

            // Establecemos las opciones 

            cout << "\n¿Qué acción desea realizar?" << endl;
            cout << "1. Calcular el valor total de cada producto" << endl;
            cout << "2. Generar una nueva lista de productos" << endl;
            cout << "3. Salir" << endl;
            cout << "Opción: ";
            cin >> opcion;

            // Utilizamos if anidados para tomar las opciones de la lista

            if (opcion == '1') {
                cout << "\nValores totales por producto:" << endl;
                cout << "Producto     Total" << endl;
                for (int i = 0; i < numProductos; i++) {
                    double total = productos[i][0] * productos[i][1] * (1 - productos[i][2] / 100);
                    
                    // Formatear y alinear producto otra vez para que se vea mejor
                    cout << i + 1;
                    for (int j = 0; j < 12 - to_string(i + 1).length(); j++) cout << " ";

                    // Formatear y alinear total
                    int totalEntero = (int)(total * 100 + 0.5);
                    string totalStr = to_string(totalEntero / 100) + "." + (totalEntero % 100 < 10 ? "0" : "") + to_string(totalEntero % 100);
                    cout << totalStr << endl;
                }
            } else if (opcion == '2') {
                break;
            } else {
                cout << "Opción no válida. Intente de nuevo." << endl;
            }
        } while (opcion != '2');

    } while (true);

    // Y finalizamos el programa

    return 0;
}