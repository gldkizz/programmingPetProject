#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

void shiftRotors(int rotors[][26]) {
    int counterR, counterC;
    for(int i = 25; i > 0; i--){
        int perR = rotors[2][i];
        rotors[2][i] = rotors[2][i-1];
        rotors[2][i-1] = perR;
    }
    counterR++;
    if(counterR == 26) {
        counterR = 0;
        for(int i = 26; i > 0; i--){
            int perC = rotors[1][i];
            rotors[1][i] = rotors[1][i-1];
            rotors[1][i-1] = perC;
        }
        counterC++;
        if(counterC == 26) {
            counterC = 0;
            for(int i = 26; i > 0; i--){
                int perL = rotors[0][i];
                rotors[0][i] = rotors[0][i-1];
                rotors[0][i-1] = perL;
            }
        }
    }
}

// int binFind(int rotors[], int num, int index) {
//     if(26 > index) {
//         if(rotors[index] == num) {
//             return index;
//         } else if(num > rotors[index]) {
//             return binFind(rotors, num, index + 1);
//         } else {
//             return binFind(rotors, num, index - 1);
//         }
//     }
//     return -1;
// }

int findIndex(int rotors[], int num) {
    for(int i = 0; i < 26; i++){
        if(rotors[i] == num) {
            return i;
        }
    }
    return -1;
}

void EnigmaStraightRotorPassage(int rotors[][26], int ringSettings[], int reflector[], int alphabet[], vector<int>&inputDataIndex) {
    for(int i = 0; i < inputDataIndex.size(); i++) {
        int numRot, new_code, code;
        code = inputDataIndex[i];

        // Прямой проход
        new_code = rotors[2][(code + ringSettings[2]) % 26];
        
        if(abs(ringSettings[1] - ringSettings[2]) > 12) {
            numRot = 26 - abs(ringSettings[1] - ringSettings[2]);
        } else {
            numRot = abs(ringSettings[1] - ringSettings[2]);
        }
        new_code = rotors[1][(new_code + numRot) % 26];

        if(abs(ringSettings[0] - ringSettings[1]) > 12) {
            numRot = 26 - abs(ringSettings[0] - ringSettings[1]);
        } else {
            numRot = abs(ringSettings[0] - ringSettings[1]);
        }
        new_code = rotors[0][(new_code + numRot) % 26];

        // reflector
        if((new_code - ringSettings[0]) % 26 < 0) {
            new_code = reflector[26 - abs((new_code - ringSettings[0]) % 26)];
        } else {
            new_code = reflector[(new_code - ringSettings[0]) % 26];
        }

        // Обратный проход
        new_code = alphabet[findIndex(rotors[0],(new_code + ringSettings[0]) % 26)];

        if(abs(ringSettings[0] - ringSettings[1]) > 12) {
            numRot = 26 - abs(ringSettings[0] - ringSettings[1]);
        } else {
            numRot = abs(ringSettings[0] - ringSettings[1]);
        }
        if((new_code - numRot) % 26 < 0) {
            new_code = alphabet[findIndex(rotors[1], 26 - abs((new_code - numRot) % 26))];
        } else {
            new_code = alphabet[findIndex(rotors[1], (new_code - numRot) % 26)];
        }

        if(abs(ringSettings[1] - ringSettings[2]) > 12) {
            numRot = 26 - abs(ringSettings[1] - ringSettings[2]);
        } else {
            numRot = abs(ringSettings[1] - ringSettings[2]);
        }
        if((new_code - numRot) % 26 < 0) {
            new_code = alphabet[findIndex(rotors[2], 26 - abs((new_code - numRot) % 26))];
        } else {
            new_code = alphabet[findIndex(rotors[2], (new_code - numRot) % 26)];
        }
        
        if((new_code - ringSettings[2]) % 26 < 0) {
            new_code = 26 - abs((new_code - ringSettings[2]) % 26);
        } else {
            new_code = (new_code - ringSettings[2]) % 26;
        }
        cout << char(new_code + 65);
        shiftRotors(rotors);
    }
}

int main() {
    string inputData;
    vector<int> inputDataIndex;
    int alphabetInt[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
    int reflector[] = {24, 17, 20, 7, 16, 18, 11, 3, 15, 23, 13, 6, 14, 10, 12, 8, 4, 1, 5, 25, 2, 22, 21, 9, 0, 19};
    int rotors[][26] = {
        {1, 3, 5, 7, 9, 11, 2, 15, 17, 19, 23, 21, 25, 13, 24, 4, 8, 22, 6, 0, 10, 12, 20, 18, 16, 14},
        {0, 9, 3, 10, 18, 8, 17, 20, 23, 1, 11, 7, 22, 19, 12, 2, 16, 6, 25, 13, 15, 24, 5, 21, 14, 4},
        {4, 10, 12, 5, 11, 6, 3, 16, 21, 25, 13, 19, 14, 22, 24, 7, 23, 20, 18, 15, 0, 8, 1, 17, 2, 9}
    };
    int ringSettings[] = {2, 21, 17};

    cout << "Input data: ";
    getline(cin,inputData);
    for(int i = 0; i < inputData.length(); i++) {
        if(int(inputData[i]) == 32 || (int(inputData[i]) >= 48 && int(inputData[i]) <= 57)) { // Обработка пробела и цифр
            continue;
        }
        inputDataIndex.push_back(int(inputData[i]) - 65);
    }
    cout << "OutputData: ";
    EnigmaStraightRotorPassage(rotors, ringSettings, reflector, alphabetInt, inputDataIndex);
    cout << endl;
    return 0;
}