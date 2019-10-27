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

				cout << first_movie->title;
				num_of_movies++;

				break;
			}
			case 'U': case 'u': {
				cout << "Which movie to update(1-" << num_of_movies << ")? ";
				getline(cin, input);
				int index = atoi(input.c_str()) - 1;

				Movie * p = first_movie; //The movie to update

				//
				if (index >= 0 && index < num_of_movies) {
					//
					for (int i = 0; i < index; i++) {
						p = p->next;
					}

					//Update the movie at p
					cout << "The current title for movie " << index + 1 << " is " << p->title;
					cout << "What is the new title for this movie? ";
					getline(cin, p->title);

					cout << "The current year viewed for movie " << index + 1 << " is " << p->viewed;
					cout << "What is the new year viewed for this movie? ";
					getline(cin, input);
					p->viewed = atoi(input.c_str());

					cout << "The current rating for movie " << index + 1 << " is " << p->rating;
					cout << "What is the new rating for this movie? ";
					getline(cin, input);
					p->rating = atoi(input.c_str());
				}
				else
					cout << "Invalid index" << endl;
				
				break;
			}
			case 'E': case 'e': {
				//Get index to remove
				cout << "which movie to remove (1-" << num_of_movies << ")? ";
				getline(cin, input);
				int index = atoi(input.c_str()) - 1;

				Movie * prev_p; //The previous movie of the movie to remove
				Movie * p = first_movie; //The movie to remove

				//
				if (index >= 0 && index < num_of_movies) {
					//
					for (int i = 0; i < index; i++) {
						prev_p = p;
						p = p->next;
					}

					//Remove the movie at p
					prev_p->next = p->next;
					delete p;
					num_of_movies--;
					cout << "Removed movie at index " << index << endl;
				}
				else
					cout << "Invalid index" << endl;

				break;
			}
			case 'L': case 'l': {
				coutTableHeader();

				int movie_count = 0; //
				Movie * p = first_movie; //Pointer to the movie to print out
				cout << first_movie->title << endl;
				
				//
				for (int i = 0; i < num_of_movies; i++) {
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

					p = p->next;
				}
				break;
			}
			case 'T': case 't': {
				break;
			}
			case 'V': case 'v': {
				//Get how the user wants to sort the movies
				cout << "Arrange by newest to oldest (Enter N) or oldest to newest (Enter O)? ";
				getline(cin, input);

				bool swapped = true; //Find out whether the lists has swapped or not

				//
				/*if (input.at(0) == 'O' || input.at(0) == 'o') {
					//
					while (swapped) {
						swapped = false;

						Movie * p = first_movie;
						Movie * prev_p;

						//
						for (int i = 0; i < num_of_movies; i++) {
							if (p->viewed > p->next->viewed) {
								swapped = true;

								Movie * temp = p;
								p->next = p;
							}

							p = p->next;
							prev_p = p;
						}
					}
				}
				else if (input.at(0) == 'N' || input.at(0) == 'n') {

				}
				else
					cout << "Invalid input" << endl;*/

				break;
			}
			case 'R': case 'r': {
				break;
			}
			case 'Q': case 'q': {
				//Delete the whole movie list
				for (int i = 0; i < num_of_movies; i++) {
					Movie * p = first_movie;
					first_movie = first_movie->next;
					delete p;
				}
				
				return 0;
			}
			default:
				cout << "Invalid input, please try again" << endl;
		}

		cout << endl; //Print empty line
	}
}

/**********************************************************************
* Purpose: Print out the header of the movie table
*
* Parameters: None
*
* Return: Nothing
**********************************************************************/
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
