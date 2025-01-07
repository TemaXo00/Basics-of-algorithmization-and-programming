#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double y, a=0.1, b=1, h=(b-a)/10, n=160, fact=1;
    long double s;
    cout << "x" << setw(15) << "s" << setw(15) << "y" << endl;
    do {
        s=a;
        for (int i=1; i<=n;i++) {
            for (int j = 1; j <= 2 * i + 1; j++)
                fact *= j;
            s += pow(-1, i) * (pow(s, 2 * i + 1) / fact);
            fact=1;
        }
        y=sin(a);
        cout << a << setw(15) << s << setw(15) << y << endl;
        a+=h;
    }while(a<=b);
}