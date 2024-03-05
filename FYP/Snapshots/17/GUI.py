# The code for changing pages was derived from: http://stackoverflow.com/questions/7546050/switch-between-two-frames-in-tkinter
# License: http://creativecommons.org/licenses/by-sa/3.0/   
import random
from itertools import count
import pandas as pd
import matplotlib.pyplot as plt
#from matplotlib.animation import FuncAnimation
plt.style.use('fivethirtyeight')
import os
import matplotlib
matplotlib.use("TkAgg")
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg, NavigationToolbar2TkAgg
from matplotlib.figure import Figure
import matplotlib.animation as animation
from matplotlib import style
import tkinter as tk
from tkinter import ttk
import tkinter.font as font
from subprocess import call
import time
import multiprocessing



font_mainButton = ("Verdana", 20)
font_mainHeading = ("Verdana", 30)
font_subHeading = ("Verdana", 25)
font_info = ("Verdana", 20)
bg_color_mainButton = "thistle3"
fg_color_mainButton = "black"
bg_color_exitButton = "red2"
#style.use("dark_background")
style.use("ggplot")

f = Figure(figsize=(20,7), dpi=50)
x = f.add_subplot(211)
f1 = Figure(figsize=(20,7), dpi=50)
y = f.add_subplot(212)

x_vals = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36 ,37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60]
y_vals = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
flowList = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
pressureList = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
parameters = [0, 0, 0]
modeSelect = 0
CPAP_dutyCycle = 0
CPAP_enabled = False
VC_enabled = False
VC_BPM = 10
VC_E = 1
#VC_IE = 1.0
VC_Volume = 0.0


def getData():
    pullData = open("data/sensorData.txt","r").read()
    dataList = pullData.split('\n')
    for eachLine in dataList:
        if len(eachLine) > 0:
            a, b, c, d, e = eachLine.split(',')
            flowList.append(float(a))
            flowList.pop(0)
            pressureList.append(int(b))
            pressureList.pop(0)

def animatea(i):
    getData()
    x.clear()
    x.plot(x_vals, flowList)
    #plt.ylim([0, 100])
    x.set_ylim([0, 70])        
def animateb(i):
    getData()
    y.clear()
    y.plot(x_vals, pressureList)
    #plt.ylim([0, 100])
    y.set_ylim([0, 3400])
    
def updateFlow(label):
    def updateflow():
        getData()
        out = "Flow: " + str(round((flowList[len(flowList) - 1]), 3)) + " SLM"
        #print(flowList[0])
        label.config(text = out)
        label.after(200, updateflow)
    updateflow()
def updatePressure(label):
    def updatepressure():
        getData()
        out = "Pressure: " + str(round((pressureList[len(pressureList) - 1]), 3)) + " cmH2O"
        #print(pressureList[0])
        label.config(text = out)
        label.after(200, updatepressure)
    updatepressure()

def write_modeSelect(mode):
    global modeSelect, parameters
    modeSelect = mode
    parameters[0] = modeSelect
    out = str(parameters[0]) + "," + str(parameters[1]) + "," + str(parameters[2])
    file = open("data/parameters.txt", "w")
    file.write(str(out))
    file.close()

def updateCPAP_label1(label):
    def updateCPAP__label1():
        global CPAP_dutyCycle
        #print(flowList[0])
        out = "PWM: " + str(CPAP_dutyCycle) + " %"
        label.config(text = out)
        label.after(200, updateCPAP__label1)
    updateCPAP__label1()
def updateCPAP_button(button):
    global CPAP_enabled, CPAP_dutyCycle
    if CPAP_enabled == True:
        CPAP_dutyCycle = 0
        button.config(text = "Start", bg = "green2", fg = "black")
        CPAP_enabled = False
        write_modeSelect(0)
    else:
        CPAP_dutyCycle = 10
        button.config(text = "Stop", bg = "red", fg = "black")
        CPAP_enabled = True
        write_modeSelect(1)
    write_CPAP()
def CPAP_Func(PWM):
    global CPAP_dutyCycle
    if CPAP_enabled == True:
        CPAP_dutyCycle = CPAP_dutyCycle + PWM
    else:
        CPAP_dutyCycle = 0
    if CPAP_dutyCycle > 90:
        CPAP_dutyCycle = 90
    elif (CPAP_dutyCycle < 5) and (CPAP_enabled == False):
        CPAP_dutyCycle = 0
    elif CPAP_dutyCycle < 5:
        CPAP_dutyCycle = 5
    write_CPAP()
def write_CPAP():
    global CPAP_dutyCycle
    file = open("data/CPAP.txt", "w")
    file.write(str(CPAP_dutyCycle))
    file.close()

def VC_changeBPM(bpm):
    global VC_BPM
    VC_BPM = VC_BPM + bpm
    if VC_BPM > 20:
        VC_BPM = 20
    elif VC_BPM < 10:
        VC_BPM = 10
    write_VC()
def VC_changeE(e):
    global VC_E
    VC_E = VC_E + e
    if VC_E > 4:
        VC_E = 4
    elif VC_E < 1:
        VC_E = 1
    write_VC()
def updateVC_label1a(label):
    def updateVC__label1a():
        global VC_BPM
        #print(flowList[0])
        out = str(VC_BPM) + " bpm"
        label.config(text = out)
        label.after(200, updateVC__label1a)
    updateVC__label1a()
def updateVC_label2a(label):
    def updateVC__label2a():
        global VC_E, VC_IE
        if VC_E > 0:
            VC_IE = 1 / float(VC_E)
            VC_IE = round(VC_IE, 3)
        out = "1:" + str(VC_E)
        label.config(text = out)
        label.after(200, updateVC__label2a)
    updateVC__label2a()
def updateVC_label3a(label):
    def updateVC__label3a():
        global VC_Volume
        if VC_Volume > 900:
            VC_Volume = 900
        elif VC_Volume < 500:
            VC_Volume = 500
        out = str(VC_Volume) + " ml"
        label.config(text = out)
        label.after(200, updateVC__label3a)
    updateVC__label3a()
def updateVC_button(button):
    global VC_enabled, VC_BPM, VC_E
    VC_BPM = 10
    VC_E = 1
    if VC_enabled == True:
        button.config(text = "Start", bg = "green2", fg = "black")
        VC_enabled = False
        write_modeSelect(0)
    else:
        button.config(text = "Stop", bg = "red", fg = "black")
        VC_enabled = True
        write_modeSelect(2)
    write_VC()
def VC_changeVolume(volume):
    global VC_Volume
    VC_Volume = VC_Volume + volume
    if VC_Volume > 900:
        VC_Volume = 900
    elif VC_Volume < 500:
        VC_Volume = 500
    write_VC()
def write_VC():
    global VC_BPM, VC_E, VC_Volume
    out = str(VC_BPM) + "," + str(VC_E) + "," + str(VC_Volume)
    file = open("data/VC.txt", "w")
    file.write(str(out))
    file.close()





class mainFunc(tk.Tk):
    def __init__(self, *args, **kwargs):
        tk.Tk.__init__(self, *args, **kwargs)
        #tk.Tk.iconbitmap(self, default="clienticon.ico")
        tk.Tk.wm_title(self, "Ventilator")
        tk.Tk.geometry(self, "1024x600")        
        tk.Tk.wm_attributes(self, '-fullscreen', True)
        
        container = tk.Frame(self)
        container.config(background = "red")
        container.pack(side="top", fill="both", expand = True)
        container.grid_rowconfigure(0, weight=1)
        container.grid_columnconfigure(0, weight=1)

        self.frames = {}

        for F in (AboutPage, StartPage, PageOne, PageTwo, PageThree, CPAP, volumeControl):
            frame = F(container, self)
            self.frames[F] = frame
            if F == PageThree:
                frame.config(background = "white", highlightbackground = "grey15", highlightthickness = 2)
            else:
                frame.config(background = "white", highlightbackground = "grey15", highlightthickness = 2)
            frame.grid(row=0, column=0, sticky="nsew")

        self.show_frame(StartPage)

    def show_frame(self, cont):
        frame = self.frames[cont]
        frame.tkraise()


class AboutPage(tk.Frame):
    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)
        
        label = tk.Label(self, text="About Ventilator", font=font_subHeading, bg = "white", fg = "black")
        label.pack(side = tk.TOP, pady = (20, 0))

        label1 = tk.Label(self, text="Controller", font=font_info, bg = "white", fg = "black")
        label1.place(x = 140, y = 100)
        label1a = tk.Label(self, text="Raspberry Pi 3B+", font=font_info, bg = "white", fg = "black")
        label1a.place(x = 600, y = 100)
        
        label2 = tk.Label(self, text="Air Blower", font=font_info, bg = "white", fg = "black")
        label2.place(x = 140, y = 150)
        label2a = tk.Label(self, text="WM7040-12V", font=font_info, bg = "white", fg = "black")
        label2a.place(x = 600, y = 150)
        
        label3 = tk.Label(self, text="Power Supply Unit", font=font_info, bg = "white", fg = "black")
        label3.place(x = 140, y = 200)
        label3a = tk.Label(self, text="SPS-100-15 12V 10A", font=font_info, bg = "white", fg = "black")
        label3a.place(x = 600, y = 200)
        
        label4 = tk.Label(self, text="Flow Sensor", font=font_info, bg = "white", fg = "black")
        label4.place(x = 140, y = 250)
        label4a = tk.Label(self, text="AFM3020", font=font_info, bg = "white", fg = "black")
        label4a.place(x = 600, y = 250)
        
        label5 = tk.Label(self, text="Differential Pressure Sensor", font=font_info, bg = "white", fg = "black")
        label5.place(x = 140, y = 300)
        label5a = tk.Label(self, text="XGZP6897A", font=font_info, bg = "white", fg = "black")
        label5a.place(x = 600, y = 300)
        
        label2 = tk.Label(self, text="Designed by: Nabeel Ali, Farakh Ali, Shahzaib Shahid Bhatti", font=font_info, bg = "white", fg = "black")
        label2.place(width = 800, x = 112, y = 370)
        label2a = tk.Label(self, text="Under the supervision of Dr. Tahir Awan", font=font_info, bg = "white", fg = "black")
        label2a.place(width = 600, x = 212, y = 410)
        #button1 = ttk.Button(self, text="Back to Home",
        #                    command=lambda: controller.show_frame(StartPage))
        #button1.pack()

        #button2 = ttk.Button(self, text="Page One",
        #                    command=lambda: controller.show_frame(PageOne))
        #button2.pack()
        exitButton = tk.Button(self, text="Back", relief = 'ridge', bg = bg_color_exitButton, fg = fg_color_mainButton, font = font_mainButton,
                            command=lambda: controller.show_frame(StartPage))
        exitButton.pack(side = tk.BOTTOM, ipadx = 15, ipady = 10, padx = 10, pady = (0, 60))


class StartPage(tk.Frame):
    def __init__(self, parent, controller):
        tk.Frame.__init__(self,parent)
        
        label = tk.Label(self, text="Design of Ventilator for Respiratory Diseases", font = font_mainHeading, bg = "white", fg = "black")
        label.place(x = 60, y = 20)

        button0 = tk.Button(self, text="About Ventilator", bg = bg_color_mainButton, fg = fg_color_mainButton, font = font_mainButton,
                            command=lambda: controller.show_frame(AboutPage))
        button0.place(height = 80, width = 300, x = 362, y = 125)

        button1 = tk.Button(self, text="Mode Selection", bg = bg_color_mainButton, fg = fg_color_mainButton, font = font_mainButton,
                            command=lambda: controller.show_frame(PageOne))
        button1.place(height = 80, width = 300, x = 140, y = 275)

        button2 = tk.Button(self, text="Settings", bg = bg_color_mainButton, fg = fg_color_mainButton, font = font_mainButton,
                            command=lambda: controller.show_frame(PageTwo))
        button2.place(height = 80, width = 300, x = 140, y = 425)

        button3 = tk.Button(self, text="Data Monitoring", bg = bg_color_mainButton, fg = fg_color_mainButton, font = font_mainButton,
                            command=lambda: controller.show_frame(PageThree))
        button3.place(height = 80, width = 300, x = 580, y = 275)
        
        exitButton = tk.Button(self, text="Exit", relief = 'ridge', bg = bg_color_exitButton, fg = fg_color_mainButton, font = font_mainButton,
                            command=lambda: app.quit())
        exitButton.place(height = 80, width = 300, x = 580, y = 425)


class PageOne(tk.Frame):
    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)
        
        label = tk.Label(self, text="Mode Selection", font=font_subHeading, bg = "white", fg = "black")
        label.place(width = 250, x = 387, y = 20)

        button1 = tk.Button(self, text="CPAP", bg = bg_color_mainButton, fg = fg_color_mainButton, font = font_mainButton,
                            command=lambda: controller.show_frame(CPAP))
        button1.place(height = 90, width = 302, x = 140, y = 200)

        button2 = tk.Button(self, text="Volume Control", bg = bg_color_mainButton, fg = fg_color_mainButton, font = font_mainButton,
                            command=lambda: controller.show_frame(volumeControl))
        button2.place(height = 90, width = 302, x = 582, y = 200)
        #button3 = tk.Button(self, text="", bg = bg_color_mainButton, fg = fg_color_mainButton, font = font_mainButton,
        #                    command=lambda: controller.show_frame(PageThree))
        #button3.place(height = 69, width = 224, x = 417, y = 270)
        exitButton = tk.Button(self, text="Back", relief = 'ridge', bg = bg_color_exitButton, fg = fg_color_mainButton, font = font_mainButton,
                            command=lambda: controller.show_frame(StartPage))
        exitButton.pack(side = tk.BOTTOM, ipadx = 15, ipady = 10, padx = 10, pady = (0, 60))


class PageTwo(tk.Frame):
    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)
        
        label = tk.Label(self, text="Settings", font=font_subHeading, bg = "white", fg = "black")
        label.pack(side = tk.TOP, pady = (20, 0))

        button1 = ttk.Button(self, text="Back to Home",
                            command=lambda: controller.show_frame(StartPage))
        button1.pack()

        button2 = ttk.Button(self, text="Page One",
                            command=lambda: controller.show_frame(PageOne))
        button2.pack()


class PageThree(tk.Frame):
    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)
        
        label1 = tk.Label(self, text="", font=font_info, bg = "white", fg = "black")
        label1.place(x = 10, y = 10)
        updateFlow(label1)
        
        label2 = tk.Label(self, text="", font=font_info, bg = "white", fg = "black")
        label2.pack(pady=10,padx=10)
        updatePressure(label2)
        """
        button1 = ttk.Button(self, text="Back to Home",
                            command=lambda: controller.show_frame(StartPage))
        button1.pack()
        """
        button1 = tk.Button(self, text="Back", relief = 'ridge', bg = bg_color_exitButton, fg = fg_color_mainButton, font = font_mainButton,
                            command=lambda: controller.show_frame(StartPage))
        button1.pack(side = tk.BOTTOM, ipadx = 15, ipady = 10, padx = 10, pady = (0, 60))

        canvas = FigureCanvasTkAgg(f, self)
        canvas.show()
        canvas.get_tk_widget().pack(side=tk.LEFT, expand=True)
        #toolbar = NavigationToolbar2TkAgg(canvas, self)
        #toolbar.update()
        #canvas._tkcanvas.pack(side=tk.TOP, expand=True)
        canvas1 = FigureCanvasTkAgg(f1, self)
        canvas1.show()
        canvas1.get_tk_widget().pack(side=tk.LEFT, expand=True)
        #toolbar1 = NavigationToolbar2TkAgg(canvas1, self)
        #toolbar1.update()
        #canvas1._tkcanvas.pack(side=tk.TOP, expand=True)


class CPAP(tk.Frame):
    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)
        
        label = tk.Label(self, text="CPAP", font=font_subHeading, bg = "white", fg = "black")
        label.pack(side = tk.TOP, pady = (20, 0))

        label1 = tk.Label(self, text="", font=font_info, bg = "white", fg = "black")
        label1.place(x = 190, y = 400)
        updateFlow(label1)
        
        label2 = tk.Label(self, text="", font=font_info, bg = "white", fg = "black")
        label2.place(x = 632, y = 400)
        updatePressure(label2)
        
        label3 = tk.Label(self, text="", font=font_mainButton, bg = "white", fg = "black")
        label3.place(width = 292, x = 365, y = 350)
        updateCPAP_label1(label3)
        
        CPAP_Func(0)
        
        button = tk.Button(self, text="Start", bg = "green2", fg = fg_color_mainButton, font = font_mainButton,
                            command= lambda: updateCPAP_button(button))
        button.place(height = 69, width = 302, x = 361, y = 110)
        
        button1 = tk.Button(self, text="Increase Pressure", bg = bg_color_mainButton, fg = fg_color_mainButton, font = font_mainButton,
                            command= lambda: CPAP_Func(5))
        button1.place(height = 69, width = 302, x = 582, y = 220)

        button2 = tk.Button(self, text="Decrease Pressure", bg = bg_color_mainButton, fg = fg_color_mainButton, font = font_mainButton,
                            command= lambda: CPAP_Func(-5))
        button2.place(height = 69, width = 302, x = 140, y = 220)

        exitButton = tk.Button(self, text="Back", relief = 'ridge', bg = bg_color_exitButton, fg = fg_color_mainButton, font = font_mainButton,
                            command=lambda: controller.show_frame(PageOne))
        exitButton.pack(side = tk.BOTTOM, ipadx = 15, ipady = 10, padx = 10, pady = (0, 60))


class volumeControl(tk.Frame):
    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)
        
        label = tk.Label(self, text="Volume Control", font=font_subHeading, bg = "white", fg = "black")
        label.pack(side = tk.TOP, pady = (20, 0))

        button = tk.Button(self, text="Start", bg = "green2", fg = fg_color_mainButton, font = font_mainButton,
                            command= lambda: updateVC_button(button))
        button.place(height = 69, width = 302, x = 361, y = 110)

        label1 = tk.Label(self, text="Breaths per Minute", font=font_info, bg = "white", fg = "black")
        label1.place(height = 50, width = 300, x = 150, y = 190)
        button1a = tk.Button(self, text="<-", bg = bg_color_mainButton, fg = fg_color_mainButton, font = font_mainButton,
                            command= lambda: VC_changeBPM(-1))
        button1a.place(height = 50, width = 60, x = 240, y = 240)
        button1b = tk.Button(self, text="->", bg = bg_color_mainButton, fg = fg_color_mainButton, font = font_mainButton,
                            command= lambda: VC_changeBPM(1))
        button1b.place(height = 50, width = 60, x = 300, y = 240)
        label1a = tk.Label(self, text="", font=font_info, bg = "white", fg = "black")
        label1a.place(width = 100, x = 255, y = 300)
        updateVC_label1a(label1a)
        
        label2 = tk.Label(self, text="I:E Ratio", font=font_info, bg = "white", fg = "black")
        label2.place(height = 50, width = 200, x = 624, y = 190)
        button2a = tk.Button(self, text="<-", bg = bg_color_mainButton, fg = fg_color_mainButton, font = font_mainButton,
                            command= lambda: VC_changeE(1))
        button2a.place(height = 50, width = 60, x = 664, y = 240)
        button2b = tk.Button(self, text="->", bg = bg_color_mainButton, fg = fg_color_mainButton, font = font_mainButton,
                            command= lambda: VC_changeE(-1))
        button2b.place(height = 50, width = 60, x = 724, y = 240)
        label2a = tk.Label(self, text="", font=font_info, bg = "white", fg = "black")
        label2a.place(width = 100, x = 674, y = 300)
        updateVC_label2a(label2a)


        label3 = tk.Label(self, text="Tidal Volume", font=font_info, bg = "white", fg = "black")
        label3.place(height = 50, width = 300, x = 362, y = 270)
        button3a = tk.Button(self, text="<-", bg = bg_color_mainButton, fg = fg_color_mainButton, font = font_mainButton,
                            command= lambda: VC_changeVolume(-10))
        button3a.place(height = 50, width = 60, x = 452, y = 320)
        button3b = tk.Button(self, text="->", bg = bg_color_mainButton, fg = fg_color_mainButton, font = font_mainButton,
                            command= lambda: VC_changeVolume(10))
        button3b.place(height = 50, width = 60, x = 512, y = 320)
        label3a = tk.Label(self, text="", font=font_info, bg = "white", fg = "black")
        label3a.place(width = 100, x = 462, y = 380)
        updateVC_label3a(label3a)
        
        
        exitButton = tk.Button(self, text="Back", relief = 'ridge', bg = bg_color_exitButton, fg = fg_color_mainButton, font = font_mainButton,
                            command=lambda: controller.show_frame(PageOne))
        exitButton.pack(side = tk.BOTTOM, ipadx = 15, ipady = 10, padx = 10, pady = (0, 60))





#call("sudo python dataAcquisition.py", shell = True)
app = mainFunc()
ani = animation.FuncAnimation(f, animatea, interval=500)
ani1 = animation.FuncAnimation(f1, animateb, interval=500)
app.mainloop()

write_modeSelect(0)
CPAP_Func(-100)
VC_changeBPM(-10)
VC_changeE(-4.0)
os.system('clear')
#app.destroy()
#call("sudo nohup shutdown -h now", shell = True)