## DHCP

**Un único DHCP por RED**

**BPF para DHCP => `bootp`**

### Conceptos

#### Leasing

Préstamo de un recurso (dirección IP).

Si el cliente tarda mucho en contestar, cuando quiera aceptar la oferta puede ser que le hayan dado la IP a otro cliente

- Tiempo de *leasing* (`default-lease-time`): tiempo que dura el préstamo
- Tiempo máximo de *leasing* (`max-lease-time`): tiempo máximo que dura la asignación de una IP


El servidor identifica los clientes por la dirección **MAC**

### Handshake

**OJOTA CON LOS `Transaction ID`. Siempre ver ese valor para identificar qué mensaje pertenecen a la misma negociación**

1) Cliente hace `DHCP Discover` a la dirección de broadcast (255.255.255.255)
    - Tipo de mensaje: 1
    - Un host antes de tener una IP, igualmente está en la red y puede enviar un mensaje de broadcast
    - Los mensajes DHCP viajan sobre **UDP**
    - **El cliente no tiene IP, su mensaje sale por el puerto 68 y va hacia el puerto 67**
    - Campo `OPTIONS`: el cliente solicita conocer un montón de valores de la red
        - Dirección IP
        - Máscara de subred
        - Router
        - Puerta de enlace predeterminada
        - Servidor de DNS
2) "Servidor" DHCP (que sí tiene IP) le contesta un `DHCP Offer` y le ofrece una dirección IP (el mensaje va destinado a una dirección IP, que sería la IP de la máquina solicitante)
    - Tipo de mensaje: 2
    - Acá se sabe una potencial IP para el cliente, y qué IP tiene el servidor
3) Cliente acepta la oferta con un `DHCP Request`
4) "Servidor" se la concede con un `DHCP ACK`


Los ISP trabajan también con DHCP para asignar IPs a los clientes

#### Campos relevantes

- Puertos origen/destino
- El `DHCP Discover` va con IP origen 0.0.0.0 y destino 255.255.255.255
- El `DHCP Offer` va con IP origen 192.168.3.1 (por ej, siendo la red 192.168.3.0/24; es la IP del servidor DNS)
- Qué se pide
    - DNS
    - IPs
    - MTU del enlace
    - **Lease time**
    - Servidor de horario
    - Imagen de arranque
    - NETBios



## ARP

##### ARP ES SOBRE LA MISMA SUBRED

> ARP es sobre el mismo cablecito. -Nahuel Defossé

---

##### Antes de hacer PING, hay que saber las MAC

**Dominio de colisión**: interfases conectadas al mismo cable

Traceroute le importa MAC??? No monito, no le calienta para nada. Una MAC nunca va a salir de la máquina

**Tabla ARP**: tabla clave/valor:
    - MAC : Dirección IPv[4|6]

Primeros mensajes cuando se prende un host en una red
1) [BROADCAST] Quién tiene la IP X (ARP)
2) Respuesta ARP: `La IP X la tiene la MAC A` 
3) Ping
4) [BROADCAST] Quién tiene la IP Y (ARP)
5) Respuesta ARP: `LA IP Y la tiene la MAC B`
6) Ping

Para ver las tablas ARP del host
```bash
arp -n
```

