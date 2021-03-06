# -*- coding: utf-8 -*-
"""Actividad de clase 12

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1_BXyQ35iZugLIYQ9NJws40tujBDetz1T

**Actividad 11:** Construcción de programas que utilizan listas

24/septiembre/2021

Jaime Eduardo López Castro **A00833173**

Link: https://colab.research.google.com/drive/1_BXyQ35iZugLIYQ9NJws40tujBDetz1T?usp=sharing

### Problema 1
Diseña y codifica un programa en Python en el cual el usuario ingrese la cantidad de elementos que va a ingresar a la lista; posteriormente, el programa debe leer cada uno de los elementos de la lista, uno por línea y se van agregando a la lista.

Importante: El programa debe validar que el número de elementos a ingresar sea mayor que cero, sino debe volver a pedir el valor hasta que cumpla.

**Entradas**

Número entero n que corresponde al número de elementos a ingresar a la lista. Debe ser mayor a 0, de lo contrario, se solicitará de nuevo hasta que se cumpla la condición.

Posteriormente, se reciben los n elementos de la lista, uno en cada renglón.

**Salidas**

El programa debe desplegar los elementos ingresados en la siguiente forma:

lista[0] = 1

lista[1] = 2

lista[2] = 3

lista[3] = 4

lista[4] = 5

Posteriormente, el programa debe desplegar el último elemento.

Después, el programa debe desplegar la suma de todos los elementos de la lista.

Por último, el programa debe desplegar el promedio de todos los elementos de la lista.
"""

# Problema 1

elementos = []
n = 0

while n <= 0:
  n = int(input("¿Cuántos elementos quieres ingresar?: "))

  if n <= 0:
    print("Número no válido, inténtalo de nuevo")


for num in range(n):
  elemento = int(input("Ingresa un número: "))
  elementos.append(elemento)


promedio = sum(elementos) / n

print()
print("Elementos en la lista: ")

for i in range(len(elementos)):
  print(f"lista[{i}] =", elementos[i])

print("El último elemento de la lista es:", elementos[-1])
print("La suma de los elementos en la lista es:", sum(elementos))
print("El promedio de todos los elementos de la lista es:", promedio)

"""### Problema 2
Escribe un programa que reciba del usuario una lista y devuelva otra con los elementos de la lista original, pero sin elementos duplicados.

**Entradas**

Se recibe un número entero positivo correspondiente al número de elementos que el usuario ingresará.

Se reciben uno a uno y por renglón, los elementos de la lista (strings y de acuerdo al número recibido anteriormente).

**Salidas**

Si el valor correspondiente al número de elementos que tendrá la lista es 0 o negativo, se deberá mandar el mensaje “Error”. Si el valor recibido es mayor a 0, se despliega la lista original (después de haber recibido los datos). Posteriormente, se despliega la lista, pero sin duplicados.
"""

# Problema 2

elementos = int(input("Ingresa la cantidad de elementos de la lista: "))
lista = []

if elementos <= 0:
  print("ERROR")
else:
  for num in range(elementos):
    dato = input("Ingresa un nombre: ")
    lista.append(dato)

  lista_sin_repetidos = list(dict.fromkeys(lista))

  print(lista)
  print(lista_sin_repetidos)

"""### Problema 3
Desarrolla un programa que permitirá obtener, a partir de una lista que recibirá del usuario, crear y desplegar una sublista con valores pares y otra sublista con valores impares.

**Entrada**

Cero o más valores enteros, uno en cada renglón. Finaliza la captura con un *

**Salida**

Se muestra la salida que deberá mostrar tu programa, tal como se ilustra a continuación:

PARES

[2, 4, 8]

IMPARES

[1, 5]

(Es decir, la palabra PARES en mayúscula en un renglón y, posteriormente, el despliegue de la lista de pares y, de manera similar, los impares, tal como se muestra en el ejemplo) Respeta el orden.
"""

# Problema 3

lista = []
lista_pares = []
lista_impares = []

elemento = ""
print("Ingrese números enteros para agregar a la lista, para terminar escriba '*'")

while elemento != "*":
  elemento = input()

  if elemento != "*":
    lista.append(int(elemento))

for n in range(len(lista)):
  if lista[n] % 2 == 0:
    lista_pares.append(lista[n])
  elif lista[n] % 2 != 0:
    lista_impares.append(lista[n])

print("PARES")
print(lista_pares)
print()
print("IMPARES")
print(lista_impares)
