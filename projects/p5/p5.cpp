#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <algorithm>
using namespace std;

//********************************************************************************
//DECLARATIONS
//********************************************************************************
bool OpenFile(ifstream&);
void CreateAnswerArrays(ifstream&, string*);
int ChoosePuzzle(bool*);
void PlayGame(string*, int, int&, int&);

const int MAX = 20;
const int TOLOSE = 7;
//********************************************************************************
//DRIVER
//********************************************************************************
int main(){
	ifstream answerFile;
	if(!OpenFile(answerFile))
		exit(1);
	string answers[MAX] = {"0"};
	bool isUsed[MAX] = {false};
	int winCount, loseCount = 0;
	int toContinue;
	CreateAnswerArrays(answerFile, answers);
	do{
	int puzzleSelector = ChoosePuzzle(isUsed);
	PlayGame(answers, puzzleSelector, winCount, loseCount);
	cout << "Do you want to continue?" << endl;
	cout << "1 - Yes" << endl;
	cout << "0 - No" << endl;
	cin >> toContinue;
	} while (toContinue == 1);
	return 0;
}

//********************************************************************************
//DEFINITIONS
//********************************************************************************

bool OpenFile(ifstream& answerFile){
	answerFile.open("puzzleoptions.txt");
	if (answerFile.fail()){
		cout << "puzzleoptions.txt is not found" << endl;
		exit(1);
	}
	return true;
}

void CreateAnswerArrays(ifstream& answerFile, string* answers){
	for(int i = 0; getline(answerFile, answers[i]) && i < MAX; ++i);
}
int ChoosePuzzle(bool* usedAr){
	int puzzleSelector;

	while (puzzleSelector = rand() % 20 && usedAr[puzzleSelector] == true);
	usedAr[puzzleSelector] = true;
	return puzzleSelector;
}

void PlayGame(string* answers, int puzzlePosition, int& winCount, int& loseCount){
	char temp;
	string letters = "";
	int correctGuess = 0;
	int correctGuessCount = 0;
	int incorrectGuess = 0;
	string currentGame = answers[puzzlePosition];
	bool correctLetters = false;
	for (int i = 0; i < currentGame.length(); ++i) {
		if (correctLetters == false)
			cout << "_";
		else
			cout << currentGame[i];
	}
	while (incorrectGuess < 8 && correctGuessCount < currentGame.length()){
		cout << endl;
		cout << "Enter guess: " << endl;
		int used = 0;
		do{
			cin >> temp;
			used = letters.find(temp);
			if (used != -1)
				cout << "Already guessed. Try again." << endl;
		}while(used != -1);
		letters += temp;
		used = 0;
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
		if (correctGuess == 0)
			incorrectGuess++;
		else{
			correctGuessCount++;
			correctGuess = 0;
		}
	}
	if (incorrectGuess == 7){
		cout << endl << "Sorry! You lose!" << endl;
		++loseCount;
	}
	else{
		cout << endl << "Congratulations! You Win!" << endl;
		++ winCount;
	}
}
