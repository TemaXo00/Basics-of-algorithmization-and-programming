#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <unistd.h>
using namespace std;
#define LISTREAD studIterator->F << " " << studIterator->N << " " << studIterator->FN << " " << studIterator->groupNum << " " << studIterator->gradeBookNum << " " << studIterator->marks[0] << " " << studIterator->marks[1] << " " << studIterator->marks[2] << " " << studIterator->marks[3] << endl;
#define LISTWRITE \
    cout << "Ввод информации и студенте №" << i + 1 << "\nВведите фамилию: ";\
    cin >> studStruct.F;\
    cout << "Введите имя: ";\
    cin >> studStruct.N;\
    cout << "Введите отчество: ";\
    cin >> studStruct.FN;\
    cout << "Введите номер группы: ";\
    cin >> studStruct.groupNum;\
    cout << "Введите номер зачётной книжки: ";\
    cin >> studStruct.gradeBookNum;\
    for (int j = 0; j < 4; j++) {\
        cout << "Введите оценку по " << j + 1 << " предмету: ";\
        cin >> studStruct.marks[j];\
    }\
    studList.push_back(studStruct);

void continueProg() {
    cout << "\nНажмите Enter для продолжения";
    cin.ignore();
    cin.get();
    system("clear");
}
string setFileName() {
    string name;
    cout << "Введите название файла: ";
    cin >> name;
    name+=".txt";
    cout << "Название файла: " << name;
    continueProg();
    return name;
}
int main() {
    int tasks, task1C=0, task4C=0, task5C=0, studentsCount;;
    struct Students {
        string F;
        string N;
        string FN;
        int groupNum;
        int gradeBookNum;
        int marks[4];
    };
    list <Students> studList;
    Students studStruct;
    list <Students>::iterator studIterator;
    string fileName;
    while(true) {
        cout << "Выберите операцию, которую необходимо выполнить:\n1.Запись списка\n2.Просмотр списка\n3.Добавление данных\n4.Дать название файлу\n5.Запись файла\n6.Чтение файла\n7.Просмотр условия\n8.Выход из программы\n";
        cin >> tasks;
        system("clear");
        switch(tasks) {
            case 1:
                studList.clear();
                cout << "Введите количество студентов: ";
                cin >> studentsCount;
                system("clear");
                for (int i=0; i<studentsCount; i++) {
                    LISTWRITE;
                    system("clear");
                }
                cout << "Список был записан успешно\nКоличество студентов равно: " << studentsCount;
                task1C=1;
                continueProg();
                break;
            case 2:
                if (task1C==0) {
                    cout << "Список не был записан. Запустите задачу 1, а затем вернитесь к выполнению этой задачи.";
                }
                else {
                    studIterator = studList.begin();
                    cout << "Данные, которые были занесены в список:\n";
                    while (studIterator != studList.end()) {
                        cout << LISTREAD;
                        studIterator++;
                    }
                }
                continueProg();
                break;
            case 3:
                if (task1C==0)
                    cout << "Список не был записан. Запустите задачу 1, а затем вернитесь к выполнению этой задачи.";
                else {
                    int addedStud;
                    cout << "Введите количество студентов, которое необходимо добавить: ";
                    cin >> addedStud;
                    system("clear");
                    for (int i = studentsCount; i < studentsCount + addedStud; i++) {
                        LISTWRITE;
                        system("clear");
                    }
                    studentsCount += addedStud;
                    cout << "Список был обновлён\nТекущее количество студентов: " << studentsCount;
                }
                continueProg();
                break;
            case 4:  fileName=setFileName(); task4C=1; break;
            case 5:
                if (task1C==0) {
                    cout << "Список не был записан. Запустите задачу 1, а затем вернитесь к выполнению этой задачи.";
                }
                else {
                    if (task4C == 0)
                        cout << "Файлу не было присвоено имя. Запустите задачу 4, а затем вернитесь к выполнению этой задачи.";
                    else {
                        ofstream writeFile(fileName, ios::out);
                        if (writeFile.is_open()) {
                            studIterator=studList.begin();
                            while (studIterator != studList.end()) {
                                writeFile << LISTREAD;
                                studIterator++;
                            }
                            sleep(1);
                            cout << "Запись файла была произведена успешно";
                        } else
                            cerr << "Произошла ошибка при открытии файла";
                        writeFile.close();
                    }
                }
                task5C=1;
                continueProg();
                break;
            case 6:
                if (task5C==0)
                    cout << "Файл не был создан и записан. Запустите задачу 5, а затем вернитесь к выполнению данной задачи";
                else {
                    string fileRead;
                    ifstream readFile(fileName);
                    if (readFile.is_open()) {
                        cout << "Данные, которые находятся в файле:\n";
                        while (getline(readFile,fileRead))
                            cout << fileRead << endl;
                    }
                    else
                        cerr << "Произошла ошибка при открытии файла";
                }
                continueProg();
                break;
            case 7: cout << "Условия:\nВариант - 1\nОбъекты задаются - списком\nРежим открытия файла - текстовый"; continueProg(); break;
            case 8: cout << "Программа была завершена."; return 0;
            default: cout << "Было введено неверное значение."; continueProg(); break;
        }
    }
}