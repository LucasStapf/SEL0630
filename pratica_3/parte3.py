import Adafruit_DHT
import time
import RPi.GPIO as GPIO

sensor = Adafruit_DHT.DHT11
pino_GPIO = 14 

while True:
    try:
        hum, temp = Adafruit_DHT.read_retry(sensor, pino_GPIO)
        str_temp = "{:.2f}".format(temp)
        str_hum = "{:.2f}".format(hum)

        print("Temperatura: " + str_temp + "ºC - umidade: " + str_hum + " %")
        time.sleep(1)
    except KeyboardInterrupt:
        GPIO.cleanup()
        exit()


    
