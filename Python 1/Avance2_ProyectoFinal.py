"""
## Algoritmos por función
registrar_pregunta():
1. Primero se crea la lista de posibles respuestas para añadirle elementos después.
2. Después se pregunta por el enfoque (lectura, matemáticas o ciencias).
3. Si el input es válido, se asigna el nombre correspondiente a la variable 'enfoque', si no, se vuelve a preguntar.
4. Pedimos el texto de la pregunta y se asigna a la variable 'texto_pregunta'.
5. Se pregunta por las posibles respuestas, añadiéndolas a la lista de creada anteriomente: 'lista_posibles_respuestas'.
6. Después se pregunta por qué inciso es el correcto y se almacena en la variable de 'respuesta_correcta', que indica qué elemento en la lista de posibles respuesta es la correcta.
7. De ahí se unen todos los datos en un string
8. De ese string se crean una lista de strings con los datos por separado: el número de pregunta, su enfoque, el texto de la pregunta, todas las posibles respuestas y la respesta correcta.
9. Se agrega la lista de strings a la lista de 'respuestas' que contiene todas las preguntas actuales.
10. Se modifica el archivo de texto con las preguntas, añadiendo esta última.

actualizar_pregunta():
1. Se enseña la lista de preguntas actuales en base al archivo csv.
2. Se pregunta por la pregunta que se quiere actualizar.
3. Si el input es válido, se imprimen los datos de la pregunta seleccionada y se preguntan por los nuevos datos uno por uno.
4. Se van guardando estos datos en una nueva lista que funciona como borrador, si se presiona enter sin ingresar un nuevo valor, se agrega a la lista el valor que se encontraba originalmente en la pregunta.
5. Después de preguntar por todos los valores se imprimen los datos actualizados de la pregunta.
6. Se le pregunta al usuario si está seguro de cambiar los datos viejos por los nuevos.
7. Si la respuesta es que sí, se sustituye el borrador por los datos en la lista de respuestas original. Si la respuesta es que no, se deja la lista original sin modificaciones.
8. Se actualiza el archivo csv con los nuevos datos. 

estudiar_area():
1. Se pregunta por el enfoque que se desea estudiar y si el input es válido, se guarda en la variable "enfoque_deseado".
2. Se crea una lista nueva con todas las preguntas posibles que se podrían hacer de acuerdo al enfoque deseado.
3. Preguntamos por el número de preguntas que se desean practicar. Si este número es un entero entre 1 y el número máximo de preguntas posibles, entonces el número se guarda en la variable "n_preguntas_deseadas".
4. Se selecciona un orden aleatorio para hacer la cantidad de preguntas deseadas por el usuario, en base a la cantidad de preguntas posibles.
5. Se usan como parámetros la lista de preguntas posibles y el orden aleatorio de las mismas en la función de "hacer_pregunta()"
6. Esta función realiza las preguntas y devuelve los aciertos y errores, los cuales son almacenados en 2 variables.
7. Se imprimen la cantidad de aciertos y errores obtenidos en la práctica.

hacer_pregunta(preguntas_posibles, orden_aleatorio)
1. Se imprime una pregunta de la lista de preguntas_posibles junto con sus respuestas.
2. Se guarda la respuesta dada por el usuario.
3. Evaluamos si la respuesta es correcta o si es incorrecta. Después de guarda en una variable correspondiente para cada caso.
4. Se regresan estas variabls.

presentar_quiz():
1. Se lee la lista de preguntas y se crean 3 listas con las posibles preguntas de matemáticas, lectura y ciencias, consecutivamente.
2. Se crea un orden aleatorio para cada una de las preguntas en los enfoques.
3. Se almacenan en 3 listas diferentes las 10 preguntas que se realizarán por cada enfoque.
4. Estas listas con 10 preguntas y sus órdenes aleatorios se envían a la función mencionada anteriormente de "hacer_pregunta()" y se almacenan los aciertos y errores por enfoque.
5. Se imprimen los errores y aciertos por área.
6. Se guardan los datos del número de examen realizado, su calificación, total de aciertos y de errores en una lista llamada "pregunta_realizada".
7. Los datos de esta lista se guardan en otra lista llamada "examenes_realizados", donde se guardan todos los datos de los exámenes realizados anteriormente (De momento están puestos desde el principio, hasta que se implemente el uso de archivos .txt).

reportar_calificaciones():
1. Se calcula la suma de calificaciones, aciertos y errores.
2. Con esa información calculamos el promedio, porcentaje de aciertos y de errores.
3. Guardamos esta información en una lista, la cual irá dentro de una variable llamada "Tabla".
4. Se tabula la variable "Tabla".

salir():
1. Imprimimos un mensaje de despedida.
2. Rompemos el ciclo while que mantiene el programa corriendo.
"""

#Primero que nada, pido una disculpa
#por todos los pecados cometidos en este código

from tabulate import tabulate
import csv
import random

lista_preguntas = []
examenes_realizados = [['1', '50.0', '15', '15'], ['2', '66.66', '20', '10'], ['3', '83.33', '25', '5'], ['4', '100.0', '30', '0']]

with open("Lista_de_Preguntas.csv") as csv_file:
  csv_reader = csv.reader(csv_file)
  #next(csv_file)

  for line in csv_file:
    lista_preguntas.append(line.split(","))

for i in range(len(lista_preguntas)):
  lista_preguntas[i][-1] = lista_preguntas[i][-1].replace("\n", "")

def hacer_pregunta(posibles_preguntas, numeros_random):
    ta = 0
    te = 0
    for i in range(len(numeros_random)):
      print(f"\nPregunta {i + 1}: {posibles_preguntas[numeros_random[i]][2]}")
      print(f"a) {posibles_preguntas[numeros_random[i]][3]}")
      print(f"b) {posibles_preguntas[numeros_random[i]][4]}")
      print(f"c) {posibles_preguntas[numeros_random[i]][5]}")
      print(f"d) {posibles_preguntas[numeros_random[i]][6]}")

      respuesta_dada = int(input("(1-> a  2-> b  3-> c  4-> d) Tu respuesta: "))
      if respuesta_dada == int(posibles_preguntas[numeros_random[i]][7]):
        ta += 1
      else:
        te += 1

    return ta, te

def main():
    menu()

def registrar_pregunta():
    lista_de_posibles_respuestas = []

    n_enfoque = int(input("""
    ¿Cuál es el enfoque de la pregunta?:
    1. Matemática
    2. Lectura
    3. Ciencias
    --> """))

    # Revisar si el usuario escogió un enfoque válido
    while n_enfoque < 1 or n_enfoque > 3:
        print("Ingresa un valor válido")
        n_enfoque = int(input("""
        ¿Cuál es el enfoque de la pregunta?:
        1. Matemáticas
        2. Lectura
        3. Ciencias
        --> """))

    if n_enfoque == 1:
        enfoque = "Matematicas"
    elif n_enfoque == 2:
        enfoque = "Lectura"
    elif n_enfoque == 3:
        enfoque = "Ciencias"

    texto_pregunta = input("\nIngresa la pregunta: ")

    for posible_respuesta in range(4):
        pR = input("Ingresa la posible respuesta: ")
        lista_de_posibles_respuestas.append(pR)

    respuesta_correcta = int(input("""\n¿Cuál es la respuesta correcta?
    1 --> el incizo a)
    2 --> el incizo b)
    3 --> el incizo c)
    4 --> el incizo d)
    """))

    # Revisar si el usuario escogió un una respuesta válida
    while respuesta_correcta < 1 or respuesta_correcta > 4:
        print("Ingresa un valor válido")
        respuesta_correcta = int(input("""¿Cuál es la respuesta correcta?
    1 --> el incizo a)
    2 --> el incizo b)
    3 --> el incizo c)
    4 --> el incizo d)
    """))

    pregunta_completa_string = str(f"{len(lista_preguntas) + 1} {enfoque} {texto_pregunta} {lista_de_posibles_respuestas[0]} {lista_de_posibles_respuestas[1]} {lista_de_posibles_respuestas[2]} {lista_de_posibles_respuestas[3]} {respuesta_correcta}")

    pregunta = pregunta_completa_string.split()

    lista_preguntas.append(pregunta)

    with open("Lista_de_Preguntas.csv", 'w') as csv_file_w:
        csv_writer = csv.writer(csv_file_w)
        for pregunta in lista_preguntas:
          csv_writer.writerow(pregunta)
    print("Pregunta resgistrada exitosamente")

def actualizar_pregunta():
    contador = 0
    print("\nPreguntas registradas:")
    for pregunta in lista_preguntas: #Aquí se imprimen las preguntas registradas y se pregunta cuál quieres actualizar
      contador += 1
      print(f"Pregunta {contador}: {pregunta}")
    pregunta_a_actualizar = int(input("\n¿Qué pregunta quiere modificar? (Ingrese el número): "))
    
    while pregunta_a_actualizar < 1 or pregunta_a_actualizar > len(lista_preguntas) + 1:
      print("Número inválido, inténtelo de nuevo porfavor")
      pregunta_a_actualizar = int(input("¿Qué pregunta quiere modificar? (Ingrese el número): "))
    
    print(f"\nNúmero de pregunta: {lista_preguntas[pregunta_a_actualizar - 1][0]}. "\
f"Enfoque: {lista_preguntas[pregunta_a_actualizar - 1][1]}. "\
f"Texto de la pregunta: {lista_preguntas[pregunta_a_actualizar - 1][2]}. "\
f"Opción 1: {lista_preguntas[pregunta_a_actualizar - 1][3]}. "\
f"Opción 2: {lista_preguntas[pregunta_a_actualizar - 1][4]}. "\
f"Opción 3: {lista_preguntas[pregunta_a_actualizar - 1][5]}. "\
f"Opción 4: {lista_preguntas[pregunta_a_actualizar - 1][6]}. "\
f"Opción correcta: {lista_preguntas[pregunta_a_actualizar - 1][7]}")
    

    borrador_nueva_pregunta = ["", "", "", "", "", "", "", ""]

    print("Ingrese los datos nuevos, si no quiere actualizar el dato, presione 'enter'")

    borrador_nueva_pregunta[0] = lista_preguntas[pregunta_a_actualizar - 1][0]

    nuevo_enfoque = input("Nuevo enfoque: ")
    if nuevo_enfoque == "":
      borrador_nueva_pregunta[1] = lista_preguntas[pregunta_a_actualizar - 1][1]
    else:
      borrador_nueva_pregunta[1] = nuevo_enfoque

    nuevo_texto_pregunta = input("Nuevo texto de pregunta: ")
    if nuevo_texto_pregunta == "":
      borrador_nueva_pregunta[2] = lista_preguntas[pregunta_a_actualizar - 1][2]
    else:
      borrador_nueva_pregunta[2] = nuevo_texto_pregunta

    nueva_opcion1 = input("Ingresa una nueva opción 1: ")
    if nueva_opcion1 == "":
      borrador_nueva_pregunta[3] = lista_preguntas[pregunta_a_actualizar - 1][3]
    else:
      borrador_nueva_pregunta[3] = nueva_opcion1

    nueva_opcion2 = input("Ingresa una nueva opción 2: ")
    if nueva_opcion2 == "":
      borrador_nueva_pregunta[4] = lista_preguntas[pregunta_a_actualizar - 1][4]
    else:
      borrador_nueva_pregunta[4] = nueva_opcion2

    nueva_opcion3 = input("Ingresa una nueva opción 3: ")
    if nueva_opcion3 == "":
      borrador_nueva_pregunta[5] = lista_preguntas[pregunta_a_actualizar - 1][5]
    else:
      borrador_nueva_pregunta[5] = nueva_opcion3

    nueva_opcion4 = input("Ingresa una nueva opción 4: ")
    if nueva_opcion4 == "":
      borrador_nueva_pregunta[6] = lista_preguntas[pregunta_a_actualizar - 1][6]
    else:
      borrador_nueva_pregunta[6] = nueva_opcion4

    nueva_respuesta_correcta = input("Ingrese una nueva respuesta correcta: ")
    if nueva_respuesta_correcta == "":
      borrador_nueva_pregunta[7] = lista_preguntas[pregunta_a_actualizar - 1][7]
    else:
      borrador_nueva_pregunta[7] = nueva_respuesta_correcta

    print("Así quedaría la nueva opción: ")

    print(f"\nNúmero de pregunta: {borrador_nueva_pregunta[0]}. "\
    f"Enfoque: {borrador_nueva_pregunta[1]}. "\
    f"Texto de la pregunta: {borrador_nueva_pregunta[2]}. "\
    f"Opción 1: {borrador_nueva_pregunta[3]}. "\
    f"Opción 2: {borrador_nueva_pregunta[4]}. "\
    f"Opción 3: {borrador_nueva_pregunta[5]}. "\
    f"Opción 4: {borrador_nueva_pregunta[6]}. "\
    f"Opción correcta: {borrador_nueva_pregunta[7]}")
    cambiar_pregunta = input("¿Está seguro de que quiere actualizar los datos de la pregunta? (1-sí 2-no)")

    while cambiar_pregunta != "1" and cambiar_pregunta != "2":
      print("Inválido, inténtelo otra vez")
      cambiar_pregunta = input("¿Está seguro de que quiere actualizar los datos de la pregunta? (1-sí 2-no)")

    if cambiar_pregunta == "1":
      lista_preguntas[pregunta_a_actualizar - 1] = borrador_nueva_pregunta
        
      with open("Lista_de_Preguntas.csv", 'w') as csv_file_w:
        csv_writer = csv.writer(csv_file_w)
        for pregunta in lista_preguntas:
          csv_writer.writerow(pregunta)

      print("Pregunta actualizada con éxito")


def estudiar_area():
    enfoque_deseado_index = int(input("""¿Qué enfoque te gustaría estudiar?: 
1 - Matemáticas
2 - Lectura
3 - Ciencias
--> """))
    
    while enfoque_deseado_index < 1 or enfoque_deseado_index > 3:
      print("Número inváludo, inténtelo de nuevo")
      enfoque_deseado_index = int(input("""¿Qué enfoque te gustaría estudiar?: 
1 - Matemáticas
2 - Lectura
3 - Ciencias
--> """))

    if enfoque_deseado_index == 1:
      enfoque_deseado = "Matematicas"
    elif enfoque_deseado_index == 2:
      enfoque_deseado = "Lectura"
    elif enfoque_deseado_index == 3:
      enfoque_deseado = "Ciencias"
      
    lista_preguntas_posibles = []
    for pregunta in range(len(lista_preguntas)):
      if lista_preguntas[pregunta][1] == enfoque_deseado:
        lista_preguntas_posibles.append(lista_preguntas[pregunta])

    print(f"\n¿Cuántas preguntas te gustaría practicar? ({len(lista_preguntas_posibles)} preguntas disponibles para el enfoque)")
    n_preguntas_deseadas = int(input("--> "))

    while n_preguntas_deseadas < 1 or n_preguntas_deseadas > len(lista_preguntas_posibles):
      print("Número de preguntas inválido, intente de nuevo")
      print(f"\n¿Cuántas preguntas te gustaría practicar? ({len(lista_preguntas_posibles)} preguntas disponibles para el enfoque)")
      n_preguntas_deseadas = int(input("--> "))

    random_questions = random.sample(range(len(lista_preguntas_posibles)), n_preguntas_deseadas)

    aciertos, errores = hacer_pregunta(lista_preguntas_posibles, random_questions)
    print(f"Aciertos: {aciertos} - Errores: {errores}")

def presentar_quiz():
    lista_preguntas_posibles_mate = []
    lista_preguntas_posibles_lectura = []
    lista_preguntas_posibles_ciencias = []

    for pregunta in range(len(lista_preguntas)):
      if lista_preguntas[pregunta][1] == "Matematicas":
        lista_preguntas_posibles_mate.append(lista_preguntas[pregunta])
      if lista_preguntas[pregunta][1] == "Lectura":
        lista_preguntas_posibles_lectura.append(lista_preguntas[pregunta])
      if lista_preguntas[pregunta][1] == "Ciencias":
        lista_preguntas_posibles_ciencias.append(lista_preguntas[pregunta])

    diez_preguntas_mate = []
    diez_preguntas_lectura = []
    diez_preguntas_ciencias = []

    random_questions_mate = random.sample(range(len(lista_preguntas_posibles_mate)), 10)
    random_questions_lectura = random.sample(range(len(lista_preguntas_posibles_lectura)), 10)
    random_questions_ciencias = random.sample(range(len(lista_preguntas_posibles_ciencias)), 10)

    for pregunta in range(len(random_questions_mate)):
      diez_preguntas_mate.append(lista_preguntas_posibles_mate[random_questions_mate[pregunta]])
    for pregunta in range(len(random_questions_lectura)):
      diez_preguntas_lectura.append(lista_preguntas_posibles_lectura[random_questions_lectura[pregunta]])
    for pregunta in range(len(random_questions_ciencias)):
      diez_preguntas_ciencias.append(lista_preguntas_posibles_ciencias[random_questions_ciencias[pregunta]])

    print("\nMatemáticas:")
    aciertos_mate, errores_mate = hacer_pregunta(diez_preguntas_mate, random_questions_mate)
    print("\nLectura:")
    aciertos_lectura, errores_lectura = hacer_pregunta(diez_preguntas_lectura, random_questions_lectura)
    print("\nCiencias:")
    aciertos_ciencias, errores_ciencias = hacer_pregunta(diez_preguntas_ciencias, random_questions_ciencias)

    print(f"\nMatemáticas: \nAciertos: {aciertos_mate} - Errores: {errores_mate}")
    print(f"Lecturas: \nAciertos: {aciertos_lectura} - Errores: {errores_lectura}")
    print(f"Ciencias: \nAciertos: {aciertos_ciencias} - Errores: {errores_ciencias}")

    total_aciertos = aciertos_mate + aciertos_lectura + aciertos_ciencias
    total_errores = errores_mate + errores_lectura + errores_ciencias
    calif = (total_aciertos / 30) * 100

    pregunta_realizada = f"{len(examenes_realizados) + 1},{calif},{total_aciertos},{total_errores}"
    examenes_realizados.append(pregunta_realizada.split(","))

    #Poner un tiempo de 20 minutos

def reportar_calificaciones():

    suma_califs = 0
    for examen in range(len(examenes_realizados)):
      suma_califs += round(float(examenes_realizados[examen][1]))
    suma_aciertos = 0
    for examen in range(len(examenes_realizados)):
      suma_aciertos += round(float(examenes_realizados[examen][2]))
    suma_errores = 0
    for examen in range(len(examenes_realizados)):
      suma_errores += round(float(examenes_realizados[examen][3]))
    
    Tabla = {'Headers': ["Total de usuarios", 
                         "Promedio de calificaciones", 
                         "Preguntas correctas", 
                         "Preguntas incorrectas"],
             'Datos': [len(examenes_realizados), 
                       suma_califs/len(examenes_realizados), 
                       f"{(suma_aciertos/(30*len(examenes_realizados)))*100}%", 
                       f"{(suma_errores/(30*len(examenes_realizados)))*100}%"]}
        
    print(tabulate(Tabla))

def salir():
    print("Gracias por su preferencia")

def menu(): # Imprime el menu y realiza una función dependiendo el input
    while True:
        print("""
        Menu:
        1. Alta de preguntas de prueba PISA (lectura, matemáticas, ciencias)
        2. Actualizar preguntas de la prueba PISA (lectura, matemáticas, ciencias)
        3. Estudiar preguntas de cierta área (lectura, matemáticas, ciencias)
        4. Presentar un quiz (lectura, matemáticas, ciencias)
        5. Reporte de calificaciones
        6. Salir 
        """)
        opcion = input("Elige una opción: ")

        if opcion == "1":
            registrar_pregunta()

        elif opcion == "2":
            actualizar_pregunta()

        elif opcion == "3":
            estudiar_area()

        elif opcion == "4":
            presentar_quiz()

        elif opcion == "5":
            reportar_calificaciones()

        elif opcion == "6":
            salir()
            break

        else:
            print("Opción no válida") 

main()
