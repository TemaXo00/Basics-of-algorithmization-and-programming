#include <iostream>
#include <string>
using namespace std;
string changeNumeralTo (int a, int b) {
    if (a==1)
        return "1";
    if (a==0)
        return "0";
    if (a>2)
        return changeNumeralTo(a/b,b)+to_string(a%b);
}
int main() {
    int number, numeral;
    cout << "Введите число: ";
    cin >> number;
    cout << "Введите необходимую систему счисления:\nУсловие: она должна быть более 2 и менее 10\n";
    do {
        cin >> numeral;
        if (numeral >10 || numeral<2)
            cout << "Условие не было выполнено. Введите заново: ";
    } while (numeral >10 || numeral<0);
    cout << changeNumeralTo (number, numeral);
}