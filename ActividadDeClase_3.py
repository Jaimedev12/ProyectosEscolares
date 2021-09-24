

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
