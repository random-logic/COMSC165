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

struct Course {
    string name;
    int year;
    int units;
    string grade;
};

void printId(string assignment);
int cinAllCourses(Course courses[], int size, int index);
void coutAllCourses(Course courses[], int size, int index);

int main() {
    printId("Lab 4"); ////Print information about ID

    const int SIZE = 100;
    struct Course courses[SIZE];

    int index = 0; //The first unused index of the courses 

    //Get previous data
    ifstream fin; //Create new infile object

    fin.open("Courses.txt"); //Open a specific file

    //Check to see if the file exists
    if (fin.good()) {
        //Read the contents of the file
        while (true) {
            string buf;
            getline(fin, buf);

            //Break if the end of the file is reached
            if (buf == "EOF") {
                break;
            }
            else {
                //Restore Course object
                courses[index].name = buf;
                getline(fin, buf);
                courses[index].year = atoi(buf.c_str());
                getline(fin, buf);
                courses[index].units = atoi(buf.c_str());
                getline(fin, courses[index].grade);
                index++;
            }
        }
    }

    fin.close(); //Done with file

    //Get course inputs
    index = cinAllCourses(courses, SIZE, index);

    //Output all results into file
    ofstream fout; //Create new outfile object

    fout.open("Courses.txt");

    //Get all of the courses that are in the array until the first unused index
    for (int i = 0; i < index; i++) {
        fout << courses[i].name << endl;
        fout << courses[i].year << endl;
        fout << courses[i].units << endl;
        fout << courses[i].grade << endl;
    }

    fout << "EOF" << endl; //Mark end of file

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

/**********************************************************************
* Purpose: 
*
* Parameters: 
*
* Return: The first unused index of the array
**********************************************************************/
int cinAllCourses(Course courses[], int size, int index) {
    //Get course inputs while the index is not past the size
    while (index < size) {
        coutAllCourses(courses, size, index);

        string buf;
        cout << "Enter course #" << index + 1 << " [Q to exit]: ";
        getline(cin, buf);
        
        //Quit if q is pressed
        if (buf == "Q" || buf == "q") {
            break;
        }
        
        //Get input
        courses[index].name = buf;

        cout << "What year for " << courses[index].name << "? ";
        getline(cin, buf);
        courses[index].year = atoi(buf.c_str());

        cout << "How many units is " << courses[index].name << " worth? ";
        getline(cin, buf);
        courses[index].units = atoi(buf.c_str());

        cout << "What is your grade in " << courses[index].name << "? ";
        getline(cin, buf);
        courses[index].grade = buf;

        index++; //Move the next unused index by one
    }

    return index;
}

/**********************************************************************
* Purpose: 
*
* Parameters: 
*
* Return: Nothing
**********************************************************************/
void coutAllCourses(Course courses[], int size, int index) {
    //Set course name to 12 spaces and have it align left
    cout.setf(ios::left);
    cout.width(12);
    cout << "Course Name";
    cout.unsetf(ios::left);

    cout.setf(ios::right); //Set cout to align to the right

    cout << "  "; //Print spacers in table

    //Set year to 4 spaces
    cout.width(4);
    cout << "Year";

    cout << "  "; //Print spacers in table

    //Set units to 5 spaces
    cout.width(5);
    cout << "Units";

    cout << "  "; //Print spacers in table

    //Set grade to 5 spaces
    cout.width(5);
    cout << "Grade";

    cout.unsetf(ios::right); //Unset cout to align to the right

    cout << endl; //Next line

    cout << "------------  ----  -----  -----" << endl; //Seperate header from data

    //Cout all of the data
    for (int i = 0; i < index; i++) {
        //Catch to see if i overflows array size
        if (i >= size) {
            break;
        }

        //Set course name to 12 spaces and have it align left
        cout.setf(ios::left);
        cout.width(12);
        cout << courses[i].name;
        cout.unsetf(ios::left);

        cout.setf(ios::fixed); //Set cout to be fixed

        cout << "  "; //Print spacers in table

        //Set year to 4 spaces
        cout.width(4);
        cout << courses[i].year;

        cout << "  "; //Print spacers in table

        //Set units to 5 spaces
        cout.width(5);
        cout << courses[i].units;

        cout.unsetf(ios::fixed); //Unset cout to be fixed

        cout.setf(ios::right); //Set cout to align to the right

        cout << "  "; //Print spacers in table

        //Set grade to 5 spaces
        cout.width(5);
        cout << courses[i].grade;

        cout.unsetf(ios::right); //Unset cout to align to the right

        cout << endl; //Next line
    }
}