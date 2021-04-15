#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

/*
* \brief Находит площадь грани куба
* \param side Длина ребра куба
* \return Площадь грани куба
*/

double getFaceArea(double side);

/*
* \brief Находит площадь полной поверхности куба
* \param side Длина ребра куба
* \return Площадь полной поверхности куба
*/

double getTotalSurfaceArea(double side);

/*
* \brief Находит объем куба
* \param side Длина ребра куба
* \return Объем куба
*/

double getCubeVolume(double side);

/*
* \brief Вход в программу
* \return в случае успеха, возвращает 0
*/

int main()
{
	double side;
	cout << "Cube edge length: "; cin >> side;

	const double square = getFaceArea(side);
	const double totalArea = getTotalSurfaceArea(side);
	const double volume = getCubeVolume(side);

	cout << "Area of the cube face: " << square << ", The total surface area of the cube: " << totalArea << ", Cube volume: " << volume;

	return 0;
}

double getFaceArea(double side)
{
	return side * side;
}

double getTotalSurfaceArea(double side)
{
	return side * side * 6;
}

double getCubeVolume(double side)
{
	return side * side * side;
}