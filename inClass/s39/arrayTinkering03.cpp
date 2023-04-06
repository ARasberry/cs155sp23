#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 20;
//************************************************
//DECLARATIONS
//************************************************
void GetArray(double li[], int& size);
double GetAvg(double li[], int size);
void PrintArray(double li[], int size);
void FillArrayFromFile(double li[], int& size);
void PrintArrayReverse(double li[], int size);
void ReverseArray(double li[], int size);
int GetChoice();

//************************************************
//DRIVER
//************************************************
int main(){
    double ar1[MAX] = {0}; 
    double ar2[MAX] = {0};   
    int size = 0; 
    double avg;   
    int userChoice = GetChoice();
    switch(userChoice){
        case 1:
            GetArray(ar1, size);
            break;
        case 2:
            avg = GetAvg(ar1,size);
            break;
        case 3:
            

    return 0;
}

//********************************************************************
//DEFINITIONS
//********************************************************************
void GetArray(double ar[], int& size){
    cout << "Enter the number of items [0.." << MAX << "]" << endl;
    int valid = 0;
    while (valid == 0){
        cin >> size;
        if (size > MAX){
           cout << "Exceeds array size, try again" << endl;
           size = MAX;
        }
        else if (size < 0) {
            cout << "Size is invalid, try again" << endl;
            size = 0;
        }
        else{
            valid++;
        }  
    }
    cout << "Enter " << size << " number of values: " << endl;
    for (int i = 0; i < size; ++i){
        cin >> ar[i];        
    }
}

double GetAvg(double ar[], int size) {
    double sum = 0, average;
    for (int i = 0; i < size; i++)
        sum += ar[i];
    average = sum /size;
    return average;
}

void PrintArray(double ar[], int size){
    cout << "Printing List" << endl;
    for (int i = 0;i < size; i++)
        cout << ar[i] << endl;    

}

void FillArrayFromFile(double ar[], int& size){
    string userFile;
    cout << "Enter a file name: " << endl;
    cin >> userFile;
    ifstream infile;
    infile.open(userFile);

    for(size = 0; size < MAX && infile >> ar[size]; ++size);

    infile.close(userFile);
}
    
int GetChoice(){
    int functionId;
    // INSERT DO WHILE
    do {
    cout >> "----------Commands------------- " << endl;
    cout >> "Create an User Entered Array = 1" << endl;
    cout >> "Get the Average of an Array = 2" << endl;
    cout >> "Print Array = 3" << endl;
    cout >> "Create an Array from a File = 4" << endl;
    cin << functionId;
    }
    while (functionId > 0; functionId < 5);
    return fuctionId;
}
