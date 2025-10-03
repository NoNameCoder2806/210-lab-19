// COMSC-210 | Lab 19 | Dat Hoang Vien
// IDE used: Visual Studio Code

// Libraries and headers
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "MovieReview.h"
#include "Movie.h"
using namespace std;

// Constants
const int RATING_STEPS = 41;                 // Number of possible increments (0.0 … 4.0 in steps of 0.1)
const double MIN_RATING = 1.0f;              // Minimum rating
const double RATING_INCREMENT = 0.1f;        // Step size
const string DATA_FILE = "data.txt";         // The path of the data file

// Function prototypes
double generateRating();

void readMovies(vector<Movie*>& movies, string path);

// Main function
int main()
{
    // Call srand() and time()
    srand(time(0));

    // Declare a vector to store all the Movie pointers
    vector<Movie*> movies;

    // Declare a string variable to hold the data file path
    string path = DATA_FILE;

    // Read all the Movie objects from the data file
    readMovies(movies, path);

    // Iterate through the vector of Movie objects
    for (int i = 0; i < movies.size(); i++)
    {
        // Display the Movie title
        cout << i + 1 << ". Movie: " << movies.at(i)->getTitle() << endl;

        // Display all the reviews of the Movie
        movies.at(i)->displayReviews();

        // Enter a new line
        cout << endl;
    }

    return 0;
}

// Function implementations
/*
    generateRating()
    Randomly generate a random rating (between 1.0 and 5.0)
    Arguments: none
    Return: a double rating between 1.0 and 5.0
*/
double generateRating()
{
    // Randomly generate a rating between 1.0 and 5.0
    double rating = (rand() % RATING_STEPS) * RATING_INCREMENT + MIN_RATING;

    // Return the rating
    return rating;
}

/*
    readMovies()
    Read all the Movie objects and add them into the vector
    Arguments:
        - movies: a reference to a Movie pointers vector
        - path: a string that stores the data file path
    Return: none
*/
void readMovies(vector<Movie*>& movies, string path)
{
    // Declare a file stream to read the file
    ifstream fin;
    fin.open(path);

    // Declare a string variable to store the lines' content
    string line;

    // Iterate through the file and read the titles
    while (true)
    {        
        // Declare a new Movie object to store the title and reviews
        Movie* temp = new Movie;

        // Read the title of the movie
        if (getline(fin, line) && line != "")      // If the line is not blank
        {
            temp->setTitle(line);                  // Set the title of the Movie object
        }
        else if (line == "")                       // If the line is blank
        {
            continue;                              // Skip to the next iteration
        }
        else                                       // If getline() fails, we reached the EOF
        {
            break;                                 // Break out of the loop
        }

        // Add a second loop to read all the comments
        while (getline(fin, line) && line != "")
        {
            // Declare 2 variables to store the comment and rating
            string comment = line;                          // Store the comment
            float rating = (float) generateRating();        // Generate a random rating

            // Add the review to the Linked list
            temp->addReview(rating, comment);
        }

        // Add the Movie object into the vector
        movies.push_back(temp);
    }
}