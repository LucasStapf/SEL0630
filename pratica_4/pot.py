from smbus import SMBus

addr = 0x8
bus = SMBus(1)

try:
    while True:
        low_byte = bus.read_byte(addr)
        high_byte = bus.read_byte(addr)

        val_completo = (high_byte << 2) | low_byte

        print(f"Valor recebido: {val_completo}")
except KeyboardInterrupt:
    print("Programa terminado")
    pass

bus.close()


