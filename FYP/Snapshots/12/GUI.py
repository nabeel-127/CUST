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

x_vals = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
y_vals = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
flowList = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
pressureList = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
dutyCycle = 0
enabledCPAP = False

def animatea(i):
    
    pullData = open("data/sensorData.txt","r").read()
    dataList = pullData.split('\n')
    for eachLine in dataList:
        if len(eachLine) > 0:
            a, b, c, d, e = eachLine.split(',')
            flowList.append(float(a))
            flowList.pop(0)
            pressureList.append(int(b))
            pressureList.pop(0)

    x.clear()
    x.plot(x_vals, flowList)
    #plt.ylim([0, 100])
    x.set_ylim([0, 90])
            
def animateb(i):
    
    pullData = open("data/sensorData.txt","r").read()
    dataList = pullData.split('\n')
    for eachLine in dataList:
        if len(eachLine) > 0:
            a, b, c, d, e = eachLine.split(',')
            flowList.append(float(a))
            flowList.pop(0)
            pressureList.append(int(b))
            pressureList.pop(0)

    y.clear()
    y.plot(x_vals, pressureList)
    #plt.ylim([0, 100])
    y.set_ylim([0, 3400])
    
def updateFlow(label):
    def updateflow():
        #print(flowList[0])
        out = "Flow: " + str(flowList[0]) + " SLM"
        label.config(text = out)
        label.after(500, updateflow)
    updateflow()

def updatePressure(label):
    def updatepressure():
        #print(flowList[0])
        out = "Pressure: " + str(pressureList[0]) + " Pa"
        label.config(text = out)
        label.after(500, updatepressure)
    updatepressure()

def updateCPAP_label1(label):
    def updateCPAP__label1():
        global dutyCycle
        #print(flowList[0])
        out = "Pressure: " + str(dutyCycle) + " cmH2O"
        label.config(text = out)
        label.after(500, updateCPAP__label1)
    updateCPAP__label1()
    
def updateCPAP_button(button):
    global enabledCPAP, dutyCycle
    if enabledCPAP == True:
        dutyCycle = 0
        button.config(text = "Start", bg = "green2", fg = "black")
        enabledCPAP = False
    else:
        dutyCycle = 10
        button.config(text = "Stop", bg = "red", fg = "black")
        enabledCPAP = True
    write_CPAP()

def CPAP_Func(PWM):
    global dutyCycle
    if enabledCPAP == True:
        dutyCycle = dutyCycle + PWM
    else:
        dutyCycle = 0
    if dutyCycle > 40:
        dutyCycle = 40
    elif dutyCycle < 5:
        dutyCycle = 5
    write_CPAP()

def write_CPAP():
    global dutyCycle
    file = open("data/CPAP.txt", "w")
    file.write(str(dutyCycle))
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
        #label['text'] = str(flowList[0])

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
        label1 = tk.Label(self, text="", font=font_subHeading, bg = "white", fg = "black")
        label1.place(x = 10, y = 10)
        #label1.pack(pady=10,padx=10)
        updateFlow(label1)
        
        label2 = tk.Label(self, text="", font=font_mainButton, bg = "white", fg = "black")
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
        #button1.place(height = 55, width = 98, x = 480, y = 450)
        

        canvas = FigureCanvasTkAgg(f, self)
        canvas.show()
        canvas.get_tk_widget().pack(side=tk.LEFT, expand=True)
        
        #toolbar = NavigationToolbar2TkAgg(canvas, self)
        #toolbar.update()
        #canvas._tkcanvas.pack(side=tk.TOP, expand=True)
        
        canvas1 = FigureCanvasTkAgg(f1, self)
        canvas1.show()
        canvas1.get_tk_widget().pack(side=tk.LEFT, expand=True)
        """
        toolbar1 = NavigationToolbar2TkAgg(canvas1, self)
        toolbar1.update()
        canvas1._tkcanvas.pack(side=tk.TOP, expand=True)
        """

class CPAP(tk.Frame):

    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)
        label = tk.Label(self, text="CPAP", font=font_subHeading, bg = "white", fg = "black")
        label.pack(side = tk.TOP, pady = (20, 0))

        label1 = tk.Label(self, text="", font=font_mainButton, bg = "white", fg = "black")
        label1.place(width = 292, x = 365, y = 350)
        #label1.pack(pady=10,padx=10)
        updateCPAP_label1(label1)
        
        CPAP_Func(0)
        
        button = tk.Button(self, text="Start", bg = "green2", fg = fg_color_mainButton, font = font_mainButton,
                            command= lambda: updateCPAP_button(button))
        button.place(height = 69, width = 302, x = 361, y = 110)
        #updateCPAP_button(button)
        
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

        button1 = tk.Button(self, text="->", bg = bg_color_mainButton, fg = fg_color_mainButton, font = font_mainButton,
                            command= lambda: CPAP_Func(5))
        button1.place(height = 69, width = 302, x = 582, y = 220)
        
        exitButton = tk.Button(self, text="Back", relief = 'ridge', bg = bg_color_exitButton, fg = fg_color_mainButton, font = font_mainButton,
                            command=lambda: controller.show_frame(PageOne))
        exitButton.pack(side = tk.BOTTOM, ipadx = 15, ipady = 10, padx = 10, pady = (0, 60))





#call("sudo python dataAcquisition.py", shell = True)
app = mainFunc()
#ani = animation.FuncAnimation(f, animatea, interval=500)
#ani1 = animation.FuncAnimation(f1, animateb, interval=500)
app.mainloop()

CPAP_Func(-100)
os.system('clear')
#app.destroy()
#call("sudo nohup shutdown -h now", shell = True)