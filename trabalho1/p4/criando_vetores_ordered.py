import random

def generate_ordered_random_list(n):
    upper_limit = 10**n
    sample_size = upper_limit // 2
    random_numbers = random.sample(range(upper_limit), sample_size)
    return sorted(random_numbers)

n = int(input("Enter the value of n: "))

with open("vetores.txt", "w") as V:

    for n in range(0, 7):
        V.write("// Base " + str(n) + " //--------------------------\n")
        V.write("{")
        array = generate_ordered_random_list(n)
        for i in array:
            V.write(str(i))
            if i!= 10**n -1 :
                V.write(", ")
        V.write("}\n")
