num = int(input("Enter a Number"))
sum = 0 
while num > 0:
    a = num % 10
    sum += a
    num //= 10
print(sum)