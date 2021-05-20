#define USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

/*
*\brief Находит значение функции y
*\param x Значение аргумента
*\return Значение функции y в точке x
*/
double GetY(double x);

/*
*\brief Находит значение суммы элементов ряда
*\param sum Сумма элементов функционального ряда
*\param element Элемент функционального ряда
*\param eps Точность вычисления функционального ряда
*\param n Порядковый номер элемента ряда
*\return Сумма элементов ряда
*/
double GetRowSum(double sum, double element, double eps, double x, int n);

/*
*\brief Находит факториал от числа
*\param n Входное чилсо
*\return Факториал числа
*/
int Factorial(int n);

/*
*\brief Вход в программу
*\return В случае успеха возвращает 0
*/
int main()
{
    const double a = 0.1, b = 1, h = 0.1, eps = pow(10, -4);
    double x = 0.0, sum = 0.0, element = 1.0;
    int n = 0;

    for (x = a; x <= b; x += h)
    {
        cout << "Argument value: " << x << " Function value: " << GetY(x) << " Row sum: " << GetRowSum(sum, element, eps, x, n) << endl;
    }
    return 0;
}

double GetY(double x)
{
    return sin(x);
}

int Factorial(int n)
{
    if (n == 0) return 1;
    return n * Factorial(n - 1);
}


double GetRowSum(double sum, double element, double eps, double x, int n)
{
    while (abs(element) > eps)
    {
        element = pow(-1, n) * (pow(x, 2 * n + 1) / Factorial(2 * n + 1));
        n += 1;
        sum = sum + element;
    }
    return sum;
}
    
