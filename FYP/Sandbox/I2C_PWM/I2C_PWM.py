from Tkinter import *
import tkFont
import RPi.GPIO as GPIO
import time
import smbus

bus = smbus.SMBus(1)
addr = 0x40
addrREAD = 0x81
i = 0

dutyCycle = 0;
LED_state = 0;
FLOW = 0;

GPIO.setmode(GPIO.BOARD)
GPIO.setup(32, GPIO.OUT)
#GPIO.output(32, GPIO.LOW)

led = GPIO.PWM(32, 3000)
led.start(0)

win = Tk()

myFont = tkFont.Font(family = 'Helvetica', size = 18, weight = 'bold')



def increment():
    global dutyCycle
    print("INC Button pressed")
    if (dutyCycle < 90):
        dutyCycle += 10;
    led.ChangeDutyCycle(dutyCycle)
    PWM = Label(win, text = dutyCycle, font = myFont).place(x = 500 , y = 250)
    PWMA = Label(win, text = "%", font = myFont).place(x = 530 , y = 250)

def decrement():
    global dutyCycle
    print("DEC Button pressed")
    if (dutyCycle >= 10):
        dutyCycle -= 10;
    led.ChangeDutyCycle(dutyCycle)
    PWM = Label(win, text = dutyCycle, font = myFont).place(x = 500 , y = 250)
    PWMA = Label(win, text = "%", font = myFont).place(x = 530 , y = 250)

def ledON():
    global dutyCycle
    print("LED Button pressed")
    if (dutyCycle < 10):
        dutyCycle = 10;
        led.ChangeDutyCycle(dutyCycle)
        ledButton["text"] = "POWER ON"
    else:
        led.ChangeDutyCycle(0)
        dutyCycle = 0;
        ledButton["text"] = "POWER OFF"
        #LED_state = 0;
    PWM = Label(win, text = dutyCycle, font = myFont).place(x = 500 , y = 250)
    PWMA = Label(win, text = "%", font = myFont).place(x = 530 , y = 250)

def exitProgram():
    print("Exit Button pressed")
    GPIO.cleanup()
    win.quit()
    
def i2c():
    
    global FLOW
    bus.write_byte(addr, 0x10)
    bus.write_byte(addr, 0x00)
    time.sleep(.01)
    dataLIST = bus.read_i2c_block_data(addr, 0, 2)
    data = (dataLIST[0]<<8) | dataLIST[1]
    
    FLOW = (data - 32000) / 140
    print(FLOW)



win.title("Initial GUI")
win.geometry('1024x600')

exitButton = Button(win, text = "Click for value", font = myFont, command = i2c, height = 2, width = 16)
exitButton.pack(side = BOTTOM)
 
ledButton = Button(win, text = "POWER ON", font = myFont, command = ledON, height = 2, width = 12)
ledButton.pack()


#PWM = Label(win, text = dutyCycle, font = myFont).place(x = 500 , y = 250)
#PWMA = Label(win, text = "%", font = myFont).place(x = 530 , y = 250)
    
incButton = Button(win, text = "PWM INC", font = myFont, command = increment, height = 2, width = 10)
incButton.pack(side = RIGHT)

decButton = Button(win, text = "PWM DEC", font = myFont, command = decrement, height = 2, width = 10)
decButton.pack(side = LEFT)



mainloop()





