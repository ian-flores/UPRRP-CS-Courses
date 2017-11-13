print("Welcome")
print("
m = eval(input("Enter the largest integer -->"))
n = eval(input("Enter the smallest integer -->"))

r = m%n

if (m < n): 
   print("Please follow the instructions.")
else: 
   while(r != 0): 
      m = n 
      n = r
      r = m%n
   print(n) 
