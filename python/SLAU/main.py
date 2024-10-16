def outData(numEq, A, Y):
    for i in range(numEq):
        for j in range(numEq):
            print(f"{A[i][j]}*x{j}",end='')
            if (j < numEq - 1):
                print(' + ',end='')
        print(f" = {Y[i]}")

def Gauss(A, Y, numEq):
    X = [0] * numEq
    
    for i in range(numEq):
        maxEl = abs(A[i][i])
        maxRow = i
        for j in range(i+1,numEq):
            if(abs(A[j][i]) > maxEl):
                maxEl = abs(A[j][i])
                maxRow = j

        temp1 = A[maxRow]
        A[maxRow] = A[i]
        A[i] = temp1
        temp2 = Y[maxRow]
        Y[maxRow] = Y[i]
        Y[i] = temp2
        outData(numEq,A,Y)
        print('')
        
        for k in range(i+1, numEq):
            coeff = A[k][i] / A[i][i]
            for j in range(i, numEq):
                A[k][j] -= coeff * A[i][j]
            Y[k] -= coeff * Y[i]
        
    for i in range(numEq-1, -1, -1):
        print(i)
        X[i] = Y[i] / A[i][i]
        for k in range(i-1, -1,-1):
            Y[k] -= A[k][i] * X[i]

    for i in range(numEq):
        print(f"x[{i}] = {X[i]}")
        

numEq = int(input("Введите количество уравнений: "))
A = [[0 for j in range(numEq)] for i in range(numEq)]
Y = [0] * numEq
for i in range(numEq):
    for j in range(numEq):
        A[i][j] = int(input(f"A[{i}][{j}]: "))
for i in range(numEq):
    Y[i] = int(input(f"y[{i}]: "))
outData(numEq, A, Y)
Gauss(A, Y, numEq)
