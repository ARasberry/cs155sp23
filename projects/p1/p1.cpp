# include <iostream>
using namespace std;

/*
Austin Rasberry
Project 1
	The program takes in four digits as characters, prints them out line by line,
casts them as integers, adds them together and outputs the sum. 
It then returns an integer that is the input in reverse order.
Then it prompts the user to input a five digit number
and prints the place order of the number starting with the ones place.
*/


int main(){

	//Declaring Vars
	char char1;
	char char2;
	char char3;
	char char4;
	int sum;
	int reverseInput;
	int fiveDigitInput;
	int tempVar;
	int tempVar2;

	//Input Chars
	cout << "Enter a four digit number: " << endl;
	cin >> char1 >> char2 >> char3 >> char4;
	
	//Output Chars line by line
	cout << char1 << endl;
	cout << char2 << endl;
	cout << char3 << endl;
	cout << char4 << endl;

	//Giving Chars their int values
	char1 -= 48;
	char2 -= 48;
	char3 -= 48;
	char4 -= 48;

	//Processing and outputting Sum
	sum = char1 + char2 + char3 + char4;

	cout << "The sum of the input is: " << sum << endl;
	
	//Creates and outputs the reverse of the input
	reverseInput = (char4 * 1000) + (char3 * 100) + (char2 * 10) + char1;

	cout << "The reverse of the input is: " << reverseInput << endl;

	//Input and store five digot number
	cout << "Enter a five digit number: " << endl;
	cin >> fiveDigitInput;

	//Creates tempVar2 as a placeholder to use while iterating
	tempVar2 = fiveDigitInput;

	//tempVar stores the digit in the place value checked, then it is outputted and tempVar removes that digit through integer divison
	tempVar = fiveDigitInput % 10;
	cout << "Ones: " << tempVar << endl;
	tempVar2 = tempVar2 / 10;

	tempVar = tempVar2 % 10;
	cout << "Tens: " << tempVar << endl;
	tempVar2 = tempVar2 / 10;

	tempVar = tempVar2 % 10;
	cout << "Hundreds: " << tempVar << endl;
	tempVar2 = tempVar2 / 10;

	tempVar = tempVar2 % 10;
	cout << "Thousands: " << tempVar << endl;
	tempVar2 = tempVar2 / 10;

	tempVar = tempVar2 % 10;
	cout << "Ten Thousands: " << tempVar << endl;
	
return 0;
}
