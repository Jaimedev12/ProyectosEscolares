// Actividad2_A00833173.cpp

#include <iostream>
using namespace std;

int main()
{
    float a = 0;
    float b = 0;

    cout << "Ingresa el primer numero: ";
    cin >> a;
    cout << "Ingresa el segundo numero: ";
    cin >> b;

    cout << "\nQue quieres hacer con los numeros?\n";
    cout << "<S> Mostrar una suma de los dos numeros\n";
    cout << "<R> Mostrar una resta de los dos numeros(el primero menos el segundo)\n";
    cout << "<M> Mostrar una multiplicacion de los dos números";
    
    string opcion = "";
    cin >> opcion;

    if (opcion != "S" && opcion != "R" && opcion != "M")
    {
        cout << "Opcion no valida";
        abort()
    };




    /*En  caso  de  no  introducir  una  opción  válida, el  programa  informará  con  un  letrero  que  no  es
    correcta"

    operaNumeros.Función  que  lea  dos  números  por  teclado  y  permita  elegir  entre  3  opciones  en  un
    menú :

    */


    cout << "Hello World!\n";
}



// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración



// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
