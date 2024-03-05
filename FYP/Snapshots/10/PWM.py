import RPi.GPIO as GPIO
import time


GPIO.setmode(GPIO.BOARD)
GPIO.setup(32, GPIO.OUT)
led = GPIO.PWM(32, 1000)
led.start(10)

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
        led.ChangeDutyCycle(dutyCycle)
        
        
except KeyboardInterrupt:
    GPIO.cleanup()
#finally:
    #GPIO.cleanup()
