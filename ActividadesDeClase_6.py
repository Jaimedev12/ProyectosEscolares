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
