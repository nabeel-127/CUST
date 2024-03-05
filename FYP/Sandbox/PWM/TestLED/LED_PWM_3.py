import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
GPIO.setup(12, GPIO.OUT)

led = GPIO.PWM(12, 200)
led.start(0)

led.ChangeDutyCycle(25)
time.sleep(3)

led.ChangeDutyCycle(50)
time.sleep(3)

led.ChangeDutyCycle(75)
time.sleep(3)

led.ChangeDutyCycle(99)
time.sleep(3)

GPIO.cleanup()


