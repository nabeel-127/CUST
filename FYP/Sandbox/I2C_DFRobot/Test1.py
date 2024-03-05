import sys
sys.path.append('../')
import time
import RPi.GPIO as GPIO
from DFRobot_ADS1115 import ADS1115

ADS1115_REG_CONFIG_PGA_6_114V = 0x00
ADS1115_REG_CONFIG_PGA_4_096V = 0x02
ADS1115_REG_CONFIG_PGA_2_048V = 0x04
ADS1115_REG_CONFIG_PGA_1_024V = 0x06
ADS1115_REG_CONFIG_PGA_0_512V = 0x08
ADS1115_REG_CONFIG_PGA_0_256V = 0x0A
ads1115 = ADS1115()

while True:
    ads1115.setAddr_ADS1115(0x48)
    ads1115.setGain(ADS1115_REG_CONFIG_PGA_6_144V)
    adc0 = ads1115.readVoltage(0)
    v = adc0['r'] * (3.3 / 65535.0)
    dist = v
    print("Distanz: %.2f cm"%dist)
    time.sleep(.2)
    


