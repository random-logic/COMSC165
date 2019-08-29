//Andrew
//Lab 1, console programming basics
//Editor Used: Visual Studio Code
//Compiler Used: Visual Studio Developer Command Prompt

#include <iostream>
using std::ios;
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

double convertTempFToC (double temp_f);
void printId(string assignment);

int main()
{
	printId("Lab 1"); //Print information about ID

	short int age; //Store the user's age
	string name; //Store the user's name
	double temp_f; //Store the user's temp in F
	double temp_c; //Store the user's temp in C
	string city; //Store the user's city
	string buf; //Use as buffer for getting inputs

	//Get age input
	cout << "Please input age: ";
	getline(cin, buf);
	age = atoi(buf.c_str());

	//Get name input
	cout << "Please input name: ";
	getline(cin, name);

	//Get temp input
	cout << "Please input temperature (degrees F): ";
	getline(cin, buf);
	temp_f = atof(buf.c_str());

	//Get city input
	cout << "What city are you in right now? ";
	getline(cin, city);

	//Convert the input temp from F to C
	temp_c = convertTempFToC(temp_f);

	//Display Name and Age
	cout << name << " is " << age << " years old now, and will be " << age + 2 
		<< " two years from now." << endl;

	//Format numbers to be rounded to the nearest tenth
	cout.precision(1);
	cout.setf(ios::fixed);

	//Display Temp
	cout << "It's " << temp_f << " degrees F in " << city << " -- that's " 
		<< temp_c << " degrees C." << endl;

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

/**********************************************************************
 * Purpose: Convert the temperature from F to C using math
 * 
 * Parameters: double temp_f - The given temperature in F
 * 
 * Return: double temperature in C
 *********************************************************************/
double convertTempFToC (double temp_f) {
	return (temp_f - 32) * 5 / 9;
}