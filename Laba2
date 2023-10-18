/*******************************************************
* 
* Степанов Артём Андреевич,ПИ-231
* Share-Link:https://onlinegdb.com/5SQ5334Vd
* Тема: Циклы с пред- и постусловием, вариант 20
* 
********************************************************/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
   double M = 500.0;
   double q = 90.0;
   double u = 18.0;
   double e = 2.718;
   double toki[10] {0, 2.0, 4.0, 6.0, 8.0, 10.0, 15.0, 20.0, 25.0, 30.0};
   for(double t : toki) {
        double v;
        v = u * (1 - pow(e, -( (q * t) / M) ) );
        double n;
        n = 2 * ( 1 - (v / u) ) * (v / u);
        cout << "t=" << t << endl;
        cout << "v=" << v << endl;
        cout << "n=" << n << endl;
    }
}
