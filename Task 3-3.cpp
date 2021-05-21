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
* \brief Расчет рекуррентной функции
* \param x Значение x
* \param index Значение n в форумуле
* \return Рекуррентное значение
*/
double Recurrent(const int index, const double x);

/*
* \brief Расчёт суммы ряда
* \param x Значение x с шагом 0,1
* \param eps Точность
* \return Значение суммы
*/
double GetRowSum(const double x, const double eps);

/*
*\brief Вход в программу
*\return В случае успеха возвращает 0
*/
int main()
{
    const double a = 0.1, b = 1, h = 0.1, eps = pow(10, -4);
	double x = a;
	
	while (x <= b + eps)
	{
		const double function = GetY(x);
		const double rowsum = GetRowSum(x, eps);
		cout << "Argument value: " << x << " Function value: " << function << " Row sum: " << rowsum << endl;
		x += h;
	}
    return 0;
}

double GetY(double x)
{
    return sin(x);
}

double GetRowSum(const double x, const double eps)
{
	auto null = 0.0;
	auto previous = 0.0;
	auto current = Recurrent(null, x);
	auto sum = current;
	unsigned int index = 1;
	do
	{
		previous = current;
		current = previous * Recurrent(index, x);
		sum += current;
		index++;
	} while (abs(previous - current) < eps);

	return sum;
}

double Recurrent(const int index, const double x)
{
    return pow(-1, index) * (pow(x, 2 * index + 1) / (2 * index + 1));
}