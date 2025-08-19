#include <iostream>
using namespace std;

int main ()
{
    int input;
    cout << "Provide an input number" << endl;
    cin >> input;

    for (int i = 1; i <= input; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}