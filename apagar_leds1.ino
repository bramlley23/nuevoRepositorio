import network
import time
from machine import Pin, ADC
from umqtt.simple import MQTTClient

# Configuración WiFi
SSID = 'Nombre WiFi'
PASSWORD = 'Contraseña'

# Configuración MQTT
MQTT_SERVER = 'broker.emqx.io'
PORT = 1883
CLIENT_ID = 'arduinoClient'
TOPIC_SUB = b'Entrada/01'
TOPIC_PUB = b'Salida/01'

# Pines
led_pin = Pin(26, Pin.OUT)  # LED en pin 26
photoresistor = ADC(Pin(33))  # Fotoresistor en pin 33
photoresistor.atten(ADC.ATTN_11DB)  # Permite rango completo (0-3.6V)

# Variables globales
var = 0
resultS = ""

def connect_wifi():
    wlan = network.WLAN(network.STA_IF)
    wlan.active(True)
    wlan.connect(SSID, PASSWORD)

    print(f"Conectándose a {SSID}...")
    while not wlan.isconnected():
        print(".", end="")
        time.sleep(0.5)

    print("\nConectado a WiFi")
    print("Dirección IP:", wlan.ifconfig()[0])

def mqtt_callback(topic, msg):
    global var, resultS
    print(f"Mensaje recibido [{topic.decode()}] {msg.decode()}")

    try:
        var = int(msg.decode())
    except:
        var = 0
    
    resultS = msg.decode()

def mqtt_connect():
    client = MQTTClient(CLIENT_ID, MQTT_SERVER, PORT)
    client.set_callback(mqtt_callback)
    client.connect()
    client.subscribe(TOPIC_SUB)
    print("Conectado al broker MQTT y suscrito al tópico")
    return client

# Inicio
connect_wifi()
mqtt_client = mqtt_connect()

while True:
    if mqtt_client:
        mqtt_client.check_msg()  # Revisa nuevos mensajes MQTT

    print("String:", resultS)

    if var == 0:
        led_pin.off()
    elif var == 1:
        led_pin.on()

    photo_value = photoresistor.read()
    print("Foto:", photo_value)

    message = f"Valor fotoresistencia: {photo_value}"
    mqtt_client.publish(TOPIC_PUB, message)

    time.sleep(5)

