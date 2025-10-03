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
    /*
        addReview()
        Add a MovieReview node to the head of the Linked list
        Arguments:
            - rating: a float value as the rating of the Movie (from 1.0 to 5.0)
            - comment: a string as the comment on the Movie
        Return: none
    */
    void addReview(double rating, string comment)
    {
        // Declare a new MovieReview node
        MovieReview* newNode = new MovieReview;
        newNode->rating = rating;          // Assign the rating
        newNode->comment = comment;        // Assign the comment
        newNode->next = nullptr;           // Let next point to a nullptr

        // Add the new MovieReview node to the head of the Linked list
        newNode->next = reviews;
        reviews = newNode;
    }

    void displayMovie()
    {
        // Display the title of the Movie
        cout << " --- Title: " << getTitle() << " --- " << endl;

        // Declare a new MovieReview node to traverse through the Linked list
        MovieReview* current = new MovieReview;

        // Display all the ratings and comments
        while (current)
        {

        }
    }
};