print("Criando Vetores")

with open("vetores.txt", "w") as V:

    for n in range(0, 7):
        V.write("// Base " + str(n) + " //--------------------------\n")
        V.write("{")
        for i in range(0, 10**n):
            V.write(str(i))
            if i!= 10**n -1 :
                V.write(", ")
        V.write("}\n")

