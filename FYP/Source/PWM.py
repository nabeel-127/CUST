import RPi.GPIO as GPIO
import time
import os

GPIO.setmode(GPIO.BOARD)
GPIO.setup(32, GPIO.OUT)
led = GPIO.PWM(32, 1000)
led.start(0)
GPIO.setup(40, GPIO.OUT)
GPIO.output(40, GPIO.HIGH)
VC_BPM = 10
VC_E = 1
VC_Volume = 0.0
VC_SLM = 0.0
#VC_IE = 1.0
VC_range = 0.0
VC_I_time = 0.0
VC_E_time = 0.0
VC_dutyCycle = 0
dutyCycle = 0
dutyCycleLIMIT = 85

#5, 20
#10, 26
#15, 29
#20, 32
#25, 36
#30, 37
#35, 38
#40, 39
#45, 40
#50, 40
#55, 41
#60, 42
#65, 42.5
#70, 43

def setPWM():
    global dutyCycle, dutyCycleLIMIT
    if dutyCycle > dutyCycleLIMIT:
        dutyCycle = dutyCycleLIMIT
    elif dutyCycle < 0:
        dutyCycle = 0
    #print(dutyCycle)
    led.ChangeDutyCycle(dutyCycle)
def VC_setPWM():
    global VC_dutyCycle, VC_SLM
    if VC_SLM > 0 and VC_SLM < 23:
        VC_dutyCycle = 5
    elif (VC_SLM >= 23) and (VC_SLM < 28.5):
        VC_dutyCycle = 10
    elif (VC_SLM >= 28.5) and (VC_SLM < 30.5):
        VC_dutyCycle = 15
    elif (VC_SLM >= 30.5) and (VC_SLM < 34):
        VC_dutyCycle = 20
    elif (VC_SLM >= 34) and (VC_SLM < 36.5):
        VC_dutyCycle = 25
    elif (VC_SLM >= 36.5) and (VC_SLM < 37.5):
        VC_dutyCycle = 30
    elif (VC_SLM >= 37.5) and (VC_SLM < 38.5):
        VC_dutyCycle = 35
    elif (VC_SLM >= 38.5) and (VC_SLM < 39.5):
        VC_dutyCycle = 40
    elif (VC_SLM >= 39.5) and (VC_SLM < 40.25):
        VC_dutyCycle = 45
    elif (VC_SLM >= 40.25) and (VC_SLM < 40.75):
        VC_dutyCycle = 50
    elif (VC_SLM >= 40.75) and (VC_SLM < 41.5):
        VC_dutyCycle = 55
    elif (VC_SLM >= 41.5) and (VC_SLM < 42.25):
        VC_dutyCycle = 60
    elif (VC_SLM >= 42.25) and (VC_SLM < 42.75):
        VC_dutyCycle = 65
    elif (VC_SLM >= 42.75) and (VC_SLM < 43):
        VC_dutyCycle = 70
    elif VC_SLM >= 43:
        VC_dutyCycle = 75

try:
    while True:
        file_parameters = open("data/parameters.txt", "r")
        dataList = file_parameters.read().split(',')
        file_parameters.close()
        
        if dataList[0] == '0':
            dutyCycle = 0
            setPWM()

        elif dataList[0] == '1':
            file_CPAP = open("data/CPAP.txt", "r")
            dataListCPAP = file_CPAP.read().split('\n')
            file_CPAP.close()
            for eachLine in dataListCPAP:
                if len(eachLine) > 0:
                    dutyCycle = float(dataListCPAP[0])
            setPWM()

        elif dataList[0] == '2':
            file_VC = open("data/VC.txt", "r")
            dataListVC = file_VC.read().split('\n')
            file_VC.close()
            for eachLine in dataListVC:
                if len(eachLine) > 0:
                    VC_BPM, VC_E, VC_Volume = eachLine.split(',')
                    VC_BPM = float(VC_BPM)
                    VC_E = float(VC_E)
            VC_range = 60 / VC_BPM
            VC_I_time = (1 / (VC_E + 1)) * VC_range
            VC_E_time = (VC_E / (VC_E + 1)) * VC_range
            VC_SLM = (float(VC_Volume) / 1000) * 60
            VC_setPWM()
            dutyCycle = VC_dutyCycle
            setPWM()
            GPIO.output(40, GPIO.HIGH)
            time.sleep(VC_I_time)
            
            dutyCycle = 0
            setPWM()
            GPIO.output(40, GPIO.LOW)
            time.sleep(VC_E_time)



except KeyboardInterrupt:
    GPIO.cleanup()
    os.system('clear')
#finally:
    #GPIO.cleanup()
