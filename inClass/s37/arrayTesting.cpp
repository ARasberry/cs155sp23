#include <iostream>
using namespace std;

const int MAX = 10;

int main(){

    double ar[MAX];
    int size = 0;
    int valid = 0;

    cout << "Enter the number of items [0.." << MAX << "]" << endl;
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
    cout << endl;
    double avg = 0;
    double sum = 0;
    for (int i = 0; i < size; ++i){
        sum += ar[i];
    }
    avg = sum / size;
    cout << avg << endl;

    cout << "Printing List" << endl;
    for (int i = 0; i < size; ++i){
        cout << ar[i] << endl;
    }

return 0;
}
