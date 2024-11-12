def caesarROT(inputData, rotNum):
    for ch in inputData:
        if(ch.isalpha()):
            print(chr(97 + (ord(ch) - 97 + rotNum) % 26), end='')
        elif(ch.isdigit()):
            print(chr(48 + (ord(ch) - 48 + rotNum) % 10), end='')
        else:
            print(ch, end='')
print("Вывод: ", end='')
caesarROT("Hello", 20)
print("\n")