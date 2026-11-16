from tkinter import *

def calculate():
    a, b = int(e1.get()), int(e2.get())
    op = choice.get()

    if op == "+": r = a + b
    elif op == "-": r = a - b
    elif op == "*": r = a * b
    else: r = a / b

    result.config(text="Result: " + str(r))

root = Tk()
root.title("Calculator")

e1 = Entry(root)
e1.pack()

e2 = Entry(root)
e2.pack()

choice = StringVar(value="+")
OptionMenu(root, choice, "+", "-", "*", "/").pack()

Button(root, text="Calculate", command=calculate).pack()

result = Label(root, text="Result:")
result.pack()

root.mainloop()