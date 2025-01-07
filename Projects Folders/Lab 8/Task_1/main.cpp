#include <iostream>
#include <string>
#define sentences text[i]=='.' || text[i]=='?' || text[i]=='!'
#define space text[i]==' '
using namespace std;

void contPr() {
    cout << "\nНажмите Enter для продолжения...";
    cin.get();
    system("clear");
}
int getCountOf (string text, int idOfSearch, int endOfSearch) {
    int counter=0;
    // 1 - пробелы, для количества слов, 2 - для поиска количества предложений
    for (int i=0; i<endOfSearch; i++) {
        switch(idOfSearch) {
            case 1: if (space) counter++; break;
            case 2: if (sentences) counter++; break;
            default: break;
        }
    }
    return counter;
}
void printNeeded(string text, int BOS, int EOS, int NOS, int neededId) {
    //id=1 - для предложений, id=2 - для слов
    cout << "Вывод " << (neededId==1 ? "предложения №": "слова №") << NOS << ": ";
    for (int i=BOS; i<=EOS; i++)
        cout << text[i];
    cout << endl;
}

bool infoAS(string text) {
    bool info=false;
    int searchS= getCountOf(text,2,text.length());
    if (searchS!=0)
        info=true;
    return info;
}
string convertToFift(string number) {
    string fifteen[15]={"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E"};
    cout << "Первое число в первом предложении: " << number << endl;
    int myNum = stoi(number);
    number="";
    do {
        number.insert(0, fifteen[myNum%15]);
        myNum/=15;
    } while(myNum>0);
    cout << "Переведенный в пятнадцатиричную систему: " << number << endl;
    return number;
}

int main() {
    string text;
    int task;
    do {
        cout << "Выберите действие:\n1.Записать свой текст\n2.Использовать пример\n";
        cin >> task;
        system("clear");
        switch(task) {
            case 1: cout << "Введите текст:\n"; cin.ignore(); getline(cin, text); break;
            case 2: text="The parade of hundreds of demons was held in Japan on December 24, 2017.The main figure was the special rank shaman Suguru Geto, who managed more than 2000 curses.Stop it was only through the efforts of student 1 year of the Magic College Yuta Okkotsu, who with a curse of special rank defeated Geto.During the incident, about 183 people were injured, 546 were wounded.";
            cout << "Текст из примера был взят успешно"; break;
            default: cout << "Произошла ошибка. Вы ввели неправильный номер задания\n";
        }
    } while(task<1 || task>2);
    bool SC = infoAS(text);
    if (!SC) {
        cout << "В тексте не было найдено ни одного предложения. Закрываем программу...";
        return 0;
    }
    cin.ignore();
    contPr();
    //1.по нажатию произвольной клавиши поочередно выделяет каждое
    //предложение текста, выводит его, а также определяет количество предложений в
    //тексте;
    int COS = getCountOf(text, 2, text.length()), dots[COS+1], counter=1;
    for (int i=0; i<text.length(); i++) {
        if (sentences) {
            dots[counter]=i;
            counter++;
        }
    }
    dots[0]=0;
    printNeeded(text, dots[0], dots[1], 1, 1);
    for (int i=1; i<COS; i++)
        printNeeded(text, dots[i] + 1, dots[i + 1], i + 1, 1);
    printf("Количество предложений равно: %d",COS);
    contPr();
    //2.определяет количество слов в первом предложении и выводит каждое
    //четное слово;
    int countOfWords = getCountOf(text,1,dots[1])+1;
    printf("Количество слов в первом предложении равно: %d\n",countOfWords);
    struct words {
        int begin;
        int end;
        int series;
    };
    words wd[countOfWords];
    counter=1;
    wd[0].begin=0;
    wd[countOfWords-1].end=dots[1]-1;
    for (int i=0; i<dots[1]; i++) {
        if (space) {
            wd[counter-1].end=i-1;
            wd[counter].begin=i+1;
            counter++;
        }
    }
    for (int i=1; i<=countOfWords; i+=2)
        printNeeded(text, wd[i].begin, wd[i].end, i+1,2);
    contPr();
    //3.переводит первое целое число первого предложения из десятичной
    //системы счисления в пятнадцатеричную.
    string number;
    for (int i=0; i<countOfWords; i++) {
        for (int j=wd[i].begin; j<=wd[i].end; j++) {
            if (isdigit(text[j])) {
                number+=text[j];
            }
        }
        if (number!="")
            break;
    }
    if (number=="")
        cout << "В первом предложении не найдено ни одного числа.";
    else {
        number = convertToFift(number);
    }
    contPr();
    //4.каждое из первых трех предложений текста выводит в обратном порядке;
    bool threeSent = COS>3;
    if (!threeSent)
        cout << "В тексте не было найдено три предложения";
    else {
        for (int i = 4; i > 2; i--)
            printNeeded(text,dots[i-1]+1, dots[i], i-1, 1);
        printNeeded(text, dots[0], dots[1], 1, 1);
    }
    contPr();
    //5.упорядочивает слова первого предложения в соответствии с ростом их
    //характеристик (характеристика - длина содержащейся в слове максимальной
    //серии);
    for (int i=0; i<countOfWords; i++) {
        wd[i].series = (wd[i].end-wd[i].begin)+1;
    }
    for (int i=0; i<countOfWords; i++) {
        for (int j=0; j<countOfWords-1; j++) {
            if (wd[j].series>wd[j+1].series) {
                swap (wd[j].begin, wd[j+1].begin);
                swap (wd[j].end, wd[j+1].end);
                swap (wd[j].series, wd[j+1].series);
            }
        }
    }
    cout << "Отсортированное по серии первое предложение:\n";
    for (int i=0; i<countOfWords; i++) {
        printNeeded(text, wd[i].begin, wd[i].end, i+1,2);
    }
    contPr();
    cout << "Программа завершена успешно.";
}