#include <iostream>
using namespace std;

int checkerEven (int a) {
    if (a%2 != 0 || a<2) {
        do {
            cout << "Было введено неверное значение. Повторите ввод: ";
            cin >> a;
        } while (a%2!=0 || a<2);
    }
    return (a);
}

bool simple (int c) {
    int checking=0, entering;
    if (c==1)
        return false;
    else {
        for (int i = 1; i <= c; i++) {
            entering = c % i;
            if (entering == 0)
                checking++;
        }
        if (checking == 2)
            return false;
        else
            return true;
    }
}

int main() {
    int chislo, summ1, summ2, proverka;
    cout << "Введите чётное число: ";
    cin >> chislo;
    chislo=checkerEven (chislo);

    do {
        cout << "Введите 1 значение: ";
        cin >> summ1;
        cout << "Введите 2 значение: ";
        cin >> summ2;
        if (chislo!=summ1+summ2)
            cout << "Были введены некорректные значения (они в сумме не дают начальное чётное значение). Введите заново.";
    } while (chislo!=summ1+summ2);

    proverka=simple(summ1)+ simple(summ2);
    switch(proverka) {
        case 0: cout << "Гипотеза потверждена. Оба числа являются простыми, и они в сумме дают четное число."; break;
        case 1: cout << "Гипотеза не была подтверждена. Одно число не является простым."; break;
        case 2: cout << "Гипотеза не была подтверждена. Оба числа не являются простыми."; break;
    };
}