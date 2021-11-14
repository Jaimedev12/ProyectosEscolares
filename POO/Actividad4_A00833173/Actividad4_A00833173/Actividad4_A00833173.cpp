// Actividad4
// Jaime Eduardo López Castro 
// A00833173

// Cosas que no supe cómo hacer:
// Usar funciones para pedir los datos y no llenar de texto main()
// Recortar la cantidad de decimales que se imprimen al convertir los floats a string


// Descripción de las clases
//
// Cliente()
// Esta clase guarda tiene los atributos de nombre, telefono, direccion y horaRec. 
// Tiene 2 métodos, el primero es guardarDatos(string nom, string tel, string dir, string horas) que recibe 4 parámetros y
// los asigna a los atributos del objeto; el segundo es datos2String() que toma los atributos del objeto y los convierte
// en un string.
//
// Paquete()
// Esta clase guarda tiene los atributos de peso, largo, ancho y alto. 
// Tiene 2 métodos, el primero es guardarDatos(float p, float x, float y, float z) que recibe 4 parámetros y
// los asigna a los atributos del objeto; el segundo es datos2String() que toma los atributos del objeto y los convierte
// en un string.
//
// Destinatario()
// Esta clase guarda tiene los atributos de nombreDestinatario, telefonoDestinatario y direccionDestinatario;. 
// Tiene 2 métodos, el primero es guardarDatos(string nombre, string telefono, string direccion) que recibe 3 parámetros y
// los asigna a los atributos del objeto; el segundo es datos2String() que toma los atributos del objeto y los convierte
// en un string.

#include <iostream>
#include <string>
#include "Cliente.h"
#include "Paquete.h"
#include "Destinatario.h"
using namespace std;


int main()
{
    string datosCliente, datosPaquete, datosDestinatario;

    //Variables para el cliete
    string nombreCliente, direccion, telefonoCliente, horaRec;
    Cliente* cliente1 = new Cliente();

    //Variables para el paquete
    float peso, largo, ancho, alto;
    Paquete* paquete1 = new Paquete();

    //Variables para el destinatario
    string nombreDestinatario, telefonoDestinatario, direccionDestinatario;
    Destinatario* destinatario1 = new Destinatario();

    //Datos del cliente
    cout << "Ingrese su nombre: ";
    cin >> nombreCliente;

    cout << "Telefono: ";
    cin >> telefonoCliente;

    cout << "Direccion: ";
    cin >> direccion;

    cout << "Hora a la que se recogio su paquete: ";
    cin >> horaRec;

    //Se guardan los datos en el objeto del cliente
    cliente1->guardarDatos(nombreCliente, telefonoCliente, direccion, horaRec);

    //Se convierten los datos del cliente en string y se imprimen
    cout << endl;
    datosCliente = cliente1->datos2String();



    //Se preguntan los datos del paquete
    cout << "Ingrese el peso del paquete (kg): ";
    cin >> peso;

    cout << "Largo del paquete (cm): ";
    cin >> largo;

    cout << "Ancho del paquete (cm): ";
    cin >> ancho;

    cout << "Alto del paquete (cm): ";
    cin >> alto;

    //Se asignan los valores al objeto de la clase
    paquete1->guardarDatos(peso, largo, ancho, alto);

    //Se convierten los datos en string y se imprimen
    cout << endl;
    datosPaquete = paquete1->datos2String();



    //Datos del destinatario
    cout << "Ingrese el nombre del destinatario: ";
    cin >> nombreDestinatario;

    cout << "Telefono: ";
    cin >> telefonoDestinatario;

    cout << "Direccion: ";
    cin >> direccionDestinatario;
    
    //Se asignan los valores al objeto de la clase
    destinatario1->guardarDatos(nombreDestinatario, telefonoDestinatario, direccionDestinatario);

    //Se convierten los datos en string y se imprimen
    cout << endl;
    datosDestinatario = destinatario1->datos2String();


    //Imprimir etiqueta
    cout << "Los datos se han ingresado con exito! aqui tiene su etiqueta: " << endl;
    cout << datosCliente;
    cout << datosPaquete;
    cout << datosDestinatario;
}


