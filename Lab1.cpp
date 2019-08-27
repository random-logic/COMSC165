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

void printId(string assignment);

int main()
{
	printId("Lab 1"); //Print information about ID

	short int age; //Store the user's age
	string name; //Store the user's name
	short int temp; //Store the user's temp
	string buf; //Use as buffer for getting inputs

	//Get age input
	cout << "Please input age: ";
	getline(cin, buf);
	age = atoi(buf.c_str());

	//Get name input
	cout << "Please input name: ";
	getline(cin, name);

	//Get temp input
	cout << "Please input temperature: ";
	getline(cin, buf);
	temp = atof(buf.c_str());

	//Display Results
	cout << name << " is " << age << " years old now, and will be " << age + 2 
		<< " two years from now. It's " << temp 
		<< " degrees F in San Ramon." << endl;

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