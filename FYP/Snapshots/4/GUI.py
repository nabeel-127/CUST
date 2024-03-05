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

font_Button= ("Verdana", 15)
style.use("dark_background")
#style.use("ggplot")

f = Figure(figsize=(21,8), dpi=50)
x = f.add_subplot(211)
f1 = Figure(figsize=(21,8), dpi=50)
y = f.add_subplot(212)

x_vals = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
y_vals = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
flowList = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
pressureList = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

def animatea(i):
    
    pullData = open("data/sensorData.txt","r").read()
    dataList = pullData.split('\n')
    for eachLine in dataList:
        if len(eachLine) > 0:
            a, b, c, d, e = eachLine.split(',')
            flowList.append(int(a))
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
            flowList.append(int(a))
            flowList.pop(0)
            pressureList.append(int(b))
            pressureList.pop(0)

    y.clear()
    y.plot(x_vals, pressureList)
    #plt.ylim([0, 100])
    #b.set_ylim([0, 90])

class mainFunc(tk.Tk):

    def __init__(self, *args, **kwargs):
        
        tk.Tk.__init__(self, *args, **kwargs)

        #tk.Tk.iconbitmap(self, default="clienticon.ico")
        tk.Tk.wm_title(self, "Ventilator")
        tk.Tk.geometry(self, "1024x600")        
        
        
        
        container = tk.Frame(self)
        container.config(background = "red")
        container.pack(side="top", fill="both", expand = True)
        container.grid_rowconfigure(0, weight=1)
        container.grid_columnconfigure(0, weight=1)

        self.frames = {}

        for F in (StartPage, PageOne, PageTwo, PageThree):

            frame = F(container, self)

            self.frames[F] = frame
            
            if F == PageThree:
                frame.config(background = "black", highlightbackground = "black", highlightthickness = 2)
            else:
                frame.config(background = "grey30", highlightbackground = "black", highlightthickness = 2)
            frame.grid(row=0, column=0, sticky="nsew")

        self.show_frame(StartPage)

    def show_frame(self, cont):

        frame = self.frames[cont]
        frame.tkraise()

        
class StartPage(tk.Frame):

    def __init__(self, parent, controller):
        tk.Frame.__init__(self,parent)
        label = tk.Label(self, text="Welcome", font='30', bg = "grey30", fg = "white")
        label.pack(pady=25,padx=100)

        button = tk.Button(self, text="Mode Selection", bg = "navy", fg = "white", font = font_Button,
                            command=lambda: controller.show_frame(PageOne))
        button.place(height = 60, x = 435, y = 90)

        button2 = tk.Button(self, text="Settings", bg = "navy", fg = "white", font = font_Button,
                            command=lambda: controller.show_frame(PageTwo))
        button2.place(height = 60, x = 463, y = 155)

        button3 = tk.Button(self, text="Flow Sensor Data", bg = "navy", fg = "white", font = font_Button,
                            command=lambda: controller.show_frame(PageThree))
        button3.place(height = 60, x = 428, y = 220)
        
        button4 = tk.Button(self, text="Exit", bg = "navy", fg = "white", font = font_Button,
                            command=lambda: app.quit())
        button4.place(height = 50, x = 440, y = 420)


class PageOne(tk.Frame):

    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)
        label = tk.Label(self, text="Mode Selection", font='30', bg = "grey30", fg = "white")
        label.pack(pady=10,padx=10)

        button1 = ttk.Button(self, text="Back to Home",
                            command=lambda: controller.show_frame(StartPage))
        button1.pack()

        button2 = ttk.Button(self, text="Page Two",
                            command=lambda: controller.show_frame(PageTwo))
        button2.pack()


class PageTwo(tk.Frame):

    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)
        label = tk.Label(self, text="Settings", font=font_Button, bg = "grey30", fg = "white")
        label.pack(pady=10,padx=10)

        button1 = ttk.Button(self, text="Back to Home",
                            command=lambda: controller.show_frame(StartPage))
        button1.pack()

        button2 = ttk.Button(self, text="Page One",
                            command=lambda: controller.show_frame(PageOne))
        button2.pack()


class PageThree(tk.Frame):

    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)
        label = tk.Label(self, text="Graph Page!", font=font_Button, bg = "black", fg = "white")
        label.pack(pady=10,padx=10)

        button1 = ttk.Button(self, text="Back to Home",
                            command=lambda: controller.show_frame(StartPage))
        button1.pack()

        canvas = FigureCanvasTkAgg(f, self)
        canvas.show()
        canvas.get_tk_widget().pack(side=tk.TOP, expand=True)
        
        #toolbar = NavigationToolbar2TkAgg(canvas, self)
        #toolbar.update()
        #canvas._tkcanvas.pack(side=tk.TOP, expand=True)
        
        canvas1 = FigureCanvasTkAgg(f1, self)
        canvas1.show()
        canvas1.get_tk_widget().pack(side=tk.BOTTOM, expand=True)
        """
        toolbar1 = NavigationToolbar2TkAgg(canvas1, self)
        toolbar1.update()
        canvas1._tkcanvas.pack(side=tk.TOP, expand=True)
        """

app = mainFunc()
ani = animation.FuncAnimation(f, animatea, interval=1000)
ani1 = animation.FuncAnimation(f1, animateb, interval=1000)
app.mainloop()

os.system('clear')
app.destroy()
#call("sudo nohup shutdown -h now", shell = True)