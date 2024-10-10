#include <iostream>

using namespace std;

int BinarySearch(int arr[], int arrsize, int tar, int index)
{
    if (arrsize > index && 0 <= index)
        if (arr[index] == tar)
            return index;
        else if (arr[index] < tar && arr[index + 1])
            return -1;
        else if (arr[index] < tar)
            return BinarySearch(arr, arrsize, tar, index + 1);
        else
            return BinarySearch(arr, arrsize, tar, index - 1);
    return -1;
}

int main() {
    int arr[] = {11,22,33,44,55,77,66,88,99,110};
    int arrsize = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + arrsize);

    cout << "arr: ";
    for (int x : arr)
        cout << x << ",";
    cout << "\n";

    cout << "tar index:" << BinarySearch(arr, arrsize, 107, arrsize / 2) << "\n";
}