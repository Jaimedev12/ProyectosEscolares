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
