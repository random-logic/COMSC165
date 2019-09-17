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
double getBillsToReturn(double amount, string billType, double billTypeValue, double threshold);

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
	cout << "Here is the exact change the clerk should give back to the customer" << endl;
	amount = getBillsToReturn(amount, "$100 bills", 100, 99.999999999);
	amount = getBillsToReturn(amount, "$50 bills", 50, 49.999999999);
	amount = getBillsToReturn(amount, "$20 bills", 20, 19.999999999);
	amount = getBillsToReturn(amount, "$10 bills", 10, 9.999999999);
	amount = getBillsToReturn(amount, "$5 bills", 5, 4.999999999);
	amount = getBillsToReturn(amount, "$1 bills", 1, 0.999999999);
	amount = getBillsToReturn(amount, "$0.50 coins", 0.50, 0.499999999);
	amount = getBillsToReturn(amount, "$0.25 coins", 0.25, 0.249999999);
	amount = getBillsToReturn(amount, "$0.10 coins", 0.10, 0.099999999);
	amount = getBillsToReturn(amount, "$0.05 coins", 0.05, 0.049999999);
	amount = getBillsToReturn(amount, "$0.01 coins", 0.01, 0.009999999);
}

/**********************************************************************
* Purpose: To calculate and output the amount of specific bills (or coins) to give back for a specific amount of money
* Parameters: double amount - the amount of money the clerk has to give back to the customer
*             string billType - the type of bill (or coin) needed to give
*             double billTypeValue - the value of the bill (or coin) needed to give
*             double threshold - while the amount of money is greater than this value, more bills (or coins) is given
* Return: double - the amount of money remaining that has not been given back in billType bills (or coins)
**********************************************************************/
double getBillsToReturn(double amount, string billType, double billTypeValue, double threshold) {
	//Give the exact change
	int bills_to_give_back = 0; //Stores the amount of bills (or coins) given back
	while (amount > threshold) {
		amount -= billTypeValue;
		bills_to_give_back += 1;
	}
	
	//Output the results for the user
	cout << bills_to_give_back << " " << billType << endl;

	return amount;
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