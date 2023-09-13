import random

def generate_random_list(n):
    upper_limit = 10**n
    return random.sample(range(upper_limit), upper_limit)

n = int(input("Enter the value of n: "))
print(generate_random_list(n))


with open("vetores.txt", "w") as V:

    for n in range(0, 7):
        V.write("// Base " + str(n) + " //--------------------------\n")
        V.write("{")
        array = generate_random_list(n)
        for i in array:
            V.write(str(i))
            if i!= 10**n -1 :
                V.write(", ")
        V.write("}\n")
