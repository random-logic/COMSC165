#include <utility>
using std::swap;
#include <iostream>
#include <string>
using std::string;
using std::ios;
using std::cout;
using std::cin;
using std::endl;
#include <fstream>
using std::ifstream;
using std::ofstream;

struct MovieStruct{ //struct
    string movieTitle;
    int viewYear;
    int userRating;
    MovieStruct *next;
};

void serializeUp(MovieStruct *&firstMoviePtr, MovieStruct *&lastMoviePtr, string filename, int &nodeQuantity);
void serializeDown (MovieStruct *firstMoviePtr, string filename);
void listAll(MovieStruct* firstMoviePtr);
string upperCaser (string str);
void caseA (MovieStruct *&firstMoviePtr, MovieStruct *&lastMoviePtr, int &nodeQuantity); //add movie
void caseU (MovieStruct *&firstMoviePtr, int nodeQuantity); //update movie
void caseE (MovieStruct *&firstMoviePtr, MovieStruct *&lastMoviePtr, int &nodeQuantity); //remove movie
void caseT (MovieStruct *&firstMoviePtr, MovieStruct *&lastMoviePtr); //sort by title
void caseV (MovieStruct *&firstMoviePtr, MovieStruct *&lastMoviePtr); //sort by year viewed
void caseQ (MovieStruct*& firstMoviePtr);
void caseR (MovieStruct *&firstMoviePtr, MovieStruct *&lastMoviePtr); //sort by rating

int main()
{
  MovieStruct *firstMoviePtr = NULL; //head ptr
  MovieStruct *lastMoviePtr = NULL; //tail ptr
  int nodeQuantity = 0; //counts number of entries
  string input = ""; // to hold user input
 
  serializeUp(firstMoviePtr, lastMoviePtr, "movies.txt", nodeQuantity);
 
    while(true){
        cout << "A Add a movie" << endl; //menu
        cout << "U Update a movie" << endl;
        cout << "E rEmove a movie"<< endl;
        cout << "L List all movies" << endl;
        cout << "T arrange by Title" << endl;
        cout << "V arrange by year Viewed" << endl;
        cout << "R arrange by Rating" << endl;
        cout << "Q Quit" << endl;
        getline(cin, input);
            if(input.length() != 1){
                cout << "Please enter exactly 1 character." << endl;
                continue;
            }
            switch (input.at(0)){
                case 'A': case 'a': {
                    caseA(firstMoviePtr,lastMoviePtr, nodeQuantity);
                    continue;
                }
                case 'U': case 'u': {
                    caseU(firstMoviePtr, nodeQuantity);
                    continue;
                }
                case 'E': case 'e': {
                    caseE(firstMoviePtr, lastMoviePtr, nodeQuantity);
                    continue;
                }
                case 'L': case 'l':{
                    listAll(firstMoviePtr);
                    continue;
                }
                case 'T': case 't':{
                    caseT(firstMoviePtr, lastMoviePtr);
                    listAll(firstMoviePtr);
                    continue;
                }
                case 'V': case 'v': {
                    caseV(firstMoviePtr, lastMoviePtr);
                    listAll(firstMoviePtr);
                    continue;
                }
               
                case 'R': case 'r':{
                    caseR(firstMoviePtr, lastMoviePtr);
                    listAll(firstMoviePtr);
                    continue;
                }
                case 'Q': case 'q':{
                    serializeDown(firstMoviePtr, "movies.txt");
                    caseQ(firstMoviePtr);
                    return 0;
                }
                default:
                    cout << "Invalid input!" << endl;
            }
    }
}
/**
* Purpose:
* Parameters:
* Returns:
*/
void listAll(MovieStruct* firstMoviePtr){
    const int NUM_WIDTH = 2;
const int TITLE_WIDTH = 27;
    const int VIEWRATING_WIDTH = 6;

cout << "#  Title                         Viewed Rating" << endl;
cout << "-- ---------------------------   ------ ------" << endl;
    int i = 1;
    for(MovieStruct *p = firstMoviePtr; p != NULL; p = p->next){
    cout.width(NUM_WIDTH);
    cout << i;
    cout << " ";
    cout.width(TITLE_WIDTH);
    cout << p->movieTitle;
    cout << " ";
    cout.width(VIEWRATING_WIDTH);
    cout << p->viewYear;
    cout << " ";
    cout.width(VIEWRATING_WIDTH);
    cout << p->userRating << endl;
    i++;
    }
   
}
/**
* Purpose: homogenizes upper and lower case for comparison
* Parameters: string str
* Returns:
*/
string upperCaser (string str) {
for (int i = 0; i < str.length(); i++)
str[i] = toupper(str.at(i));
return str;
}
/**
* Purpose:
* Parameters:
* Returns:
*/
void caseA (MovieStruct *&firstMoviePtr, MovieStruct *&lastMoviePtr, int &nodeQuantity){
    string input;
    MovieStruct *add_movie = new MovieStruct;
    cout << "Name of the movie to add: ";
    getline(cin, add_movie->movieTitle);
   
    cout << "Year that the movie was watched in: ";
    getline(cin, input);
    add_movie->viewYear = atoi(input.c_str());
   
    cout << "Your rating (1-5) for the movie: ";
    getline(cin, input);
    add_movie->userRating = atoi(input.c_str());
   
    add_movie->next = NULL;
    if(lastMoviePtr != NULL){
        lastMoviePtr->next = add_movie;
    }
    else{
        firstMoviePtr = add_movie;
    }
    lastMoviePtr = add_movie;
    nodeQuantity++;
}
/**
* Purpose:
* Parameters:
* Returns:
*/
void caseU (MovieStruct*& firstMoviePtr, int nodeQuantity){
    string input;
    if (nodeQuantity < 1){
    cout << "There are no movies." << endl;
    return;

    cout << "Choose the movie entry to update. (1-" << nodeQuantity << "): ";
    getline(cin, input);
    int index = atoi(input.c_str()) - 1; // taking user input and comparing it to simulated index
   
    int i; // index counter
    MovieStruct* p; // traversal pointer
    for (p = firstMoviePtr, i = 0; p != 0 && i != index; p = p->next, i++); // note the semicolon!
   
    if (p != 0 && index >= 0) { // just making sure index is not negative
        string buf;
        cout << "Found " << p->movieTitle << " at index " << index << endl;
        cout << "Enter the updated Title: ";
        getline(cin, p->movieTitle);
        cout << "Enter the updated year viewed: ";
        getline(cin, buf);
        p->viewYear = atoi(buf.c_str());
        cout << "Enter the updated movie rating: ";
        getline(cin, buf);
        p->userRating = atoi(buf.c_str());
    }
    else
        cout << "Index " << index << " is out of range.\n";
    }
}
/**
* Purpose:
* Parameters:
* Returns:
*/
void caseE (MovieStruct*& firstMoviePtr, MovieStruct*& lastMoviePtr, int &nodeQuantity){
    string input;
    cout << "Choose the movie entry to remove. (1-" << nodeQuantity << "): ";
    getline(cin, input);
    int index = atoi(input.c_str()) - 1; // taking user input and comparing it to simulated index
   
    int i; // index counter
    MovieStruct* p; // traversal pointer
    MovieStruct* prev_p; // Node previous to p
    for (p = firstMoviePtr, i = 0; p != 0 && i != index; p = p->next, i++)
        prev_p = p;
   
    if (p != 0 && index >= 0) {
        if(p == firstMoviePtr){
            firstMoviePtr = p->next;
        }
        else{
            prev_p->next = p->next;
        }      
        delete p;
        nodeQuantity--;
    }
    else
        cout << "Index " << index << " is out of range.\n";
}
/**
* Purpose:
* Parameters:
* Returns:
*/
void caseT (MovieStruct *&firstMoviePtr, MovieStruct *&lastMoviePtr){
  MovieStruct* p = firstMoviePtr;
    for (; p != NULL; p = p->next) {
      for (MovieStruct* q = p->next; q; q = q->next)
        if(upperCaser(p->movieTitle).compare(upperCaser(q->movieTitle)) > 0) //flip comparer to reverse
        {
          swap(*p, *q);
          swap(p->next, q->next);
        }
      if(p->next == NULL){ // to set tail ptr
        lastMoviePtr = p;
        break;
     }
    }
}
/**
* Purpose:
* Parameters:
* Returns:
*/
void caseV (MovieStruct*& firstMoviePtr, MovieStruct *&lastMoviePtr){
    for (MovieStruct* p = firstMoviePtr; p != NULL; p = p->next) {
        for (MovieStruct* q = p->next; q; q = q->next)
            if (q->viewYear < p->viewYear)
            {
                swap(*p, *q);
                swap(p->next, q->next);
            }
   
      if (p->next == NULL) {
        lastMoviePtr = p;
        break;
      }
    }
}
/**
* Purpose:
* Parameters:
* Returns:
*/
void caseR (MovieStruct*& firstMoviePtr, MovieStruct *&lastMoviePtr){
    for (MovieStruct* p = firstMoviePtr; p != NULL; p = p->next) {
        for (MovieStruct* q = p->next; q; q = q->next)
            if (q->userRating < p->userRating)
            {
                swap(*p, *q);
                swap(p->next, q->next);
            }
        if (p->next == NULL) {
            lastMoviePtr = p;
            break;
        }    
    }
}
/**
* Purpose:
* Parameters:
* Returns:
*/
void caseQ (MovieStruct*& firstMoviePtr){
    while (firstMoviePtr) {
        MovieStruct* p = firstMoviePtr;
        firstMoviePtr = firstMoviePtr -> next;
        delete p;
    }
}
/**
* Purpose:
* Parameters:
* Returns:
*/
void serializeUp(MovieStruct *&firstMoviePtr, MovieStruct *&lastMoviePtr, string filename, int &nodeQuantity){
    ifstream fin;
    fin.open(filename); //open file
    if(fin.good()){
        while (!fin.eof()) {
            string input;
            getline(fin, input);
            if(input == "")
                break;
            MovieStruct *add_movie = new MovieStruct;
           
            add_movie->movieTitle = input;
           
            getline(fin, input);
            add_movie->viewYear = atoi(input.c_str()); //converts input to int
           
            getline(fin, input);
            add_movie->userRating = atoi(input.c_str());
           
            add_movie->next = NULL;
            if(lastMoviePtr != NULL){
                lastMoviePtr->next = add_movie;
               
            }
            else{
                firstMoviePtr = add_movie;
            }
            lastMoviePtr = add_movie;
            nodeQuantity++;
           
        }
    }
    fin.close();
}
/**
* Purpose:
* Parameters:
* Returns:
*/
void serializeDown (MovieStruct *firstMoviePtr, string filename){
    ofstream fout;
    fout.open(filename); //opens file
   
    if(fout.good()){ //checks file
        while(firstMoviePtr != NULL){
            fout << firstMoviePtr->movieTitle << endl; //writes
            fout << firstMoviePtr->viewYear << endl;
            fout << firstMoviePtr->userRating << endl;
           
            firstMoviePtr = firstMoviePtr->next; //points to next
        }
    }
    fout.close(); //close
}