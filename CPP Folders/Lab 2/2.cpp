#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int number;
    cout << "Введите трёхзначное число: ";
    cin >> number;
    if (number>=100 && number<=999 || number>=-999 && number<=-100)
        cout << (pow(number,2)==pow(number/100+number%10+number%100/10,3) ?
        "Квадрат числа равен кубу суммы цифр": "Квадрат числа не равен сумме цифр");
    else
        cout << "Число не является трёхзначным";
}