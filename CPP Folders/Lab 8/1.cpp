#include <iostream>
#include <string>
#define sentences text[i]=='.' || text[i]=='?' || text[i]=='!'
#define space text[i]==' '
using namespace std;

void continueProgram() {
    cout << "\nНажмите Enter для продолжения...";
    cin.get();
    system("clear");
}
int getCountOf(string text, int begin, int end, char id) {
    int counter=0;
    for (int i=begin; i<end; i++) {
        switch(id) {
            case 'S': if (sentences) counter++; break;
            case 'W': if (space) counter++; break;
            default: break;
        }
    }
    return counter;
}
bool checkForWorkplace(string text) {
    int counter= getCountOf(text, 0, text.length(), 'S');
    if (counter<=1)
        return false;
    else
        return true;
}
void print(string text, int begin, int end, int number, char id) {
    cout << (id=='S' ? "Вывод предложения №": "Вывод слова №") << number << ": ";
    for (int i=begin; i<=end; i++)
        cout << text[i];
    cout << endl;
}
void convertToFift(string number) {
    string fifteen[15]={"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E"};
    cout << "Первое число в первом предложении: " << number << endl;
    int myNum = stoi(number);
    number="";
    do {
        number.insert(0, fifteen[myNum%15]);
        myNum/=15;
    } while(myNum>0);
    cout << "Переведенный в пятнадцатиричную систему: " << number << endl;
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
                cout << "Текст из примера был взят успешно"; cin.ignore(); break;
            default: cout << "Произошла ошибка. Вы ввели неправильный номер задания\n";
        }
    } while(task<1 || task>2);
    text.insert(0,".");
    continueProgram();
    bool checkForWork = checkForWorkplace(text);
    if (!checkForWork) {
        cout << "В тексте не было найдено ни одного предложения. Программа не может отработать.";
        return 0;
    }
    //Task 1
    int sentencesCounter = getCountOf(text,0,text.length(),'S');
    int dotsPlacement[sentencesCounter], counter=0;
    for (int i=0; i<text.length(); i++) {
        if (sentences) {
            dotsPlacement[counter]=i;
            counter++;
        }
    }
    for (int i=0; i<sentencesCounter-1; i++)
        print(text,dotsPlacement[i]+1,dotsPlacement[i+1], i+1, 'S');
    printf("Количество предложений в тексте: %d",sentencesCounter-1);
    continueProgram();
    //Task 2
    int wordsCounter = getCountOf(text,dotsPlacement[0],dotsPlacement[1],'W')+1;
    counter=0;
    printf("Количество слов: %d\n", wordsCounter);
    struct words {
        int begin;
        int end;
        int series;
    };
    words w[wordsCounter];
    w[0].begin=dotsPlacement[0]+1;
    w[wordsCounter-1].end=dotsPlacement[1]-1;
    for (int i=dotsPlacement[0]; i<dotsPlacement[1]; i++) {
        if (space) {
            w[counter].end=i-1;
            w[counter+1].begin=i+1;
            counter++;
        }
    }
    for (int i=1; i<wordsCounter; i+=2)
        print(text,w[i].begin,w[i].end,i+1,'W');
    continueProgram();
    //Task 3
    string number;
    bool foundedFirst=false;
    for (int i=0; i<wordsCounter; i++) {
        for (int j=w[i].begin; j<=w[i].end; j++) {
            if (isdigit(text[j]) && !foundedFirst)
                number+=text[j];
        }
        if (!number.empty())
            foundedFirst=true;
    }
    if (!foundedFirst)
        cout << "В первом предложении число не было найдено";
    else
        convertToFift(number);

    continueProgram();
    //Task 4
    bool three = sentencesCounter>4;
    if (!three)
        cout << "В тексте менее трёх предложений";
    else {
        for (int i=3; i>0; i--)
            print(text,dotsPlacement[i-1]+1,dotsPlacement[i],i,'S');
    }
    continueProgram();
    //Task 5
    for (int i=0; i<wordsCounter; i++)
        w[i].series=(w[i].end-w[i].begin)+1;
    for (int i=0; i<wordsCounter; i++) {
        for (int j=0; j<wordsCounter-1; j++) {
            if (w[j].series>w[j+1].series) {
                swap (w[j].begin, w[j+1].begin);
                swap (w[j].end, w[j+1].end);
                swap (w[j].series, w[j+1].series);
            }
        }
    }
    cout << "Отсортированное по серии первое предложение:\n";
    for (int i=0; i<wordsCounter; i++)
        print(text, w[i].begin, w[i].end,i+1,'W');
    continueProgram();
    cout << "Программа была завершена успешно.";
}