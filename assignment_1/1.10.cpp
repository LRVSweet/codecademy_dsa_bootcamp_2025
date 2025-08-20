#include <bits/stdc++.h>

#include "printing_utils.hpp"

using namespace std;

int main ()
{
    cout << "Please enter a number." << endl;
    int input;
    cin >> input;

    int max_stars = input * 2;
    /**
     * Steps:
     * 1. current_stars = max_stars - (2i)
     * 2. one_side_star = current_stars / 2
     * 3. current_spaces = max_stars - current_stars
     * 4. print one_side_stars
     * 5. print current_spaces
     * 6. print one_side_stars
     * 7. i++; iterate
     */

    for (int i = 0; i < input; i++)
    {
       int current_stars = max_stars - (2 * i);
       int one_side_stars = current_stars / 2;
       int current_spaces = max_stars - current_stars;

       print_char(one_side_stars, '*');
       print_char(current_spaces, ' ');
       print_char(one_side_stars, '*');
       cout << endl;
    }

    for (int i = input - 1; i >= 0; i--)
    {
       int current_stars = max_stars - (2 * i);
       int one_side_stars = current_stars / 2;
       int current_spaces = max_stars - current_stars;

       print_char(one_side_stars, '*');
       print_char(current_spaces, ' ');
       print_char(one_side_stars, '*');
       cout << endl;
    }
    
    
    
    return 0;
}