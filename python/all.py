
# 1. Segregate odd and even numbers into separate lists

numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

odd = []
even = []

for n in numbers:
    if n % 2 == 0:
        even.append(n)
    else:
        odd.append(n)

print("Odd numbers:", odd)
print("Even numbers:", even)


# 2. Print common elements from two lists

list1 = [1, 2, 3, 4, 5]
list2 = [3, 4, 5, 6, 7]

common = []

for item in list1:
    if item in list2 and item not in common:
        common.append(item)

print("Common elements:", common)


# 3. Find Strong, Happy, and Armstrong numbers from 1 to 5000000

def is_strong(n):
    total = 0
    for digit in str(n):
        fact = 1
        for i in range(1, int(digit) + 1):
            fact *= i
        total += fact
    return total == n


def is_happy(n):
    seen = set()

    while n != 1 and n not in seen:
        seen.add(n)
        total = 0

        for digit in str(n):
            total += int(digit) ** 2

        n = total

    return n == 1


def is_armstrong(n):
    digits = str(n)
    power = len(digits)
    total = 0

    for digit in digits:
        total += int(digit) ** power

    return total == n


result = {
    "Strong": [],
    "Happy": [],
    "Armstrong": []
}

for n in range(1, 5000001):
    if is_strong(n):
        result["Strong"].append(n)

    if is_happy(n):
        result["Happy"].append(n)

    if is_armstrong(n):
        result["Armstrong"].append(n)

print("Strong numbers:", result["Strong"])
print("Happy numbers:", result["Happy"])
print("Armstrong numbers:", result["Armstrong"])


# 4. Convert uppercase characters to lowercase and store in a tuple
# Without using the lower() method

text = "HELLO PYTHON"
lowercase = ""

for ch in text:
    if 'A' <= ch <= 'Z':
        lowercase += chr(ord(ch) + 32)
    else:
        lowercase += ch

result_tuple = tuple(lowercase)

print("Lowercase tuple:", result_tuple)


# 5. Count unique values in a list

numbers = [1, 2, 2, 3, 4, 4, 5, 5, 5]

unique_values = []

for n in numbers:
    if n not in unique_values:
        unique_values.append(n)

print("Unique values:", unique_values)
print("Count of unique values:", len(unique_values))


# 6. Extract words starting with K from a string list

words = ["King", "apple", "Kite", "book", "Karnataka", "cat"]

result = []

for word in words:
    if word.startswith("K"):
        result.append(word)

print("Words starting with K:", result)


# 7. Filter strings using a substring at corresponding indices

test_list1 = ["Gfg", "not", "best"]
test_list2 = ["yes", "noo", "its yes"]
sub_str = "yes"

result = []

for i in range(len(test_list1)):
    if sub_str in test_list2[i]:
        result.append(test_list1[i])

print("Filtered list:", result)


# 8. Skew nested tuple summation

test_tup = (5, (6, (1, (9, None))))

def nested_sum(tup):
    total = 0

    for item in tup:
        if isinstance(item, tuple):
            total += nested_sum(item)
        elif isinstance(item, (int, float)):
            total += item

    return total

print("Sum:", nested_sum(test_tup))


# 9. Grade calculator using weighted average

Yogit = {
    "name": "Yogit",
    "assignment": [80, 50, 40, 20],
    "test": [75, 75],
    "lab": [78.20, 77.20]
}

assignment_avg = sum(Yogit["assignment"]) / len(Yogit["assignment"])
test_avg = sum(Yogit["test"]) / len(Yogit["test"])
lab_avg = sum(Yogit["lab"]) / len(Yogit["lab"])

final_score = (
    assignment_avg * 0.10
    + test_avg * 0.70
    + lab_avg * 0.20
)

if final_score >= 90:
    grade = "A"
elif final_score >= 80:
    grade = "B"
elif final_score >= 70:
    grade = "C"
elif final_score >= 60:
    grade = "D"
else:
    grade = "F"

print(f"Average marks of {Yogit['name']} is : {final_score:.2f}")
print(f"Letter Grade of {Yogit['name']} is : {grade}")


# 10. Convert two lists into a dictionary

keys = ["Ten", "Twenty", "Thirty"]
values = [10, 20, 30]

result = dict(zip(keys, values))

print(result)


# 11. Concatenate two dictionaries into a new dictionary

dict1 = {"Name": "Ram", "Age": 23}
dict2 = {"City": "Salem", "Gender": "Male"}

combined = {**dict1, **dict2}

print("Concatenated dictionary:", combined)


# 12. Check whether a key exists in a dictionary

student = {"Name": "Ram", "Age": 23}
key = "Name"

if key in student:
    print("Key is Available in the Dictionary")
else:
    print("Key is Not Available in the Dictionary")
