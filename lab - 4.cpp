/******************************************************************************
* Степанов Артём Андреевич,ПИ-231
* Share-Link:https://onlinegdb.com/bnocDzcYH
* Тема: Обработка массивов, вариант 20  
*******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    srand(time(0));
    int matrix[100][100];

    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            matrix[i][j] = rand() % 100; // случайные числа от 0 до 99, по тому что мне много не надо
        }
    }

    cout << "Исходная матрица:" << endl;
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            cout << matrix[i][j] << "\t"; // можно не надо
        }
        cout << endl;
    }
    
    int maxMainDiagonal = matrix[0][0];
    int maxSecondaryDiagonal = matrix[0][100 - 1];

    for (int i = 0; i < 100; ++i) {
        if (matrix[i][i] > maxMainDiagonal) {
            maxMainDiagonal = matrix[i][i];
        }

        if (matrix[i][100 - 1 - i] > maxSecondaryDiagonal) {
            maxSecondaryDiagonal = matrix[i][100 - 1 - i];
        }
    }
    cout << "Максимальный элемент на главной диагонали: " << maxMainDiagonal << endl;
    cout << "Максимальный элемент на побочной диагонали: " << maxSecondaryDiagonal << endl;

    return 0;
}
