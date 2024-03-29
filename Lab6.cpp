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
	Movie * next;
};

void coutAllMovies(Movie * p);
void printId(string assignment);
string strToUpper(string str);

int main() {
	printId("Lab 6");

	string input = "";

	Movie * first_movie = nullptr;
	int num_of_movies = 0;

	cout << endl; //Next line

	//Infinitely loop the program until user wants to quit
	while (true) {
		//Display menu
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

		//Prompt invalid input if input length is not 1
		if (input.length() != 1) {
			cout << "Invalid input, please try again" << endl << endl;
			continue;
		}

		//Take action based on the input character
		switch (input.at(0))
		{
			case 'A': case 'a': { //Add a movie
				Movie * add_movie = new Movie; //New movie node

				//Get input
				cout << "Enter a movie's name: ";
				getline(cin, add_movie->title);
				
				cout << "Enter the year you saw " << "[like 2016]: ";
				getline(cin, input);
				add_movie->viewed = atoi(input.c_str());

				cout << "Enter your rating for " << "[1, 2, 3, 4, 5]: ";
				getline(cin, input);
				add_movie->rating = atoi(input.c_str());

				add_movie->next = first_movie; //First movie is now the next movie
				first_movie = add_movie; //This node is now the first movie

				num_of_movies++; //Add to the number of movies

				break;
			}
			case 'U': case 'u': { //Update a movie
				//Get input
				cout << "Which movie to update(1-" << num_of_movies << ")? ";
				getline(cin, input);

				int index = atoi(input.c_str()) - 1; //Simulated index of the movie to update

				//If index is in range, find the movie
				if (index >= 0 && index < num_of_movies) {
					Movie * p = first_movie; //The movie to update

					//Move the pointer to the right simulated index
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
			case 'E': case 'e': { //Remove a movie
				//Check to see if there is any movies to delete
				if (num_of_movies < 1) {
					cout << "No movies to delete" << endl;
					break;
				}

				//Get simulated index to remove
				cout << "which movie to remove (1-" << num_of_movies << ")? ";
				getline(cin, input);
				int index = atoi(input.c_str()) - 1;

				Movie * prev_p = nullptr; //The previous movie of the movie to remove
				Movie * p = first_movie; //The movie to remove

				//Check to see if index is in range
				if (index >= 0 && index < num_of_movies) {
					//Move the pointers to the right simulated indexes
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
			case 'L': case 'l': { //Lists out all movies
				coutAllMovies(first_movie);
				break;
			}
			case 'T': case 't': { //Arrange the list by titles
				//Get how the user wants to sort the movies
				cout << "Arrange by lowest value (A) to highest value (Z) string (Enter \'L\') or by highest value (Z) to lowest value (A) (Enter \'H\')? ";
				getline(cin, input);

				//User wants lowest to highest
				if (input.at(0) == 'L' || input.at(0) == 'l') {
					//For all nodes within the linked list
					for (Movie * p = first_movie; p != nullptr; p = p->next)
						//For all nodes after the first_movie in the linked list
						for (Movie * q = p->next; q != nullptr; q = q->next)
							//Swap if p title is a higher rank than q title
							if (strToUpper(p->title).compare(strToUpper(q->title)) > 0) {
								std::swap(*p, *q);
								std::swap(p->next, q->next);
							}
					coutAllMovies(first_movie); //List all movies
				}
				//User wants highest to lowest
				else if (input.at(0) == 'H' || input.at(0) == 'h') {
					//For all nodes within the linked list
					for (Movie * p = first_movie; p != nullptr; p = p->next)
						//For all nodes after the first_movie in the linked list
						for (Movie * q = p->next; q != nullptr; q = q->next)
							//Swap if p title is a lower rank than q title
							if (strToUpper(p->title).compare(strToUpper(q->title)) < 0) {
								std::swap(*p, *q);
								std::swap(p->next, q->next);
							}
					coutAllMovies(first_movie); //List all movies
				}
				else
					cout << "Invalid input" << endl;
				break;
			}
			case 'V': case 'v': { //Arrange the list by viewed
				//Get how the user wants to sort the movies
				cout << "Arrange by newest to oldest (Enter \'N\') or oldest to newest (Enter \'O\')? ";
				getline(cin, input);

				//User wants oldest to newest
				if (input.at(0) == 'O' || input.at(0) == 'o') {
					//For all nodes within the linked list
					for (Movie * p = first_movie; p != nullptr; p = p->next)
						//For all nodes after the first_movie in the linked list
						for (Movie * q = p->next; q != nullptr; q = q->next)
							//Swap if p viewed is newer than q viewed
							if (q->viewed < p->viewed) {
								std::swap(*p, *q);
								std::swap(p->next, q->next);
							}
					coutAllMovies(first_movie); //List all movies
				}
				//User wants newest to oldest
				else if (input.at(0) == 'N' || input.at(0) == 'n') {
					//For all nodes within the linked list
					for (Movie * p = first_movie; p != nullptr; p = p->next)
						//For all nodes after the first_movie in the linked list
						for (Movie * q = p->next; q != nullptr; q = q->next)
							//Swap if p viewed is older than q viewed
							if (q->viewed > p->viewed) {
								std::swap(*p, *q);
								std::swap(p->next, q->next);
							}
					coutAllMovies(first_movie); //List all movies
				}
				else
					cout << "Invalid input" << endl;

				break;
			}
			case 'R': case 'r': { //Arrange the list by rating
				//Get how the user wants to sort the movies
				cout << "Arrange by highest to lowest (Enter \'H\') or lowest to highest (Enter \'L\')? ";
				getline(cin, input);

				//User wants to sort from highest to lowest
				if (input.at(0) == 'H' || input.at(0) == 'h') {
					//For all nodes within the linked list
					for (Movie * p = first_movie; p != nullptr; p = p->next)
						//For all nodes after the first_movie in the linked list
						for (Movie * q = p->next; q != nullptr; q = q->next)
							//Swap if p rating is higher than q rating
							if (q->rating > p->rating) {
								std::swap(*p, *q);
								std::swap(p->next, q->next);
							}
					coutAllMovies(first_movie);
				}
				//User wants to sort from lowest to highest
				else if (input.at(0) == 'L' || input.at(0) == 'l') {
					//For all nodes within the linked list
					for (Movie * p = first_movie; p != nullptr; p = p->next)
						//For all nodes after the first_movie in the linked list
						for (Movie * q = p->next; q != nullptr; q = q->next)
							//Swap if p rating is higher than q rating
							if (q->rating < p->rating) {
								std::swap(*p, *q);
								std::swap(p->next, q->next);
							}
					coutAllMovies(first_movie);
				}
				else
					cout << "Invalid input" << endl;

				break;
			}
			case 'Q': case 'q': { //Quit the program
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

	//Print every node of the list
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
* Purpose: Change the case of the contents of the string to upper if possible
*
* Parameters: string str - The string to convert the case
*
* Return: The new string in upper case
**********************************************************************/
string strToUpper (string str) {
	//Replace every char with upper case if needed
	for (int i = 0; i < str.length(); i++)
		str[i] = toupper(str.at(i));
	
	return str;
}