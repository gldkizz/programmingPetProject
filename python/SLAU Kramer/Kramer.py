def findDet(matr, n):
    if(n == 1):
        return matr[0][0]
    if(n == 2):
        return matr[0][0] * matr[1][1] - matr[0][1] * matr[1][0]
    else:
        det = 0
        for k in range(n):
            subMatr = [[0 for i in range(n-1)] for k in range(n-1)]
            for i in range(1, n):
                subCol = 0
                for j in range(n):
                    if (j == k): continue
                    subMatr[i-1][subCol] = matr[i][j]
                    subCol += 1
            det += (1 if k % 2 == 0 else -1) * matr[0][k] * findDet(subMatr, n-1)
        return det
    
def Kramer(matr, constants, n):
    det = findDet(matr, n)
    if (det == 0): 
        print("СЛАУ нельзя решить методом Крамера")
        return
    res = [0 for i in range(n)]
    for i in range(n):
        modMatr = [[0 for i in range(n)] for j in range(n)]
        for j in range(n):
            for k in range(n):
                modMatr[j][k] = matr[j][k]
            modMatr[j][i] = constants[j]
        res[i] = findDet(modMatr, n) / det
    for i in range(n):
        print(f"x({i}) =",res[i])

n = int(input("Введите количество переменных: "))
matr = [[0 for j in range(n)] for i in range(n)]
constants = [0 for j in range(n)]
for i in range(n):
    for j in range(n):
        matr[i][j] = int(input(f"matr[{i+1}][{j+1}]: "))
for i in range(n):
    constants[i] = int(input(f"constants[{i+1}]: "))
Kramer(matr, constants, n)
    

