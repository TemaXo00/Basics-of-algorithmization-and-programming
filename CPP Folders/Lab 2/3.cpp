#include <iostream>
using namespace std;

int main() {
    int a,b,operation;
    cout << "Введите числа a и b: ";
    cin >> a >> b;
    cout << "Выберите операцию:\n1 — Сложение\t2 — Вычитание\n3 — Умножение\t4 — Деление\n";
    cin >> operation;
    switch(operation) {
        case 1: cout << "Результат сложения: " << a+b; break;
        case 2: cout << "Результат вычитания: " << a-b; break;
        case 3: cout << "Результат умножения: " << a*b; break;
        case 4: cout << "Результат деления: " << a/b; break;
        default: cout << "Был введён неверный номер операции."; break;
    }
}