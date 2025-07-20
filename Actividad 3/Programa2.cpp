// Aprendiz Juan Carlos Lopez Moreno 
// Programa 2

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

const double PI = 3.14159265358979323846;

// Variables globales
vector<vector<double>> resultados;
vector<string> nombresFiguras;

// Funciones para calcular área y perímetro
void calcularCirculo() {
    double radio;
    cout << "Ingrese el radio del círculo: ";
    cin >> radio;
    
    double area = PI * radio * radio;
    double perimetro = 2 * PI * radio;
    
    resultados.push_back({area, perimetro});
    nombresFiguras.push_back("Círculo");
}

void calcularRectangulo() {
    double alto, ancho;
    cout << "Ingrese el alto del rectángulo: ";
    cin >> alto;
    cout << "Ingrese el ancho del rectángulo: ";
    cin >> ancho;
    
    double area = alto * ancho;
    double perimetro = 2 * (alto + ancho);
    
    resultados.push_back({area, perimetro});
    nombresFiguras.push_back("Rectángulo");
}

void calcularCuadrado() {
    double lado;
    cout << "Ingrese el lado del cuadrado: ";
    cin >> lado;
    
    double area = lado * lado;
    double perimetro = 4 * lado;
    
    resultados.push_back({area, perimetro});
    nombresFiguras.push_back("Cuadrado");
}

void calcularTriangulo() {
    double base, altura;
    cout << "Ingrese la base del triángulo: ";
    cin >> base;
    cout << "Ingrese la altura del triángulo: ";
    cin >> altura;
    
    double area = 0.5 * base * altura;
    double hipotenusa = sqrt(base*base + altura*altura);
    double perimetro = base + altura + hipotenusa;
    
    resultados.push_back({area, perimetro});
    nombresFiguras.push_back("Triángulo");
}

// Función para mostrar los resultados

void mostrarResultados() {
    cout << "\nEstos son los resultados:\n";
    cout << fixed << setprecision(2);
    for (size_t i = 0; i < resultados.size(); ++i) {
        cout << nombresFiguras[i] << ":\n";
        cout << "  Área: " << resultados[i][0] << "\n";
        cout << "  Perímetro: " << resultados[i][1] << "\n\n";
    }
}

// Función principal para pedir las figuras que desea calcular

int main() {
    int opcion;
    do {
        cout << "\nMenú de Figuras Geométricas:\n";
        cout << "1. Círculo\n";
        cout << "2. Rectángulo\n";
        cout << "3. Cuadrado\n";
        cout << "4. Triángulo\n";
        cout << "5. Mostrar resultados y salir\n";
        cout << "Elija una opción: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                calcularCirculo();
                break;
            case 2:
                calcularRectangulo();
                break;
            case 3:
                calcularCuadrado();
                break;
            case 4:
                calcularTriangulo();
                break;
            case 5:
                mostrarResultados();
                cout << "Gracias por usar el programa.\n";
                break;
            default:
                cout << "Opción no válida. Intente de nuevo.\n";
        }
    } while (opcion != 5);

    return 0;
}