#include <iostream>
using namespace std;

int main () {
    int numberOfStudents, checkExam=0, NotAllDone=0;
    const int numberOfExams=4;
    cout << "Введите количество студентов: ";
    cin >> numberOfStudents;
    struct Discipline {
        string name;
        int mark;
    };
    struct Students {
        string Surname;
        string Name;
        string FatherName;
        Discipline ds[numberOfExams];
    };
    Students st[numberOfStudents];
    for (int i=0; i<numberOfExams; i++) {
        cout << "Введите название " << i+1 << " дисциплины: ";
        cin >> st->ds[i].name;
    }
    for (int i=0; i<numberOfStudents; i++) {
        cout << "Введите информацию о " << i+1 << " студенте по примеру: Фамилия Имя Отчество" << endl;
        cin >> st->Surname >> st->Name >> st->FatherName;
        for (int j=0; j<numberOfExams; j++) {
            cout << "Введите отметку по " << st->ds[j].name << ": ";
            do {
                cin >> st->ds[j].mark;
                if (st->ds[j].mark > 10 || st->ds[j].mark<0)
                    cout << "Ошибка, повторите ввод: ";
            }while(st->ds[j].mark > 10 || st->ds[j].mark<0);
            if (st->ds[j].mark>4)
                checkExam++;
        }
        if (checkExam<numberOfExams)
            NotAllDone++;
        checkExam=0;
    }
    cout << "Количество студентов, которые имеют хотя бы одну неудовлетворительную оценку: " << NotAllDone;
}