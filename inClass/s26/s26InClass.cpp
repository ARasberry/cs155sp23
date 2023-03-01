#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

    string subString;
    cout << "Enter a string:" << endl;
    cin >> subString;

    ifstream infile;
    infile.open("in.txt");
    ofstream ofile;
    ofile.open("out.txt");
    if (infile.fail()){
       cout << "file not found" << endl;
       exit(1);
    }

    int stringCount = 0;
    int subStringCount = 0;
    string tempString;
    while (infile >> tempString) {
        if (tempString.find(subString) >= 0 && tempString.find(subString) < tempString.length()){
           subStringCount ++;
        }
        stringCount ++;
    }      
    cout << "Total number of strings is: " << stringCount << endl;
    cout << "Times " << subString << " is used is: " << subStringCount << endl;
    ofile << "Total number of strings is: " << stringCount << endl;
    ofile << "Times " << subString << " is used is: " << subStringCount << endl;

return 0;
}
