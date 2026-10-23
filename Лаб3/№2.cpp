#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ---------- Статический полиморфизм ----------
class account { // Базовый класс - "Простой счет в банке"
protected:
    string fio; // ФИО владельца
    double sum0; // Начальная сумма счета
    double rate; // Ставка вклада (проценты в год)
    int years; // Время существования вклада в годах
    public:
account(string fio, double sum0, double rate, int years) {  // Конструктор для инициализации полей
    this->fio=fio; this->sum0=sum0; this->rate=rate; this->years=years;
} double calc(){    // Сумма на счете с учетом начисленных процентов
    return sum0+sum0*rate/100*years;
} void print(){ // Метод для печати параметров счета
        cout<<"account: fio="<<fio<<" start="<<sum0<<" rate="<<rate<<"% years="<<years<<endl;
    }
};
class privAccount: public account {     // Производный класс - "Привилегированный счет"
double credit;  // Процент кредита от доступной суммы
public:
privAccount(string fio, double sum0, double rate, int years, double credit):    // Конструктор
  account(fio, sum0, rate, years) {     // Явный вызов конструктора базового класса
    this->credit=credit;
} double calc(){    // Переопределенная функция: сумма с учетом доступного кредита
    double s=account::calc();   // Вызов функции базового класса (сумма с процентами)
    return s+s*credit/100;  // Плюс кредит в процентах от этой суммы
  } void print() {  // Переопределенный метод print
        account::print();   // Вызов в переопределенном методе метода базового класса
        cout<<"  privileged: credit="<<credit<<"%"<<endl;   // Допечатывает новое поле
  }
};
// ---------- Динамический полиморфизм ----------
class accountV{     // Базовый класс - "Простой счет в банке"
protected:
    string fio; // ФИО владельца
    double sum0;    // Начальная сумма счета
    double rate;    // Ставка вклада (проценты в год)
    int years;  // Время существования вклада в годах
    public:
    accountV(string fio, double sum0, double rate, int years) { // Конструктор для инициализации полей
        this->fio=fio; this->sum0=sum0; this->rate=rate; this->years=years;
} virtual double calc(){    // Сумма на счете с учетом начисленных процентов (виртуальная функция)
    return sum0+sum0*rate/100*years;
} virtual void print(){     // Метод для печати параметров счета (виртуальный)
    cout<<"account: fio="<<fio<<" start="<<sum0<<" rate="<<rate<<"% years="<<years<<endl;
    }
};
class privAccountV: public accountV{    // Производный класс - "Привилегированный счет"
    double credit; // Процент кредита от доступной суммы
    public:
    privAccountV(string fio, double sum0, double rate, int years, double credit):   // Конструктор
    accountV(fio, sum0, rate, years){   // Явный вызов конструктора базового класса
        this->credit=credit;
  } double calc(){  // Переопределенная виртуальная функция: сумма с учетом доступного кредита
        double s=accountV::calc();  // Вызов функции базового класса
        return s+s*credit/100;
  } void print(){   // Переопределенный метод print
        accountV::print();  // Вызов метода базового класса
        cout<<"  privileged: credit="<<credit<<"%"<<endl;   // Допечатывает новое поле
  }
};

int main(){
    cout<<"1. Static polymorphism (no virtual)"<<endl;
    account a("Ivanov", 1000, 5, 2);    // Создается объект базового класса с вызовом конструктора
    privAccount pa("Petrov", 2000, 4, 3, 10);   // Создается объект производного класса
    a.print(); // Вызов метода через объект
    cout<<"  sum="<<a.calc()<<endl;
    pa.print(); // Вызов метода через объект
    cout<<"  sum="<<pa.calc()<<endl;
    account *p; // Указатель типа базового класса
    p=&a; // Настраиваем на объект базового класса
    p->print(); // Вызов метода через указатель
    p=&pa; // Настраиваем указатель на объект производного класса
       // (преобразование типа допустимо)
    p->print(); // Вызывается метод класса account: выбор по типу указателя
    cout<<"  p->calc()="<<p->calc()<<" (without credit)"<<endl<<endl; // Тоже функция базового класса

    cout<<"2. Dynamic polymorphism (virtual)"<<endl;
    accountV av("Ivanov", 1000, 5, 2); // Объект базового класса
    privAccountV pav("Petrov", 2000, 4, 3, 10); // Объект производного класса
    accountV *pv; // Указатель типа базового класса
    pv=&av; // Настраиваем на объект базового класса
    pv->print(); // Вызывается метод класса accountV
    pv=&pav; // Настраиваем на объект производного класса
    pv->print(); // Вызывается метод класса privAccountV: выбор по типу объекта
    cout<<"  pv->calc()="<<pv->calc()<<" (with credit)"<<endl<<endl; // Вызывается функция privAccountV

    cout<<"3. Vector of pointers to objects of base and derived classes"<<endl;
    accountV a1("Ivanov", 1000, 5, 2), a2("Sidorov", 500, 10, 1); // Объекты базового класса
    privAccountV b1("Petrov", 2000, 4, 3, 10), b2("Kozlov", 3000, 3, 2, 25); // Объекты производного класса
    vector<accountV*> v; // Вектор указателей на объекты базового класса
    v.push_back(&a1); // В одном векторе указатели
    v.push_back(&b1); // на объекты базового
    v.push_back(&a2); // и производного
    v.push_back(&b2); // классов
    double sum=0; // Доступная сумма на всех счетах
    for (int i = 0; i < v.size(); i++) {
        v[i]->print(); // Печатаем данные объекта (динамический полиморфизм)
        cout<<"  sum="<<v[i]->calc()<<endl; // Сумма на счете (для каждого объекта вызывается своя функция)
        sum+=v[i]->calc();
    }
    cout<<"Total available sum = "<<sum<<endl; // Вывод суммы
    return 0;
}
