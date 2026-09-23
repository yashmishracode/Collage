text = input("Enter a word:-")
count = 0
l1 = list(x for x in text.split())
for x in l1:
    x = str(x)
    if len(x) > 3:
        count +=1
print(count)

