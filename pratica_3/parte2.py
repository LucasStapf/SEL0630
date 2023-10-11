from gpiozero import DistanceSensor, LED
import time

sensor = DistanceSensor(echo=23, trigger=24)
led = LED(20)

sensor.when_in_range = led.on
sensor.when_out_of_range = led.off

while True:
    print("distance is:", sensor.distance, "m")
    time.sleep(1)

