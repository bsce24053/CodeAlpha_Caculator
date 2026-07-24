#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
using namespace std;

class CGPACalculator{
    float* grade;
    int numCourses;
    int* creditHours;
    string* courseName;
    public:
    CGPACalculator(){
        grade=nullptr;
        numCourses=0;
        creditHours=nullptr;
        courseName=nullptr;
    }
    ~CGPACalculator(){
        delete[] grade;
        delete[] courseName;
        delete[] creditHours;
    }

    void inputData(){
        cout<<"enter the courses :"<<endl;
        cin>>numCourses;
        grade=new float[numCourses];
        creditHours=new int[numCourses];
        courseName=new string[numCourses];
        for(int i=0;i<numCourses;i++){
            cout<<"enter the credit hours :"<<endl;
            cin>>creditHours[i];
            cout<<"enter the course name :"<<endl;
            cin>>courseName[i];
            cout<<"enter the grade :"<<endl;
            cin>>grade[i];
        }
    }
    int calculateTotalCredits(){
        int totalCreditHour=0;
        for(int i=0;i<numCourses;i++){
            totalCreditHour+=creditHours[i];
        }
        return totalCreditHour;
    }
    float calculateTotalGradePoints(){
     float totalGradePoint=0;
            for(int i=0;i<numCourses;i++){
                totalGradePoint=grade[i]*creditHours[i];
            }
            return totalGradePoint;
    }
    float calculateGPA(){
        return calculateTotalGradePoints()/calculateTotalCredits();

}
float calculateCGPA(){
    return  calculateGPA();
}
void displayCourses(){
    for(int i=0 ;i<numCourses;i++){
    cout<<"The Course Name is :"<<courseName[i]<<endl;
    cout<<"The Course Grade is :"<<grade[i]<<endl;
    cout<<"The Course Credit Hour is :"<<creditHours[i]<<endl;
}
}
 void displayResult()
    {
        displayCourses();
        cout << "Total Credits: "
             << calculateTotalCredits() << endl;
        cout << "Total Grade Points: "
             << calculateTotalGradePoints() << endl;
        cout << "Semester GPA: "
             << calculateGPA() << endl;
        cout << "Final CGPA: "
             << calculateCGPA() << endl;
    }
};

#endif