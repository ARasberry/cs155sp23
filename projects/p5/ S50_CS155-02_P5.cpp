//Author: S50
//Project 5
//Date: 04-25-23
//Plays hangman


#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <algorithm>
#include <cstdlib>
using namespace std;

//********************************************************************************
//DECLARATIONS
//********************************************************************************
bool OpenFile(ifstream&); //Opens the puzzleoptions.txt file 
void CreateAnswerArrays(ifstream&, string*, int&); //Reads the file into the answer array
int ChoosePuzzle(bool*); //Chooses an unused puzzle
void PrintWelcome(); //Prints a welcome
void PlayGame(string*, int, int&, int&); //Plays the hangman game
void PrintWins(int&, int&); //Prints out the wins and losses
void PrintUsed(string*, bool*, int); //Prints a list of unused and used puzzles

const int MAX = 20; //Max storage for index
const int TOLOSE = 7; //How many misses to lose. I did this here so that if I wanted to make it harder or easier I could in one line
//********************************************************************************
//DRIVER
//********************************************************************************
int main(){
	//Opens files
	ifstream answerFile;
	if(!OpenFile(answerFile))
		exit(1);
	
	//Initializes the two arrays	
	string answers[MAX] = {"0"};
	bool isUsed[MAX] = {false};
	
	//Initializes variables
	int winCount = 0; 
	int loseCount = 0;
	int toContinue;
	int size; //Size of array

	//Seeds the randomizer
	srand(time(NULL));
	
	//Two beginning functions
	CreateAnswerArrays(answerFile, answers, size);
	PrintWelcome();
	
	//Primary game loop: selecting a puzzle playing the game and then deciding to or not to continue
	do{
	int puzzleSelector = ChoosePuzzle(isUsed);
	PlayGame(answers, puzzleSelector, winCount, loseCount);
	cout << "Do you want to continue?" << endl;
	cout << "1 - Yes" << endl;
	cout << "0 - No" << endl;
	cin >> toContinue;
	} while (toContinue == 1);

	//Print the wins
	PrintWins(winCount, loseCount);
	
	//Controls whether or not to see the used and unused puzzles
	int seeUnused;
	cout << "Enter 1 to see all used and unused puzzles. Otherwise enter 0" << endl;
	cin >> seeUnused;
	if (seeUnused == 1)
		PrintUsed(answers, isUsed, size);
	
	return 0;
}

//********************************************************************************
//DEFINITIONS
//********************************************************************************

bool OpenFile(ifstream& answerFile){
	//Opens the file
	answerFile.open("puzzleoptions.txt");
	if (answerFile.fail()){
		cout << "puzzleoptions.txt is not found" << endl;
		exit(1);
	}
	return true;
}

void CreateAnswerArrays(ifstream& answerFile, string* answers, int& size){
	//Reads the file into the answer array
	for(int size = 0; getline(answerFile, answers[size]) && size < MAX; ++size);
}
int ChoosePuzzle(bool* usedAr){
	//The index for the arrays
	int puzzleSelector;

	//Uses random in order to select a puzzle
	while (puzzleSelector = rand() % 20 && usedAr[puzzleSelector] == true);
	usedAr[puzzleSelector] = true;
	return puzzleSelector;
}
void PrintWelcome(){
	//Prints a welcome
	cout << "**************************************" << endl;
	cout << "* Welcome! Press any key to contine. *" << endl;
	cout << "**************************************" << endl;
	system("pause");
}

void PlayGame(string* answers, int puzzlePosition, int& winCount, int& loseCount){
	//Initializes variables
	char temp; //The user guess
	string letters = ""; 
	int correctGuess = 0; 
	int correctGuessCount = 0;
	int incorrectGuess = 0;
	string currentGame = answers[puzzlePosition]; //Easier way of using whatever the current puzzle is
	bool correctLetters = false; //Used to print blanks in the game

	//Prints a blank game
	for (int i = 0; i < currentGame.length(); ++i) {
		if (correctLetters == false)
			cout << "_";
		else
			cout << currentGame[i];
	}

	//While loop that actually runs the game
	while (incorrectGuess < TOLOSE && correctGuessCount < currentGame.length()){ //loop ends if all the correct letters have been entered or if too many incorrect guesses have been entered
		cout << endl;
		cout << "Enter guess: " << endl;
		int used = 0;
		do{
			cin >> temp;
			//Makes sure that the guess has not already been used
			used = letters.find(temp);
			if (used != -1) 
				cout << "Already guessed. Try again." << endl;
		}while(used != -1);
		letters += temp; 
		used = 0;
		//Prints blanks and checks if guess is correct or not
		for(int i = 0; i < currentGame.length(); ++i){
			if (currentGame[i] == temp){
				cout << temp;
				correctGuess++;
			}
			else if(letters.find(currentGame[i]) != -1)
				cout << currentGame[i];
			else
				cout << "_"; 
			}
		//Counts incorrect or correct guesses up and resets the correctGuess counter
		if (correctGuess == 0)
			incorrectGuess++;
		else{
			correctGuessCount++;
			correctGuess = 0;
		}

		//Prints the lives counter: X is used O is avaliable
		cout << "Lives: " << endl;
		for(int i = 0; i < TOLOSE; ++i){
			if (i < incorrectGuess)
				cout << "X";
			else
				cout << "O";
		}
	}
	//Iterates win and lose counts 
	if (incorrectGuess == TOLOSE){
		cout << endl << "Sorry! You lose!" << endl;
		++loseCount;
	}
	else{
		cout << endl << "Congratulations! You Win!" << endl;
		++ winCount;
	}
	cout << endl;
}

void PrintWins(int& winCount, int& loseCount){
	//Prints The wins and losses
	cout << "**********************************" << endl;
	cout << "* 	Wins 	* 	Losses	 *" << endl;
	cout << "**********************************" << endl;
	cout << "*	" << winCount << "	*  	" << loseCount << "	 *" << endl; 
	cout << "**********************************" << endl;
}

void PrintUsed(string* answers, bool* isUsed, int size){
	//Prints unused puzzles
	for (int i = 0; i < size; ++i){
		cout << "Unused puzzles" << endl;
		if (isUsed[i] == 0)
			cout << answers[i] << endl;
	}
	//Prints used puzzles
	for (int i = 0; i < size; ++i){
		cout << "Used puzzles" << endl;
		if (isUsed[i] == 1)
			cout << answers[i] << endl;
	}
}
