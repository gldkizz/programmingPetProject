#include <iostream>
#include <array>

using namespace std;

int* insertSort(int* arr, int len) {
    for(int i = 1; i < len; i++){
        for(int j = i; j > 0 && arr[j-1] > arr[j]; j--){
            int per = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = per;
        }
    }
    return arr;
}

int binFind(int arr[], int index, int num, int len, int c) {
    if (len > index) {
        if (arr[index] == num) {
            cout << c << " - количество проходов" << endl;
            return index;
        }
        else if (num > arr[index]) {
            c++;
            return binFind(arr, index + 1, num, len, c);
        }
        else {
            c++;
            return binFind(arr, index - 1, num, len, c);
        }
    }
    return -1;
}

int main() {
    int arr[] = {3,1,6,12,8,235,2,75};
    int lenArr = sizeof(arr)/sizeof(arr[0]);
    int num;
    cout << "Введите искомое значение: ";
    cin >> num;

    cout << binFind(insertSort(arr, lenArr), lenArr / 2, num, lenArr, 0) << " - индекс искомого значения" << endl;
}