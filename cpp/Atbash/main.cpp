#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void atbashEncoder(string inputData) {
    for(int i = 0; i < inputData.length(); i++){
        if(isalpha(inputData[i])){
            if(isupper(inputData[i])) {
                cout << char(toupper(122 - (int(tolower(inputData[i])) - 97)));
            } else {
                cout << char(122 - (int(tolower(inputData[i])) - 97));
            }
        } else if(!isdigit(inputData[i])){
            cout << inputData[i];
        }
    }
}

void atbashDecoder(string outputData) {
    for(int i = 0; i < outputData.length(); i++){
        if(isalpha(outputData[i])){
            if(isupper(outputData[i])) {
                cout << char(toupper(122 - (int(tolower(outputData[i])) - 97)));
            } else {
                cout << char(122 - (int(tolower(outputData[i])) - 97));
            }
        } else if(!isdigit(outputData[i])){
            cout << outputData[i];
        }
    }
}


int main() {
    string inputData;
    string outputData;
    char input;
    cout << "1. Шифратор" << "\n" << "2. Дешифратор" << endl; 
    cout << "Введите цифру: ";
    cin >> input;
    switch (input)
    {
    case '1':
    {
        cout << "Введите входные данные: ";
        cin.get();
        getline(cin, inputData);
        atbashEncoder(inputData);
        break;
    }
    case '2':
    {
        cout << "Введите выходные данные: ";
        cin.get();
        getline(cin, outputData);
        atbashDecoder(outputData);
        break;
    }
    default:
        break;
    }
    cout << endl;
    return 0;
}