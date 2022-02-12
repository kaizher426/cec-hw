x = input("FirstNumber: ")
y = input("SecondNumber: ")
g = input("+.-.*./: ")

if g == "+":
  print(int(x)+int(y))

elif g == "-":
  print(int(x)-int(y))

elif g == "*":
  print(int(x)*int(y))

elif g == "/":
  print(int(x)/int(y))

else:
  print("error")
