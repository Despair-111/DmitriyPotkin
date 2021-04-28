#define _USE_MATH_DEFINES 

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/**
 * \brief Расчет периметра прямоугольного треугольника
 * \param FirstCatheter Длина первого катета
 * \param SecondCatheter Длина второго катета
 * \return Периметр прямоугольного треугольника
 */
double getPerimeter(double FirstCatheter, double SecondCatheter);

/**
 * \brief Расчет площади прямоугольного треугольника
 * \param FirstCatheter Длина первого катета
 * \param SecondCatheter Длина второго катета
 * \return Площадь прямоугольного треугольника
 */
double getSquare(double FirstCatheter, double SecondCatheter);

/**
 * \brief Пользовательский выбор расчета или периметра прямоугольного треугольника (0),
 * или площади прямоугольного треугольника (1)
 */
enum class ActionChoice { perimeter, square };

/**
 * \brief Точка входа в программу.
 * \return Код ошибки (0 - успех).
 */
int main()
{
	double FirstCatheter, SecondCatheter;
	cout << "Length of the first leg: "; cin >> FirstCatheter;
	cout << "Length of the second leg: "; cin >> SecondCatheter;

	cout << "Enter an action on the triangle (perimeter = 0, square = 1) ";
	int input;
	cin >> input;

	const auto choice = static_cast<ActionChoice>(input);

    switch (choice)
    {
        case ActionChoice::perimeter:
        {
           const double Perimeter = getPerimeter(FirstCatheter, SecondCatheter);
           cout << "Triangle perimeter = " << Perimeter;
           break;
        }
        case ActionChoice::square:
        {
           const double Square = getSquare(FirstCatheter, SecondCatheter);
           cout << "Area of the triangle = " << Square;
           break;
        }
    }
    cout << endl;
    return 0;
}

double getPerimeter(double FirstCatheter, double SecondCatheter)
{
    return FirstCatheter + SecondCatheter + sqrt(FirstCatheter * FirstCatheter + SecondCatheter * SecondCatheter);
}

double getSquare(double FirstCatheter, double SecondCatheter)
{
    return (FirstCatheter * SecondCatheter) / 2;
}
