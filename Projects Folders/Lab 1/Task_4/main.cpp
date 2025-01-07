#include <iostream>
using namespace std;

int main() {
    int l;
    cout << "Введите длину (в см): ";
    cin >> l;
    cout << "Количество полных метров: " << l/100;
}