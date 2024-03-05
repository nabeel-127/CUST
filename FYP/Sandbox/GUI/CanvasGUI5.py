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

LARGE_FONT= ("Verdana", 12)
style.use("ggplot")

f = Figure(figsize=(7,4), dpi=75)
a = f.add_subplot(111)

x_vals = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
y_vals = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

def animate(i):
    
    pullData = open("data/sensorData.txt","r").read()
    dataList = pullData.split('\n')
    xList = []
    #yList = []
    yList = y_vals
    for eachLine in dataList:
        if len(eachLine) > 0:
            #x, y = eachLine.split(',')
            #xList.append(int(x))
            yList.append(dataList[0])
            yList.pop(0)
    
    #y_vals.append(random.randint(-5, 5))
    #y_vals.pop(0)

    a.clear()
    a.plot(x_vals, yList)
    #plt.ylim([0, 100])
    a.set_ylim([0, 90])
            

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
            frame.config(background = "grey30")
            frame.grid(row=0, column=0, sticky="nsew")

        self.show_frame(StartPage)

    def show_frame(self, cont):

        frame = self.frames[cont]
        frame.tkraise()

        
class StartPage(tk.Frame):

    def __init__(self, parent, controller):
        tk.Frame.__init__(self,parent)
        label = tk.Label(self, text="Welcome", font=LARGE_FONT, bg = "grey30", fg = "white")
        label.pack(pady=25,padx=100)

        button = ttk.Button(self, text="Mode Selection",  
                            command=lambda: controller.show_frame(PageOne))
        button.place(height = 50, width = 150, x = 10, y = 100)

        button2 = ttk.Button(self, text="Settings",
                            command=lambda: controller.show_frame(PageTwo))
        button2.place(x = 50, y = 10)

        button3 = ttk.Button(self, text="Flow Sensor Data",
                            command=lambda: controller.show_frame(PageThree))
        button3.place(x = 100, y = 100)


class PageOne(tk.Frame):

    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)
        label = tk.Label(self, text="Mode Selection", font=LARGE_FONT)
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
        label = tk.Label(self, text="Settings", font=LARGE_FONT)
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
        label = tk.Label(self, text="Graph Page!", font=LARGE_FONT)
        label.pack(pady=10,padx=10)

        button1 = ttk.Button(self, text="Back to Home",
                            command=lambda: controller.show_frame(StartPage))
        button1.pack()

        canvas = FigureCanvasTkAgg(f, self)
        canvas.show()
        canvas.get_tk_widget().pack(side=tk.BOTTOM, fill=tk.BOTH, expand=True)

        toolbar = NavigationToolbar2TkAgg(canvas, self)
        toolbar.update()
        canvas._tkcanvas.pack(side=tk.TOP, fill=tk.BOTH, expand=True)


app = mainFunc()
ani = animation.FuncAnimation(f, animate, interval=100)
app.mainloop()
 