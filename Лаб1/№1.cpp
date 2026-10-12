#include <iostream>
#include <iomanip>
#include <cstdlib>
#define _USE_MATH_DEFINES   // Необходимо, чтобы использовать константу M_PI
#include <math.h>
using namespace std;
int main()
{
    double sum = 0, e, sl; // Объявляем вещественные переменные
    int k = 1, znak = 1; // Объявляем целые переменные (знаменатель и знак)
    cout <<"E="; cin >> e;  // Вводим точность
    int n = 0; // Счетчик числа повторений цикла
    sl = 4. / k;
    while (sl > e)
    {
        sum += sl * znak; // Считаем сумму
        n++ ;
        k += 2; // Увеличиваем значение знаменателя дроби
        znak *= -1;
        sl = 4. / k;
    }  // Пока слагаемое >= точности цикл продолжается
    cout << fixed << setprecision(10);
    cout<<"Sum = "<<sum<<"  n = " << n<<" PI = " << M_PI<< endl; // Вывод результатов
    return 0;
}
