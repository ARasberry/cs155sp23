#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {

	string name;
	string address;
	string city;
	string state;
	string zip;
	int scoopDecider;
	int mulchQuantity;
	double pricePerUnit;
	double totalCost;
	string scoopOrBag;

	cout << "Enter your name: " << endl;
	getline(cin, name);
	cout << "Enter your address: " << endl;
	getline(cin, address);
	cout << "Enter your city: " << endl;
	cin >> city;
	cout << "Enter your state: " << endl;
	cin >> state;
	cout << "Enter your zip: " << endl;
	cin >> zip;
	cout << "Press 0 for scoops, press 1 for bags: ";
	cin >> scoopDecider;

	if (scoopDecider == 0){
		scoopOrBag = "Scoop";
		cout << "How many scoops do you want? " << endl;
		cin >> mulchQuantity;
		if (mulchQuantity < 3){
			pricePerUnit = 40;
			totalCost = pricePerUnit * mulchQuantity;
		}
		else{
			pricePerUnit = 30;
			totalCost = pricePerUnit * mulchQuantity;
		}
	}
	else {
		scoopOrBag = "Bag";
		cout << "How many bags do you want?" << endl;
		cin >> mulchQuantity;
		if (mulchQuantity < 6) {
			pricePerUnit = 7.50;
			totalCost = pricePerUnit * mulchQuantity;
		}
		else {
			pricePerUnit = 5;
			totalCost = pricePerUnit * mulchQuantity;
		}
	}
	
	cout << "\n" << endl;
	cout <<"Tulip Central Garden Center" << endl;
	cout << "One Harrison Plaza" << endl;
	cout << "Florence, AL 35632" << "\n" <<  endl;

	cout << "Name: " << "\t" << "\t" << name << endl;
	cout << "Address: " << "\t" << address << endl;
	cout << "City: " << "\t" << "\t" << city << endl;
	cout << "State: " << "\t" << "\t" << state << endl;
	cout << "Zip: " << "\t" << "\t" << zip << endl;

	cout << setprecision(2) << fixed;
	cout << "Quantity" << setw(15) << "Type" << setw(29) << "Price Per Unit" << setw(25) << "Total Cost" << endl;
	cout << mulchQuantity << setw(22) << scoopOrBag << setw(21) << "$" << pricePerUnit << setw(25) << "$" << totalCost << endl;


return 0;
}
