#include <iostream>
using namespace std;

int main(){

    int list[2][3];
    //Storage
    cout << "Enter 6 digits: " << endl;
    for(int r = 0; r < 2; ++r){
        for(int c = 0; c < 3; ++c){
            cin >> list[r][c];
        }
    }
    
    //Output
    for(int r = 0; r < 2; ++r){
        for(int c = 0; c < 3; ++c){
            cout << list[r][c] << "\t";
        }
        cout << endl;
    }
    cout << "***************************" << endl;

    for(int r = 0; r < 2; ++r){
        for(int c = 0; c < 3; ++c){
           list[r][c] = rand();
        }
    }
    
    for(int r = 0; r < 2; ++r){
        for(int c = 0; c < 3; ++c){
            cout << list[r][c] << "\t";
        }
        cout << endl;
    }


    return 0;
}
