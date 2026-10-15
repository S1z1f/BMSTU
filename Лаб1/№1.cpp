#include <iostream>
 #include <iomanip>
 #define _USE_MATH_DEFINES // Необходимо для использования константы M_PI
 #include <math.h>
 #include <windows.h>
 using namespace std;
 int main () {
     SetConsoleOutputCP(CP_UTF8);
     SetConsoleCP(CP_UTF8);  // Строка необходимая для использования кирилицы
     double e;
     cout << "Точность =";
     cin >> e;  // Вводим точность
     double sum = 0;  //сумма ряда
     double sl;    // слагаемое
     int k = 1;    // Знаменатель дроби
     int znak = 1;    // знак слагаемого (1, -1)
     int n = 0;    // число операций 
     do {
         sl = 4./ k;    //слагаемое
         sum += sl*znak;    // считаем сумму
         k += 2;    // увеличение знаменателя на 2
         znak *= -1;    // замена знака на противоположный
         n++;    // считаем количество операций 
     } while (sl >= e);    // программа работает пока слагаемое >= точности
     cout << fixed << setprecision(10);    // выводит 10 цифр после запятой 
     cout << "Сумма = " << sum << " слагаемых " << n << endl; 
     cout << "Точность значения: пи = " << M_PI << endl;
     return 0;
 }

