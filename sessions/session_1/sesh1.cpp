#include <bits/stdc++.h>
using namespace std;

int get_vowel_count(string input)
{
    unordered_set vowels = {'a', 'e', 'i', 'o', 'u'};
    int vowel_count = 0;

    for (char character : input)
    { 
        if (vowels.count(character))
        {
            vowel_count++;
        }
    }

    return vowel_count;
}

int main()
{
    string input_string;
    getline(cin, input_string);

    int vowel_count = get_vowel_count(input_string);

    cout << vowel_count << endl;
    return 0;
}