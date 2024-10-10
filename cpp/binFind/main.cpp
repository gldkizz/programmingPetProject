#include <iostream>
#include <array>

using namespace std;



int binFind(int arr[], int left, int right, bool flag, int number) {
    int middle;
    while((left <= right) && (flag != true)) {
        middle = (left + right) / 2;
        if(arr[middle] == number) {
            flag = true;
            middle--;
        }
        if(arr[middle > number]) {
            right = middle--;
        }
        else { 
            left = middle++;
        }
    }
    if(flag) {
        cout << "Индекс элемента " << number << " в массиве равен: " << middle << endl;
    } else {
        cout << "Такого элемента в массиве не существует";
    }
}

int main() {
    int arr[] = {4,2,6,3,5,7,1};
    bool flag = false;
    int left = 0;
    int right = sizeof(arr)/sizeof(arr[0]) - 1; // len - 1 // 8
    int num;
    cout << "Введите искомое значение: ";
    cin >> num;

    for (int i = 0; i <= right; i++){
        for(int j = i; j <= right; j++){
            if(arr[j] > arr[j+1]) {
                int per = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = per;
            }
        }
    }

    binFind(arr, left, right, flag, num);
    
    return 0;
}