//Andrew
//Lab 4, 
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

void printId(string assignment);

struct Course {
    string name;
    int year;
    int units;
    /*char*/ string grade;
};

int main() {
    printId("Lab 4"); ////Print information about ID

    const int SIZE = 100;
    Course courses[SIZE];

    int index = 0; //The first unused index of the courses 

    //Get previous data
    ifstream fin; //Create new infile object

    fin.open("Lab4.txt"); //Open a specific file

    if (fin.good()) {
        while (true) {
            string buf;
            getline(fin, buf);
            if (buf == "EOF") {
                break;
            }
            else {
                //Restore Course object
                courses[index].name = buf;
                fin >> courses[index].year;
                fin >> courses[index].units;
                fin >> courses[index].grade;
                index++;
            }
        }
    }

    fin.close(); //Done with file

    //Get course inputs
    while (index < SIZE) {
        string buf;
        cout << "Enter course #" << index + 1 << " [Q to exit]: ";
        getline(cin, buf);
        
        //Quit if q is pressed
        if (buf == "Q" || buf == "q") {
            break;
        }
        
        courses[index].name = buf;

        cout << "What year for " << courses[index].name << "? ";
        getline(cin, buf);
        courses[index].year = atoi(buf.c_str());

        cout << "How many units is " << courses[index].name << " worth? ";
        getline(cin, buf);
        courses[index].units = atoi(buf.c_str());

        cout << "What is your grade in " << courses[index].name << "? ";
        getline(cin, buf);
        courses[index].grade = buf/*.at(0)*/; //Get the first character of the buffer

        index++;
    }

    //Output all results into file
    ofstream fout; //Create new outfile object

    fout.open("Lab4.txt");

    for (int i = 0; i < index; i++) {
        fout << courses[index].name << endl;
        fout << courses[index].year << endl;
        fout << courses[index].units << endl;
        fout << courses[index].grade << endl;

        cout << courses[index].name << endl;
        cout << courses[index].year << endl;
        cout << courses[index].units << endl;
        cout << courses[index].grade << endl;
    }

    fout << "EOF" << endl;

    fout.close(); //Done with file

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