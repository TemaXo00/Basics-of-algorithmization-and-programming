#include <iostream>
using namespace std;

int main() {
    int a,b;
    cout << "Введите числа A и B" << endl << "Условие: A>B" << endl;
    do {
        cin >> a >> b;
        if (a<b)
            cout << "Условие не было выполнено. Повторите ввод\n";
    }while(a<b);
    while(a>=b)
        a-=b;
    cout << "Длина незанятой части: " << a;
}