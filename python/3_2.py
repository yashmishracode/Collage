from tkinter import *
from tkinter import ttk

def start():
    bar["value"] = 0
    for i in range(10):
        root.after(i * 300, lambda v=(i+1)*10: bar.config(value=v))

root = Tk()
root.title("Menu and Progress Bar")

menu = Menu(root)
root.config(menu=menu)

file = Menu(menu, tearoff=0)
menu.add_cascade(label="File", menu=file)
file.add_command(label="Exit", command=root.destroy)

bar = ttk.Progressbar(root, length=200, maximum=100)
bar.pack(pady=20)

Button(root, text="Start", command=start).pack()

root.mainloop()