# Proyecto_POO_Asteroid
Se trata del proyecto final de la materia POO de las Ingenierias: en Informatica y en Inteligencia Artificial de la FICh
Integrantes: Grandoli, Leonel; Medina, Juan Francisco  






-----------------------------------------------------------------------------------------------------
Fran: Se Agrego una implementacion basica de settings a la navesita, se pueden cambiar los controles desde el archivo de texto. 
Esta en la rama el cambio, no esta agregado al main. Es muy basico.

30/12/24

d86e35d (nuevo_asteroide): Ligeros cambios en el main e implementacion de bucles para hacer que los asteroides funcionen en base a un vector.
-G.

2c4d7eb (nuevo_asteroide):  Se crearon los argumentos speed y size para la clase asteroid, se crearon clases para generar valores de estos tipos, se reescribieron todas las funciones para variar en base a los valores de tamaño de asteroides...

263f3e5 (nuevo_asteroide):  ... se elimino la funcion respawn y se reprogramo desde cero utilizando las nuevas funciones de asteroid, ubicado en el archivo a_manip, al igual que la funcion respawn. se reprogramo el constructor, la textura se encuentra declarada en el main como puntero...

83f2788 (nuevo_asteroide):  ... ahora utilizando estas funciones se puede generar y relocalizar un vector completamente aleatoria de asteroides con velociddad y tamaño variante... 
cansado de la vida -G.   

36d9829 / ab33400 (nuevo_asteroide): se añadieron valores como hp e id para facilitar el manejo y trabajar a futuro con la funcion destruccion creada
-G 

30/12/24

(puntaje): creada branch puntaje, los asteroides estan listos, espero a la funcion disparo de la nave y r de la nave. Por ende empiezo a trabajar en el sistema de puntaje.
-G

<<<<<<< HEAD
31/12/24
6b99b8b (puntaje): la clase tabla_de_puntos funciona en base a c_string para facilitar su uso en manejo de archivos; se creo un constructor, funcion para actualizar el .bin y para actualizar los puntos y nombre.
-G

36e0906 (puntaje): se creo el metodo para recibir el nombre (string) ahora funciona en base a c_strimg. usando la funcion strncopy.
-G

    
=======
02/01/2025 5ed2b29 (archivo_setting)

Se implementa la rama setting con la funcionalidad de obtenerControles lista para usar. Esta funcionando, podes cambiar los controles, le agregue las flechas en el formato "Flecha-(Direccion)" siempre la direccion sin abreviar y con mayuscula al inicio. Parecia al principio mas trabajoso, pero resulto ser bastante practico, una vez que entendes como funciona la carga desde el archivo y la busqueda de los strings, es facil de ampliar

-M. 
<<<<<<< HEAD
>>>>>>> main
=======

16/01/2025 61e2d1 (main)

Se implementa clase abstracta efecto.h, clase OndaConcentrica, funcionamiento del efecto de colision de la nave

-M

18/01/2025 94a03de (main)

Reestructuracion funcion RNG, se agrega rng.cpp
Se agrega AsteroideExplosion (.h y .cpp) ya implementados
Cambios en ast_manip para la generacion del efecto de explosion
Se implementa la eliminacion del efecto. Se utiliza STL
Se agrega la clase Particula con .h y .cpp. Se implementan todos sus metodos
Queda implementado y completamente funcional el efecto de explosion del asteroide
Es el commit mas significativo, el otro no hice grandes cambios. Este es el pesado

-M

>>>>>>> main
