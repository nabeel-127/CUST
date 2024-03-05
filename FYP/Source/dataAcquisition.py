import smbus
#from smbus import SMBus
import time
import sys
sys.path.append('../')
from DFRobot_ADS1115 import ADS1115
import os

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

flowRate = 0.0
pressure = 0
data = " "

def setPressure():
    global pressure, flowRate
    if (flowRate > 0) and (flowRate < 12.4):
        pressure = 15
    elif (flowRate > 12.4) and (flowRate < 24.2):
        pressure = 15
    elif (flowRate > 24.2) and (flowRate < 35.5):
        pressure = 19
    elif (flowRate > 35.5) and (flowRate < 43.6):
        pressure = 25
    elif (flowRate > 43.6) and (flowRate < 54.3):
        pressure = 31
    elif (flowRate > 54.3) and (flowRate < 63.8):
        pressure = 37
    elif (flowRate > 63.8) and (flowRate < 73.0):
        pressure = 43
    elif (flowRate > 73.0) and (flowRate < 80.9):
        pressure = 50
    elif (flowRate > 80.9) and (flowRate < 85.6):
        pressure = 55
    elif flowRate > 85.6:
        pressure = 62

time.sleep(1)

try:
    while True:
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
        #print "A0:%dmV A1:%dmV A2:%dmV A3:%dmV"%(adc0['r'],adc1['r'],adc2['r'],adc3['r'])
        setPressure()
        
        time.sleep(0.2)
        
        try:
            bus.write_byte(addr, 0x10)
            bus.write_byte(addr, 0x00)
            time.sleep(.01)
            dataLIST = bus.read_i2c_block_data(addr, 0, 2)
            flowData = float((dataLIST[0]<<8) | dataLIST[1])
            flowRate = float((flowData - 32000) / 140)
        except IOError:
            pass
            #subprocess.call(['i2cdetect', '-y', '1'])
        
        time.sleep(0.2)

        data = str(flowRate) + "," + str(pressure) + "," + str(adc1['r']) + "," + str(adc2['r']) + "," + str(adc3['r'])
        file = open("/home/pi/Desktop/FINAL/data/sensorData.txt", "w")
        file.write(data)
        file.close()

except KeyboardInterrupt:
    os.system('clear')
finally:
    bus.close()
