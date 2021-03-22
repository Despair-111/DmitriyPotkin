#define _USE_MATH_DEFINES 
#include <iostream>
#include <cmath>
using namespace std;
/**
* \brief Расчёт значения а
* \param x Значение x
* \param y Значение y
* \param z Значение z
* \return Значение а
*/
double getA(double x, double y, double z)
{
	return pow(x, y / x) - pow(y / x, 1 / 3.0); 
}
/**
* \brief Расчёт значения b
* \param x Значение x
* \param y Значение y
* \param z Значение z
* \return Значение b
*/
double getB(double x, double y, double z)
{
	return (y-x) + ((y-z)/(y-x))/(3 + (z*z/5));
}
int main()
{
	const auto x = 1.825;
	const auto y = 18.225;
	const auto z = -3.298;
    const auto a = getA(x, y, z);
	const auto b = getB(x, y, z);
    cout << "x=" << x << ", y=" << y << ", z=" << z << "\n";
	cout << "a=" << a << ", b=" << b;
    return 0;
}











