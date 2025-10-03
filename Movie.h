// COMSC-210 | Lab 19 | Dat Hoang Vien
// IDE used: Visual Studio Code

#pragma once

// Libraries and headers
#include <iostream>
#include <string>
#include <iomanip>
#include "MovieReview.h"
using namespace std;

// Movie class
class Movie
{
private:
    string title;                // The movie's title
    MovieReview* reviews;        // The Linked list of the movie's reviews

    // Constants
    static const int INDEX_WIDTH = 3;
    static const int RATING_WIDTH = 8;
    static const int COMMENT_WIDTH = 25;

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
        cout << "In the function:" << endl;
        cout << "Comment: " << comment << endl;
        cout << "rating: " << rating << endl;

        // Declare a new MovieReview node
        MovieReview* newNode = new MovieReview;
        newNode->rating = (float) rating;      // Assign the rating
        newNode->comment = comment;            // Assign the comment
        newNode->next = nullptr;               // Let next point to a nullptr

        cout << "After assigning the values: " << endl;
        cout << "Comment: " << newNode->comment << endl;
        cout << "rating: " << newNode->rating << endl;

        // Add the new MovieReview node to the head of the Linked list
        newNode->next = reviews;
        reviews = newNode;

        
        cout << "First node: " << endl;
        cout << "Comment: " << reviews->comment << endl;
        cout << "rating: " << reviews->rating << endl;
    }

    void displayReviews()
    {
        cout << "First node:" << endl;
        cout << "Rating: " << reviews->rating << endl;
        cout << "Comment: " << reviews->comment << endl;

        // Declare a new MovieReview node to traverse through the Linked list
        MovieReview* current = reviews;

        // Check whether the Linked list is empty
        if (!reviews)
        {
            // Display a message
            cout << " --- There are no reviews in the list! --- " << endl;

            return;        // Exit the function
        }

        // Declare a counter variable to keep track of the number of reviews
        int count = 0;

        // Display a header
        cout << setw(INDEX_WIDTH) << left << "#";                // Index column
        cout << setw(RATING_WIDTH) << left << "Rating";          // Rating column
        cout << setw(COMMENT_WIDTH) << left << "Comment";        // Comment column
        cout << endl;

        // Display a separator
        cout << string(INDEX_WIDTH + RATING_WIDTH + COMMENT_WIDTH, '-') << endl;

        // Display all the ratings and comments
        while (current)
        {
            // Display all the fields
            cout << setw(INDEX_WIDTH) << left << count + 1;                 // Index column
            cout << setw(RATING_WIDTH) << left << current->rating;          // Rating column
            cout << setw(COMMENT_WIDTH) << left << current->comment;        // Comment column
            cout << endl;

            // // Check whether the next node is null or not
            // if (current->next == nullptr)
            // {
            //     // Exit the function
            //     return;
            // }

            // Advance to the next node
            current = current->next;

            // Increment the count
            count++;
        }
    }
};