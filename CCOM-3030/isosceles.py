#This program displays a beautiful isosceles triangle

print("Welcome!")
print("This program will display a beautiful isosceles triangle")
print()
n = eval(input("How high do you want this triangle to be? "))
while(n < 0): 
   n = eval(input("Your number needs to be positive --> "))

empty = "*"

for i in range(n+1):
   print(empty*i)
print("Your triangle is", n, "levels high")
