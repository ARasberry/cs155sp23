//Author: S50
//Project 6
//Date: 03-20-23
//Project 6 skeleton code provided by Dr. Jenkins and Austin Rasberry in project 4

#include <iostream>
using namespace std;


//***************************************************************
//Constants
//***************************************************************
const string line = "----------------------------------";
const int MAXROW = 10; //Max number of rows
const int MAXCOL = 10; //Max number of columns

//***************************************************************
//Declarations
//***************************************************************
int GetChoice(); //Selects function from menu
void FillMatrix(int[][MAXCOL], int&, int&); // Fills the matrix from the user
void PrintRowMajorMatrix(int[][MAXCOL], int, int); // Prints the matrix in row order
void PrintColMajorMatrix(int[][MAXCOL], int, int); // Prints the matrix in column order
bool PrintDiagonal(int[][MAXCOL], int, int); // Prints the diagonal values (in a diagonal)
int GetSumofValues(int[][MAXCOL], int, int); // Adds the matrix together and prints the sum
void PrintColumnProducts(int[][MAXCOL], int, int); // Prints the column number and the product of the column

//***************************************************************
//Driver
//***************************************************************

int main(){
    
	//Declaing Variables
	int matrix[MAXROW][MAXCOL] = {0}; // Declares the matrix
	int row = 0;
	int col = 0;
	bool isSquare; // Used to see if the matrix is square
	int sum = 0;

	//Main usage loop
	int choice = GetChoice(); // user selects from menus in GetChoice() 
    while (choice != 0){ // Controls when to break from loop
        if (choice == 1){
        	FillMatrix(matrix, row, col);
        }
        else if (choice == 2){
			PrintRowMajorMatrix(matrix, row, col);
		}
		else if (choice == 3){
		    PrintColMajorMatrix(matrix, row, col);
		}
		else if (choice == 4){
		   isSquare = PrintDiagonal(matrix, row, col);
		   if (isSquare == false)
			   cout << "Matrix is not square" << endl;
		}
		else if (choice == 5){
		   sum = GetSumofValues(matrix, row, col);
		   cout << "The sum of the matrix is " << sum << endl;
		}		
        else if (choice == 6){
		   PrintColumnProducts(matrix, row, col);
        }
        
        choice = GetChoice(); // Reruns after the function call to continue the loop
    }
   

   return 0;
}

//***************************************************************
//Definitions
//***************************************************************

//Prints the menu of options and gets the choice from the user 
int GetChoice(){ 
   int result = 0;
   cout << endl << line << endl;
   cout << "Enter the choice you want to complete: " << endl;
   cout << "1: Fill Matrix" << endl;
   cout << "2: Print Matrix in Row Major Order" << endl;
   cout << "3: Print Matrix in Col Major Order" << endl;
   cout << "4: Print Diagonal" << endl;
   cout << "5: Get a Sum of Values" << endl;
   cout << "6: Print the Product of Each Column" << endl;
   cout << "0: Stop" << endl;
   cout << line << endl;
   cout << "Enter your choice here: ";
   cin >> result;
   cout << line << endl << endl;
   return result;
}

//Fills the matrix from user input
void FillMatrix(int matrix[][MAXCOL], int& row, int& col){
	cout << "Enter the number of rows: " << endl;
	cin >> row;
	cout << "Enter the number of columns:" << endl;
	cin >> col;
	for (int r = 0; r < row; ++r){
		for(int c = 0; c < col; ++c){
			cout << "Enter Value for Row " << r << " and Column " << c << endl;
			cin >> matrix[r][c];
		}
	}		
}

//Prints the matrix in row order
void PrintRowMajorMatrix(int matrix[][MAXCOL], int row, int col){
	for(int r = 0; r < row; ++r){
		for(int c = 0; c < col; ++c){
		cout << matrix[r][c] << "\t";
		}
		cout << endl;
	}	
}

//Prints the matrix in column order
void PrintColMajorMatrix(int matrix[][MAXCOL], int row, int col){
	for(int c = 0; c < col; ++c){
		for(int r = 0; r < row; ++r){
		cout << matrix[r][c] << "\t";
		}
		cout << endl;
	}	
}

//If the matrix is a square it returns true and prints the diagonal of the matrix
//If the matrix is not square it returns false and the driver prints a message
bool PrintDiagonal(int matrix[][MAXCOL], int row, int col){
	if (row == col){
		for (int r = 0; r < row; ++r){
			for(int c = 0; c < col; ++c){
				if (r == c)
					cout << matrix[r][c] << "\t";
				else
					cout << "\t";
			}
			cout << endl;
		}
		return true;
	}
	else
		return false;
}

//Returns the sum of the values in the matrix
int GetSumofValues(int matrix[][MAXCOL], int row, int col){
	int sum = 0;
	for (int r = 0; r < row; ++r){
		for (int c = 0; c < col; ++c)
			sum += matrix[r][c];
	}
	return sum;
}

//Prints the column number and the corresponding product of the column
void PrintColumnProducts(int matrix[][MAXCOL], int row, int col){
	for (int c = 0; c < col; ++c){
		int prod = 1;
		for (int r = 0; r < row; ++r){
			prod *= matrix[r][c];
		}
		cout << "Column number: " << c << endl;
		cout << "Column product: " << prod << endl;
	}
}

