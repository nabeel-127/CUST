import RPi.GPIO as GPIO
import time
import os

GPIO.setmode(GPIO.BOARD)
GPIO.setup(32, GPIO.OUT)
GPIO.setup(40, GPIO.OUT)
led = GPIO.PWM(32, 1000)
led.start(0)
GPIO.output(40, GPIO.LOW)
dutyCycle = 0

try:
    while True:
        file = open("data/PWM.txt","r")
        dataList = file.read().split('\n')
        file.close()
        for eachLine in dataList:
            if len(eachLine) > 0:
                dutyCycle = float(eachLine)
                #print(dutyCycle)
                if dutyCycle > 50:
                    dutyCycle = 50
        #print(dutyCycle)
        #dutyCycle = 0
        led.ChangeDutyCycle(dutyCycle)
        time.sleep(2)
        GPIO.output(40, GPIO.HIGH)
        time.sleep(2)
        GPIO.output(40, GPIO.LOW)
        
except KeyboardInterrupt:
    GPIO.cleanup()
    os.system('clear')
#finally:
    #GPIO.cleanup()
