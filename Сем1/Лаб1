#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
#include <windows.h>
using namespace std;
int main () {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    double e;
    cout << "Точность =";
    cin >> e;
    double sum = 0;
    double sl;
    int k = 1;
    int znak = 1;
    int n = 0;
    do {
        sl = 4./ k;
        sum += sl*znak;
        k += 2;
        znak *= -1;
        n++;
    } while (sl >= e);
    cout << fixed << setprecision(10);
    cout << "Сумма = " << sum << " слагаемых " << n << endl;
    cout << "Точность значения: пи = " << M_PI << endl;
    return 0;
}
