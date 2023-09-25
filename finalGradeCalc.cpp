#include<iostream>
#include<string>
using namespace std;

int main(){

    // var declaration 
    int exam1 = 0;
    int exam2 = 0;
    int exam3 = 0;
    int misc = 0;
    double exams = 0;
    int finalExam = 0;
    double examFinalGrades = 0;
    int projects = 0;
    int quizes = 0;
    double examsPercent = 0;
    double finalPercent = 0;
    double miscPercent = 0;
    double projPercent = 0;
    double quizPercent = 0;
    double finalGrade = 0;

    // user input to get grades 
    cout << "Enter grade for exam 1" << endl;
    cin >> exam1;
    cout << "Enter grade for exam 2" << endl;
    cin >> exam2;
    cout << "Enter grade for exam 3" << endl;
    cin >> exam3;
    cout << "Enter grade for the final exam" << endl;
    cin >> finalExam;
    cout << "Enter grade for misc" << endl;
    cin >> misc;
    cout << "Enter grade for quizes" << endl;
    cin >> quizes;
    cout << "Enter grade for projects" << endl;
    cin >> projects;


    //helper functions 
    exams = ((exam1 + exam2 + exam3) / 3);
    examFinalGrades = (exams + finalExam) / 2;
    examsPercent = exams * .35;


return 0;
}
