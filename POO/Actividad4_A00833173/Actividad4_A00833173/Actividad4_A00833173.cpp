// Actividad4_A00833173.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include "Cliente.h"
#include "Paquete.h"
using namespace std;


int main()
{
    string nombreCliente, direccion, telefonoCliente, horaRec;
    string datosCliente, datosPaquete;
    Cliente* cliente1 = new Cliente();

    float peso, largo, ancho, alto;
    Paquete* paquete1 = new Paquete();

    //Datos del cliente
    cout << "Ingrese su nombre: ";
    cin >> nombreCliente;

    cout << "Telefono: ";
    cin >> telefonoCliente;

    cout << "Direccion: ";
    cin >> direccion;

    cout << "Hora a la que recogio su paquete: ";
    cin >> horaRec;

    //Se guardan los datos en el objeto del cliente
    cliente1->guardarDatos(nombreCliente, telefonoCliente, direccion, horaRec);

    //Se convierten los datos del cliente en string y se imprimen
    cout << endl;
    datosCliente = cliente1->datos2String();
    cout << datosCliente;


    cout << endl << endl;

    //Se preguntan los datos del paquete
    cout << "Ingrese el peso del paquete: ";
    cin >> peso;

    cout << "Largo del paquete: ";
    cin >> largo;

    cout << "Ancho del paquete: ";
    cin >> ancho;

    cout << "Alto del paquete: ";
    cin >> alto;

    //Se asignan los valores al objeto de la clase
    paquete1->guardarDatos(peso, largo, ancho, alto);

    //Se convierten los datos en string y se imprimen
    cout << endl;
    datosPaquete = paquete1->datos2String();
    cout << datosPaquete;


    //Planear recolección del envío
    //Ingresar nombre, teléfono, dirección y horario de recolección

    //Ingresar destino (nombre del destinatario, teléfono y dirección), peso y direcciones del paquete

    //Imprimir etiqueta
}

/*
Aprovechando su flota de aviones, la aerolínea “Vuela Alto” quiere entrar al mercado
del envío.Para ello, requieren desarrollar un sistema y se han acercado a ti para que
les ayudes.Después de varias reuniones, has logrado obtener información del
siguiente escenario :

El cliente entra al sitio Web de la aerolínea y programa la recolección del envío.El
cliente ingresará su nombre, teléfono, dirección y horario de la recolección.El sistema
también registrará el destino(nombre de destinatario, teléfono, dirección), peso y
dimensiones del paquete.Con todos estos datos capturados, se imprime una etiqueta
que se debe pegar al paquete y esperar la recepción.

1. Identifica las clases que se describen en el escenario propuesto.
2. Asegura incluir todos los atributos y métodos de las clases que has
identificado.
3. Utiliza la herramienta DIA que has instalado.
4. Agrega una breve descripción a cada una de las clases que has identificado.
5. Genera un documento en formato.pdf que contenga el diagrama de clases y
la información solicitada.Nombra a este documento Actividad_3.pdf
*/


