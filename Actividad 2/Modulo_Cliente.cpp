#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

int main() {

    // Definimos las variables incluidas el vector de productos 

    vector<string> listaProductos;
    int numProductos;
    char satisfecho;

    // Establecemos un bucle do while para que el programa se ejecute hasta que el usuario ingrese "s" para satisfacer

    do {

        // Leemos el número de productos que el usuario desea agregar a la lista

        cout << "¿Cuántos productos desea agregar a la lista de compra? ";
        while (!(cin >> numProductos) || numProductos <= 0) {
            cout << "Por favor, ingrese un número válido: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Limpiamos la entrada del usuario

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Limpiamos la lista de productos para que se puedan agregar nuevos productos

        listaProductos.clear();
        listaProductos.resize(numProductos);

        // Leemos los nombres de los productos que el usuario desea agregar a la lista

        for (int i = 0; i < numProductos; ++i) {
            cout << "Ingrese el nombre del producto " << i + 1 << ": ";
            getline(cin, listaProductos[i]);
        }

        // Imprimimos la lista de productos ingresados

        cout << "\nLista de productos ingresados:\n";
        for (int i = 0; i < numProductos; ++i) {
            cout << i + 1 << ". " << listaProductos[i] << endl;
        }

        // Leemos la respuesta del usuario sobre si está satisfecho con la lista

        cout << "\n¿Está satisfecho con la lista realizada? (s/n): ";
        cin >> satisfecho;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Si el usuario responde "s" para satisfacer, imprimimos un mensaje de agradecimiento y terminamos el programa

        if (tolower(satisfecho) == 's') {
            cout << "Gracias por usar nuestro sistema. ¡Hasta luego!\n";
            break;
        } else {
            cout << "Entendido, generaremos una nueva lista.\n\n";
        }

    } while (true);

    return 0;
}