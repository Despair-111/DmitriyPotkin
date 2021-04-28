#define _USE_MATH_DEFINES 

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/**
 * \brief Функция расчета для случая, x >= 1 и x <= 2.
 * \param x Входная величина.
 * \param a Входная величина.
 * \return Значение функции.
 */
double F1(const double x, const double a);

/**
 * \brief Функция расчета для случая, когда x > 2.
 * \param x Входная величина.
 * \param a Входная величина.
 * \return Значение функции.
 */
double F2(const double x, const double a);

/**
 * \brief Точка входа в программу.
 * \return Код ошибки (0 - успех).
 */
int main()
{
	const double a = 2;
    const double q = 2;
    const double r = 1;
	double x;
	cout << "Enter a variable x = "; cin >> x;
    double result;

     if (x > q)
    {
        result = F2(x, a);
    }

    else if(x < r)
    {
        result = 1;
    }
    else 
     {
        result = F1(x, a);
     }
     

    cout << "y = " << setprecision(15) << result << endl;
    return 0;
}

double F1(const double x, const double a)
{
    return a * pow(x, 2 * log(x));
}

double F2(const double x, const double a)
{
    return exp(a * x) * cos(x);
}