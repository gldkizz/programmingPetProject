#include <iostream>
#include <vector>

using namespace std;

// Функция для вычисления определителя матрицы размером n x n
double determinant(const vector<vector<double>>& matrix, int n) {
    double det = 0.0;

    // Базовый случай для 2x2 матрицы
    if (n == 1) {
        return matrix[0][0];
    }
    if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    // Разложение по первой строке
    for (int k = 0; k < n; k++) {
        // Создаем матрицу меньшего размера для миноров
        vector<vector<double>> subMatrix(n - 1, vector<double>(n - 1));

        for (int i = 1; i < n; i++) {
            int subCol = 0;
            for (int j = 0; j < n; j++) {
                if (j == k) continue; // Пропускаем текущий столбец
                subMatrix[i - 1][subCol] = matrix[i][j];
                subCol++;
            }
        }

        // Рекурсивный вызов для вычисления определителя
        det += (k % 2 == 0 ? 1 : -1) * matrix[0][k] * determinant(subMatrix, n - 1);
    }

    return det;
}

int main() {
    int n;
    cout << "Введите размер матрицы (n x n): ";
    cin >> n;

    vector<vector<double>> matrix(n, vector<double>(n));

    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    double det = determinant(matrix, n);
    cout << "Определитель матрицы: " << det << endl;

    return 0;
}