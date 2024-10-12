def binFind(arr, len, index, num):
    if(len > index):
        if(arr[index] == num): 
            return index
        elif(num < arr[index]):
            return binFind(arr, len, index-1, num)
        else: 
            return binFind(arr,len, index+1, num)
    return -1

def countingSort(arr):
    arrCounter = [0] * len(arr)
    for i in range(len(arr)):
        for j in range(i+1, len(arr)):
            if(arr[i] > arr[j]):
                arrCounter[i] += 1
            else: arrCounter[j] += 1
    newArr = [0] * len(arr)
    for i in range(len(arr)):
        newArr[arrCounter[i]] = arr[i]
    return newArr

arr = [3,1,2,5,4,6,8,7]
inputData = int(input("Введите искомое значение: "))
print("Индекс искомого значения:",binFind(countingSort(arr), len(arr), len(arr)//2, inputData))