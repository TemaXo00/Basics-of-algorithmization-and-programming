#include <iostream>
using namespace std;

int main() {
    const int k=5;
    char array[k], intArray[k], charArray[k];
    int intCounter=0, charCounter=0;
    for (int i=0; i<k; i++) {
        cout << "Введите элемент №" << i+1 << ": ";
        cin >> array[i];
        if (isdigit(array[i])) {
            intArray[intCounter] = array[i];
            intCounter++;
        }
        else {
            charArray[charCounter] = array[i];
            charCounter++;
        }
    }
    for (int i=0; i<intCounter; i++)
        array[i]=intArray[i];
    for (int i=0; i<charCounter; i++) {
        array[intCounter+i]=charArray[i];
    }
    cout << "Преобразованный массив: ";
    for (int i=0; i<k; i++)
        cout << array[i] << " ";
}