#include <iostream>
using namespace std;

int main() {
    const int k = 10;
    int array[k], firstMinus, lastPlus, firstMC = 0, lastPC;
    cout << "Введите элементы массива: ";
    for (int i = 0; i < k; i++) {
        cin >> array[i];
        if (array[i] < 0 && firstMC != 1) {
            firstMinus = i;
            firstMC++;
        }
        if (array[i] >= 0) {
            lastPlus = i;
            lastPC++;
        }
    }
    if (firstMC==0)
        cout << "Первый отрицательный элемент не был найден.";
    else
        cout << "Первый отрицательный элемент: " << array[firstMinus] << " Положение в массиве: " << firstMinus;

    if (lastPC==0)
        cout << "\nПоследний положительный элемент не был найден.";
    else
        cout << "\nПоследний положительный элемент: " << array[lastPlus] << " Положение в массиве: " << lastPlus;
}