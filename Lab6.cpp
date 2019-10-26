//Andrew
//Lab 6, Course Objects With Serializations
//Editor Used: Visual Studio Code
//Compiler Used: Visual Studio Developer Command Prompt

#include <iostream>
using std::ios;
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

void coutTableHeader();
void printId(string assignment);

struct Movie {
	string title;
	int viewed;
	int rating;
	Movie* next;
};

int main() {
    printId("Lab 6");

	string input = "";

	Movie * first_movie = NULL;
	int num_of_movies = 0;

	const int NUM_WIDTH = 2;
	const int TITLE_WIDTH = 27;
	const int VIEWED_AND_RATING_WIDTH = 6;

	while (true) {
		cout << "Movie menu:" << endl;
		cout << "A Add a movie" << endl;
		cout << "U Update a movie" << endl;
		cout << "E Remove a movie" << endl;
		cout << "L List all movies" << endl;
		cout << "T arrange by Title" << endl;
		cout << "V arrange by year Viewed" << endl;
		cout << "R arrange by Rating" << endl;
		cout << "Q Quit" << endl;
		getline(cin, input);

		//
		switch (input.at(0))
		{
			case 'A': case 'a': {
				Movie add_movie;
				cout << "Enter a movie's name: ";
				getline(cin, add_movie.title);
				
				cout << "Enter the year you saw " << "[like 2016]: ";
				getline(cin, input);
				add_movie.viewed = atoi(input.c_str());

				cout << "Enter your rating for " << "[1, 2, 3, 4, 5]: ";
				getline(cin, input);
				add_movie.rating = atoi(input.c_str());

				add_movie.next = first_movie;				
				first_movie = &add_movie;
				num_of_movies++;

				break;
			}
			case 'U': case 'u':
				break;
			case 'E': case 'e':
				break;
			case 'L': case 'l': {
				coutTableHeader();

				int movie_count = 0; //

				//
				for (Movie* p = first_movie; p != NULL; p = p->next) {
					cout.width(NUM_WIDTH);
					cout << ++movie_count;
					cout << " ";

					cout.width(TITLE_WIDTH);
					cout << p->title;
					cout << " ";

					cout.width(VIEWED_AND_RATING_WIDTH);
					cout << p->viewed;
					cout << " ";

					cout.width(VIEWED_AND_RATING_WIDTH);
					cout << p->rating;
					cout << " ";

					cout << endl;
				}
				break;
			}
			case 'T': case 't':
				break;
			case 'V': case 'v':
				break;
			case 'R': case 'r':
				break;
			case 'Q': case 'q':
				return 0;
			default:
				cout << "Invalid input, please try again" << endl;
		}
	}
}

void coutTableHeader() {
	cout << "#  Title                         Viewed Rating" << endl;
	cout << "-- ---------------------------   ------ ------" << endl;
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
