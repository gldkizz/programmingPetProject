from random import randint
import time

start_time = time.time()
def getRandomPrimeNumber():
    flag = False
    while(flag == False):
        n = randint(2, 10**10)
        lst = []
        for i in range(1,int(n ** 0.5) + 1):
            if(n % i == 0):
                lst.append(i)
                lst.append(n//i)
        if(len(lst) == 2):
            flag = True
            return n
        
def primitiveRoot(mod):
    n = mod - 1
    lst = []
    for i in range(2,int(n ** 0.5) + 1):
            if(n % i == 0):
                lst.append(i)
                lst.append(n//i)
    lst = set(lst)

    for g in range(2, mod):
        is_primitive = True
        for delit in lst:
            if((pow(g, n // delit) % mod) == 1):
                is_primitive = False
                break
        if(is_primitive): return g

primeNumber = getRandomPrimeNumber()
g = primitiveRoot(primeNumber)

secretKeyA = randint(1,10**10)
secretKeyB = randint(1,10**10)

publicKeyA = (g**secretKeyA) % primeNumber
publicKeyB = (g**secretKeyB) % primeNumber

# print("\n ===== Общие данные для двух собеседников:\n",
#     "Простое число:",primeNumber,"\n",
#     "Первообразный корень по модулю:",g,'\n',
#     "===== Данные собеседника A:\n",
#     "Секретный ключ:", secretKeyA,'\n',
#     "Публичный ключ:", publicKeyA,'\n',
#     "===== Данные собеседника B:\n",
#     "Секретный ключ:", secretKeyB,'\n',
#     "Публичный ключ:",publicKeyB,'\n'
# )

fullKeyA = (publicKeyB**secretKeyA) % primeNumber
fullKeyB = (publicKeyA**secretKeyB) % primeNumber

print("\nПолный ключ собеседника A:", fullKeyA, "\nПолный ключ собеседника B:",fullKeyB)

end_time = time.time()
elapsed_time = end_time - start_time
print("Elapsed time:", elapsed_time)