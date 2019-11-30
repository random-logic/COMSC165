//Andrew
//Lab 8, Artificial Intelligence With Innate Knowledge
//Editor Used: Visual Studio Code
//Compiler Used: Visual Studio Developer Command Prompt
#include <iostream>
using std::ios;
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

#include <fstream>
using std::ofstream;

struct Diagnose {
	string message;
	Diagnose * y;
	Diagnose * n;
};

void printId(string assignment);
void serializeTree(Diagnose * p, ofstream & fout);

int main() {
  printId("Lab 8");

	Diagnose * a = new Diagnose {"The answer is a", 0, 0};
	Diagnose * b = new Diagnose {"The answer is b", 0, 0};
	Diagnose * c = new Diagnose {"The answer is c", 0, 0};
	Diagnose * d = new Diagnose {"The answer is d", 0, 0};
	Diagnose * ab = new Diagnose {"Is the answer to the test question a (y/n)? ", a, b};
	Diagnose * cd = new Diagnose {"Is the answer to the test question c (y/n)? ", c, d};
	Diagnose * ab_cd = new Diagnose {"Is the answer to the test question a or b (y/n)? ", ab, cd};

	Diagnose * p = ab_cd;
	while (true) {
		cout << p->message;

		if (p->y == 0 || p->n == 0)
			break;
		
		string input;
		getline(cin, input);

		if (input.at(0) == 'Y' || input.at(0) == 'y')
			p = p->y;
		else if (input.at(0) == 'N' || input.at(0) == 'n')
			p = p->n;
	}

	ofstream fout;
	fout.open("ai.txt");
	serializeTree(ab_cd, fout);
	fout.close();

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

/**
 * Purpose: Serialize out the Diagnose tree
 * Parameters: Diagnose * p - The head of the Diagnose tree
 *             ofstream fout - The file to write to (assuming already opened previously)
 * Returns: Nothing
 */
void serializeTree(Diagnose * p, ofstream & fout) {
	fout << p->message << endl;
	if (p->y != 0)
		serializeTree(p->y, fout);
	if (p->n != 0)
		serializeTree(p->n, fout);
}