// Aprendiz Juan Carlos Lopez Moreno
// Programa 1

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Establecemos una clase que contenga los datos de los empleados

class Empleado {
    private: 
        int cedula;
        string nombre;
        string cargo; 
        string telefono;
        int horasMes;
        float horasExtras;
        float desPrestamo;
        float desSocial;
        float ahorroVol;
        double salarioBasico;
    public:
    Empleado() : cedula(0), nombre(""), cargo(""), telefono(""), 
                horasExtras(0), desPrestamo(0), desSocial(0), ahorroVol(0), 
                salarioBasico(0), horasMes(0) {}

    // Función para pedir datos básicos 

    void pedirDatos() {
        cout << "Ingrese la cedula del empleado: ";
        cin >> cedula;
        
        cout << "Ingrese el nombre del empleado: ";
        cin.ignore();
        getline(cin, nombre);
        
        cout << "Ingrese el cargo: ";
        getline(cin, cargo);
        
        cout << "Ingrese el telefono: ";
        cin >> telefono;
    }

    //Función para pedir datos de laborales 

    void datosLabor() {
        cout << "Ingrese las horas extras que usted laboro: ";
        cin >> horasExtras;
        
        cout << "Ingrese el descuento del prestamo: ";
        cin >> desPrestamo;

        cout << "Ingrese el descuento de seguridad social: ";
        cin >> desSocial;
        
        cout << "¿De cuánto fue el ahorro voluntario? ";
        cin >> ahorroVol;

        cout << "¿Cuánto es su salario? ";
        cin >> salarioBasico;

        cout << "¿Cuántas horas trabaja al mes? ";
        cin >> horasMes;
    }

    // Función para calcular el salario neto

    double calcularSalario() {
        double salarioNeto = 0;
        double valorHorasExtras = 0;
        valorHorasExtras = (salarioBasico / horasMes) * horasExtras;
        salarioNeto = (salarioBasico + valorHorasExtras) - (desPrestamo + desSocial + ahorroVol);

        return salarioNeto;
    }

    // Función para imprimir la información

    void ImprimirInfo() {
        cout << "\nInformación del empleado\n";
        cout << "Nombre: " << nombre << endl;
        cout << "Cargo: " << cargo << endl;
        cout << "Telefono: " << telefono << endl;
        cout << "Cedula: " << cedula << endl;
        cout << "Horas extras: " << horasExtras << endl;
        cout << "Descuento del prestamo: " << desPrestamo << endl;
        cout << "Descuento de seguridad social: " << desSocial << endl;
        cout << "Ahorro voluntario: " << ahorroVol << endl; 
        cout << "Salario básico: " << salarioBasico << endl;
        cout << "Horas trabajadas al mes: " << horasMes << endl;
        cout << "Salario neto: " << calcularSalario() << endl;
    }
};

// Función principal para pedir la cantidad de empleados y calcular su salario neto

int main() {

    vector<Empleado> empleados;
    int cantidadEmpleados;

    cout << "Ingrese la cantidad de empleados: ";
    cin >> cantidadEmpleados;

    for (int i = 0; i < cantidadEmpleados; i++) {
        cout << "\nEmpleado #" << i+1 << endl;
        Empleado nuevoEmpleado;
        nuevoEmpleado.pedirDatos();
        nuevoEmpleado.datosLabor();
        empleados.push_back(nuevoEmpleado);
    }

    cout << "\n--- Resumen de Empleados ---\n";
    for (int i = 0; i < empleados.size(); i++) {
        empleados[i].ImprimirInfo();
    }

    return 0;
}