//Andrew
//Lab 3, Student Objects With Serializing Down
//Editor Used: Visual Studio Code
//Compiler Used: Visual Studio Developer Command Prompt

#include <iostream>
using std::ios;
using std::cout;
using std::cin;
using std::endl;

#include <fstream>
using std::ofstream;

#include <string>
using std::string;

struct Student {
    string name;
    string home_address;
    double gpa;
    int year_graduating;
    int birth_year;
};

Student getStudentInputs();
void printId(string assignment);

int main() {
    printId("Lab 3"); //Print information about ID

    const int NUM_OF_STUDENTS = 3; //Size of the array list
    Student students[NUM_OF_STUDENTS]; //The array storing all of the students

    //Get student information for NUM_OF_STUDENTS time
    for (int i = 0; i < NUM_OF_STUDENTS; i++) {
        students[i] = getStudentInputs();
    }

    //Print results into a file
    ofstream fout; //Create new out file object

    //Open a specific file
    fout.open("Lab3_Output.txt");

    //For each student, output all of the details to the file and print it in console app
    for (int i = 0; i < NUM_OF_STUDENTS; i++) {
        //Print details into file
        fout << students[i].name << endl;
        fout << students[i].home_address << endl;
        fout << students[i].gpa << endl;
        fout << students[i].year_graduating << endl;
        fout << students[i].birth_year << endl;

        //Now output into console app
        //Set name and address width to 20 spaces and have it align left
        cout.setf(ios::left);
        cout.width(20);
        cout << students[i].name;
        cout.width(20);
        cout << students[i].home_address;
        cout.unsetf(ios::left);

        //Set gpa to 5 spaces with a precision of 2 fixed
        cout.setf(ios::fixed);
        cout.width(5);
        cout.precision(2);
        cout << students[i].gpa;
        cout.unsetf(ios::fixed);

        //Set years to 5 spaces
        cout.width(5);
        cout << students[i].year_graduating;
        cout.width(5);
        cout << students[i].birth_year;

        //End line
        cout << endl;
    }

    //End of file
    fout << "EOF" << endl;

    //Done with file
    fout.close();

    return 0;
}

/**********************************************************************
 * Purpose: To get input on all student details for a specific student in students
 * 
 * Parameters: None
 * 
 * Returns: A Student type object with all of the details
 *********************************************************************/
Student getStudentInputs() {
    Student student;

    //Create buffers for the inputs
    string gpa_buff;
    string year_graduating_buff;
    string birth_year_buff;

    //Get the input of all details about the student
    cout << "Please input the name of the student: ";
    getline(cin, student.name);
    cout << "Please input where the student lives: ";
    getline(cin, student.home_address);
    cout << "Please enter the age, the year graduating, and the birth year below seperated by spaces:" << endl;
    cin >> gpa_buff;
    cin >> year_graduating_buff;
    cin >> birth_year_buff;
    cin.ignore(256, '\n');

    //Convert string buffers to numbers
    student.gpa = atof(gpa_buff.c_str());
    student.year_graduating = atoi(year_graduating_buff.c_str());
    student.birth_year = atoi(birth_year_buff.c_str());

    return student;
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