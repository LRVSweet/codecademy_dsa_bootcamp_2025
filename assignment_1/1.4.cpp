#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Please enter a number:" << endl;
    int input;
    cin >> input;

    for (int i = input; i > 0; i--)
    {
        for (int j = i; j > 0; j--)
        {
            cout << j;
        }

        cout << endl;
    }

    return 0;
}