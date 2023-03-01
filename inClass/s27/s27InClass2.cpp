#include <iostream> 
#include <string>
using namespace std;

int main (){

    string concactString = "";
    string newChar = "";

    cout << "Enter a letter. When finished type '&'. " << endl;

    while (cin >> newChar && newChar != "&"){
          concactString += newChar;
    }
    cout << concactString << endl;


return 0;
}
