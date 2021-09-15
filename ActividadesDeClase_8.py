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

"""# Actividad 5: Construcción de programas que toman decisiones - IF"""

sueño = True

if sueño:
  print("Pégate una dormida carnal")
else:
  print("Déjate de cosas y ponte a hacer algo ándale")

# PROBLEMA 1

a = int(input("Dame un número: "))
b = int(input("Dame otro número: "))
c = int(input("Dame otro número: "))

if a < b and a < c and b < c:
  print(a)
  print(b)
  print(c)
elif a < b and a < c and c < b:
  print(a)
  print(c)
  print(b)
elif b < a and b < c and a < c:
  print(b)
  print(a)
  print(c)
elif b < a and b < c and c < a:
  print(b)
  print(c)
  print(a)
elif c < a and c < b and a < b:
  print(b)
  print(a)
  print(c)
elif c < a and c < b and b < a:
  print(b)
  print(c)
  print(a)
else:
  print("Input no válido")

# PROBLEMA 2

peso = float(input("Ingresa tu peso en kilos: "))
altura = float(input("Ingresa tu altura en centímetros: ")) / 100

imc = peso / altura ** 2

if imc < 20:
  print("Peso bajo")
elif imc < 25:
  print("Peso normal")
elif imc < 30:
  print("Sobrepeso")
elif imc >= 30:
  print("Obesidad")
else:
  print("Resultado no válido")

"""# Actividad 6: Programas que utilizan funciones y decisiones."""

# Problema 1

lado1 = int(input("Ingresa el lado 1: "))
lado2 = int(input("Ingresa el lado 2: "))
lado3 = int(input("Ingresa el lado 3: "))

def determinar_triangulo(x, y, z):
  if x > 0 and y > 0 and z > 0:
    if x + y > z and x + z > y and y + z > x:
      
      if x == y and y == z:
        print("El triángulo es equilátero")
      elif x == y or x == z or y == z:
        print("El triángulo es isósceles")
      else:
        print("El triángulo es escaleno")

    else: 
      print("Lados no pueden generar un triángulo válido")
  else:
    print("Los lados de el triángulo no pueden medir menos que 0")

determinar_triangulo(lado1, lado2, lado3)

# Problema 2

import math

radio = float(input("Ingresa el radio del círculo: "))
xcentro = float(input("Ingresa la coordenada x del centro: "))
ycentro = float(input("Ingresa la coordenada y del centro: "))
xpunto = float(input("Ingresa la coordenada x del punto: "))
ypunto = float(input("Ingresa la coordenada y del punto: "))

def determinar_posicion(r, xc, yc, xp, yp):

  distancia = math.sqrt((xc - xp) ** 2 + (yc - yp) ** 2)
  
  if distancia <= r:
    print("El punto está dentro del círculo :D")
  else:
    print("El punto está fuera del círculo")

determinar_posicion(radio, xcentro, ycentro, xpunto, ypunto)

"""# Actividad 7: Construcción de programas que utilizan repeciciones - FOR

### PROBLEMA 1
Muestra una serie de números que empiezan en a y se vayan incrementando de 5 en 5 hasta llegar a b, donde a y b son dos número capturados por el usuario; asume que a siempre es menor que b 

Nota que a y b no necesariamente son múltiplos de 5, y que debe mostrar todos los números que sean menor o igual a b.
"""

# Problema 1

a = int(input("Ingresa el número a: "))
b = int(input("Ingresa el número b: "))

for numero in range(a, b + 1, 5): 
  print(numero)

"""### PROBLEMA 2
Muestra el valor de la sumatoria de todos los números desde el 1 hasta n, donde n es un número entero capturado por el usuario.
"""

# Problema 2

n = int(input("Ingresa un número: "))
sumatoria = 0

for num in range(0, n + 1, 1):
  sumatoria += num

print(sumatoria)

"""### PROBLEMA 3
Calcula el factorial de un número N, donde N es un número que el usuario captura.
"""

# Problema 3

n = int(input("Ingresa un número: "))
total = 1

for num in range(1, n + 1, 1):  
  total = total * num
print(total)

"""### PROBLEMA 4
Muestra en pantalla n caracteres que alternan entre # y %, donde n es un número entero capturado por el usuario.
Los caracteres se deben mostrar uno en cada renglón.
Observa que el primer caracter que se debe mostrar siempre es #
"""

# Problema 4

n = int(input("Ingresa un número :"))

for num in range(0, n, 1):
  if num % 2 == 0:
    print("#")
  elif num % 2 != 0:
    print("%")

"""### PROBLEMA 5
Escribe un programa que lea un número entero positivo n y muestre una lista de números que empieza en 1 e incrementa de uno en uno hasta llegar a n y después decrementa de uno en uno hasta llegar a 1:
"""

# Problema 5

n = int(input("Ingresa un número: "))
listaNumeros = []

for num in range(1, n + 1, 1):
  listaNumeros.append(num)
for num in range(n - 1, 0, -1):
  listaNumeros.append(num)

print(*listaNumeros, sep = ", ")

"""# Actividad 8: Construcción de programas que utilizan repeciciones - FOR y WHILE

### Problema 1

Muestra el promedio de todos los números capturados por el usuario. Primero, pregunta por la cantidad de números que el usuario desea capturar y luego pregunta por cada uno de los números y después despliega en pantalla el promedio de todos los números.
"""

n = int(input("¿Cuántos números quiere promediar?: "))
suma = 0

for numero in range(n):
  numeroAPromediar = float(input("Elige el número " + str(numero + 1) + " a promediar es: "))
  suma += numeroAPromediar
  
promedio = suma / n
print("El promedio es", round(promedio, 2))

"""### Problema 2

En una cuenta de inversion, a principios del año 2021, el saldo era de 100,500 pesos. El banco da un rendimiento de 8% de interés anual, donde cada mes el porcentaje de interés calculado se acumula al saldo de la cuenta, es decir, cada mes el saldo de la cuenta al final del mes, es igual al saldo en ese momento, más el cálculo del interés mensual.

saldo = saldo + (saldo × (interésAnual / 12))

En el mes de julio se va hacer un retiro por 90,500 pesos.

Y el mes de octubre se va hacer un depósito por 50,000 pesos.

Utiliza el estatuto for para calcular y desplegar cuánto va a ser el saldo de la cuenta al final del año.
"""

saldo = 100500
interes = 0.08
retiroJulio = 90500
depositoOctubre = 50000

for mes in range(1, 12 + 1):
  saldo += (saldo * (interes / 12))

  if mes == 7:
    saldo -= retiroJulio
  
  if mes == 10:
    saldo += depositoOctubre

print("El saldo al final del año es", round(saldo))

"""### Problema 3
Escribe un programa que desplique la palabra Python letra por letra formando el siguiente patrón:

P

Py

Pyt

Pyth

Pytho

Python
"""

palabra = "Python"
texto = ""

for letra in palabra:
  texto = texto + letra
  print(texto)

"""### Problema 4
Suma los números enteros (positivos y negativos) que el usuario teclee, deberás dejar de preguntar por números hasta que la suma de todos los números capturados sea igual a cero.
"""

numero = int(input("Ingresa un número a sumar: "))
suma = numero
print(suma)

while suma != 0:
  numero = int(input("Ingresa un número a sumar: "))
  suma += numero
  print(suma)

"""### Programa 5


Recupera el código de tu programa de la calculadora de IMC (índice de masa corporal) y realiza las adecuaciones para que la calculadora le permita al usuario calcular repetidamente el IMC de los pacientes en un consultorio.
"""

n = int(input("¿Cuántos IMC quiere calcular? "))

for persona in range(n):
  peso = float(input("Ingresa el peso en kilos: "))
  altura = float(input("Ingresa la altura en centímetros: ")) / 100

  imc = peso / altura ** 2
  print("El IMC es de", round(imc, 2))

  if imc < 20:
    print("Peso bajo")
  elif imc < 25:
    print("Peso normal")
  elif imc < 30:
    print("Sobrepeso")
  elif imc >= 30:
    print("Obesidad")
  else:
    print("Resultado no válido")

"""### Programa 6
Escribe un programa que pregunte el nombre del usuario y contraseña, que valide si son correctas y si alguna no es correcta, que vuela a preguntar hasta que sean correctas y despliegue el mensaje: "Bienvenido, usuario."
"""

user = "Jaime"
password = "contraseña"

while True:

  usuario = input("Ingresa el usuario: ")
  contraseña = input("Ingresa la contraseña: ")

  if usuario == user and contraseña == password:
    print("Bienvenido,", usuario)
    break
  else:
    print("Usuario o contraseña inválidos, vuelve a intentarlo")
