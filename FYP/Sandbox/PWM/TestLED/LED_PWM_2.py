import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
GPIO.setup(12, GPIO.OUT)

led = GPIO.PWM(12, 500)
led.start(0)

for inc in range(50, 100, 1):
	led.ChangeDutyCycle(inc)
	time.sleep(.1)

time.sleep(3)

for dec in range(95, 0, 5):
	led.ChangeDutyCycle(dec)
	time.sleep(.1)

time.sleep(3)

GPIO.cleanup()
