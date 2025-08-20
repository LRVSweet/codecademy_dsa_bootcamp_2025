#include <iostream>
using namespace std;

int main()
{
    cout << "Please provide a number:" << endl;
    int input;
    cin >> input;

    int max_row = (input * 2) - 1;
    int max_spaces = max_row / 2;
    int increment = 2;

    int star_count = 1;
    while (star_count > 0)
    {
        // Reverses the direction of the printed triangle
        if (star_count > max_row)
        {
            increment *= -1;
            star_count += increment;
            continue;
        }

        int space_count = max_spaces - (star_count / 2);
        
        for (int i = 0; i < space_count; i++)
        {
            cout << " ";
        }

        for (int j = 0; j < star_count; j++)
        {
            cout << "*";
        }

        cout << endl;
        star_count += increment;
    }

    return 0;
}