import serial
import serial.tools.list_ports

ports = serial.tools.list_ports.comports()
for port in ports:
    print(port.device)

# Configuração da porta serial (ajuste a porta conforme seu sistema)
# Exemplo: no Windows, pode ser 'COM3', 'COM4', etc. No Linux/Mac, algo como '/dev/ttyUSB0'
porta_serial = 'COM3'  # Porta correta
baud_rate = 9600  # Mesmo baud rate definido no Arduino

# Conexão com o Arduino
ser = serial.Serial(porta_serial, baud_rate)

# Lista para armazenar os valores de dB
valores_dB = []

print(valores_dB)