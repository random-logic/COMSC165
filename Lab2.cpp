//Andrew
//Lab 2, Making Exact Change
//Editor Used: Visual Studio Code
//Compiler Used: Visual Studio Developer Command Prompt

#include <iostream>
using std::ios;
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

void printId(string assignment);

int main() 
{
    printId("Lab 2"); //Print information about ID

	double amount_tendered; //Store the change_due of money tendered
	double purchase_amount; //Store the change_due of money for the purchase
	string buf; //Use as buffer for getting inputs
	double change_due; //Store the change due from purchase value calculated

    int bills_100 = 0; //Stores the change_due of each bill
	int bills_50 = 0;
	int bills_20 = 0;
	int bills_10 = 0;
	int bills_5 = 0;
	int bills_1 = 0;
    int coins_50 = 0;
	int coins_25 = 0;
	int coins_10 = 0;
	int coins_5 = 0;
	int coins_1 = 0;

	//Get user input
	cout << "Input the purchase amount and amount tendered with a space seperating the two values: ";
	cin >> buf;
	purchase_amount = atof(buf.c_str());
	cin >> buf;
	amount_tendered = atof(buf.c_str());

	//Calculate the total change due
	change_due = amount_tendered - purchase_amount;

	//Format numbers to be rounded to the nearest penny for this one statement
	cout.precision(2);
	cout.setf(ios::fixed);
	cout << "The change due is $" << change_due << endl;
	cout.unsetf (ios::floatfield);
	cout.unsetf(ios::fixed);

    //Give the exact change
	while (change_due > 99.999999999) {
		change_due -= 100;
		bills_100 += 1;
	}

	while (change_due > 49.999999999) {
		change_due -= 50;
		bills_50 += 1;
	}

	while (change_due > 19.999999999) {
		change_due -= 20;
		bills_20 += 1;
	}

	while (change_due > 9.999999999) {
		change_due -= 10;
		bills_10 += 1;
	}

	while (change_due > 4.999999999) {
		change_due -= 5;
		bills_5 += 1;
	}

	while (change_due > 0.999999999) {
		change_due -= 1;
		bills_1 += 1;
	}

    while (change_due > 0.499999999) {
		change_due -= 0.50;
		coins_50 += 1;
	}

	while (change_due > 0.249999999) {
		change_due -= 0.25;
		coins_25 += 1;
	}

	while (change_due > 0.099999999) {
		change_due -= 0.10;
		coins_10 += 1;
	}

	while (change_due > 0.049999999) {
		change_due -= 0.5;
		coins_5 += 1;
	}

	while (change_due > 0.009999999) {
		change_due -= 0.01;
		coins_1 += 1;
	}

	//Output the results for the user
	cout << "Here is the exact change the clerk should give back to the customer" << endl;
	cout << bills_100 << " $100 bills" << endl;
	cout << bills_50 << " $50 bills" << endl;
	cout << bills_20 << " $20 bills" << endl;
	cout << bills_10 << " $10 bills" << endl;
	cout << bills_5 << " $5 bills" << endl;
	cout << bills_1 << " $1 bills" << endl;
    cout << coins_50 << " $0.50 coins" << endl;
	cout << coins_25 << " $0.25 coins" << endl;
	cout << coins_10 << " $0.10 coins" << endl;
	cout << coins_5 << " $0.05 coins" << endl;
	cout << coins_1 << " $0.01 coins" << endl;

    return 0;
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