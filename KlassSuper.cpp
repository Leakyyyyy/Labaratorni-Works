/******************************************************************************
* Степанов Артём Андреевич,ПИ-231
* Share-Link:https://onlinegdb.com/9GyHxfDMB
* Тема: Использование процедур и функций, вариант 20  
*******************************************************************************/
#include <iostream>
using namespace std;

int trash(int masiv[], int size) {
    int cloun = 0;
    for (int i = 0; i < size; i++) {
        if (masiv[i] > 0) {
            cloun++;
        }
    }
    return cloun;
}

int main() {
    const int n = 5; 
    const int m = 7;  

    int F[n] = {-1, 2, -3, 4, -5};
    int G[m] = {1, -2, 3, -4, 5, -6, 7};

    int lol = trash(F, n);

    int kek = trash(G, m);

    cout << "Количество положительных элементов в массиве F: " << lol << endl;
    cout << "Количество положительных элементов в массиве G: " << kek << endl;

    return 0;
}
