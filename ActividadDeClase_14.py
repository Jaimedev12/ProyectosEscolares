"""Actividad de clase 14

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1V7rca99rZQLiY3qcm0DoMi79OPd3pfz8

**Actividad 14:** Construcción de programas que manipulan archivos

1/octubre/2021

Jaime Eduardo López Castro **A00833173**

Link: https://colab.research.google.com/drive/1V7rca99rZQLiY3qcm0DoMi79OPd3pfz8?usp=sharing

### Problema 1
Crea una lista de palabras (cada palabra es introducida por el usuario).

Define con qué clave el usuario dejará de capturar palabras.

Guarda la lista de palabras en el archivo "palabras.txt".

Cierra el archivo.

Abre el archivo y lee su contenido. Carga el contenido en otra lista.

Ordena la lista de palabras en orden alfabético.

Escribe la lista de palabras ordenadas en el archivo (reemplaza el contenido del archivo).

Cierra el archivo.

Abre nuevamente el archivo.

Pide al usuario que inserte 3 palabras más en una lista nueva.

Agrega al archivo la lista con las 3 nuevas palabras.

Cierra el archivo.

Abre el archivo, guarda el nombre del autor del programa y la fecha y la última hora de modificación del archivo.

Cierra el archivo.
"""
lista_palabras = []

palabra = input("Ingresa una palabra, escribe '*' para terminar: ")

while palabra != "*":
  lista_palabras.append(palabra)
  palabra = input("Ingresa una palabra, escribe '*' para terminar: ")

