from tkinter import *
from PIL import Image, ImageTk
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.figure import Figure
from matplotlib.backends.backend_tkagg import (FigureCanvasTkAgg, NavigationToolbar2Tk)



def plot():
    fig = Figure(figsize = (5,5), dpi = 100)
    y = [i**2 for i in range(101)]
    plot1 = fig.add_subplot(111)
    plot1.plot(y)
    canvas = FigureCanvasTkAgg(fig, master = root)
    canvas.draw()
    canvas.get_tk_widget().pack()
    toolbar = NavigationToolbar2Tk(canvas, root)
    toolbar.update()
    canvas.get_tk_widget().pack()
    


root = Tk()

root.title('Ventilator')
root.geometry("1024x600")

    
my_button = Button(master = root, height = 2, width = 10, text = "PLOT", command = plot)
my_button.pack()




root.mainloop()