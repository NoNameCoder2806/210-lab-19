// COMSC-210 | Lab 19 | Dat Hoang Vien
// IDE used: Visual Studio Code

// Libraries and headers
#include <iostream>
#include <string>
#include "MovieReview.h"
using namespace std;

// Movie class
class Movie
{
private:
    string title;                // The movie's title
    MovieReview* reviews;        // The Linked list of the movie's reviews

public:
    // Accessors / Getters
    string getTitle() const
    {
        return title;
    }

    // Mutators / Setters
    void setTitle(string t)
    {
        title = t;
    }
};