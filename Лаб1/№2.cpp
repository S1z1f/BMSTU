#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;
const int Disc = 4;    // минимальное число дисциплин
struct Discipline {    // вводим структуру дисциплина
    string name;    // название предмета
    int mark;    // оценка по предмету
};
struct Student {    // вводим структуру студент
    string fio;    // ФИО
    vector <Discipline> disc;    // Результаты сдачи сессии
};
void inputStudent(Student& s) {    // объявление функции, которая принимает одного студента
    cout << "Фио:" ;
    getline(cin, s.fio);    // ввод с пробелом
    int k;    // создаём переменную количество предметов
    do {
        cout << "Число дисциплин (не меньше " << Disc << "):" << endl;    // число предметов не должно превышать заранее заявленное количество
        cin >> k;    // вводим количество предметов
    } while (k < Disc);    // цикл будет выполняться до тех пор пока пользовательне введёт число большее 4
        cin.ignore();    // очищает ввод при невыполнении условия
        s.disc.resize(k);    // изменяет размер вектора под количество введённых студентов
        for (int i = 0; i < k; i++) {    // переберает значения до k
            cout << "Дисциплина " << i+1 << ":" << endl;
            getline(cin, s.disc[i].name);    // считывает название предмета
            do {
                cout << "Оценка:";
                cin >> s.disc[i].mark;    // считывает оценку для i предмета
            } while (s.disc[i].mark < 2 || s.disc[i].mark > 5);    // цикл повторяется если в вводных данных число меньше 2 или больше 5
            cin.ignore();    // очищает поле ввода
        }
}
void printStudent(const Student& s) {    // функция принимает данные студента
    cout << s.fio << ":" << endl;
    for (const Discipline& d : s.disc) {    // цикл, который пробегает по всем значениям в массиве s.disc
        cout << "" << d.name << "-" << d.mark << ";" << endl;    // выводит имя и оценку студента
    }
}
int main () {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);    // строка необходимая для использования кирилицы
    int n;    // создаёт переменную с значенме количества студентов в группе
    cout << "Количество студентов = ";
    cin >> n;    // вводим количество студентов
    cin.ignore();
    vector<Student> group(n);    // массив студентов 
    for (int o = 0; o < n; o++) {    // переберает значения до n
        cout << endl << "Студент №" << o+1 << endl;
        inputStudent(group[o]);    //передаёт значение студента 
    }
    return 0;
}
