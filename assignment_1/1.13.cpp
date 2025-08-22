#include <bits/stdc++.h>

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
    cout << "Please enter a number." << endl;
    int input;
    cin >> input;

    vector<int> palindrome_vec = get_palindrome_sequence(input);

    // palindrome_vec serves a dual purpose:
    // 1. A list of the min values for each row.
    // 2. A row "template" that is compared against the min.
    
    // The outer loop provides each row's min value.
    for (int row_min : palindrome_vec)
    {
        // The inner loop produces the result by comparison against the min.
        for (int element : palindrome_vec)
        {
            if (element < row_min)
            {
                cout << row_min << " ";
            }
            else
            {
                cout << element << " ";
            }
        }

        cout << endl;
    }

    return 0;
}