#include <iostream>
using namespace std;

const int MAX = 10;

//DECLARATIONS
void GetArray(double li[], int& size);
double GetAvg(double li[], int size);
void PrintArray(double li[], int size);



int main(){
    double ar[MAX] = {0};    
    int size = 0; 
    double avg;   
    //INPUT
    GetArray(ar, size);

    //PROCESSING
    avg = GetAvg(ar, size);
    cout << "Average is: " << avg << endl;
    PrintArray(ar,size);
   

    return 0;
}


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
 //OUTPUT
    cout << "Printing List" << endl;
    for (int i = 0;i < size; i++)
        cout << ar[i] << endl;    

}
