// Actividad2_A00833173.cpp

#include <iostream>
#include <string>
using namespace std;

int imprimirMenuProblemaUno()
{
    cout << "\nQue quieres hacer con los numeros?\n";
    cout << "1 - Mostrar una suma de los dos numeros\n";
    cout << "2 - Mostrar una resta de los dos numeros(el primero menos el segundo)\n";
    cout << "3 - Mostrar una multiplicacion de los dos numeros:\n";

    int opcion;
    cin >> opcion;

    return opcion;
}

float problemaUno() {
    float a = 0;
    float b = 0;

    cout << "Ingresa el primer numero: ";
    cin >> a;
    cout << "Ingresa el segundo numero: ";
    cin >> b;

    int opcion;
    opcion = imprimirMenuProblemaUno();

    float resultado;
    switch(opcion)
    {
    case 1:
        resultado = sumar(a, b);
        break;
    case 2:
        resultado = restar(a, b);
        break;
    case 3:
        resultado = multuplicar(a, b);
        break;
    default:
        cout << "Opcion no valida";
        abort();
    }
}

float sumar(float a, float b) {
    float resultado;
    resultado = a + b;
    return resultado
}

float restar(float a, float b) {
    float resultado;
    resultado = a - b;
    return resultado;
}

float multiplicar(float a, float b) {
    float resultado;
    resultado = a * b;
    return resultado;
}

void imprimir(string algo) {
    cout << algo;
}

int main()
{
    problemaUno();




    /*En  caso  de  no  introducir  una  opción  válida, el  programa  informará  con  un  letrero  que  no  es
    correcta"

    operaNumeros.Función  que  lea  dos  números  por  teclado  y  permita  elegir  entre  3  opciones  en  un
    menú :

    */


    //cout << "Hello World!\n"; 
}



// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración



// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
