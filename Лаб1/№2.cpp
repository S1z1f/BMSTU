#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;
const int Disc = 4;
struct Discipline {
    string name;
    int mark;
};
struct Student {
    string fio;
    vector <Discipline> disc;
};
void inputStudent(Student& s) {
    cout << "Фио:" ;
    getline(cin, s.fio);
    int k;
    do {
        cout << "Число дисциплин (не меньше " << Disc << "):" << endl;
        cin >> k;
    } while (k < Disc);
        cin.ignore();
        s.disc.resize(k);
        for (int i = 0; i < k; i++) {
            cout << "Дисциплина " << i+1 << ":" << endl;
            getline(cin, s.disc[i].name);
            do {
                cout << "Оценка:";
                cin >> s.disc[i].mark;
            } while (s.disc[i].mark < 2 || s.disc[i].mark > 5);
            cin.ignore();
        }
}
void printStudent(const Student& s) {
    cout << s.fio << ":" << endl;
    for (const Discipline& d : s.disc) {
        cout << "" << d.name << "-" << d.mark << ";" << endl;
    }
}
int main () {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int n;
    cout << "n = ";
    cin >> n;
    cin.ignore();
    vector<Student> group(n);
    for (int o = 0; o < n; o++) {
        cout << endl << "Студент №" << o+1 << endl;
        inputStudent(group[o]);
    }
    return 0;
}
