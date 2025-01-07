#include <iostream>
using namespace std;

int main() {
    int arraySize,maxAbsEl=0, maxPos1=0, maxPos2=0;
    cout << "Введите размерность оригинального массива: ";
    cin >> arraySize;
    int origArray[arraySize][arraySize], transArray[arraySize-1][arraySize-1];
    cout << "Заполните массив\n";
    for (int i=0; i<arraySize; i++) {
        for (int j=0; j<arraySize; j++) {
            cout << "[" << i << "." << j << "]: ";
            cin >> origArray[i][j];
            if (abs(maxAbsEl)<abs(origArray[i][j])) {
                maxAbsEl=origArray[i][j];
                maxPos1=i;
                maxPos2=j;
            }
        }
    }
    cout << "Максимальный по модулю элемент: " << maxAbsEl << "\nЕго расположение в массиве: " << "[" << maxPos1 << "." << maxPos2 << "]\n";
    for (int i=0; i<arraySize; i++) {
        for (int j=0; j<arraySize; j++) {
            if (i<maxPos1) {
                if (j<maxPos2) {
                    transArray[i][j]=origArray[i][j];
                }
                else
                    transArray[i][j]=origArray[i][j+1];
            }
            else {
                if (j < maxPos2)
                    transArray[i][j] = origArray[i + 1][j];
                else
                    transArray[i][j]=origArray[i+1][j+1];
            }
        }
    }
    cout << "Преобразованный массив:\n";
    for (int i=0; i<arraySize-1; i++) {
        for (int j=0; j<arraySize-1; j++) {
            cout << transArray[i][j] << " ";
        }
        cout << endl;
    }
}