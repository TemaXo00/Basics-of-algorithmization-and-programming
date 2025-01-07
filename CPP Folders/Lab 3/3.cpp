#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Введите число N" << endl << "Условие: N>0" << endl;
    do {
        cin >> n;
        if (n < 0)
            cout << "Условие не было выполнено. Повторите ввод: ";
    }while(n<0);
    while (n>0) {
        cout << n%10 << " ";
        n/=10;
    }
}