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

	float amount_tendered; //Store the amount of money tendered
	float purchase_amount; //Store the amount of money for the purchase
	string buf; //Use as buffer for getting inputs
	float change_due; //Store the change due from purchase value calculated

	//Get user input
	cout << "Input the purchase amount and amount tendered with a space seperating the two values: ";
	cin >> buf;
	purchase_amount = atof(buf.c_str());
	cin >> buf;
	amount_tendered = atof(buf.c_str());

	//Calculate the total change due
	change_due = amount_tendered - purchase_amount;

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