#include <iostream>
#include <cmath>

using namespace std;

int findDet(int** matr, int n) {
    if(n == 1) {
        return matr[0][0];
    }
    else if(n == 2){
        return matr[0][0]*matr[1][1]-matr[0][1]*matr[1][0];
    } 
    else {
        double det = 0.0;
        for(int k = 0; k < n; k++){
            int** subMatr = new int*[n-1];
            for(int i = 0; i < n -1; i++){
                subMatr[i] = new int[n-1];
            }
            for(int i = 1;i < n; i++){
                int subCol = 0;
                for(int j = 0; j < n; j++) {
                    if(j == k) continue;
                    subMatr[i-1][subCol] = matr[i][j];
                    subCol++;
                }
            }
            det += (k % 2 == 0 ? 1 : -1) * matr[0][k] * findDet(subMatr, n-1);
        }
        return det;
    }
}

void Kramer(int** matr, int* constants, int n) {
    int det = findDet(matr, n);
    if(det == 0) {
        cout << "СЛАУ нельзя решить методом Крамера";
        return;
    }
    int* res = new int(n);
    for(int i = 0; i < n; i++){
        int** modMatr = new int*[n];
        for(int j = 0; j < n; j++){
            modMatr[j] = new int[n];
            for(int k = 0; k < n; k++){
                modMatr[j][k] = matr[j][k];
            }
            modMatr[j][i] = constants[j];
        }
        res[i] = findDet(modMatr,n) / det;
        for(int j = 0; j < n; j++){
            delete[] modMatr[j];
        }
        delete[] modMatr;
    }
    for(int i = 0; i < n; i++){
        cout << "x[" << i << "]: " << res[i] << endl;
    }

}

int main() {
    int n;
    cout << "Введите кол-во неизвестных: ";
    cin >> n;
    int** matr = new int*[n];
    for(int i = 0; i < n; i++){
        matr[i] = new int[n];
        for(int j = 0; j < n; j++){
            cout << "matr[" << i+1 << "][" << j+1 << "]: ";
            cin >> matr[i][j];
        }
    }
    int* constants = new int[n];
    cout << "Введите свободные члены" << endl;
    for(int i = 0; i < n; i++){
        cout << "const[" << i+1 << "]: ";
        cin >> constants[i];
    }
    Kramer(matr, constants, n);
    exit(0);
}

