"""Actividad de clase 13

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/15Kt83Ubd2MIyMEhJOmsExJ_GxVDajpZp

**Actividad en clase 13:** Programas con datos estructurados Strings

28/septiembre/2021

Jaime Eduardo López Castro **A00833173**

Link: https://colab.research.google.com/drive/15Kt83Ubd2MIyMEhJOmsExJ_GxVDajpZp?usp=sharing

### Problema 1
Escribe una función que reciba como parámetro una cadena de texto y como resultado devuelva la cadena, pero invertida y en mayúsculas.

cadena = "Esta cadena de texto será invertida"
"""

def invertir_cadena(s):
  s_inv = s[::-1]
  return s_inv.upper()

cadena = "Esta cadena de texto será invertida"
print(invertir_cadena(cadena))

"""### Problema 2
Escribe una función que reciba dos parámetros: un texto y una letra. La función deberá imprimir la cadena, pero en cada letra diferente de “letra” deberá escribir asteriscos.

Ejemplo:

cadena = "Esta cadena de texto será modificada"

letra = "a"

la función debe imprimir

```
***a**a***a**********************a*a
```

"""

def sustituir_caracteres(texto, letra):
  for caracter in texto:
    if caracter != letra:
      texto = texto.replace(caracter, "*")
  return texto

cadena = "Esta cadena de texto será modificada"
letra = "a"

print(sustituir_caracteres(cadena, letra))

"""### Problema 3
Escribe una función que recibe como parámetro un texto. La función deberá eliminar todos los espacios en blanco de la cadena original.

cadena = "Esta cadena de texto no tendrá espacios en blanco"
"""

def eliminar_espacios(s):
  s_troncho = s.replace(" ", "")
  return s_troncho

cadena = "Esta cadena de texto no tendrá espacios en blanco"
print(eliminar_espacios(cadena))

"""### Problema 4
Escribe una función que reciba como parámetro dos cadenas de texto (cadena y subcadena). La función deberá buscar la “subcadena” dentro de la “cadena” original y deberá eliminarla. El resultado es la cadena ya sin la subcadena.

cadena = "Esta cadena de texto no contendrá la subcadena"

subcadena = "Esta"
"""

def eliminar_subcadena(cadena, subcadena):
  nueva_cadena = cadena.replace(subcadena, "")
  return nueva_cadena

cadena = "Esta cadena de texto no contendrá la subcadena"
subcadena = "Esta"
print(eliminar_subcadena(cadena, subcadena))

"""### Problema 5
Escribe una función que recibe como parámetro una cadena de texto y una subcadena. La función deberá contar cuántas veces se repite la subcadena en la cadena original y devolver dicho número.

Ejemplo:

cadena = "Armando Escándalos escribe este código, aquel código y el mismo código"

subcadena = “código”

Una vez que se ejecuta la función el resultado es:

“La subcadena este se repite 3 veces”
"""

def contar_repeticiones(cadena, subcadena):
  contador = 0

  for index in range(len(cadena)):
    if cadena[index : index + len(subcadena)] == subcadena:
      contador += 1
  
  return contador

cadena = "Armando Escándalos escribe este código, aquel código y el mismo código"
subcadena = "código"

print(f"La subcadena se repite {contar_repeticiones(cadena, subcadena)} veces")