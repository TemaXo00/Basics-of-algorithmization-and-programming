#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a;
    cout << "Введите длину ребра куба: ";
    cin >> a;
    cout << "Объем куба: " << pow(a,3) << "\nПлощадь поверхности: " << 6*pow(a,2);
}