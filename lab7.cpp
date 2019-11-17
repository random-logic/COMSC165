//Andrew
//Lab 7, Queue Data Structure
//Editor Used: Visual Studio Code
//Compiler Used: Visual Studio Developer Command Prompt

#include <iostream>
using std::ios;
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

#include <utility>
using std::swap;

#include <fstream>
using std::ifstream;
using std::ofstream;

struct Movie {
	string title;
	int viewed;
	int rating;
	Movie * next;
};

void serializeUp(Movie *& first, Movie *& last, string file, int & count);
void coutMenu();
void addMovie(Movie *& first, Movie *& last, int & count);
void updateMovie(Movie * first, int count);
void removeMovie(Movie *& first, Movie *& last, int & count);
void coutAllMovies(Movie * first);
void sortByTitle(Movie *& first, Movie *& last);
void sortByViewed(Movie *& first, Movie *& last);
void sortByRating(Movie *& first, Movie *& last);
string strToUpper(string str);
void serializeDown(Movie * first, string file);
void printId(string assignment);

int main() {
	printId("Lab 7");

	string input;

	Movie * first_movie = nullptr;
  Movie * last_movie = nullptr;
	int num_of_movies = 0;

  serializeUp(first_movie, last_movie, "movies.txt", num_of_movies);

	//Infinitely loop the program until user wants to quit
	while (true) {
    cout << endl; //Print empty line
    coutMenu(); //Display menu
    getline(cin, input); //Get input

		//Prompt invalid input if input length is not 1
		if (input.length() != 1) {
			cout << "Invalid input, please try again" << endl << endl;
			continue;
		}

		//Take action based on the input character
		switch (input.at(0))
		{
			case 'A': case 'a': //Add a movie
				addMovie(first_movie, last_movie, num_of_movies);
				continue;
			case 'U': case 'u': //Update a movie
        updateMovie(first_movie, num_of_movies);
				continue;
			case 'E': case 'e': //Remove a movie
				removeMovie(first_movie, last_movie, num_of_movies);
				continue;
			case 'L': case 'l': //Lists out all movies
				coutAllMovies(first_movie);
				continue;
			case 'T': case 't': //Arrange the list by titles
				sortByTitle(first_movie, last_movie);
				continue;
			case 'V': case 'v': //Arrange the list by viewed
				sortByViewed(first_movie, last_movie);
				continue;
			case 'R': case 'r': //Arrange the list by rating
				sortByRating(first_movie, last_movie);
				continue;
			case 'Q': case 'q': //Break out of switch and while loop
				break;
			default:
				cout << "Invalid input, please try again" << endl;
        continue;
		}

    break;
	}

  serializeDown(first_movie, "movies.txt");

  //Delete the whole movie list
  while (first_movie != nullptr) {
    Movie * p = first_movie;
    first_movie = first_movie->next;
    delete p;
  }
  last_movie = nullptr;
  num_of_movies = 0;

  //Quit the program
  cout << endl << "Program Finished!" << endl;
  return 0;
}

/**********************************************************************
* Purpose: Display menu
*
* Parameters: None
*
* Return: Nothing
**********************************************************************/
void coutMenu() {
  cout << "Movie menu:" << endl;
  cout << "A Add a movie" << endl;
  cout << "U Update a movie" << endl;
  cout << "E Remove a movie" << endl;
  cout << "L List all movies" << endl;
  cout << "T arrange by Title" << endl;
  cout << "V arrange by year Viewed" << endl;
  cout << "R arrange by Rating" << endl;
  cout << "Q Quit" << endl;
}

/**********************************************************************
* Purpose: Add a movie to the queue
*
* Parameters: Movie *& first - The pointer to the first movie
*             Movie *& last - The pointer to the last movie
*             int & count - The number of movies
*
* Return: Nothing
**********************************************************************/
void addMovie(Movie *& first, Movie *& last, int & count) {
  //Get input
  string input;
  cout << "Enter a movie's name: ";
  getline(cin, input);

  if (input == "") {
    cout << "No movie exists without a name" << endl;
    return;
  }

  Movie * add_movie = new Movie; //New movie node
  add_movie->title = input;
  
  cout << "Enter the year you saw " << "[like 2016]: ";
  getline(cin, input);
  add_movie->viewed = atoi(input.c_str());

  cout << "Enter your rating for " << "[1, 2, 3, 4, 5]: ";
  getline(cin, input);
  add_movie->rating = atoi(input.c_str());

  // link to the end of the list
  add_movie->next = nullptr;
  if (last != nullptr) //Make last next the movie to add if it exists
    last->next = add_movie;
  else  //Otherwise there is no movies yet and it is the first movie
    first = add_movie;
  
  last = add_movie;

  count++; //Add to the number of movies
}

/**********************************************************************
* Purpose: Update a movie at a simulated index
*
* Parameters: Movie * first - The pointer to the first movie
*             int count - The number of movies
*
* Return: Nothing
**********************************************************************/
void updateMovie(Movie * first, int count) {
  //Stop if there is no movies to update
  if (count < 1) {
    cout << "No movies to update" << endl;
    return;
  }

  //Get input
  string input;
  cout << "Which movie to update(1-" << count << ")? ";
  getline(cin, input);

  int index = atoi(input.c_str()) - 1; //Simulated index of the movie to update

  //If index is in range, find the movie
  if (index >= 0 && index < count) {
    Movie * p = first; //The movie to update

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
}

/**********************************************************************
* Purpose: Delete a movie from the queue
*
* Parameters: Movie *& first - The pointer to the first movie
*             Movie *& last - The pointer to the last movie
*             int & count - The number of movies
*
* Return: Nothing
**********************************************************************/
void removeMovie(Movie *& first, Movie *& last, int & count) {
  //Check to see if there is any movies to delete
  if (count < 1) {
    cout << "No movies to delete" << endl;
    return;
  }

  //Get simulated index to remove
  string input;
  cout << "which movie to remove (1-" << count << ")? ";
  getline(cin, input);
  int index = atoi(input.c_str()) - 1;

  Movie * prev_p = nullptr; //The previous movie of the movie to remove
  Movie * p = first; //The movie to remove

  //Check to see if index is in range
  if (index >= 0 && index < count) {
    //Move the pointers to the right simulated indexes
    for (int i = 0; i < index; i++) {
      prev_p = p;
      p = p->next;
    }
    
    //Link next movie of p to first movie
    if (prev_p == nullptr) {
      if (first == last) {
        first = nullptr;
        last = nullptr;
      }
      else
        first = p->next;
    }
    //Link next movie of p to next movie of previous movie
    else {
      prev_p->next = p->next;
      if (p == last)
        last = prev_p;
    }

    //Remove the movie at p
    delete p;
    count--;
    cout << "Removed movie at index " << index + 1<< endl;
  }
  else
    cout << "Invalid index" << endl;
}

/**********************************************************************
* Purpose: Print out all of the movies in a nicely formatted table
*
* Parameters: Movie * p - The pointer to the first movie
*
* Return: Nothing
**********************************************************************/
void coutAllMovies(Movie * first) {
	const int NUM_WIDTH = 2; //The width of the number column
	const int TITLE_WIDTH = 27; //The width of the title column
	const int VIEWED_AND_RATING_WIDTH = 6; //The width of the viewed and rating column

	cout << "#  Title                         Viewed Rating" << endl;
	cout << "-- ---------------------------   ------ ------" << endl;

	int movie_count = 0; //The count of the movie

	//Print every node of the list
	for (Movie * p = first; p != nullptr; p = p->next) {
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
* Purpose: Sort the queue by title
*
* Parameters: Movie *& first - The pointer to the first movie
*             Movie *& last - The pointer to the last movie
*
* Return: Nothing
**********************************************************************/
void sortByTitle(Movie *& first, Movie *& last) {
  //Get how the user wants to sort the movies
  string input;
  cout << "Arrange by lowest value (A) to highest value (Z) string (Enter \'L\') or by highest value (Z) to lowest value (A) (Enter \'H\')? ";
  getline(cin, input);

  //User wants lowest to highest
  if (input.at(0) == 'L' || input.at(0) == 'l') {
    //For all nodes within the linked list
    for (Movie * p = first; true; p = p->next) {
      //For all nodes after the first_movie in the linked list
      for (Movie * q = p->next; q != nullptr; q = q->next)
        //Swap if p title is a higher rank than q title
        if (strToUpper(p->title).compare(strToUpper(q->title)) > 0) {
          swap(*p, *q);
          swap(p->next, q->next);
        }
      
      //Set the last pointer to p and break if next does not exist
      if (p->next == nullptr) {
        last = p;
        break;
      }
    }
    coutAllMovies(first); //List all movies
  }
  //User wants highest to lowest
  else if (input.at(0) == 'H' || input.at(0) == 'h') {
    //For all nodes within the linked list
    for (Movie * p = first; true; p = p->next) {
      //For all nodes after the first_movie in the linked list
      for (Movie * q = p->next; q != nullptr; q = q->next)
        //Swap if p title is a lower rank than q title
        if (strToUpper(p->title).compare(strToUpper(q->title)) < 0) {
          swap(*p, *q);
          swap(p->next, q->next);
        }
      
      //Set the last pointer to p and break if next does not exist
      if (p->next == nullptr) {
        last = p;
        break;
      }
    }
    coutAllMovies(first); //List all movies
  }
  else
    cout << "Invalid input" << endl;
}

/**********************************************************************
* Purpose: Sort the queue by viewed
*
* Parameters: Movie *& first - The pointer to the first movie
*             Movie *& last - The pointer to the last movie
*
* Return: Nothing
**********************************************************************/
void sortByViewed(Movie *& first, Movie *& last) {
  //Get how the user wants to sort the movies
  string input;
  cout << "Arrange by newest to oldest (Enter \'N\') or oldest to newest (Enter \'O\')? ";
  getline(cin, input);

  //User wants oldest to newest
  if (input.at(0) == 'O' || input.at(0) == 'o') {
    //For all nodes within the linked list
    for (Movie * p = first; true; p = p->next) {
      //For all nodes after the first_movie in the linked list
      for (Movie * q = p->next; q != nullptr; q = q->next)
        //Swap if p viewed is newer than q viewed
        if (q->viewed < p->viewed) {
          swap(*p, *q);
          swap(p->next, q->next);
        }
      
      if (p->next == nullptr) {
        last = p;
        break;
      }
    }
    coutAllMovies(first); //List all movies
  }
  //User wants newest to oldest
  else if (input.at(0) == 'N' || input.at(0) == 'n') {
    //For all nodes within the linked list
    for (Movie * p = first; true; p = p->next) {
      //For all nodes after the first_movie in the linked list
      for (Movie * q = p->next; q != nullptr; q = q->next)
        //Swap if p viewed is newer than q viewed
        if (q->viewed > p->viewed) {
          swap(*p, *q);
          swap(p->next, q->next);
        }
      
      if (p->next == nullptr) {
        last = p;
        break;
      }
    }
    coutAllMovies(first); //List all movies
  }
  else
    cout << "Invalid input" << endl;
}

/**********************************************************************
* Purpose: Sort the queue by rating
*
* Parameters: Movie *& first - The pointer to the first movie
*             Movie *& last - The pointer to the last movie
*
* Return: Nothing
**********************************************************************/
void sortByRating(Movie *& first, Movie *& last) {
  //Get how the user wants to sort the movies
  string input;
  cout << "Arrange by highest to lowest (Enter \'H\') or lowest to highest (Enter \'L\')? ";
  getline(cin, input);

  //User wants to sort from highest to lowest
  if (input.at(0) == 'H' || input.at(0) == 'h') {
    //For all nodes within the linked list
    for (Movie * p = first; true; p = p->next) {
      //For all nodes after the first_movie in the linked list
      for (Movie * q = p->next; q != nullptr; q = q->next)
        //Swap if p rating is higher than q rating
        if (q->rating > p->rating) {
          swap(*p, *q);
          swap(p->next, q->next);
        }
      
      if (p->next == nullptr) {
        last = p;
        break;
      }
    }
    coutAllMovies(first); //List all movies
  }
  //User wants to sort from lowest to highest
  else if (input.at(0) == 'L' || input.at(0) == 'l') {
    //For all nodes within the linked list
    for (Movie * p = first; true; p = p->next) {
      //For all nodes after the first_movie in the linked list
      for (Movie * q = p->next; q != nullptr; q = q->next)
        //Swap if p rating is higher than q rating
        if (q->rating < p->rating) {
          swap(*p, *q);
          swap(p->next, q->next);
        }
      
      if (p->next == nullptr) {
        last = p;
        break;
      }
    }
    coutAllMovies(first); //List all movies
  }
  else
    cout << "Invalid Input" << endl;
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

/**********************************************************************
* Purpose: Serialize up the movies to the queue
*
* Parameters: Movie *& first - The pointer to the first movie
*             Movie *& last - The pointer to the last movie
*             string file - The file name
*             int & count - The number of movies
*
* Return: Nothing
**********************************************************************/
void serializeUp(Movie *& first, Movie *& last, string file, int & count) {
  //Open the file to write
  ifstream fin;
  fin.open(file);
  
  //Do only if the file exists
  if (fin.good()) {
    //Do until the end of file is reached
    while (!fin.eof()) {
      //Get input
      string input;
      getline(fin, input);

      if (input == "")
        break;
      
      Movie * add_movie = new Movie; //New movie node
      add_movie->title = input;
      
      getline(fin, input);
      add_movie->viewed = atoi(input.c_str());

      getline(fin, input);
      add_movie->rating = atoi(input.c_str());

      // link to the end of the list
      add_movie->next = nullptr;
      if (last != nullptr) //Make last next the movie to add if it exists
        last->next = add_movie;
      else  //Otherwise there is no movies yet and it is the first movie
        first = add_movie;
      
      last = add_movie; //The new movie added should be the last one

      count++; //Add to the number of movies
    }
  }

  fin.close(); //Close this file
}

/**********************************************************************
* Purpose: Serialize down the movies from the queue
*
* Parameters: Movie * first - The pointer to the first movie
*             string file - The file name
*
* Return: Nothing
**********************************************************************/
void serializeDown(Movie * first, string file) {
  //Open the file to write
  ofstream fout;
  fout.open(file);

  if (fout.good()) {
    while (first != nullptr) {
      //Write movie to file
      fout << first->title << endl;
      fout << first->viewed << endl;
      fout << first->rating << endl;

      first = first->next; //Next movie
    }
  }

  fout.close(); //Close file
}