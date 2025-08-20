#include <bits/stdc++.h>

#include "printing_utils.hpp"

using namespace std;

int main ()
{
    cout << "Please enter a number." << endl;
    int input;
    cin >> input;

    for (int i = 0; i < input; i++)
    {
        if (i == 0 || i == input - 1)
        {
            print_char(input, '*');
            cout << endl;
            continue;
        }

        cout << '*';
        print_char(input - 2, ' ');
        cout << '*' << endl ;
    }

    return 0;
}