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

struct Movie {
	string title;
	int viewed;
	int rating;
	Movie* next;
};

void swapMovies(Movie * p, Movie * q);
void coutAllMovies(Movie * p);
void printId(string assignment);

int main() {
	printId("Lab 6");

	string input = "";

	Movie * first_movie = nullptr;
	int num_of_movies = 0;

	cout << endl; //Next line

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
				Movie * add_movie = new Movie;
				cout << "Enter a movie's name: ";
				getline(cin, add_movie->title);
				
				cout << "Enter the year you saw " << "[like 2016]: ";
				getline(cin, input);
				add_movie->viewed = atoi(input.c_str());

				cout << "Enter your rating for " << "[1, 2, 3, 4, 5]: ";
				getline(cin, input);
				add_movie->rating = atoi(input.c_str());

				add_movie->next = first_movie;
				first_movie = add_movie;

				num_of_movies++;

				break;
			}
			case 'U': case 'u': {
				cout << "Which movie to update(1-" << num_of_movies << ")? ";
				getline(cin, input);
				int index = atoi(input.c_str()) - 1;

				//
				if (index >= 0 && index < num_of_movies) {
					Movie * p = first_movie; //The movie to update

					//
					for (int i = 0; i < index; i++)
						p = p->next;

					//Update the movie at p
					cout << "The current title for movie " << index + 1 << " is " << p->title << endl;
					cout << "What is the new title for this movie? ";
					getline(cin, p->title);

					cout << "The current year viewed for movie " << index + 1 << " is " << p->viewed << endl;
					cout << "What is the new year viewed for this movie? ";
					getline(cin, input);
					p->viewed = atoi(input.c_str());

					cout << "The current rating for movie " << index + 1 << " is " << p->rating << endl;
					cout << "What is the new rating for this movie? ";
					getline(cin, input);
					p->rating = atoi(input.c_str());
				}
				else
					cout << "Invalid index" << endl;
				
				break;
			}
			case 'E': case 'e': {
				if (num_of_movies < 1) {
					cout << "No movies to delete" << endl;
					break;
				}

				//Get index to remove
				cout << "which movie to remove (1-" << num_of_movies << ")? ";
				getline(cin, input);
				int index = atoi(input.c_str()) - 1;

				Movie * prev_p = nullptr; //The previous movie of the movie to remove
				Movie * p = first_movie; //The movie to remove

				//
				if (index >= 0 && index < num_of_movies) {
					//
					for (int i = 0; i < index; i++) {
						prev_p = p;
						p = p->next;
					}
					
					//Link next movie of p to first movie
					if (prev_p == nullptr)
						first_movie = p->next;
					//Link next movie of p to next movie of previous movie
					else
						prev_p->next = p->next;
					
					//Remove the movie at p
					delete p;
					num_of_movies--;
					cout << "Removed movie at index " << index + 1<< endl;
				}
				else
					cout << "Invalid index" << endl;

				break;
			}
			case 'L': case 'l': {
				coutAllMovies(first_movie);
				break;
			}
			case 'T': case 't': {
				//CASE INSENSITIVE
				//Get how the user wants to sort the movies
				cout << "Arrange by lowest value (A) to highest value (Z) string (Enter \'L\') or oldest to newest (Enter \'O\')? ";
				getline(cin, input);

				//
				if (input.at(0) == 'O' || input.at(0) == 'o') {
					for (Movie * p = first_movie; p != nullptr; p = p->next)
						for (Movie * q = p->next; q != nullptr; q = q->next) //CONTINUE
					coutAllMovies(first_movie);
				}
				else if (input.at(0) == 'N' || input.at(0) == 'n') {
					for (Movie * p = first_movie; p != nullptr; p = p->next)
						for (Movie * q = p->next; q != nullptr; q = q->next) //CONTINUE
					coutAllMovies(first_movie);
				}
				else
					cout << "Invalid input" << endl;
				break;
			}
			case 'V': case 'v': {
				//Get how the user wants to sort the movies
				cout << "Arrange by newest to oldest (Enter \'N\') or oldest to newest (Enter \'O\')? ";
				getline(cin, input);

				//
				if (input.at(0) == 'O' || input.at(0) == 'o') {
					for (Movie * p = first_movie; p != nullptr; p = p->next)
						for (Movie * q = p->next; q != nullptr; q = q->next)
							if (q->viewed > p->viewed)
								swapMovies(p, q);
					coutAllMovies(first_movie);
				}
				else if (input.at(0) == 'N' || input.at(0) == 'n') {
					for (Movie * p = first_movie; p != nullptr; p = p->next)
						for (Movie * q = p->next; q != nullptr; q = q->next)
							if (q->viewed < p->viewed)
								swapMovies(p, q);
					coutAllMovies(first_movie);
				}
				else
					cout << "Invalid input" << endl;

				break;
			}
			case 'R': case 'r': {
				//Get how the user wants to sort the movies
				cout << "Arrange by highest to lowest (Enter \'H\') or lowest to highest (Enter \'L\')? ";
				getline(cin, input);

				//
				if (input.at(0) == 'H' || input.at(0) == 'h') {
					for (Movie * p = first_movie; p != nullptr; p = p->next)
						for (Movie * q = p->next; q != nullptr; q = q->next)
							if (q->rating > p->rating)
								swapMovies(p, q);
					coutAllMovies(first_movie);
				}
				else if (input.at(0) == 'L' || input.at(0) == 'l') {
					for (Movie * p = first_movie; p != nullptr; p = p->next)
						for (Movie * q = p->next; q != nullptr; q = q->next)
							if (q->rating < p->rating)
								swapMovies(p, q);
					coutAllMovies(first_movie);
				}
				else
					cout << "Invalid input" << endl;

				break;
			}
			case 'Q': case 'q': {
				//Delete the whole movie list
				while (first_movie != nullptr) {
					Movie * p = first_movie;
					first_movie = first_movie->next;
					delete p;
				}
				cout << endl << "Program Finished!" << endl;
				return 0;
			}
			default:
				cout << "Invalid input, please try again" << endl;
		}

		cout << endl; //Print empty line
	}
}

/**********************************************************************
* Purpose: Print out all of the movies in a nicely formatted table
*
* Parameters: Movie * p - The pointer to the first movie
*
* Return: Nothing
**********************************************************************/
void coutAllMovies(Movie * p) {
	const int NUM_WIDTH = 2; //The width of the number column
	const int TITLE_WIDTH = 27; //The width of the title column
	const int VIEWED_AND_RATING_WIDTH = 6; //The width of the viewed and rating column

	cout << "#  Title                         Viewed Rating" << endl;
	cout << "-- ---------------------------   ------ ------" << endl;

	int movie_count = 0; //The count of the movie

	for (p; p != nullptr; p = p->next) {
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
* Purpose: Swap the movies within the linked list
*
* Parameters: Movie * p - The first movie to swap
*             Movie * q - The second movie to swap
*
* Return: Nothing
**********************************************************************/
void swapMovies (Movie * p, Movie * q) {
	Movie * temp;
	temp = p;
	p = q;
	q = temp;
	temp = p->next;
	p->next = q->next;
	q->next = temp;
}