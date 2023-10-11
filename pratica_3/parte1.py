from gpiozero import PWMLED
from time import sleep

PIN = 15


led = PWMLED(PIN, frequency=100)

while True:
    for b in range(101):
        led.value = b/ 100.0
        sleep(0.02)
