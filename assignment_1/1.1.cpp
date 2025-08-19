#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
    // --- Step 1: Gather Input ---
    
    int math_grade, physics_grade, chem_grade;
    cin >> math_grade >> physics_grade >> chem_grade;

    // --- Step 2: Calculate Average Percentage ---
    
    double avg_grade = (math_grade + physics_grade + chem_grade) / 3.0;

    // --- Step 3: Determine Status and Letter Grade ---

    string status = "Pass";
    char letter_grade;
    
    if (math_grade <= 60 || physics_grade <= 60 || chem_grade <= 60)
    {
        status = "Fail";
        letter_grade = 'F';
    }
    else if (avg_grade >= 90)
    {
        letter_grade = 'A';
    }
    else if (avg_grade >= 80)
    {
        letter_grade = 'B';
    }
    else if (avg_grade >= 70)
    {
        letter_grade = 'C';
    }
    else if (avg_grade >= 60)
    {
        letter_grade = 'D';
    }
    else
    {
        status = "Fail";
        letter_grade = 'F';
    }

    // --- Step 4: Print Result ---

    avg_grade = round(avg_grade * 100) / 100.0;

    cout << "Final Percentage: " << avg_grade << endl;
    cout << fixed << setprecision(2) << "Status: " << status << endl;
    cout << "Letter Grade: " << letter_grade << endl;

    return 0;
}