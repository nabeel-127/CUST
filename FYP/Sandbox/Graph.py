import random
from itertools import count
import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
plt.style.use('fivethirtyeight')
import os

x_vals = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
y_vals = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

index = count()

def animate(i):
    #x_vals.pop(0)
    #x_vals.append(next(index))
    y_vals.append(random.randint(-5, 5))
    y_vals.pop(0)
    plt.clf()
    plt.plot(x_vals, y_vals)

try:
    while True:
        ani = FuncAnimation(plt.gcf(), animate, interval = 1000)
        plt.plot(x_vals, y_vals)
        plt.tight_layout()
        plt.show()
        
except:
    os.system('clear')
finally:
    os.system('clear')