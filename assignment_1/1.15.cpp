#include <bits/stdc++.h>

#include "printing_utils.hpp"

using namespace std;

vector<int> get_palindrome_sequence (int input)
{
    int max_iterations = input + (input - 1);
    vector<int> result_vec;

    for (int i = 0; i < max_iterations; i++)
    {
        int result = abs((input - 1) - i) + 1;
        result_vec.push_back(result);
    }

    return result_vec;
}

int main ()
{
    
    // --- Step 1: Collect and Validate the Input ---
    
    cout << "Please enter a positive odd number:" << endl;

    int input;
    cin >> input;

    if (input < 1)
    {
        cout << "The input mut be a positive odd number.  Exiting the program." << endl;
        return 0;
    }
    
    if (input % 2 == 0)
    {
        cout << "The input mut be an odd number.  The program will proceed with your input - 1." << endl;
        input --;
    }

    // --- Step 2: Prepare Variables for Iteration ---
    
    int max_value = (input + 1) / 2;
    int iteration_diff = 1;
    
    // --- Step 3: Iterative Step ---
    
    for (int i = 1; i > 0; i += iteration_diff)
    {
        int space_count = max_value - i;
        print_char(space_count, ' ');
        
        vector<int> values_to_print = get_palindrome_sequence(i);

        for (int element : values_to_print)
        {
            cout << element;
        }

        cout << endl;

        // Produces the symmetrical output by reversing the iteration direction
        if (i == max_value)
        {
            iteration_diff *= -1;
        }
    }

    return 0;
}