#include "functions.h"

int main()
{
    CGPACalculator student;
    int choice;
    do
    {
        cout << "\n===== CGPA CALCULATOR =====\n";
        cout << "1. Enter Course Data\n";
        cout << "2. Display Result\n";
        cout << "3. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                student.inputData();
                break;

            case 2:
                student.displayResult();
                break;

            case 3:
                cout << "Program Ended.\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while(choice != 3);

    return 0;
}