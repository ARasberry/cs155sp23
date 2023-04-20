//Author: Austin Rasberry
//Project 4
//Date: 03-20-23
// Project 4 skeleton code provided by Dr. Jenkins

#include <iostream>
using namespace std;


//***************************************************************
//Constants
//***************************************************************
const string line = "----------------------------------";


//***************************************************************
//Declarations
//***************************************************************
int GetChoice();
void GetFirstLast(string& first, string& last);
void DisplayFirstLast(string first, string last);
void GetDim(int& row, int& col);
void PrintBox(int row, int col);
char ConvertDigitToChar(int digit);
void PrintMultTable(int factor);


//***************************************************************
//Driver
//***************************************************************

int main(){
	//Declare variables needed within multiple if clauses below here
	string first, last;
	int row, col, digit, factor;
	char digChar;

	//Loop to control program flow
    int choice = GetChoice();
    while (choice != 0){
        if (choice == 1){
           GetFirstLast(first, last);
        }
        else if (choice == 2){
		   DisplayFirstLast(first, last);
		}
		else if (choice == 3){
		   GetDim(row, col);
		}
		else if (choice == 4){
		   PrintBox(row,col);
		}
		else if (choice == 5){
		   cout << "Enter a single numeric digit" << endl;
		   cin >> digit;
		   digChar = ConvertDigitToChar(digit); 
		   cout << digChar << endl;
		}		
        else if (choice == 6){
           cout << "Enter a numerical factor: " << endl;
		   cin >> factor;
		   PrintMultTable(factor);
        }
        
        choice = GetChoice();
    }
   

   return 0;
}

//***************************************************************
//Definitions
//***************************************************************


//***************************************************************
// Function Name: GetChoice - do not change this routine
//***************************************************************
// Purpose:  To print options to the user for menu options
// Incoming: NA
// Outoing:  NA
// Return:   Choice as an integer
//***************************************************************
int GetChoice(){
   int result = 0;
   cout << endl << line << endl;
   cout << "Enter the choice you want to complete: " << endl;
   cout << "1: Get First and Last name of user" << endl;
   cout << "2: Display First and Last name of user" << endl;
   cout << "3: Get Current Dimensions of row and col" << endl;
   cout << "4: Print a Box" << endl;
   cout << "5: Convert a single digit integer to its char" << endl;
   cout << "6: Print multiplication table" << endl;
   cout << "0: Stop" << endl;
   cout << line << endl;
   cout << "Enter your choice here: ";
   cin >> result;
   cout << line << endl << endl;
   return result;
}

//***************************************************************
// Function Name: GetFirstLast
//***************************************************************
// Purpose:  To prompt for and input the user's first and last name 
// Incoming: NA
// Outoing:  first name as a string, last name as a string
// Return:   NA
//***************************************************************
void GetFirstLast(string& first, string& last){
	cout << "Enter your first and last name: " << endl;
	cin >> first;
	cin >> last;
}

//***************************************************************
// Function Name: DisplayFirstLast
//***************************************************************
// Purpose:  To Display the first and last names  
// Incoming: first name as a string, last name as a string
// Outoing:  NA
// Return:   NA
//***************************************************************

void DisplayFirstLast(string first, string last){
	cout << "Name: " << first << " " << last << endl;
}

//***************************************************************
// Function Name: GetDimenions
//***************************************************************
// Purpose:  To prompt for and input the row and column number 
// Incoming: NA
// Outoing:  row as an integer, column as an integer
// Return:   NA
//***************************************************************
void GetDim(int& row, int& col){
    cout << "Enter the number of rows and columns as integers: " << endl;
	cin >> row;
	cin >> col;
}

//***************************************************************
// Function Name: PrintBox
//***************************************************************
// Purpose:  To print a box given the row and column dimensions 
//           in the shape below where the X's and O's toggle, 
//			 examples given below:
//
//			 3x4			4x3
//		     XOXO 			XOX
//			 XOXO			OXO
//	         XOXO			XOX
// Incoming: row as integer, col as integer
// Outoing:  NA
// Return:   NA
//***************************************************************

void PrintBox(int row, int col){
	int evenCount = 0; //Counts up to guarrantee that the X's and O's rotate
    for (int r = 0; r < row; ++r){ // sets up the rows
		for (int c = 0; c < col; ++c){ // sets up the columns
			if (evenCount % 2 == 0) // tests to make the X's and O's rotate
				cout << "X";
			else
				cout << "O";
			++evenCount; // increments the counter 
		}
		cout << endl;
	}
}
//***************************************************************
// Function Name: ConvertDigitToChar
//***************************************************************
// Purpose:  Take the given integer digit and return the 
//           digit in its character form. Should the integer
//			 parameter be larger or smaller than a single 
//			 non-negative diegit, the function should return
//			 the letter 'Z'. That is the integer must be
//		     in the range of [0..9] to be converted to its
//			 character equivalent
// Incoming: digit as an integer
// Outoing:  NA
// Return:   digit as a character
//***************************************************************

char ConvertDigitToChar(int digit){
	char digChar;
	if (digit >= 0 && digit < 10)
		digChar = 48 + digit; // 48 is the magic number (it's the ascii value for 0) 
	else
		digChar = 'Z';
	return digChar;
}
//***************************************************************
// Function Name: PrintMultTable
//***************************************************************
// Purpose:  Take the given integer factor, print all multiplcation 
//			 facts [0..12] for each factor from 0 up to the factor 
//			 given in the parameter. Print a row and column labels 
//		     such that the intersection of the row and column label
//			 is the product of the row and column. See below for an 
//			 example with a parameter factor of 2
//     0    1       2       3       4       5       6       7       8       9       10      11      12
//  0: 0    0       0       0       0       0       0       0       0       0       0       0       0
//  1: 0    1       2       3       4       5       6       7       8       9       10      11      12
//  2: 0    2       4       6       8       10      12      14      16      18      20      22      24

// Incoming: factor as an integer
// Outoing:  NA
// Return:   NA
//***************************************************************

void PrintMultTable(int factor){

	cout << "\t0 \t1 \t2 \t3 \t4 \t5 \t6 \t7 \t8 \t9 \t10 \t11 \t12" << endl; // sets up the top line for formatting
	for (int r = 0; r <= factor; ++r) { //sets the loop to make sure all the rows are there
		cout << r << ":      "; // tells the number to be muliplied by 
		for (int c = 0; c < 13; ++c) { // sets the number of columns
			cout << r * c << "\t"; // does the calculations
		}
		cout << endl;
	}
}
