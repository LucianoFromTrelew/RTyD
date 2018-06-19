Las direcciones MAC se manejan siempre dentro de la misma red. Son visibles dentro de la subred.

#### Punto 1

La comunicación se hace en dos pasos:
    1. Desde el host 1 al router
    2. Desde el router al host 2

**Entre cada paso hay un cambio de trama (se cambia la dirección MAC de destino)**

ARP necesita de IP para asociar una IP con una MAC


#### Punto 2
El hub recibe una trama y la replica por todos los hosts (ES UN REPETIDOR)
El switch es un poquito más vivo y lo hace llegar a la rama correcta

Dominio de colisión => "Pasillo" por el que todas las tramas convergen
