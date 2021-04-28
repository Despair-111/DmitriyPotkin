#include <iostream>
#include <algorithm>

using namespace std;

/**
 * \brief Точка входа в программу
 * \return код ошибки. 0 - успех
 */
int main()
{  
    float brick[3], holesize[2];
    cout << "Enter the dimensions of the brick: "; cin >> brick[0] >> brick[1] >> brick[2];
    cout << "Enter the hole dimensions: "; cin >> holesize[0] >> holesize[1];
    
    sort(brick, brick + 3);

    if (holesize[0] > holesize[1])swap(holesize[0], holesize[1]);

    if (brick[0] <= holesize[0] && brick[1] <= holesize[1]) {
        cout << "The brick will pass through the hole\n";
    }
    else {
        cout << "The brick will not pass through the hole\n";
    }
    return 0;
}