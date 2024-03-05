import smbus
#from smbus import SMBus
import time
import sys
sys.path.append('../')
#import time
from DFRobot_ADS1115 import ADS1115
from Tkinter import *
import tkFont
import RPi.GPIO as GPIO
import random
from itertools import count
import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import os

"""
#Setup
"""
#SMBus
bus = smbus.SMBus(1)
addr = 0x40
#DFRobot
ADS1115_REG_CONFIG_PGA_6_144V        = 0x00 # 6.144V range = Gain 2/3
ADS1115_REG_CONFIG_PGA_4_096V        = 0x02 # 4.096V range = Gain 1
ADS1115_REG_CONFIG_PGA_2_048V        = 0x04 # 2.048V range = Gain 2 (default)
ADS1115_REG_CONFIG_PGA_1_024V        = 0x06 # 1.024V range = Gain 4
ADS1115_REG_CONFIG_PGA_0_512V        = 0x08 # 0.512V range = Gain 8
ADS1115_REG_CONFIG_PGA_0_256V        = 0x0A # 0.256V range = Gain 16
ads1115 = ADS1115()
#GPIO
dutyCycle = 10;
LED_state = 0;
GPIO.setmode(GPIO.BOARD)
GPIO.setup(32, GPIO.OUT)
led = GPIO.PWM(32, 3000)
led.start(10)
#Tkinter
win = Tk()
myFont = tkFont.Font(family = 'Helvetica', size = 18, weight = 'bold')



"""
#Main
"""
try:
    while True:
        bus.write_byte(addr, 0x10)
        bus.write_byte(addr, 0x00)
        time.sleep(.01)
        dataLIST = bus.read_i2c_block_data(addr, 0, 2)
        data = (dataLIST[0]<<8) | dataLIST[1]
        FLOW = (data - 32000) / 140
        #print(FLOW)
    
        time.sleep(.1)
    
        #Set the IIC address
        ads1115.setAddr_ADS1115(0x48)
        #Sets the gain and input voltage range.
        ads1115.setGain(ADS1115_REG_CONFIG_PGA_6_144V)
        #Get the Digital Value of Analog of selected channel
        adc0 = ads1115.readVoltage(0)
        time.sleep(0.2)
        adc1 = ads1115.readVoltage(1)
        time.sleep(0.2)
        adc2 = ads1115.readVoltage(2)
        time.sleep(0.2)
        adc3 = ads1115.readVoltage(3)
        print "A0:%dmV A1:%dmV A2:%dmV A3:%dmV"%(adc0['r'],adc1['r'],adc2['r'],adc3['r'])

        data = str(FLOW) + "," + str(adc0['r']) + "," + str(adc1['r']) + "," + str(adc2['r']) + "," + str(adc3['r'])
        file = open("data/sensorData.txt", "w")
        file.write(data)
        file.close()
    
except KeyboardInterrupt:
    os.system('clear')
finally:
    bus.close()
    GPIO.cleanup()
