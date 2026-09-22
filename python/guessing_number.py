secret = 12

guess = int(input("Guess the number:- "))

while guess != secret :
    print("Wrong guess \n Try Again \n ")
    guess = int(input("Guess the number again:- "))
print("correct guess" )
