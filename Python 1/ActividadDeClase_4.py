4

4 + 4

"Hola"

"ja" * 5

2 ** 3

"""### Tipos de datos"""

edad = 18
edad

type(edad)

dolar = 19.25
type(dolar)

msj = "Nombres, divertidísimo"
type(msj)

"""### Estatuto de asignación"""

a = 10
b = 5
a = b
a

a = 10
a = a + 5
a

a = 10
a += 5
a

"""### Comentarios"""

# Ahhhh wáchense un comentario

"""MIRA QUE CHIDO
SE PUEDE HACER ESTO
EN VARIOS RENGLONEEES

### Mostrar un mensaje en pantalla print()
"""

msj = "Hola mundo"
print(msj)

print("Hola mundo")

print(2 + 4)

nombre = "Germán"
print("Hola", nombre)

"""### Leer un dato del teclado con input()"""

edad = input()

print(edad)

edad = input("Ingresa tu edad: ")

print("Ingresa tu edad: ")
edad = float(input())

if(edad < 25):
    print("Nombre carnal tas bien chiquito")

"""### Librería Math"""

import math

math.sqrt(9)

math.pi

math.pow(2, 3)

"""# Actividad de clase 3: Funciones

### PROBLEMA 1.
Escribe un algoritmo que verifique si una persona puede obtener su licencia de conducir. Para hacerlo, debe ser mayor de edad (18 años o más) y traer una identificación oficial.

1. Solicitar identificación oficial.
2. Evaluar si tiene identificación válida.
3. Si no es válida, no obtiene licencia.
4. Si es válida, leer edad en identificación.
5. Evaluar si  la edad es mayor o igual a 18.
6. Si es falso, NO obtiene licencia.
7. Si es verdadero, obtiene licencia.

### PROBLEMA 2.
Realiza una función que solicite las coordenadas de dos puntos y que calcule la pendiente de la recta que une esos dos puntos.
"""

# Problema 2

def calcularPendiente():

  x1 = int(input("Ingresa la coordenada x1: "))
  y1 = int(input("Ingresa la coordenada y1: "))
  x2 = int(input("Ingresa la coordenada x2: "))
  y2 = int(input("Ingresa la coordenada y2: "))

  m = (y2 - y1) / (x2 - x1)

  print("La pendiente es:", m)

calcularPendiente()

"""### PROBLEMA 3.
Haz una función sirva para calcular el precio que va a pagar un cliente por comprar cemento.

La función debe leer la cantidad de bultos de cemento que va a comprar el cliente, y el precio del bulto de cemento.

La función debe mostrar como salida 3 datos uno en cada renglón: el precio antes de impuestos, los impuestos (que son el 16% del precio) y el total a pagar por el cliente.
"""

# Problema 3

def calcularPrecio():

  cantidadBultos = int(input("Ingresa la cantidad de bultos; "))
  precio = int(input("Ingresa el precio; "))

  subtotal = cantidadBultos * precio
  iva = subtotal * 0.16

  total = subtotal * iva

  print("El subtotal es:", subtotal)
  print("El iva es:", iva)
  print("El total es:", total)

calcularPrecio()

"""### PROBLEMA 4.
A inicio de año, las personas están preocupadas por su peso, por lo que acuden a nutriólogos, gimnasios y cualquier otra cosa que les ayude en el proceso. Realiza una función que ayude a las personas a indicar cuántos kilos debe bajar por mes dados el peso inicial, el peso final y el número de meses que una persona estará en un programa integral para bajar de peso.
"""

# Problema 4

# Preguntar datos
pesoInicial = float(input("Ingresa tu peso actual: "))
pesoFinal = float(input("Ingresa al peso al que quieres llegar: "))
meses = int(input("Ingresa en cuántos meses quieres alcanzar tu meta: "))

# Función que calcule el imprima el total
def calcularKilosxMes(pi, pf, m):
  total = (pi - pf) / m

  print("Para cumplir tu meta, tendrías que bajar", total, "kilos por mes")

# Llamar función
calcularKilosxMes(pesoInicial, pesoFinal, meses)

"""### PROBLEMA 5.
En una universidad cada estudiante cursa 4 materias en el semestre. Desarrolla una función que reciba la calificación de cada materia; calcula el promedio de las 4 materias y lo regresa.
"""

# Problema 5

# Preguntar datos
c1 = int(input("Ingresa tu primera calificación "))
c2 = int(input("Ingresa tu segunda calificación "))
c3 = int(input("Ingresa tu tercera calificación "))
c4 = int(input("Ingresa tu cuarta calificación "))

# Función que calcule el promedio y lo imprima
def calcularPromedio(c1, c2, c3, c4):
  promedio = (c1 + c2 + c3 + c4) / 4
  
  return promedio

# Llamar función
print("Tu promedio es:", calcularPromedio(c1, c2, c3, c4))

"""### PROBLEMA 6.
Desarrolla una función para calcular las siguientes medidas de un círculo/esfera/cilindro recibiendo el radio = 3cm y altura = 10

Diámetro - Perímetro o circunferencia - Área - Volumen de la esfera - 
Volumen de un cilindro
"""

# Problema 6

import math

# Definir variables
radio = 3
altura = 10

# Función para el diámetro, perímetro y área del círculo
def calcularCirculo(r):
  diametro = 2 * r
  perimetro = 2 * math.pi * r
  area = (math.pi) * (r ** 2)

  print("El diámetro del círculo es", diametro)
  print("El perímetro del círculo es", perimetro)
  print("El área del círculo es", area)

# Función para el volúmen de la esfera
def calcularVolumenEsfera(r):
  print("") # Generando espacio en la consola.
  volumen = (4 / 3) * (math.pi) * (r ** 3)
  print("El volumen de la esfera es", volumen)

# Función para el volúmen del cilindro
def calcularVolumenCilindro(r, a):
  print("") # Generando espacio en la consola.
  volumen = (math.pi) * (r ** 2) * altura
  print("El volumen del cilindro es", volumen)

# Llamar funciones
calcularCirculo(radio)
calcularVolumenEsfera(radio)
calcularVolumenCilindro(radio, altura)

"""### PROBLEMA 7.
Realiza una función para calcular el área de un triángulo cuyos lados son de longitud a, b y c se calcula como: 
"""

# Problema 7

import math

# Definir variables
lado1 = float(input("Ingresa la longitud del primer lado del tríangulo: "))
lado2 = float(input("Ingresa la longitud del segundo lado: "))
lado3 = float(input("Ingresa la longitud del tercer lado: "))

# Función para calcular el área de un triángulo según sus lados
def calcularArea(a, b, c):
  s = (a + b + c) / 2
  area = math.sqrt(s * (s - a) * (s - b) * (s - c))
  
  print("El área del triángulo es", area)

# Llamar función
calcularArea(lado1, lado2, lado3)

"""### PROBLEMA 8.
Escribe una función para calcular la distancia entre dos puntos del plano cartesiano solicitando el punto inicial y el final en términos de x y y, para desplegar el valor de la distancia.
"""

# Problema 8

import math

# Declarar variables
x1 = float(input("Ingresa la posición x el punto inicial: "))
y1 = float(input("Ingresa la posición y el punto inicial: "))
x2 = float(input("Ingresa la posición x el punto final: "))
y2 = float(input("Ingresa la posición y el punto final: "))

# Función para calcular la distancia entre los puntos
def calcularDistancia(x1, y1, x2, y2):
  distancia = math.sqrt(((x2 - x1) ** 2) + ((y2 - y1) ** 2))
  print("La distancia entre los 2 puntos es", distancia)

# Llamar funciones
calcularDistancia(x1, y1, x2, y2)

"""# Actividad 4: Construcción de programas que utilizan funciones

### PROBLEMA 1.
¿Qué aparece en la pantalla si se ejecuta el siguiente código de Python?:
"""

# Problema 1

def uno (a, b) :
     a = a + 5
     b += 10
     print(a, b)
     return b

def main() :
     x = 5
     y = 8
     z = uno(x, y)
     print(x, y, z)

main()

"""### PROBLEMA 2.
Escribe una función llamada equivalente que reciba como parámetro una cantidad de horas, minutos y segundos, y regrese como valor de retorno el tiempo equivalente en segundos.
"""

# Problema 2

# Función que calcule el equivalente en segundos
def equivalente(h, m, s):
  equivalente = s + (m * 60) + (h * 3600)

  return equivalente
1
# Función main - pregunta valores
def main():
  horas = float(input("¿Cuántas horas quieres convertir? "))
  minutos = float(input("¿Cuántos minutos quieres convertir? "))
  segundos = float(input("¿Cuántos segundos quieres convertir? "))

  print("El equivalente en segundos de", horas, "horas,", minutos, "minutos y", segundos, "segundos es:", equivalente(horas, minutos, segundos), "segundos.")

# Llamar funciones
print("Proceso 1:")
main()

print("")

print("Proceso 2:")
main()

"""### PROBLEMA 3.
Escribe una función llamada area_rectangulo( ) que reciba como parámetro el largo y ancho de un rectángulo y que regresa como valor de retorno el área del rectángulo.

Escribe una función llamada perimetro_rectangulo( ) que reciba como parámetro el largo y ancho de un rectángulo y que regresa como valor de retorno el perímetro del rectángulo.

Observa que dentro de las funciones no mostrarás nada, solo regresarás el valor calculado usando return.

Escribe ahora una función main que pregunte al usuario el largo y ancho del rectángulo (puedes pedir una clave a para área y p para perímetro) y después muestre el valor correspondiente al cálculo.
"""

# Problema 3

# Función para el calcular el área del rectángulo
def area_rectangulo(l, a):
  area = l * a

  return area

# Función para calcular el perímetro del rectángulo
def perimetro_rectangulo(l, a):
  perimetro = 2 * l + 2 * a

  return perimetro

# Función main
def main():
  largo = float(input("¿Cuál es el largo del rectángulo? "))
  ancho = float(input("¿Cuál es el ancho del rectángulo? "))

  print("")

  operacion_elegida = input("¿Quiéres sacar el perímetro o el área? (introduce 'p' para perímetro y 'a' para área): ")

  if(operacion_elegida == "p"):
    print("El perímetro es de:", perimetro_rectangulo(largo, ancho))  
  elif(operacion_elegida == "a"):
    print("El área es de:", area_rectangulo(largo, ancho), "unidades cuadradas.") 
  else:
    print("Input inválido :D")

# Llamar función
main()
