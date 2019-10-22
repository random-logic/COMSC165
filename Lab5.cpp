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

#include <cctype>

struct Expense {
	string name;
	float amount;
};

void printId(string assignment);
int getMenuOption();
int cinNewExpense(Expense expenses[], int size, int max_size);
void coutAllExpenses(Expense expenses[], int size);
void coutExpensesByString(Expense expenses[], int size);
void coutExpensesByAmount (Expense expenses[], int size);

int main () {
    printId("Lab 5");

	const int SIZE = 100;
	Expense expenses[SIZE];

	int index = 0; //Next available index in the array

	//
	while (true) {
		int menu_option = getMenuOption();
		cout << endl; //Next line

		//
		switch(menu_option) {
			case 1:
				//coutAllExpenses(expenses, index);
				//Print out all of the contents of the expenses array
				for (int i = 0; i < index; i++) {
					cout << "AMOUNT(" << expenses[i].amount << ")   ";
					cout << "DESC(" << expenses[i].name << ")" << endl;
				}
				break;
			case 2:
				index = cinNewExpense(expenses, index, SIZE);
				break;
			case 3:
				//
				coutExpensesByString(expenses, index);
				break;
			case 4:
				coutExpensesByAmount(expenses, index);
				break;
			default:
				return 0;
		}

		cout << endl; //End line
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
* Purpose: Output menu and get user selection for what to do
*
* Parameters: None
*
* Return: The menu option (int)
**********************************************************************/
int getMenuOption() {
	string buf; //String buffer

	//Output and get input
	cout << "Expense Tracking Menu" << endl;
	cout << "1) show all" << endl;
	cout << "2) spend" << endl;
	cout << "3) search expenses containing this string" << endl;
	cout << "4) search expenses with greater than or equal to this amount" << endl;
	cout << "5) exit" << endl;
	getline(cin, buf);

	return atoi(buf.c_str()); //Convert string to int and return
}

/**********************************************************************
* Purpose:
*
* Parameters: Expense expenses[] - The expenses array to add an expense to
*             int index - The index to add the next expense to
*             int max_size - The max size of the array
*
* Return: The new size of the array (the next available index after input)
**********************************************************************/
int cinNewExpense(Expense expenses[], int index, int max_size) {
	//Do not add more expenses if the array is full
	if (index == max_size) {
		cout << "Cannot add more expenses!" << endl;
		return index;
	}

	//Get user input
	cout << "Please enter the description for the expense: ";
	getline(cin, expenses[index].name);

	string buf; //String buffer

	//Get more user input
	cout << "Please enter the amount of the expense: ";
	getline(cin, buf);

	//Convert string to float
	expenses[index].amount = atof(buf.c_str());

	return ++index;
}

/**********************************************************************
* Purpose: Output all of the expenses
*
* Parameters: Expense expenses[] - The array where all of the expenses is stored
*             int size - The size of the array
*
* Return: Nothing
**********************************************************************/
void coutAllExpenses (Expense expenses[], int size) {
	if (size == 0) {
		cout << "No Expenses yet" << endl;
		return;
	}

	//Print out all of the contents of the expenses array
	for (int i = 0; i < size; i++) {
		cout << "AMOUNT(" << expenses[i].amount << ")   ";
		cout << "DESC(" << expenses[i].name << ")" << endl;
	}
}

/**********************************************************************
* Purpose: Output the expenses if they contain a part of a certain string
*
* Parameters: Expense expenses[] - The array where all of the expenses is stored
*             int size - The size of the array
*
* Return: Nothing
**********************************************************************/
void coutExpensesByString(Expense expenses[], int size) {
	string target; //The target string to find in the expenses

	//Get user input
	cout << "Please enter the search string: ";
	getline(cin, target);

	bool found = false; //See if any targets have been found

	//For all of the expenses, see if there is a match
	for (int i = 0; i < size; i++) {
		int target_pos = 0; //The position of the letter in the target string to be compared to

		//For each character, see if there is any match within the string
		for (int j = 0; j < expenses[i].name.size(); j++) {
			//Do if the target position char != expense position char
			if (tolower(expenses[i].name.at(j)) != tolower(target.at(target_pos))) {
				target_pos = 0;
			}
			//Do if target position has already covered the whole target string
			else if (target_pos == target.size() - 1){
				cout << "AMOUNT(" << expenses[i].amount << ")   ";
				cout << "DESC(" << expenses[i].name << ")" << endl;
				found = true;

				break;
			}
			//Do if target position has not covered the whole target string yet
			else {
				target_pos++;
			}
		}
	}

	if (!found)
		cout << "Not Found" << endl;
}

/**********************************************************************
* Purpose: Output the expenses if they are >= a specified amount
*
* Parameters: Expense expenses[] - The array where all of the expenses is stored
*             int size - The size of the array
*
* Return: Nothing
**********************************************************************/
void coutExpensesByAmount (Expense expenses[], int size) {
	float target_amount; //Target amount to find in the Expenses array

	string buf; //String buffer

	//Get user input
	cout << "Please enter the amount (): ";
	getline(cin, buf);

	bool found = false; //See if any targets have been found

	//Convert string to float
	target_amount = atof(buf.c_str());

	//For every expense, see if it is greater than the specified amount
	for (int i = 0; i < size; i++) {
		if (expenses[i].amount >= target_amount) {
			cout << "AMOUNT(" << expenses[i].amount << ")   ";
			cout << "DESC(" << expenses[i].name << ")" << endl;
			found = true;
		}
	}

	if (!found)
		cout << "Not Found" << endl;
}