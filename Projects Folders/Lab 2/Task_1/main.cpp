#include <iostream>
using namespace std;

int main() {
    int a,b,c;
    cout << "Введите стороны a,b,c: ";
    cin >> a >> b >> c;
    cout << (a==b || b==c || a==c ? "Треугольник равнобедренный": "Треугольник не равнобедренный");
}