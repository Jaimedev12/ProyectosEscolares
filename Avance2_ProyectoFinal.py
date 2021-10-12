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


