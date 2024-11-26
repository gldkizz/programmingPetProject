#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <ctime>
#include <vector>
//#include <boost/multiprecision/cpp_int.hpp>

using namespace std;

// int generator() {
//     int a;
//     static time_t tval = time(0);
//     tval += 10;
//     srand(tval);
//     while(true) {
//         int z = 0, kol = 0;
//         a = 1 + rand() % 100;
//         for(int i = 2; i < a; i++)
//         {
//             if(a%i==1) continue; 
//             if(a%i==0) {
//                 z=1; break;
//             }
//         } 
//         if(z==0) {
//             break;
//         }
//     }
// }

// bool isPnimitiveRoot(int р, int g) {
//     vector S(p); 
//     int t = 1;
//     S[l] = true;
//     for (int i = 2; i < p; i++){
//         t = (t * g) % p; 
//         if (S[t]) {
//             return false;
//         }
//         S[t] = true;
//     }
//     return true;
// }

void toupper(long long unsigned int &num, int k)
{
    for (int i = 0; i < k; i++)
        num *= num;
}

int main() {
    //mpz_class partial_key_A;
    long long unsigned int public_key_A = 197;
    long long unsigned int secret_key_A = 199;
    long long unsigned int public_key_B = 151;
    long long unsigned int secret_key_B = 199;

    toupper(public_key_A, secret_key_A);
    unsigned long long partial_key_A = pow(public_key_A,secret_key_A);
    partial_key_A = partial_key_A % public_key_B;

    // int partial_key_B = pow(public_key_B, secret_key_B);
    // partial_key_B = partial_key_B % public_key_A;
    cout << partial_key_A << endl;

    // int full_key_A = get_full_key(partial_key_B, public_key_B, secret_key_A);
    // int full_key_B = get_full_key(partial_key_A, public_key_A, secret_key_B);

    // cout << full_key_A << " " << full_key_B << endl;
    return 0;
}