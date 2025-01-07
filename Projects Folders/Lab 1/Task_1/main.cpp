#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int z;
    cout << "Введите величину z, выраженную в байтах: ";
    cin >> z;
    cout << "Величина в кб: " << z/1024 << endl << "Величина в мб: " << z/pow(1024,2);
}