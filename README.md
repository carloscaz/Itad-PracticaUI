# UTAD-UI-FPS-Public
  
# Documentacion Practica UI Carlos Caz Pretus

- PlayerHealthBar: La lógica del playerHealthBar consiste en una comprobación en cad tick para saber si el player tiene poca vida.
En caso de que se cumpla esta condición, la barra de vida del player comienza a parpadear alternando entre los colores rojo y verde.

- CrossHair: Para la animación del crosshair, he hecho uso de la función SetBrushSize. Si embargo, a pesar de fijar diferentes valores de tamaño en el crosshair, no he dado con la razón de por qué el crosshair no modifica su tamaño.
Además, el player lanza un raycast hacia delante y en caso de detectar el raycast al enemigo, se lanza la función SetCrosshairColor que modifica el color del mismo.

- PlayerHitMarker: El playerHitMarker consiste en un widget que se muestra cuando el jugador recibe daño.
Esto se lleva a cabo a través de su función show, que se llama desde el player.

- Pantalla splash: Esta pantalla se muestra al inicio del juego durante unos segundos y pasado ese tiempo unicamente se esconde.

- Arbol de habilidades: El arbol de habilidades se ha planteado como un widget compuesto por una serie de botones. 
De inicio, los botones de lv1 estan todos activados, mientras que el resto de botones estan desactivados. A medida que se pulsa un boton, el siguiente en la jerarquia se activa.
Además, con cada pulsación de un boton de habilidades, se pierde un punto de habilidad.
Por ultimo, el widget cuenta con una función cancelMenu que devuelve los elementos a su estado anterior y un conformationMenu que guarda el estado de los elementos del widget.
