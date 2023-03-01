#include <iostream>
using namespace std;

int main(){

    int grade;
    double sum = 0;
    double avg;
    int count = 0;
    cout <<"Enter grades. Type a negative number when finished." << endl;

    while (cin >> grade && grade >= 0){
        sum += grade;
        count++;
    }
    if (count > 0){
        avg = sum/count;
        cout << avg << endl;
    }
    else{
        avg = 0;
        cout << "Error no grades given. Cannot divide by zero." << endl;
    }

return 0;
}
