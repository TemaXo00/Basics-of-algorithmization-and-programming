#include <iostream>
using namespace std;

int main() {
    const int rows=4, columns=3;
    char array[rows][columns];
    cout << "Введите элементы массива:\n";
    for (int i=0; i<rows; i++) {
        for (int j=0; j<columns; j++) {
            cout << "[" << i << "," << j << "]: ";
            cin >> array[i][j];
        }
    }
    cout << array[0][0] << " " << array[rows-1][0] << " " << array[0][columns-1] << " " << array[rows-1][columns-1];
}