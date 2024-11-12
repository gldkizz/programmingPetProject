from random import randint

def getRandomPrimeNumber():
    flag = False
    while(flag == False):
        n = randint(2, 1_000_000_000)
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
            if(pow(g, n // delit, mod) == 1):
                is_primitive = False
                break
        if(is_primitive): return g

def encoder(key, inputData):
    encod = ""
    for ch in inputData:
        if(ch.isalpha()): 
            encod += chr(33 + ((ord(ch) - 33 + key) % 93))
        # elif(ch.isdigit()): print(chr(48 + ((ord(ch) - 48 + key) % 10)),end='')
        # else: print(ch, end='')
    return encod
        
def decoder(key, inputData):
    for ch in inputData:
        print(chr(33 + ((ord(ch) - 33 - key) % 93)), end='')
        # elif(ch.isdigit()): print(chr(48 + ((ord(ch) - 48 - key) % 10)),end='')
        # if(not (ch.isalpha())): print(ch, end='')
        



primeNumber = getRandomPrimeNumber()
g = primitiveRoot(primeNumber)

secretKeyA = randint(1,100000)
publicKeyA = (g**secretKeyA) % primeNumber

secretKeyB = randint(1,100000)
publicKeyB = (g**secretKeyB)% primeNumber

globalKeyA = (publicKeyB**secretKeyA) % primeNumber
globalKeyB = (publicKeyA**secretKeyB) % primeNumber

encod = encoder(globalKeyA, "hello, world!")
decoder(globalKeyB,encod)
print("\n")