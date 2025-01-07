#include <iostream>
using namespace std;

int main() {
    const int x=3, y=3;
    const int z = x * y;
    int a[x][y];
    int b[z];
    int c=0, f=0, d=0, e, g;

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cout << "Значение [" << i << "." << j << "] равно: ";
            cin >> a[i][j];
            b[d] = a[i][j];
            d++;
            if (c != 2) {
                f++;
                if (a[i][j] < 0 && c != 2) {
                    c++;
                    e = i; g = j;
                }
            }
        }
    }
    d = 0;
    if (c != 2) {
        cout << "Два отрицательных элемента не было найдено. Завершение программы.";
        return 0;
    }
    cout << "" << endl;
    cout << "Второй отрицательный элемент равен: " << a[e][g] << endl << "Его расположение: " << "[" << e << "." << g << "]" << endl << "Порядковый номер (от 0 до конца): " << f << endl << "" << endl << "Преобразованный массив:" << endl;

    for (int i=0; i < z; i++) {
        for (int j = f; j < z - 1; j++) {
            if (b[j] < b[j + 1]) {
                int p = b[j+1];
                b[j+1] = b[j];
                b[j] = p;
            }
        }
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            a[i][j] = b[d];
            d++;
            cout << a[i][j] << " ";
        }
        cout << "" << endl;
    }
}