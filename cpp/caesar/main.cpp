#include <iostream>

using namespace std;

// =============== 1.0 ==================
// void caesarROT(string inputData, int rotNum) {
//     for (char c: inputData) {
//         if(isalpha(c)) {
//             if(isupper(c)){
//                 if(int(tolower(c)) + rotNum > 122) cout << char(toupper(97 + (rotNum - (123 - int(tolower(c))))));
//                 else cout << char(toupper(int(tolower(c)) + rotNum));
//             } else {
//                 if(int(c) + rotNum > 122) cout << char((97 + (rotNum - (123 - int(c)))));
//                 else cout << char(int(c) + rotNum);
//             }}
//         else if (isdigit(c)) 
//             if (int(c) + rotNum > 57 && rotNum > 9) cout << char(int(c) + rotNum % 10);
//             else if (int(c) + rotNum > 57 && rotNum < 10) cout << char(48 + (rotNum - (58 - int(c))));
//             else cout << char(int(c) + rotNum);
//         else cout << c;
//     }
// }


// ============== 2.0 ===================
void caesarROT(string inputData, int rotNum) {
    for(char c: inputData) {
        if(isalpha(c)) cout << char(97 + (int(c) - 97 + rotNum) % 26);
        else if(isdigit(c)) cout << char(48 + (int(c) - 48 + rotNum) % 10);
        else cout << c;
    }
}

int main() {
    caesarROT("x123", 123564325);
    cout << endl;
    return 0;
}