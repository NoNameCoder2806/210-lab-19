// COMSC-210 | Lab 19 | Dat Hoang Vien
// IDE used: Visual Studio Code

#pragma once

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
    // Constructor
    Movie()        // Default constructor
    {
        title = "";
        reviews = nullptr;
    }

    // Destructor
    ~Movie()
    {
        // Iterate through the whole Linked list of reviews
        while (reviews)
        {
            // Declare a new MovieReview node and let it point to the current node
            MovieReview* current = reviews;

            // Move on to the next MovieReview node in the Linked list
            reviews = reviews->next;

            // Delete the current MovieReview node
            delete current;
        }
    }

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

    // Member functions
    void addReview(double rating)
    {

    }
};