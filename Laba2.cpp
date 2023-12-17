/*******************************************************
* 
* Степанов Артём Андреевич,ПИ-231
* Share-Link:https://onlinegdb.com/k5XDof1ZP
* Тема: Циклы с пред- и постусловием, вариант 20
* 
********************************************************/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
   double Mass = 500.0, ie = 2.718, ue = 18.0, qe = 90.0;
   /*double toki[] {0, 2.0, 4.0, 6.0, 8.0, 10.0, 15.0, 20.0, 25.0, 30.0};*/
   double toki = 0;
   while (toki < 10) { // Заменяем цикл for на цикл while
        double t = toki,v, n;
        v = ue * (1 - pow(ie, -( (qe * t) / Mass) ) );
        n = 2 * ( 1 - (v / ue) ) * (v / ue);
        cout << "t=" << toki << endl;
        cout << "v=" << v << endl;
        cout << "n=" << n << endl;
        toki += 2;}
    do { 
        double t = toki,v, n;
        v = ue * (1 - pow(ie, -( (qe * t) / Mass) ) );
        n = 2 * ( 1 - (v / ue) ) * (v / ue);
        cout << "t=" << toki << endl;
        cout << "v=" << v << endl;
        cout << "n=" << n << endl;
        toki += 5;
        } 
    while(toki < 31);
    
}
