1. A dónde quiero llegar
    - Bits de red ó hosts (máscara /32)
2. Cuál es el próximo salto
    - Dirección IP del proximo router con el que te vas a encontrar

Si se quiere evitar tabla de ruteo -> *Default Gateway*


En una tabla de ruteo, pueden suceder dos casos particulares:
    - Aparece un `0.0.0.0` del lado derecho: la dirección del lado izquierdo es la *dirección de red* (el nodo ya está conectado directamente a esa red por alguna de sus interfases)
    - Aparece un `0.0.0.0` del lado izquierdo: *Default Gateway* => Significa que cualquier paquete que no caiga en las reglas anteriores se debe encaminar a la dirección de la derecha

---

HOSTS:
- A (10.0.0.10/24)
- D (10.0.2.10/24)
- F (10.0.1.3/24)

ROUTERS:
- B (10.0.0.1/24 y 10.0.1.1/24)
- C (10.0.1.2/24 y 10.0.2.1/24)


|A          |HOP         |
|-----------|------------|
|10.0.0.0/24| -          |
|10.0.2.0/24|10.0.0.1/24 |
|10.0.1.3/32|10.0.0.1/24 |

|B          |HOP         |
|-----------|------------|
|10.0.0.0/24|-           |
|10.0.1.0/24|-           |
|10.0.2.0/24|10.0.1.2/24 |

|C          |HOP         |
|-----------|------------|
|10.0.1.0/24|-           |
|10.0.2.0/24|-           |
|10.0.0.0/24|10.0.1.1/24 |

|D          |HOP         |
|-----------|------------|
|10.0.2.0/24|-           |
|10.0.0.0/24|10.0.2.1/24 |

|F           |HOP         |
|------------|------------|
|10.0.1.0/24 |-           |
|10.0.0.10/32|10.0.1.1/24 |
