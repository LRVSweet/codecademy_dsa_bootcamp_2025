#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cout << "Please enter a number" << endl;

    int input;
    cin >> input;

    vector<int> input_range;
    for (int i = 1; i <= input; i++)
    {
        input_range.push_back(i);
    }

    for (int &element : input_range)
    {
        for (int &lvl_2_element : input_range)
        {
            if (lvl_2_element <= element)
            {
                cout << lvl_2_element;
            }
            else
            {
                cout << " ";
            }
        }

        vector<int>::reverse_iterator rev_it;
        for (rev_it = input_range.rbegin(); rev_it != input_range.rend(); rev_it++)
        {
            if (*rev_it <= element)
            {
                cout << *rev_it;
            }
            else
            {
                cout << " ";
            }
        }

        cout << endl;      
    }

    return 0;
}