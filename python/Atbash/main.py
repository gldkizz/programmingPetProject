def atbashEncoder(inputData):
    for i in inputData:
        if(i.isalpha()):
            if(i.isupper()): print((chr(122 - (ord(i.lower()) - 97))).upper(), end='')
            else: print(chr(122 - (ord(i) - 97)), end='')
        elif(i.isdigit() == False): print(i, end='')

def atbashDecoder(inputData):
    for i in inputData:
        if(i.isalpha()):
            if(i.isupper()): print((chr(122 - (ord(i.lower()) - 97))).upper(), end='')
            else: print(chr(122 - (ord(i) - 97)), end='')
        elif(i.isdigit() == False): print(i, end='')

print("1. Шифратор \n2. Дешифратор")
inputChoise = input("Введите цифру: ")
if(inputChoise == '1'): 
    inputData = input("Введите строку для шифрования: ")
    atbashEncoder(inputData)
    print()
elif(inputChoise == '2'):
    inputData = input("Введите строку для дешифрования: ")
    atbashDecoder(inputData)
    print()