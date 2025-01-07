#include <iostream>
using namespace std;

int main() {
    int month, year;
    cout << "Введите порядковый номер месяца: ";
    cin >> month;
    switch (month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12: cout << "В этом месяце 31 день."; break;
    case 4: case 6: case 9: case 11: cout << "В этом месяце 30 дней."; break;
    case 2:
        cout << "Введите год: ";
        cin >> year;
        switch(year%4) {
            case 0: cout << "Год високосный и в этом месяце 29 дней."; break;
            case 1: case 2: case 3: cout << "Год не високосный и в этом месяце 28 дней."; break;
        }
        break;
        default: cout << "Был введён неправильный номер месяца.";
    }
}