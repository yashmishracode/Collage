# ============================================================
# PYTHON LAB PROGRAMS - ALL 10 PROGRAMS
# ============================================================


# QUESTION 1:
# Write a Python program to define a function that accepts two
# numbers and returns their addition, subtraction, and
# multiplication as multiple returned values.

def calculate(a, b):
    addition = a + b
    subtraction = a - b
    multiplication = a * b
    return addition, subtraction, multiplication


add, sub, mul = calculate(10, 5)

print("PROGRAM 1")
print("Addition:", add)
print("Subtraction:", sub)
print("Multiplication:", mul)
print("-" * 50)


# QUESTION 2:
# Create a program demonstrating function calls with positional
# arguments, keyword arguments (name="Sagar", marks=59.53),
# and default parameter values (b=10).

def student(name, marks, b=10):
    print("Name:", name)
    print("Marks:", marks)
    print("B:", b)


print("PROGRAM 2")

# Positional arguments
print("Positional Arguments:")
student("Sagar", 59.53, 20)

# Keyword arguments
print("\nKeyword Arguments:")
student(name="Sagar", marks=59.53, b=30)

# Default argument
print("\nDefault Argument:")
student("Sagar", 59.53)

print("-" * 50)


# QUESTION 3:
# Write a Python function using variable-length arguments
# (*args) to calculate the total sum of an arbitrary number
# of numerical inputs passed during a function call.

def calculate_sum(*args):
    total = 0

    for number in args:
        total += number

    return total


print("PROGRAM 3")
print("Sum:", calculate_sum(10, 20, 30))
print("Sum:", calculate_sum(5, 10, 15, 20, 25))
print("-" * 50)


# QUESTION 4:
# Implement a function using **kwargs that accepts variable
# keyword-value pairs and iterates through them to display
# key-value pairs.

def display_details(**kwargs):
    for key, value in kwargs.items():
        print(key, ":", value)


print("PROGRAM 4")
display_details(
    name="Sagar",
    age=22,
    course="MCA",
    specialization="Data Science"
)
print("-" * 50)


# QUESTION 5:
# Write a program that reads space-separated numerical input
# into a list, passes the list to a function, and calculates
# both the sum and average of the elements.

def calculate_sum_average(numbers):
    total = sum(numbers)
    average = total / len(numbers)
    return total, average


print("PROGRAM 5")
numbers = list(map(float, input("Enter numbers separated by spaces: ").split()))

total, average = calculate_sum_average(numbers)

print("List:", numbers)
print("Sum:", total)
print("Average:", average)
print("-" * 50)


# QUESTION 6:
# Construct a Python program utilizing list comprehension to
# iterate through a range of numbers and construct a list
# consisting only of even values.

print("PROGRAM 6")

even_numbers = [x for x in range(1, 21) if x % 2 == 0]

print("Even numbers:", even_numbers)
print("-" * 50)


# QUESTION 7:
# Write a recursive function factorial(n) that calls itself
# to compute the factorial of a non-negative integer n.

def factorial(n):
    if n == 0 or n == 1:
        return 1

    return n * factorial(n - 1)


print("PROGRAM 7")
n = int(input("Enter a non-negative integer: "))

if n < 0:
    print("Factorial is not defined for negative numbers.")
else:
    print("Factorial:", factorial(n))

print("-" * 50)


# QUESTION 8:
# Write a program using an anonymous lambda function along
# with Python's built-in filter() to extract even numbers
# from a given list.

print("PROGRAM 8")

numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

even_numbers = list(filter(lambda x: x % 2 == 0, numbers))

print("Original list:", numbers)
print("Even numbers:", even_numbers)
print("-" * 50)


# QUESTION 9:
# Demonstrate higher-order functions by using map() with
# lambda to compute the square of each list item, and
# reduce() from functools to calculate the cumulative
# product of the list.

from functools import reduce

print("PROGRAM 9")

numbers = [1, 2, 3, 4, 5]

squares = list(map(lambda x: x ** 2, numbers))

product = reduce(lambda x, y: x * y, numbers)

print("Original list:", numbers)
print("Squares:", squares)
print("Product:", product)
print("-" * 50)


# QUESTION 10:
# Write a Python function using variable-length positional
# arguments (*args) to compute the L2 norm (Euclidean length)
# of an arbitrary n-dimensional coordinate vector:
#
# ||v||2 = sqrt(sum(vi^2))
#
# where i = 1 to n.

import math


def l2_norm(*args):
    sum_of_squares = 0

    for value in args:
        sum_of_squares += value ** 2

    return math.sqrt(sum_of_squares)


print("PROGRAM 10")
print("L2 Norm of (3, 4):", l2_norm(3, 4))
print("L2 Norm of (1, 2, 2):", l2_norm(1, 2, 2))
print("L2 Norm of (2, 3, 6):", l2_norm(2, 3, 6))
print("-" * 50)
