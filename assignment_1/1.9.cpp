#include <iostream>
#include <vector>
using namespace std;

int main ()
{
    vector<char> alphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    cout << "Please enter a number between 1 and 26" << endl;

    int input;
    cin >> input;

    if (input > 26 || input < 1)
    {
        cout << "Input value " << input << " is invalid.  Exiting program." << endl;
        return 0;
    }

    int stop_index = input - 1; // Convert to 0-indexed value
    
    for (int subtractor = 0; subtractor < input; subtractor++)
    {
        int start_index = stop_index - subtractor;

        int current_index = start_index;
        while (current_index <= stop_index)
        {
            cout << alphabet[current_index];
            current_index++;
        }

        cout << endl;
    }
}