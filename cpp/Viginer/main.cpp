#include <iostream>

using namespace std;

int* ViginerKey(string key){
    int *arr = new int[key.length()];
    for(int i = 0; i < key.length(); i++) {
        arr[i] = abs(97 - int(tolower(key[i])));
    }
    return arr;
}

void Viginer(string inputData, string key) {
    int *arr = ViginerKey(key);
    for(int i = 0; i < inputData.length(); i++){
        if(i >= key.length()) {
            int j = i - key.length();
        } else {
            int j = i;
        cout << (i - key.length()) << endl;
        if(int(inputData[i]) + arr[j] > 122) {
            cout << char(97 + (arr[j] - (123 - int(inputData[i]))));
        } else {
            cout << char(int(inputData[i]) + arr[j]);
        }
        }
    }
}
int main() {
    Viginer("abc", "xyz");
    cout << endl;
    return 0;
}
// Не закончен