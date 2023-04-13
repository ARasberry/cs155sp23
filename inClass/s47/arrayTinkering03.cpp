#include <iostream>
#include <cstring>
using namespace std;

int myStrLen(const char* str){
    int count = 0;
    while(str[count] != '\0')
        ++count;
    return count;
}

int main(){
    char ch1 = 'X';
    char str1[6] = "lions";
    char ch2 = 'Y';
    cout << str1 << endl;
    cout << (str1-1) << endl;
    cout << "Length of " << str1 << " is " << strlen(str1) << endl;
    cout << "Length of " << str1 << " is " << myStrLen(str1) << endl;

    return 0;
}
