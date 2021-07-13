"""
Name : Abhinandan De
Roll No : 19CS10069
"""


from tkinter import *
from ast import literal_eval
from math import *
import numpy as np
from matplotlib.figure import Figure
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg

# try to plot on the same window!

class Window(Frame):
    def __init__(self, master=None):
        self.col = "royalblue2"
        Frame.__init__(self, master, bg=self.col)
        self.grid(row=0, column=0, sticky="nsew")
        master.title("Plot a function for a given range")
        master.geometry("720x720")
        master.grid_columnconfigure(0, weight=1)
        master.grid_rowconfigure(0, weight=1)
        self.master=master

        self.label1 = Label(self, text="Enter an expression in terms of variable x: ", width=40, height=4, bg="goldenrod1", font =("Calibri", 13))
        self.label1.grid(row=0, column=0, padx=10, pady=10)

        self.e1 = Text(self, width=30, bg="lemon chiffon", height=2, font=("Comic sans ms", 13))
        self.e1.grid(row=0, column=2, padx=10, pady=10)

        self.label2 = Label(self, text="Enter the range as a tuple: ", width=40, height=4, bg="goldenrod1", font =("Calibri", 13))
        self.label2.grid(row=2, column=0, padx=10, pady=10)

        self.e2 = Text(self, width=30, bg="lemon chiffon", height=2, font=("Comic sans ms", 13))
        self.e2.grid(row=2, column=2, padx=10, pady=10)

        self.btn1 = Button(self, text="Plot", command=self.graph, width=10, bg="lavender")
        self.btn1.grid(row=4, column=0)

        self.btn2 = Button(self, text="Exit", command=exit, width=10, bg="lavender")
        self.btn2.grid(row=4, column=2)

    def graph(self):
        expr = self.e1.get(1.0, END)
        a = literal_eval(self.e2.get(1.0, END))
        self.e1.delete(1.0, END)
        self.e2.delete(1.0, END)

        xVal = [x for x in np.linspace(a[0], a[1], 1000)]
        yVal = [eval(expr) for x in np.linspace(a[0], a[1], 1000)]

        fig = Figure(figsize=(8, 4), dpi=100)
        plt = fig.add_subplot(111)
        plt.plot(xVal, yVal, color="red")
        plt.set_title("Required plot")
        plt.set_xlabel("x")
        plt.set_ylabel("y = " + expr)

        canvas = FigureCanvasTkAgg(fig, master=self.master)
        canvas.get_tk_widget().grid(row=5, column=0, padx=10, pady=10)
        canvas.draw()


root = Tk()
app=Window(root)

root.mainloop()