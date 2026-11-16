from tkinter import *
from tkinter import messagebox

def login():
    if user.get() == "admin" and pwd.get() == "1234":
        messagebox.showinfo("Login", "Login Successful")
    else:
        messagebox.showerror("Login", "Invalid Details")

root = Tk()
root.title("Login Form")

Label(root, text="Username").pack()
user = Entry(root)
user.pack()

Label(root, text="Password").pack()
pwd = Entry(root, show="*")
pwd.pack()

Button(root, text="Login", command=login).pack()

root.mainloop()