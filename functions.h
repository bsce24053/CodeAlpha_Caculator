#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
using namespace std;

class CGPACalculator{
private:
    string* courseName;
    float* grade;
    int* creditHours;
    int numCourses;

public:
    CGPACalculator(){
        numCourses = 0;
        courseName = nullptr;
        grade = nullptr;
        creditHours = nullptr;
    }
    ~CGPACalculator(){
        delete[] courseName;
        delete[] grade;
        delete[] creditHours;
    }
    void inputData(){
        delete[] courseName;
        delete[] grade;
        delete[] creditHours;
        cout<< "Enter Number of Courses: ";
        cin >> numCourses;
        courseName = new string[numCourses];
        grade = new float[numCourses];
        creditHours = new int[numCourses];
        cin.ignore();
        for (int i = 0; i < numCourses; i++){
            cout << "\nCourse " << i + 1 << endl;
            cout << "Course Name: ";
            getline(cin, courseName[i]);
            cout << "Grade Point (0-4): ";
            cin >> grade[i];
            cout << "Credit Hours: ";
            cin >> creditHours[i];
            cin.ignore();
        }
    }
    int calculateTotalCredits(){
        int totalCredits = 0;
        for (int i = 0; i < numCourses; i++){
            totalCredits += creditHours[i];
        }
        return totalCredits;
    }
    float calculateTotalGradePoints(){
        float totalGradePoints = 0;
        for (int i = 0; i < numCourses; i++){
            totalGradePoints += grade[i] * creditHours[i];
        }
        return totalGradePoints;
    }
    float calculateGPA(){
        if (calculateTotalCredits() == 0)
            return 0;

        return calculateTotalGradePoints() / calculateTotalCredits();
    }
    float calculateCGPA(){
        return calculateGPA();
    }
    void displayCourses(){
        cout << "\n===============================" << endl;
        cout << "       COURSE DETAILS" << endl;
        cout << "===============================" << endl;
        for (int i = 0; i < numCourses; i++) {
            cout << "\nCourse " << i + 1 << endl;
            cout << "Course Name  : " << courseName[i] << endl;
            cout << "Grade Point  : " << grade[i] << endl;
            cout << "Credit Hours : " << creditHours[i] << endl;
        }
    }
    void displayResult(){ 
        displayCourses();
    cout<< "\n===============================" << endl;
    cout<< "           RESULT" << endl;
    cout<< "===============================" << endl;
        cout<< "Total Credits      : "
        << calculateTotalCredits()<< endl;
        cout<< "Total Grade Points : "
        <<calculateTotalGradePoints()<< endl;
        cout<<"Semester GPA       : "<< calculateGPA() << endl;
        cout << "Overall CGPA       : "
             << calculateCGPA() << endl;
    }
};

#endif
