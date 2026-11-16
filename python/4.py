from tkinter import *
import csv

def show():
    with open("marks.csv") as f:
        data = csv.DictReader(f)
        for row in data:
            total = int(row["Math"]) + int(row["Science"]) + int(row["English"])
            avg = total / 3
            Label(root, text=f'{row["Name"]}: Total={total}, Average={avg:.2f}').pack()

root = Tk()
root.title("Student Result")

Button(root, text="Show Results", command=show).pack()

root.mainloop()