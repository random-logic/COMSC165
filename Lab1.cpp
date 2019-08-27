//Andrew
//Lab 1, console programming basics
//Editor Used: Visual Studio Community
//Compiler Used: Visual Studio Compiler

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

float convertTempFToC (float temp_f);
void printId(string assignment);

int main()
{
	printId("Lab 1"); //Print information about ID

	short int age; //Store the user's age
	string name; //Store the user's name
	float temp_f; //Store the user's temp in F
	float temp_c; //Store the user's temp in C
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

	//Convert the input temp from F to C
	temp_c = convertTempFToC(temp_f);

	//Display Results
	cout << name << " is " << age << " years old now, and will be " << age + 2 
		<< " two years from now. It's " << temp_f 
		<< " degrees F in San Ramon -- that's " << temp_c << " degrees C." << endl;

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
	cout << "Andrew" << endl;
	cout << assignment << endl;
	cout << "Editor Used: Visual Studio Community" << endl;
	cout << "Compiler Used: Visual Studio Compiler" << endl;
	cout << "File: " << __FILE__ << endl;
	cout << "Compiled: " << __DATE__ << endl;
}

/**********************************************************************
 * Purpose: Convert the temperature from F to C using math
 * 
 * Parameters: float temp_f - The given temperature in F
 * 
 * Return: Float temperature in C
 *********************************************************************/
float convertTempFToC (float temp_f) {
	return (temp_f - 32) * 5 / 9;
}