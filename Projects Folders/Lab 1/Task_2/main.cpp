#include <iostream>
using namespace std;

int main() {
    bool a=1, b=0, c=0;
    cout << "А) " << ((a||!a&&b)||c) << "\nБ) " << (a||a&&(b||c)) << "\nВ) " << ((a||b&&!c)&&c);
}