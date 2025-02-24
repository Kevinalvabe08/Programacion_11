#include <iostream>
using namespace std;

// Calcular el precio boleto
double calcularPrecioBoleto(int edad, char tipoBoleto, const int precioBase) {
    double precioFinal = 0;

    switch (tipoBoleto) {
        case 'N':
        case 'n':
            precioFinal = precioBase;
            break;
        case 'E':
        case 'e':
            precioFinal = precioBase * 0.5; // 50% DESCUENTO estudiantes
            break;
        case 'S':
        case 's':
            if (edad > 60) {
                precioFinal = precioBase * 0.7; // 30% DESCUENTO seniors
            } else {
                precioFinal = precioBase; // Precio final seniors - de 60
            }
            break;
        default:
            cout << "Clase de boleto no válido." << endl;
            return -1; // Indica un error
    }
    return precioFinal;
}

// main
int main() {
    // inicio
    cout << "HOLA" << endl;

    int edad;
    char tipoBoleto;
    const int precioBase = 100;

    // Solicitar edad 
    cout << "Ingresa tu edad: ";
    cin >> edad;

    // ver si el boleto es gratis o no
    if (edad < 5) {
        cout << "Tu boleto es gratis." << endl;
        return 0;
    }

    // eleccion de boleto
    cout << "Elige que clase de boleto quieres (N: Normal, E: Estudiante, S: Senior): ";
    cin >> tipoBoleto;

    // precio final boleto
    double precioFinal = calcularPrecioBoleto(edad, tipoBoleto, precioBase);
    
    //  error boleto
    if (precioFinal < 0) {
        return 1; // salir
    }
    // Mostrar precio final 
    cout << "El precio final de tu boleto es de $" << precioFinal << endl;
    return 0;
}