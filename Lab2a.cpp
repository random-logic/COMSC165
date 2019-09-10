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

double calculateChange(double purchased, double tendered);
void getExactChange(double amount);
void printId(string assignment);

int main() 
{
    printId("Lab 2"); //Print information about ID

	double amount_tendered; //Store the amount of money tendered
	double purchase_amount; //Store the amount of money for the purchase
	string buf; //Use as buffer for getting inputs

	//Get user input
	cout << "Input the purchase amount and amount tendered with a space seperating the two values: ";
	cin >> buf;
	purchase_amount = atof(buf.c_str());
	cin >> buf;
	amount_tendered = atof(buf.c_str());

	getExactChange(calculateChange(purchase_amount, amount_tendered));

    return 0;
}

/**********************************************************************
* Purpose: Find and output the amount of exact change due
*
* Parameters: purchased - the amount of money the customer spent on merchandise
*             tendered - the amount of money the customer gives to the clerk
*
* Return: change_due - how much money the clerk has to give back to the customer
**********************************************************************/
double calculateChange(double purchased, double tendered) {
    double change_due; //Store the change due from purchase value calculated

    //Calculate the total change due
	change_due = tendered - purchased;

	//Format numbers to be rounded to the nearest penny for this one statement
	cout.precision(2);
	cout.setf(ios::fixed);
	cout << "The change due is $" << change_due << endl;
	cout.unsetf (ios::floatfield);
	cout.unsetf(ios::fixed);

    return change_due;
}

/**********************************************************************
* Purpose: Output the exact number of bills and coins the clerk has to give to the customer
*
* Parameters: change_due - how much money the clerk has to give back to the customer
*
* Return: Nothing
**********************************************************************/
void getExactChange(double amount) {
    int bills_100 = 0; //Stores the amount of each bill
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

    //Give the exact change
	while (amount > 99.999999999) {
		amount -= 100;
		bills_100 += 1;
	}

	while (amount > 49.999999999) {
		amount -= 50;
		bills_50 += 1;
	}

	while (amount > 19.999999999) {
		amount -= 20;
		bills_20 += 1;
	}

	while (amount > 9.999999999) {
		amount -= 10;
		bills_10 += 1;
	}

	while (amount > 4.999999999) {
		amount -= 5;
		bills_5 += 1;
	}

	while (amount > 0.999999999) {
		amount -= 1;
		bills_1 += 1;
	}

    while (amount > 0.499999999) {
		amount -= 0.50;
		coins_50 += 1;
	}

	while (amount > 0.249999999) {
		amount -= 0.25;
		coins_25 += 1;
	}

	while (amount > 0.099999999) {
		amount -= 0.10;
		coins_10 += 1;
	}

	while (amount > 0.049999999) {
		amount -= 0.5;
		coins_5 += 1;
	}

	while (amount > 0.009999999) {
		amount -= 0.01;
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