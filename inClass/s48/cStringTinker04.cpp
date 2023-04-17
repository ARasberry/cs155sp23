#include <iostream>
#include <cstring>
using namespace std;

void cstringCopy(char*, char*);  

int main(){

    cout << strcmp("Apples","Apple") << endl;
    cout << strcmp("A","B") << endl;
    cout << strcmp("B","A") << endl;
  

    //STRCPY Tinker
    
    char src[6] = "Lions";
    char dest[6] = "";

    cout << "SRC: " << src << endl;
    cout << "DEST: " << dest << endl;

    cstringCopy(dest,src);

    cout << "SRC: " << src << endl;
    cout << "DEST: " << dest << endl;
    
    return 0;
}

void cstringCopy(char* dest, char* src){
     
    int i = 0;
    do {
      dest[i] = src[i];
      ++i;
    }
    while(src[i] != '\0');

}
