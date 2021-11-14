// Actividad4_A00833173.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include "Cliente.h"
using namespace std;

int main()
{
    string nombreCliente, direccion, telefono, horaRec;
    string datosCliente;
    Cliente* cliente1 = new Cliente();

    cout << "Ingrese su nombre: ";
    cin >> nombreCliente;
    
    cout << "Telefono: ";
    cin >> telefono;

    cout << "Direccion: ";
    cin >> direccion;

    cout << "Hora a la que recogio su paquete: ";
    cin >> horaRec;

    cliente1->guardarDatos(nombreCliente, telefono, direccion, horaRec);

    datosCliente = cliente1->datos2String();

    cout << datosCliente;

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


