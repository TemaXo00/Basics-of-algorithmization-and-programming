#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#define BUBBLESORT swap(ph[j].code, ph[j+1].code);\
swap(ph[j].name, ph[j+1].name);\
swap(ph[j].cost, ph[j+1].cost);\
swap(ph[j].amount, ph[j+1].amount);\
swap(ph[j].weight, ph[j+1].weight);\
swap(ph[j].firm, ph[j+1].firm);
#define CHECK for (int i=0; i<ph.size(); i++) { cout << ph[i].code << " " << ph[i].name << " " << ph[i].cost << " " << ph[i].amount << " " << ph[i].weight << " " << ph[i].firm << endl;}
using namespace std;

void convertToBin(string filename1, string filename2) {
    string rewrite;
    ifstream read(filename1);
    ofstream write(filename2, ios::binary);
    if (read.is_open() && write.is_open()) {
        while(getline(read,rewrite))
            write << rewrite << endl;
    }
    else
        cerr << "Ошибка при чтении одного из файлов";
};

void reverseConvert(string filename1, string filename2) {
    string rewrite;
    ifstream read(filename1, ios::binary);
    ofstream write(filename2);
    if (read.is_open() && write.is_open()) {
        while(getline(read,rewrite))
            write << rewrite << endl;
    }
};

void contPr() {
    cout << "\nНажмите Enter для продолжения...";
    cin.ignore();
    cin.get();
    system("clear");
}

int main() {
    int tasks;
    convertToBin("firstFile.txt", "M1.bin");
    convertToBin("secondFile.txt", "M2.bin");
    struct Phones {
        int code;
        string name;
        int cost;
        int amount;
        int weight;
        string firm;
    };
    vector <Phones> ph;
    Phones phStr;
    struct Firms {
        int code;
        string Firm;
    };
    vector <Firms> fm;
    Firms fmStr;

    ifstream firstBin ("M1.bin");
    if (firstBin.is_open()) {
        while(firstBin >> phStr.code >> phStr.name >> phStr.cost >> phStr.amount >> phStr.weight)
            ph.push_back(phStr);
    }
    else
        cerr << "Произошла ошибка при открытии файла M1.bin";
    firstBin.close();

    ifstream secondBin("M2.bin");
    if (secondBin.is_open()) {
        while(secondBin >> fmStr.code >> fmStr.Firm)
            fm.push_back(fmStr);
    }
    else
        cerr << "Произошла ошибка при открытии файла M2.bin";
    secondBin.close();
    for (int i=0; i<ph.size(); i++) {
        for (int j=0; j<fm.size(); j++) {
            if (ph[i].code==fm[j].code)
                ph[i].firm=fm[j].Firm;
        }
    }
    for (int i = 0; i < ph.size(); i++) {
        for (int j = 0; j < ph.size() - 1; j++) {
            if (ph[j].code > ph[j + 1].code) {
                BUBBLESORT;
            }
        }
    }

    while (true) {
        cout << "Введите номер задания, которое необходимо выполнить:\n1.Отобразить текущие сведения\n2.Отсортировать значения по убыванию стоимости\n3.Найти самый дорогой товар заданной фирмы\n4.Показать самый дорогой товар\n5.Отобразить на экране товары необходимой фирмы\n6.Поменять  местами  какие-нибудь  две  записи,  разность  цены  у  которых  не  превосходит заданного значения\n7.Завершить программу и удалить  записи,  содержащие  сведения  о  товарах,  стоимость  которых  меньше  заданного\n"
                   "значения\n";
        cin >> tasks;
        switch(tasks) {
            case 1: {
                system("clear");
                cout << "Текущие значения:\n";
                CHECK;
                contPr();
                break;
            }
            case 2: {
                system("clear");
                for (int i = 0; i < ph.size(); i++) {
                    for (int j = 0; j < ph.size() - 1; j++) {
                        if (ph[j].cost < ph[j + 1].cost) {
                            BUBBLESORT;
                        }
                    }
                }
                cout << "Значения после сортировки:\n";
                CHECK;
                contPr();
                break;
            }

            case 3: {
                system("clear");
                string firmName;
                vector<int> costsOfFirm;
                cout << "Введите название фирмы: ";
                cin >> firmName;
                for (int i = 0; i < ph.size(); i++) {
                    if (ph[i].firm.find(firmName) != string::npos)
                        costsOfFirm.push_back(ph[i].cost);
                }
                if (costsOfFirm.empty())
                    cout << "Фирма с нужным названием не была определена" << endl;
                else {
                    int maxCost = costsOfFirm[0];
                    for (int i = 0; i < costsOfFirm.size(); i++) {
                        if (maxCost < costsOfFirm[i])
                            maxCost = costsOfFirm[i];
                    }
                    for (int i = 0; i < ph.size(); i++) {
                        if (ph[i].firm == firmName && ph[i].cost == maxCost)
                            cout << "Самый дорогой товар фирмы " << firmName << ": " << ph[i].name << endl;
                    }
                }
                contPr();
                break;
            }

            case 4: {
                system("clear");
                int maxTovar = 0, maxTovarPlacement;
                for (int i = 0; i < ph.size(); i++) {
                    if (maxTovar < ph[i].cost) {
                        maxTovar = ph[i].cost;
                        maxTovarPlacement = i;
                    }
                }
                cout << "Товар с наибольшей ценой:\nФирма: " << ph[maxTovarPlacement].firm << "\nНазвание: "
                     << ph[maxTovarPlacement].name << "\nКод фирмы: " << ph[maxTovarPlacement].code << "\nСтоимость: "
                     << ph[maxTovarPlacement].cost << endl;
                contPr();
                break;
            }

            case 5: {
                system("clear");
                string firmName;
                cout << "Введите название фирмы: ";
                cin >> firmName;
                cout << "Товары заданной фирмы:\n";
                for (int i = 0; i < ph.size(); i++) {
                    if (ph[i].firm.find(firmName) != string::npos)
                        cout << ph[i].name << endl;
                }
                contPr();
                break;
            }

            case 6: {
                system("clear");
                int definitionOfCost;
                cout << "Введите необходимую разницу в стоимости: ";
                cin >> definitionOfCost;
                for (int j = 0; j < ph.size() - 1; j++) {
                    if (ph[j].cost - ph[j + 1].cost <= definitionOfCost) {
                        cout << "Были изменены положения товаров:" << endl << ph[j].name << endl << ph[j+1].name;
                        BUBBLESORT;
                        break;
                    }
                }
                contPr();
                break;
            }

            case 7: {
                system("clear");
                int minCost;
                cout << "Введите минимальную стоимость товаров: ";
                cin >> minCost;
                ofstream myNewFile("M2.bin", ios::binary | ios::out);
                if (myNewFile.is_open()) {
                    for (int i = 0; i < ph.size(); i++) {
                        if (ph[i].cost > minCost)
                            myNewFile << ph[i].name << " " << ph[i].cost << " " << ph[i].amount << " "
                                      << ph[i].weight << " " << ph[i].firm << endl;
                    }
                } else
                    cerr << "Произошла ошибка при записи файла M2.bin";
                reverseConvert("M2.bin", "example_output.txt");
                cout << "Завершение программы...";
                return 0;
            }
            default:
                system("clear");
                cout << "Было введено неверное значение задания";
                contPr();
                break;
        }
    }
}