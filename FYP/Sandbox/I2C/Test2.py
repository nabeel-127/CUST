import smbus
#from smbus import SMBus
import time

bus = smbus.SMBus(1)
addr = 0x40
addrREAD = 0x81
i = 0

while i < 8196:

    bus.write_byte(addr, 0x10)
    bus.write_byte(addr, 0x00)
    time.sleep(.01)
    dataLIST = bus.read_i2c_block_data(addr, 0, 2)
    data = (dataLIST[0]<<8) | dataLIST[1]
    
    FLOW = (data - 32000) / 140
    print(FLOW)
    
    i = i + 1

#i = 0;
#while i < 100:
    #data = bus.read_byte_data(addr, addrREAD)
#    data = bus.read_i2c_block_data(addr1, addrREAD, 8)
#    print(data)
#    i = i + 1
    
    
    
bus.close()
