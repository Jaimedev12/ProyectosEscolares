// Actividad2_A00833173.cpp

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <math.h>
using namespace std;

int imprimirMenuMain() {
    cout << "Que ejercicio quiere ejecutar?:\n";
    cout << "1 - Ejercicio 1\n";
    cout << "2 - Ejercicio 2\n";
    cout << "3 - Ejercicio 3\n";
    cout << "4 - Ejercicio 4\n";
    cout << "5 - Ejercicio 5\n";
    cout << "6 - Ejercicio 6\n";
    cout << "7 - Ejercicio 7\n";
    cout << "8 - Ejercicio 8\n";
    cout << "9 - Salir\n";

    int opcion;
    cin >> opcion;

    return opcion;
}

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

int sumar(int a, int b) {
    int resultado;
    resultado = a + b;
    return resultado;
}

int restar(int a, int b) {
    int resultado;
    resultado = a - b;
    return resultado;
}

int multiplicar(int a, int b) {
    int resultado;
    resultado = a * b;
    return resultado;
}

void problemaUno() {
    int a = 0;
    int b = 0;

    cout << "Ingresa el primer numero: ";
    cin >> a;
    cout << "Ingresa el segundo numero: ";
    cin >> b;

    int opcion;
    opcion = imprimirMenuProblemaUno();

    int resultado;
    switch(opcion)
    {
    case 1:
        resultado = sumar(a, b);
        break;
    case 2:
        resultado = restar(a, b);
        break;
    case 3:
        resultado = multiplicar(a, b);
        break;
    default:
        cout << "Opcion no valida";
        abort();
    }

    cout << "El resultado es: " << resultado << endl;
}

int preguntarPorNumeroImpar() {
    int num;
    cout << "Ingresa un numero entero impar:\n";
    cin >> num;

    return num;
}

void problemaDos() {
    int num;
    num = preguntarPorNumeroImpar();

    while (num % 2 == 0)
    {
        cout << "Incorrecto, ingresa un numero entero impar\n";
        num = preguntarPorNumeroImpar();
    }

    cout << "Gracias :D" << endl;
}

void problemaTres() {
    int suma = 0;

    for (int i = 0; i <= 100; i += 2)
    {
        suma += i;
    }

    cout << "La suma es " << suma << endl;
}

int pedirCantidadDeNumeros(){
    int cantidad;
    cout << "Cuantos numeros quiere ingresar?\n";
    cin >> cantidad;

    return cantidad;
}

void problemaCuatro() {
    int cantidad;
    float suma = 0, num = 0, promedio = 0;

    cantidad = pedirCantidadDeNumeros();

    for (int i = 0; i < cantidad; i++)
    {
        cout << "Ingrese un numero\n";
        cin >> num;

        suma += num;
        cout << "\n";
    }

    promedio = suma / cantidad;

    cout << "El promedio es: " << promedio << endl;
}

void problemaCinco() {
    int randInt = 0;
    int num;
    int contador = 1;

    randInt = rand() % 100 + 1;

    cout << "Ingresa un numero entero entre 1 y 100\n";
    cin >> num;

    while (num != randInt)
    {
        if (num < randInt)
        {
            cout << "MAS\n";
        }
        else if (num > randInt)
        {
            cout << "MENOS\n";
        }
        cin >> num;
        contador++;
    }

    cout << "Acertaste el valor magico " << randInt << " despues de " << contador << " intentos";
}

float celciusToFahrenheit(float celcius) {
    float fahrenheit;
    fahrenheit = celcius * (9.0f / 5.0f) + 32;

    return fahrenheit;
}

void problemaSeis() {
    float celcius, fahrenheit, incremento;
    int cantidad = 0;

    float valoresCelcius[1000], valoresFahrenheit[1000];

    cout << "Ingresa el valor inicial en Celcius:\n";
    cin >> celcius;

    cout << "Cuantas conversiones se haran?\n";
    cin >> cantidad;

    cout << "Incremento entre valores Celcius:\n";
    cin >> incremento;

    float celActual = celcius;
    for (int i = 0; i < cantidad; i++)
    {
        valoresCelcius[i] = celActual;
        celActual += incremento;
    }

    for (int i = 0; i < cantidad; i++)
    {
        valoresFahrenheit[i] = celciusToFahrenheit(valoresCelcius[i]);
    }

    cout << setw(15) << "Fahrenheit" << setw(20) << "Celcius" << endl;

    for (int i = 0; i < cantidad; i++)
    {
        cout << setw(15) << valoresFahrenheit[i] << setw(20) << valoresCelcius[i] << endl;
    }
}

void problemaSiete() {
    int a = 3, d = 3, n = 25, num, suma = 0;

    for (int i = 0; i < n; i++)
    {
        num = a + (d * i);
        cout << "Termino " << i + 1 << ": " << num << endl;
        suma += num;
    }

    cout << endl;
    cout << "Valor total de la serie: " << suma;
}

void problemaOcho() {
    float sumaGeometrica = 0, sumaArmonica = 0;
    float mediaGeometrica = 0, mediaArmonica = 0;
    int num, contador = 0;

    cout << "Ingresa un numero: " << endl;
    cin >> num;

    while (num != 0)
    {
        contador++;

        sumaGeometrica += num;
        sumaArmonica += 1.0f / num;

        cout << "Ingresa un numero: " << endl;
        cin >> num;
    }

    mediaGeometrica = pow(sumaGeometrica, 1.0f / contador);
    mediaArmonica = 1.0f / sumaArmonica;
    
    cout << "Media Geometrica: " << mediaGeometrica << endl;
    cout << "Media Armonica: " << mediaArmonica << endl;
}

int main()
{
    srand(time(NULL));

    int problemaAResolver;
    bool seguir = true;

    while (seguir)
    {
        problemaAResolver = imprimirMenuMain();

        switch (problemaAResolver)
        {
        case 1:
            problemaUno();
            break;
        case 2:
            problemaDos();
            break;
        case 3:
            problemaTres();
            break;
        case 4:
            problemaCuatro();
            break;
        case 5:
            problemaCinco();
            break;
        case 6:
            problemaSeis();
            break;
        case 7:
            problemaSiete();
            break;
        case 8:
            problemaOcho();
            break;
        case 9:
            cout << "Gracias por usar nuestros servicios";
            seguir = false;
            break;
        default:
            break;
        }
        cout << "\n\n";
    }

    return 0;
}
