#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int Reflector(int reflector[8][2], int indexRotorL) {
    for(int k = 0; k < 8; k++){
        if(reflector[k][0] == indexRotorL){
           int indexReflector = reflector[k][1];
           return indexReflector;
        }
    }
}

void passRotors() {
    
}

void shiftRotors(int rotorRight[8][2], int rotorCenter[8][2], int rotorLeft[8][2] ) {
    int counterR, counterC;
    for(int i = 7; i > 0; i--){
        int perR = rotorRight[i][1];
        rotorRight[i][1] = rotorRight[i-1][1];
        rotorRight[i-1][1] = perR;
    }
    counterR++;
    if(counterR == 7) {
        counterR = 0;
        for(int i = 7; i > 0; i--){
            int perC = rotorCenter[i][1];
            rotorCenter[i][1] = rotorCenter[i-1][1];
            rotorCenter[i-1][1] = perC;
        }
        counterC++;
        if(counterC == 7) {
            counterC = 0;
            for(int i = 7; i > 0; i--){
                int perL = rotorLeft[i][1];
                rotorLeft[i][1] = rotorLeft[i-1][1];
                rotorLeft[i-1][1] = perL;
            }
        }
    }
}

void Enigma(string inputData,string alphabet, int reflector[8][2], int rotorRight[8][2], int rotorCenter[8][2],int rotorLeft[8][2]) {
    for(int i = 0; i < inputData.length(); i++){
        if(isalpha(inputData[i])){

        }
    }
}

void rotorsFind() {

}


int main() {
    string inputData;
    int alphabet[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
    int num_rotors = 3;
    int code = 0;
    int reflector[] = {24, 17, 20, 7, 16, 18, 11, 3, 15, 23, 13, 6, 14, 10, 12, 8, 4, 1, 5, 25, 2, 22, 21, 9, 0, 19};
    int rotors[][26] = {
        {4, 10, 12, 5, 11, 6, 3, 16, 21, 25, 13, 19, 14, 22, 24, 7, 23, 20, 18, 15, 0, 8, 1, 17, 2, 9},
        {0, 9, 3, 10, 18, 8, 17, 20, 23, 1, 11, 7, 22, 19, 12, 2, 16, 6, 25, 13, 15, 24, 5, 21, 14, 4},
        {1, 3, 5, 7, 9, 11, 2, 15, 17, 19, 23, 21, 25, 13, 24, 4, 8, 6, 0, 10, 12, 20, 18, 16, 14}
    };
    int ringSettings[] = {2, 21, 17};

    // Прямой проход
    int new_code = rotors[0][ringSettings[2] + code];
    cout << new_code << endl;

    if((abs(ringSettings[1] - ringSettings[2])) > 12){
        new_code = rotors[1][new_code + (ringSettings[1] + (25 - ringSettings[2]))];
    } else {
        new_code = rotors[1][new_code + (ringSettings[1] - ringSettings[2])];
    }
    cout << new_code << endl;
    
    if((abs(ringSettings[0] - ringSettings[1])) > 12){
        new_code = rotors[2][new_code + (ringSettings[0] + (25 - ringSettings[1]))];
    } else {
        new_code = rotors[2][new_code + (ringSettings[0] - ringSettings[1])];
    }
    cout << new_code << endl; // 12

    new_code = reflector[new_code - ringSettings[0]];
    cout << new_code << endl; // 13

    
    //Обратный проход

    for(int i = 0; i < 26; i++){
        if(rotors[2][i] == new_code + ringSettings[0]){
            new_code = alphabet[i];
        }
    }
    cout << new_code << endl;

    for(int i = 0; i < 26; i++){
        if(rotors[2][i] == new_code + ringSettings[0]){
            new_code = alphabet[i];
        }
    }
    cout << new_code << endl; // 7

    
    cout << new_code << endl; // 17

    for(int i = 0; i < 26; i++){
        if(rotors[2][i] == new_code - (ringSettings[1] - ringSettings[2])){
            new_code = alphabet[i];
        }
    }

    for(int i = 0; i < 26; i++){
        if(rotors[2][i] == new_code - ringSettings[2]){
            new_code = alphabet[i];
        }
    }
    
    // cout << "Введите входные данные: ";
    // getline(cin,inputData);
    // Enigma(inputData,alphabet,reflector, rotorRight, rotorCenter, rotorLeft);
    // cout << endl;
    return 0;
}
// AY BR CU DH EQ FS GL IP JX KN MO TZ VW