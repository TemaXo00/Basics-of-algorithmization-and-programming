#include <iostream>
using namespace std;

int main() {
    int arraySize, neededPos, neededNum;
    cout << "Введите количество элементов\nУсловие: количество должно быть менее 10\n";
    do {
        cin >> arraySize;
        if (arraySize>10 || arraySize<0)
            cout << "Условие не было выполнено. Повторите ввод: ";
    }while(arraySize>10 || arraySize<0);
    int origArray[arraySize], transArray[arraySize+1];
    cout << "Оригинальный массив: ";
    for (int i = 0; i < arraySize; i++) {
        origArray[i] = rand();
        cout << origArray[i] << " ";
    }
    cout << "\nВведите позицию после которой надо ввести число: ";
    do {
        cin >> neededPos;
        if (neededPos>arraySize || neededPos<0)
            cout << "Произошла ошибка. Повторите ввод: ";
    }while(neededPos>arraySize || neededPos<0);
    cout << "Введите число, которое необходимо: ";
    cin >> neededNum;
    transArray[neededPos]=neededNum;
    for (int i=0; i<neededPos; i++)
        transArray[i]=origArray[i];
    for (int i=neededPos; i<arraySize; i++)
        transArray[i+1]=origArray[i];
    cout << "Преобразованный массив: ";
    for (int i=0; i<arraySize+1; i++)
        cout << transArray[i] << " ";
}