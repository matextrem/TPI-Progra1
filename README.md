# Trabajo práctico integrador de Programación I


## Primera parte

Dada la siguiente estructura de información que guarda datos de un alumno de una universidad:

Campo | Tipo | Validación
------------ | ------------- | -------------
dni. (Clave) | long | 10.000< dni < 100.000.000
Apellido y nombre | Cadena de 40 | `Normalizar`
Fecha de nacimiento | t_fecha | Validación formal y < fecha de proceso - 10 años
Sexo | char | 'F' o 'M'
Fecha de ingreso | t_fecha | Validación formal, <= fecha de proceso y > fecha de nacimiento
Carrera | Cadena de 4 | “INF”, “ELE”, “IND”, “ECO”, “DER”, “ADM”, “MED”, “EDF”, “FIL”
Cantidad de materias aprobadas | int | >=0
Fecha de aprobación de la última materia | t_fecha | > fecha-ingreso y <= fecha de proceso. Si no se informa, asumir la fecha de ingreso
Estado | char | Se genera en el alta como ‘R’
Fecha de baja | t_fecha | Se genera en el alta como 31/12/9999

Construir dos funciones: 
- La primera que permita ingresar los datos del alumno por teclado, los datos deben ser validados (según lo que indica el cuadro) a medida que se ingresan. Los datos de estado y fecha de baja deben ser completados automáticamente.
- La segunda que valide los datos de una estructura alumno, según lo indicado en el cuadro, que recibe por parámetro. Además del alumno a validar, debe recibir una fecha que indica el momento que fue procesado el registro. La función debe devolver qué campos dieron `error`.

`Normalizar`: Normalización del apellido y nombres, consistente en
- El/Los apellido/s y nombre/s deben comenzar con letra mayúscula y luego continuar con minúscula.
- El/Los apellido/s deben estar separado/s del/los nombre/s por una coma. De no existir dicha coma, agregarla a continuación de la primera palabra.
- Cada palabra debe separarse por no más de un espacio.
- La cadena no debe tener espacios al inicio, ni al final de la misma.

`Error`: Una forma de especificar qué campos dieron error sería a través de un vector de enteros donde cada posición representa un campo, indicando con un 1 si el campo dio error. Otra forma sería a través de un código especial que, por ejemplo, en un registro que tenga solo dni y sexo, si el dni es erróneo devuelva 1, si el sexo es erróneo devuelva 2, pero que si ambos son erróneos devuelva 3 (Nota: revise el funcionamiento del operador & para resolverlo de esta manera).

## Segunda parte

Construir un programa que, a partir de un archivo de texto (**xxxxx.txt**), cuyo nombre debe ser ingresado por teclado, genere un archivo binario (**xxxxx.dat**). El archivo de texto tiene registros de longitud variable. 
Se debe realizar la validación de los registros que se procesen (utilizando la función confeccionada para la primera parte. En caso de que el registro contenga algún error grabar en otro archivo de texto de salida la línea de texto completa, junto con una descripción del error e ignorar el registro.
Al comenzar, debe ingresarse por teclado la fecha de proceso y el path (ruta de acceso) del archivo (**xxxxx**).

## Tercera parte

Construya el TDA Índice utilizando las instrucciones de alguno de los anexos de este documento. Para esta parte no es necesario resolver las funciones ind_primero, ind_siguiente, ind_fin.
	
Generar el índice del archivo de alumnos utilizando el TDA recientemente creado. Al finalizar el proceso, debe guardar el índice en un archivo con el nombre xxxxx.idx (es decir, igual al nombre del archivo de alumnos, pero con extensión .idx).

El índice debe ser generado en el mismo momento en que se crea el archivo binario, es decir, que debe modificar el programa realizado anteriormente para que cree el índice. Entonces cuando termine el programa va a obtener los archivos:
- xxxxx.dat - con la información de los alumnos.
- errores.txt – con los errores de validación.
- xxxxx.idx – con el índice.

## Cuarta parte

Construir otro programa que realice diversas operaciones a partir de un menú con las siguientes opciones:
- Efectuar mantenimiento (altas, bajas ).
- Listar los dado de baja.
- Listarlos en orden (sin los dados de baja)

Como procedimientos iniciales, el programa debe solicitar el path del archivo binario (.dat) con el que va a trabajar y verificar la existencia del mismo en cuyo caso deberá generar el índice en memoria (ind_crear e ind_cargar) a partir del archivo de índices (igual nombre y extensión .idx), que debe existir necesariamente y está ordenado ascendentemente por la dni. Si no existiese el archivo, cancelar el proceso. Ingresar la fecha de proceso.

***Opción Efectuar mantenimiento:***
Tendrá un submenú (Alta, Baja)
- Alta: se obtendrán los datos del teclado, ingresando primero la clave (DNI) verificando que no exista en el índice  y, cuando estén todos ingresados, se realizará la validación y consistencia de los mismos (ídem proceso de generación del archivo). Si se detectan errores, se ignora todo lo ingresado. Una vez aceptado, grabarlo al final del archivo binario e insertar el registro de índice en el índice.
- Baja: Si existe la clave que se quiere dar de baja y **estado** no es ‘B’, actualizar el registro correspondiente con un carácter ‘B’ en **estado** y con la fecha de proceso como **fecha de baja**. Eliminar registro correspondiente del índice

***Opción listar los dados de baja:***
Listar los registros del archivo (.dat) que estén dados de baja (**estado**=’B’), en el orden en que están en el mismo.

***Opción listar en orden:***
Listar los registros activos (no están dados de baja) del archivo (.dat) ordenados por dni.

Como procedimientos finales:
- Grabar el archivo de índices.
- Liberar la memoria del índice.



# ANEXO

## TDA Indice (Array estático)
Construir un TDA **indice** (t_indice) en los archivos indice.h e indice.c, cuya estructura es un array donde cada elemento tiene la estructura  **{long dni; unsigned nro_reg;} (t_reg_indice)**. Cada entrada del índice (dni-nro_reg) se guarda en cada una de las posiciones del array.
Las primitivas del TDA son:
- __void ind_crear ( t_indice*)__: inicializa la estructura a indice_vacio.
- __int ind_insertar (t_indice*, const t_reg_indice*)__: inserta en orden según el dni `(1)`.
- __int ind_eliminar (t_indice*, t_reg_indice*)__: elimina el dni informado.`(1)`
- __int ind_buscar (const t_indice*, t_reg_indice* reg_ind)__: si el dni existe deja el registro en reg_ind;`(1)`
- __int ind_cargar (t_indice*, const char* path)__: Carga el array desde un archivo ordenado.`(1)`
- __int ind_grabar (const t_indice*, const char* path)__: Graba un archivo con el contenido del índice.`(1)`
- __void ind_vaciar(t_indice*)__: deja el índice en su estado de vacío.
- __int ind_primero(t_indice*, t_reg_indice* reg_ind)__: Deja el primer registro de índice en reg_ind.`(1)`
- __int ind_siguiente(t_indice*, t_reg_indice*)__: Deja el registro siguiente al último entregado en reg_ind.`(1)`
- __int ind_fin (const t_indice*)__: Devuelve verdad si la última operación de acceso secuencial no entregó el registro por haber llagado al fin de la secuencia y falso en caso contrario.
- __void ind_liberar(t_indice*)__: No aplica a la implementación (dejar vacía).

`(1)`: Devuelve 1 (uno) si la operación fue exitosa y 0 (cero) en caso contrario.

## TDA Indice (Array Redimensionable)
Construir un TDA ***indice*** (t_indice) en los archivos indice.h e indice.c, cuya estructura es un array dinámico donde cada elemento tiene la estructura  **{long dni; unsigned nro_reg;} (t_reg_indice)**. Cada entrada del índice (dni-nro_reg) se guarda en cada una de las posiciones del array.
Las primitivas del TDA son:
- void ind_crear ( t_indice * ): toma memoria para 100 elementos e inicializa la estructura a indice_vacio.
- __int ind_insertar (t_indice*, const t_reg_indice*)__: inserta en orden según el dni. Si no hay lugar en el array, tomar memoria para un 30 % más de lo que tenía.`(1)`
- __int ind_eliminar (t_indice*, t_reg_indice*)__: elimina el dni informado.`(1)`
- __int ind_buscar (const t_indice*, t_reg_indice* reg_ind)__: si el dni existe deja el registro en reg_ind.`(1)`
- __int ind_cargar (t_indice*, const char* path)__: Carga el array desde un archivo ordenado.`(1)`
- __int ind_grabar (const t_indice*, const char* path)__: Graba un archivo con el contenido del índice.`(1)`
- __void ind_vaciar(t_indice*)__: deja el índice en su estado de vacío.
- __int ind_primero(t_indice*, t_reg_indice* reg_ind)__: Deja el primer registro de índice en reg_ind.`(1)`
- __int ind_siguiente(t_indice*, t_reg_indice*)__: Deja el registro siguiente al último entregado en reg_ind.`(1)`
- __int ind_fin (const t_indice*)__: Devuelve verdad si la última operación de acceso secuencial no entregó el registro por haber llagado al fin de la secuencia y falso en caso contrario.
- __void ind_liberar(t_indice*)__: libera la memoria utilizada por el índice.

`(1)`: Devuelve 1 (uno) si la operación fue exitosa y 0 (cero) en caso contrario.

## TDA Indice (Lista simplemente enlazada)
Construir un TDA indice (t_indice) en los archivos indice.h e indice.c, cuya estructura contiene una lista simplemente enlazada y una cola.  Cada elemento de la lista (y de la cola) tiene la estructura  **{long dni; unsigned nro_reg;} (t_reg_indice)**. La lista simplemente enlazada se utiliza para guardar  las entradas (dni-nro_reg), mientras que la cola se la utiliza solo para recorrer los elementos del índice en las funciones ind_primero e ind_siguiente.
Las primitivas del TDA son: 
- __void  ind_crear ( t_indice*)__: Crea la lista y la cola.
- __int ind_insertar (t_indice*, const t_reg_indice*)__: inserta en la lista en orden según el dni..`(1)`
- __int ind_eliminar (t_indice*, t_reg_indice*)__: elimina el dni informado de la lista.
- __int ind_buscar (const t_indice*, t_reg_indice* reg_ind)__: si el dni existe en la lista deja el registro en reg_ind.
- __int ind_cargar (t_indice*, const char* path)__: Carga la lista desde un archivo ordenado.
- __int ind_grabar (const t_indice*, const char* path)__: Graba un archivo con el contenido del índice.
- __void ind_vaciar(t_indice*)__: deja el índice en su estado de vacío.
- __int ind_primero(t_indice*, t_reg_indice* reg_ind)__: Deja el primer registro de índice en reg_ind.
- __int ind_siguiente(t_indice*, t_reg_indice*)__: Deja el registro siguiente al último entregado en reg_ind.
- __int ind_fin (const t_indice*)__: Devuelve verdad si la última operación de acceso secuencial no entregó el registro por haber llagado al fin de la secuencia y falso en caso contrario.

`(1)`: Devuelve 1 (uno) si la operación fue exitosa y 0 (cero) en caso contrario.

## TDA Indice (Árbol)
Construir un TDA ***indice*** (t_indice) en los archivos indice.h e indice.c utilizando las mismas pautas que para una lista simplemente enlazada, pero utilizando un árbol en su lugar


