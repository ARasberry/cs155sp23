#include <iostream>
using namespace std;

void PrintArray(double[], int);
int LinearSearch(double[], int, double);



const int MAX = 10;

int main(){
    double ar[MAX] = {44, 3.14, 55, 99, 44};    
    int size = 5;    
    

    PrintArray(ar,size);
    double searchItem;
    cout << "Enter item to be found: " << endl;
    cin >> searchItem;
    cout << "Item found at position: " << LinearSearch(ar, size, searchItem) << endl;

    return 0;
}



void PrintArray(double li[], int size){
    cout << "Printing List" << endl;
    for (int i = 0;i < size; i++)
        cout << li[i] << endl;    

}

int LinearSearch(double li[], int size, double item){
    int position = -1;
    for( int i = 0; i < size && position < 0; ++i){
        if (li[i] == item)
           position = i;
    }
    return position;
}
