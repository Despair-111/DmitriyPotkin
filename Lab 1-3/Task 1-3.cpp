#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

/*
* \brief Находит вес мешка
* \param m Значение массы мешка
* \param g Ускорение свободного падения
* \return Вес мешка
*/
double getWeight(double m, double g);

/*
* \brief Находит силу тяжести мешка 
* \param m Значение массы мешка
* \param g Ускорение свободного падения
* \return Сила тяжести мешка
*/
double getGravity(double m, double g);

/*
* \brief вход в программу
* \return в случае успеха, возвращает 0
*/
int main()
{
	double m;
	const double g = 10;
    cout << "Bag weight: "; cin >> m;

	const double weight = getWeight(m,g);
	const double gravity = getGravity(m,g);

	cout << "Bag weight: " << weight << ", Bag gravity: " << gravity;

	return 0;
}

double getWeight(double m, double g)
{
	return m * g; // По формуле из курса физики
}

double getGravity(double m, double g)
{
	return m * g; // По формуле из курса физики
}