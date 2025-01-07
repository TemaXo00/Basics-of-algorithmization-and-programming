#include <iostream>
using namespace std;

int main() {
    double cost;
    cout << "Введите стоимость конфет: ";
    cin >> cost;
    for (int i=1; i<=10; i++)
        cout << i << "кг " << cost*i << endl;
}