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