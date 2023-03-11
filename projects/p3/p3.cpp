#include <iostream>
  1 #include <fstream>
  2 using namespace std;
  3 
  4 //****************************************************************
  5 //FUNCTION DECLARATIONS
  6 //****************************************************************
  7 
  8 void MakeAcctReceipts(int i, string fName, string lName, double sales, double rate);
  9 
 10 const string BUFFER = "******************************************";
 11 //****************************************************************
 12 //DRIVER
 13 //****************************************************************
 14 int main(){
 15 
 16     ifstream fnameinfile;
 17     fnameinfile.open("first.txt");
 18     if (fnameinfile.fail()) {
 19         cout << "first.txt not found" << endl;
 20         exit(1);
 21     }
 22 
 23     ifstream lnameinfile;
 24     lnameinfile.open("last.txt");
 25     if (lnameinfile.fail()){
 26         cout << "last.txt not found" << endl;
 27         exit(2);
 28     }
 29 
 30     ifstream srateinfile;
 31     srateinfile.open("SalesRate.txt");
 32     if (srateinfile.fail()) {
 33         cout << "SalesRate.txt not found" << endl;
 34         exit(3);
 35     }
 36 
 37     ofstream ofile;
 38     ofile.open("RasberryAustin_p3.txt");
 39 
 40     ofile << "Rasberry P3 Output File" << endl;
 41     ofile << BUFFER << endl;
 42 
 43     int numOfAccts;
 44     fnameinfile >> numOfAccts;
 45     int i = 0;
 46     string fName, lName;
 47     double sales, rate;
 48 
 49     while (i < numOfAccts && fnameinfile >> fName && lnameinfile >> lName && srateinfile >> sales && srateinfile >> rate){
 50             MakeAcctReceipts(i, fName, lName, sales, rate);
 51     }
 52 
 53 

