## ARP

### Request
    |MAC|IP|
    |---|--|
    |||

Se van a hacer consultas ARP antes de que fluja cualquier tráfico. Se tienen que conocer las MAC

### Reply


## DHCP

Corre sobre UDP.

El cliente **sale por el puerto 68**
El servidor escucha en el **puerto 67**

1) Discover
2) Offer
    Dirección IP
    Puerta de enlace predeterminada
    Dirección de Router
    Servidor de DNS
    Nombres
3) Request
    Se envía lo mismo que en el Offer
4) ACK. Recién acá el cliente tiene IP


## NAT

Para probar en CORE, ejecutar en el nodo que hace NAT (el router mayormente)

```bash
netstat-nat -n
```


|Dirección origen|Dirección local|
|----------------|---------------|
|10.0.0.10:32678|10.1.1.1:32678|
                         (Casualidad de CORE,
                         el puerto de salida
                         puede ser distinto)
