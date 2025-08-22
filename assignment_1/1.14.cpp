#include <bits/stdc++.h>
#include "printing_utils.hpp"

using namespace std;

void solid_rhombus (int input)
{
    for (int i = 0; i < input; i++)
    {
        print_char(((input - 1) - i), ' ');      
        print_char(input, '*');
        
        cout << endl;
    }
}

void hollow_rhombus (int input)
{
    for (int i = 0; i < input; i++)
    {
        print_char(((input - 1) - i), ' ');
        
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
}

int main ()
{
    cout << "Please enter a number" << endl;
    
    int input;
    cin >> input;

    cout << endl << "Solid Rhombus:" << endl;
    solid_rhombus(input);

    cout << endl << "Hollow Rhombu:" << endl;
    hollow_rhombus(input);

    return 0;
}