#include <random>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
* \brief Функция заполнения массива с клавиатуры
* \param n количество строк
* \param m количество стобцов
* \return Заполненный массив
*/
int** GetFillKeyboardArray(const int n, const int m);

/**
* \brief Функция заполнения массива случайными числами
* \param n количество строк
* \param m количество стобцов
* \return Заполненный массив
*/
int** GetFillRandomArray(const int n, const int m);

/**
 * \brief Пользовательский выбор ввода через клавиатуру (0),
 * или заполнения случайными числами (1)
 */
enum class ActionChoice { random, keyboard };

/**
\brief Вывод массива на консоль
* \param ary массив
* \param n количество строк
* \param m количество столбцов
* \return Массив
*/
void ArrayPrint(int** ary, const int n, const int m);

/**
* \brief Замена минимального по модулю элемента каждого столбца нулем
* \param Ary введенный массив
* \return Массив
*/
void ReplacingTheMinimumWithZero(int** Ary, const int n, const int m);

/**
 * \brief Точка входа в программу.
 * \return Код ошибки (0 - успех).
 */
int main()
{
    
	int n;
	cout << "Input number of rows: ";
	cin >> n;

    int m;
	cout << "Input number of columns: ";
	cin >> m;

    cout << "Choose the input method (random = 0, keyboard = 1) ";
    int input;
    cin >> input;

    int** Ary = nullptr;
    
    const auto choice = static_cast<ActionChoice>(input);

    switch (choice)
    {
    case ActionChoice::random:
    {
         Ary = GetFillRandomArray(n, m);
         break;
    }
    case ActionChoice::keyboard:
    {
        Ary = GetFillKeyboardArray(n, m);
        break;
    }
    }
    cout << endl;

    ReplacingTheMinimumWithZero(Ary, n, m);

    ArrayPrint(Ary, n, m);

    

    return 0;
}

int** GetFillKeyboardArray(const int n, const int m)
{
    int** ary;
    ary = new int * [n];
    for (int i = 0; i < n; i++) {   
        ary[i] = new int[m];     
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> ary[i][j];
        }
    }
    return ary;
    
}

int** GetFillRandomArray(const int n, const int m)
{
    int** ary;
    ary = new int* [n];
    for (int i = 0; i < n; i++) {
        ary[i] = new int[m];
    }

    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
           ary[i][j]= rand();
        }
    }
    return ary;
}

void ArrayPrint(int** ary, const int n, const int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << ary[i][j] << '\t';
        }
        cout << '\n';
    }
}

void ReplacingTheMinimumWithZero(int** Ary, const int n, const int m)
{
    int tempRow, min;

    for (int i = 0; i < m; i++)
    {
        min = abs(Ary[0][i]);
        tempRow = 0;

        for (int j = 1; j < n; j++)
        {
            if (min > abs(Ary[j][i]))
            {
                min = abs(Ary[j][i]);
                tempRow = j;
            }
        }
        Ary[tempRow][i] = 0;
    }
}

