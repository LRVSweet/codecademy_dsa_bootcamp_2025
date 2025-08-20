#include <iostream>
using namespace std;

int main()
{
    cout << "Please enter a number: " << endl;

    int input;
    cin >> input;

    for (int i = 1; i <= input; i++)
    {
        for (int j = i; j > 0; j--)
        {
            int output = j % 2;
            cout << output;
        }

        cout << endl;
    }

    return 0;
}