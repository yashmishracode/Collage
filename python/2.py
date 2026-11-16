from tkinter import *
from tkinter import filedialog
import pandas as pd
import matplotlib.pyplot as plt

def show():
    file = filedialog.askopenfilename()
    df = pd.read_csv(file)
    df.plot(kind="bar", x=df.columns[0], y=df.columns[1])
    plt.show()

root = Tk()
root.title("CSV Chart Viewer")

Button(root, text="Open CSV and Show Chart",
       command=show).pack(padx=20, pady=20)

root.mainloop()