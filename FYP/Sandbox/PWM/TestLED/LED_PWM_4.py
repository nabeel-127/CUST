import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
GPIO.setup(12, GPIO.OUT)

led = GPIO.PWM(12, 200)
led.start(0)

for inc in range(0, 100, 25):
	led.ChangeDutyCycle(inc)
	time.sleep(1)

for dec in range(100, 0, -25):
	led.ChangeDutyCycle(dec)
	time.sleep(2)

GPIO.cleanup()
