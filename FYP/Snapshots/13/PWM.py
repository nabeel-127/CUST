import RPi.GPIO as GPIO
import time
import os

GPIO.setmode(GPIO.BOARD)
GPIO.setup(32, GPIO.OUT)
GPIO.setup(40, GPIO.OUT)
led = GPIO.PWM(32, 1000)
led.start(0)
GPIO.output(40, GPIO.LOW)
VC_BPM = 0
VC_E = 0
VC_IE = 1.0
dutyCycle = 0

try:
    while True:
        file_parameters = open("data/parameters.txt", "r")
        dataList = file_parameters.read().split(',')
        file_parameters.close()
        
        if dataList[0] == '0':
            dutyCycle = 0
            
        elif dataList[0] == '1':
            file_CPAP = open("data/CPAP.txt", "r")
            dataListCPAP = file_CPAP.read().split('\n')
            file_CPAP.close()
            for eachLine in dataListCPAP:
                if len(eachLine) > 0:
                    dutyCycle = float(dataListCPAP[0])

        elif dataList[0] == '2':
            file_VC = open("data/VC.txt", "r")
            dataListVC = file_VC.read().split('\n')
            file_VC.close()
            for eachLine in dataListVC:
                if len(eachLine) > 0:
                    VC_BPM, VC_E = eachLine.split(',')
                    VC_BPM = float(VC_BPM)
                    VC_E = float(VC_E)
            VC_range = 60 / VC_BPM
            #print(VC_range)
            VC_I_time = (1 / (VC_E + 1)) * VC_range
            VC_E_time = (VC_E / (VC_E + 1)) * VC_range
            #print(VC_I_time)
            #print(VC_E_time)

        if dutyCycle > 40:
            dutyCycle = 40
        elif dutyCycle < 0:
            dutyCycle = 0
        led.ChangeDutyCycle(dutyCycle)
        """
        time.sleep(2)
        GPIO.output(40, GPIO.HIGH)
        time.sleep(2)
        GPIO.output(40, GPIO.LOW)
        """
        
except KeyboardInterrupt:
    GPIO.cleanup()
    os.system('clear')
#finally:
    #GPIO.cleanup()
