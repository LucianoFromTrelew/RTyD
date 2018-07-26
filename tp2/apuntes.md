BPF -> Berkeley Packet Filter

```bash
tcpdump -i <interfaz (lo)> BPF
```

```bash
pip install -t . sh
```

```python
from sh import Command
tcpdump = Command("tcpdump")
tcpdump() #llamada sin argumentos
tcpdump(i="lo") #tcpdump -i lo
tcpdump(i="lo", _bg=True) #tcpdump -i lo &
p = tcpdump(i="lo", _bg=True)
```

```python
from sh import nc
n = nc("-l", p=8000, _bg=True)
```

```bash
! echo "hola" | nc localhost 8000
```

---

Cuando los paquetes van con las banderas `FIN` o `SYN`, el `SEQ` se incrementa en **1**.

Caso contrario (osea cuando la conexión ya está establecida y no está por cerrarse), el `SEQ` se incrementa con el largo del paquete.

---

Puertos altos los asigna automáticamente el SO

Flags (`tcpdump`):

* . -> ACK
* S -> SYN
* R -> RST
* F -> FIN
* P -> PSH?

---

### Guardar la salida de tcpdump en un archivo .pcap

```bash
tcpdump -i lo -w output.pcap
```

### Abrir la captura

```bash
tcpdump -n -r output.pcap
```

---

Wireshark -> statistics -> flow graph

---

KUROSE, 278. Tamaño de ventana, después del gráfico de autómata finito
