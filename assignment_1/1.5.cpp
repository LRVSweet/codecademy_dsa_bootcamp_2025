#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Please enter a number" << endl;

    int input;
    cin >> input;

    int max_triangular_number = (input * 2) - 1;
    int space_count = 0;

    for (int i = max_triangular_number; i > 0; i = i - 2)
    {
        for (int j = 0; j < space_count; j++)
        {
            cout << " ";
        }
        
        space_count++;

        for (int k = 0; k < i; k++)
        {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}