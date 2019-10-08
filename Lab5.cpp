//Andrew
//Lab 5, Tracking Expenses with Arrays
//Editor Used: Visual Studio Code
//Compiler Used: Visual Studio Developer Command Prompt

#include <iostream>
using std::ios;
using std::cout;
using std::cin;
using std::endl;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <string>
using std::string;

struct Expense {
	string name;
	float amount;
};

void printId(string assignment);
int getMenuOption();
void cinNewExpense(Expense expenses[], int size);
void coutAllExpenses(Expense expenses[], int size);
void coutOneExpense(Expense expenses[], int size);
void coutAmountExpenses (Expense expenses[], int size);

int main () {
    printId("Lab 5");

	const int SIZE = 100;
	Expense expenses[SIZE];

	//
	while (true) {
		int menu_option = getMenuOption();
		cout << endl; //Next line

		//
		switch(menu_option) {
			case 1:
				cinNewExpense(expenses, SIZE);
				break;
			case 2:
				coutAllExpenses(expenses, SIZE);
				break;
			case 3:
				//
				coutOneExpense(expenses, SIZE);				
				break;
			case 4:
				coutAmountExpenses(expenses, SIZE);
				break;
			default:
				return 0;
		}

		cout << endl; //Next line
	}
}

/**********************************************************************
* Purpose: Print who typed up this program and the assignment name in the console
*	Also print name of file and date into the console
*
* Parameters: string assignment - assignment name
*
* Return: Nothing
**********************************************************************/
void printId(string assignment) {
	cout << "Andrew Jowe" << endl;
	cout << assignment << endl;
	cout << "Editor Used: Visual Studio Code" << endl;
	cout << "Compiler Used: Visual Studio Developer Command Prompt" << endl;
	cout << "File: " << __FILE__ << endl;
	cout << "Compiled: " << __DATE__ << endl;
}

/**********************************************************************
* Purpose: 
*
* Parameters: None
*
* Return: The menu option (int).
**********************************************************************/
int getMenuOption() {
	string buf;

	cout << "Expense Tracking Menu" << endl;
	cout << "1) show all" << endl;
	cout << "2) spend" << endl;
	cout << "3) search expenses containing this string" << endl;
	cout << "4) search expenses with greater than or equal to this amount" << endl;
	cout << "5) exit" << endl;
	getline(cin, buf);

	return atoi(buf.c_str());
}

/**********************************************************************
* Purpose:
*
* Parameters: Expense expenses[] -
*             int size - 
*
* Return: Nothing
**********************************************************************/
void cinNewExpense(Expense expenses[], int size, int max_size) {
	//
	if (size == max_size) {
		cout << "Cannot add more expenses!" << endl;
		return;
	}

	//
	cout << "Please enter the description for the expense: " << endl;
	getline(cin, expenses[size].name);

	float amount = -1; //

	//
	while (amount < 0) {}
}

/**********************************************************************
* Purpose:
*
* Parameters: Expense expenses[] -
*             int size - 
*
* Return: Nothing
**********************************************************************/
void coutAllExpenses (Expense expenses[], int size) {
	//Print out all of the contents of the expenses array
	for (int i = 0; i < size; i++) {
		cout.width(20);
		cout << "AMOUNT(" << expenses[i].amount << ")";
		cout << "DESC(" << expenses[i].name << ")";
	}
}

/**********************************************************************
* Purpose:
*
* Parameters: Expense expenses[] -
*             int size - 
*
* Return: Nothing
**********************************************************************/
void coutOneExpense(Expense expenses[], int size) {
	string target; //

	//
	cout << "Please enter the search string: ";
	getline(cin, target);

	//
	for (int i = 0; i < size; i++) {
		if (expenses[i].name == target) {
			cout.width(20);
			cout << "AMOUNT(" << expenses[i].amount << ")";
			cout << "DESC(" << expenses[i].name << ")";
			return;
		}
	}

	cout << "Not Found" << endl; //
}

/**********************************************************************
* Purpose:
*
* Parameters: Expense expenses[] -
*             int size - 
*
* Return: Nothing
**********************************************************************/
void coutAmountExpenses (Expense expenses[], int size) {
	float target_amount = -1; //

	//
	while (target_amount < 0) {
		string buf;
		cout << "Please enter the amount: ";
		getline(cin, buf);
		target_amount = atof(buf.c_str());
	}

	bool found = false; //

	//
	for (int i = 0; i < size; i++) {
		if (expenses[i].amount >= target_amount) {
			found = true;

			cout.width(20);
			cout << "AMOUNT(" << expenses[i].amount << ")";
			cout << "DESC(" << expenses[i].name << ")";

			break;
		}
	}

	//
	if (!found) {
		cout << "Not Found" << endl;
	}
}