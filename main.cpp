// COMSC-210 | Lab 19 | Dat Hoang Vien
// IDE used: Visual Studio Code

// Libraries and headers
#include <iostream>
#include "MovieReview.h"
using namespace std;

// Constants
const float MIN_RATING = 0.0;
const float MAX_RATING = 5.0;

// Function prototypes
float generateRating();

void displayOptions();                                        // Display all the of operations

void addHead(MovieReview*& head, MovieReview* newNode);       // Add a MovieReview node to the head

void addTail(MovieReview*& head, MovieReview* newNode);       // Add a MovieReview node to the tail

void deleteList(MovieReview*& head);                          // Delete all the MovieReview nodes

void displayList(MovieReview* head);                          // Display all the MovieReview nodes

// Main function
int main()
{
    // Declare a new Linked list
    MovieReview* head = nullptr;

    // Display the options for the user
    displayOptions();

    // Declare a char variable to store the user's choice
    int choice;

    // Prompt the user to enter thetheir choice
    cout << "   Choice: ";
    cin >> choice;
    cin.ignore(1000, 10);

    // Check whether the entered choice is valid
    while (choice != 1 && choice != 2)
    {
        // Display an error message
        cout << " --- Invalid choice! Please choose 1 or 2! --- ";

        // Prompt the user to enter a new choice
        cout << "   Enter your new choice: ";
        cin >> choice;
        cin.ignore(1000, 10);
    }

    // Loop until the user stops inputing the reviews
    while (true)
    {
        // Declare 2 variables to store the rating and comment
        float rating = 0.0;
        string comment = "";

        // Prompt the user to enter a rating
        cout << "Enter review rating (0-5): ";
        cin >> rating;
        cin.ignore(1000, 10);

        // Check whether the entered rating is valid
        while (rating < MIN_RATING || rating > MAX_RATING)
        {
            // Display an error message
            cout << " --- Invalid rating! Rating must be between 0 and 5! --- " << endl;

            // Prompt the user to enter a new rating
            cout << "Please enter a valid rating (0-5): ";
            cin >> rating;
            cin.ignore(1000, 10);
        }

        // Prompt the user to enter a comment
        cout << "Enter review comment: ";
        getline(cin, comment);

        // Check whether the comment was empty
        if (comment.length() == 0)
        {
            // let comment be "(no comment)"
            comment = "(no comment)";
        }

        // Declare a new MovieReview node
        MovieReview* node = new MovieReview;
        node->rating = rating;
        node->comment = comment;
        node->next = nullptr;

        // Implement addHead() or addTail() depending on user's choice
        if (choice == 1)
        {
            // Add the node to the head of the Linked list
            addHead(head, node);
        }
        else
        {
            // Add the node to the tail of the Linked list
            addTail(head, node);
        }

        // Declare a char variable to store user's choice
        char c;

        // Let user choose to continue or stop
        cout << "Enter another review? Y/N: ";
        cin >> c;
        cin.ignore(1000, 10);

        // Check whether the choice is valid
        while (toupper(c) != 'Y' && toupper(c) != 'N')
        {
            // Display an error message
            cout << " --- Invalid choice! Please enter 'Y' or 'N'! --- " << endl;

            // Prompt the user to enter a new choice
            cout << "Do you want to enter another review? Y/N: ";
            cin >> c;
            cin.ignore(1000, 10);
        }

        // Check if the user want to exit the program
        if (toupper(c) == 'N')
        {
            // Display all the reviews
            cout << "Outputting all the reviews: " << endl;

            // Call the displayList() function
            displayList(head);

            // Clean up the memory: deleting all the nodes in the Linked list
            deleteList(head);

            break;
        }
    }

    return 0;
}

// Function implementations
float generateRating()
{
    float rating = (rand() % 41) / 10 + 1.0;
}

/*
    displayOptions()
    Display the operations the user can implement on the Linked list
    Arguments: none
    Return: none
*/
void displayOptions()
{
    // Display the options
    cout << "Which Linked list method should we use?" << endl;
    cout << "   [1] New nodes are added at the head of the linked list" << endl;
    cout << "   [2] New nodes are added at the tail of the linked list" << endl;
}

/*
    addHead()
    Add a MovieReview node to the head of the Linked list
    Arguments:
        - head: a reference to the pointer to the head MovieReview node of the linked list
        - newNode: a pointer to the MovieReview node to add
    Return: none
*/
void addHead(MovieReview*& head, MovieReview* newNode)
{
    // Let newNode points to the current head
    newNode->next = head;

    // Update the new head of the Linked list
    head = newNode;
}

/*
    addTail()
    Add a MovieReview node to the tail of the Linked list
    Arguments:
        - head: a reference to the pointer to the head MovieReview node of the linked list
        - newNode: a pointer to the MovieReview node to add
    Return: none
*/
void addTail(MovieReview*& head, MovieReview* newNode)
{
    // Check whether the list is empty
    if (head == nullptr)
    {
        // Let newNode be the head of the Linked list
        head = newNode;

        return;      // Exit the function
    }

    // Declare a MovieReview node to traverse
    MovieReview* current = head;

    // Iterate until we reach the last MovieReview node of the Linked list
    while (current->next != nullptr)
    {
        // Move on to the next MovieReview node
        current = current->next;
    }

    // Add newNode to the tail of the Linked list
    current->next = newNode;
}

/*
    deleteList()
    Delete all MovieReview nodes in the Linked list
    Arguments:
        - head: a reference to the pointer to the head MovieReview node of the linked list
    Return: none
*/
void deleteList(MovieReview*& head)
{
    // Traverse through the Linked list
    while (head)
    {
        // Declare a new MovieReview node and let it be the head
        MovieReview* current = head;

        // Move on to the next MovieReview node
        head = head->next;

        // Delete the current MovieReview node
        delete current;
    }
}

/*
    displayList()
    Display all the MovieReview nodes of the Linked list and the average rating
    Arguments:
        - head: a pointer to the head MovieReview node of the linked list
    Return: none
*/
void displayList(MovieReview* head)
{
    // Check whether the list is empty
    if (head == nullptr)
    {
        // Display an error message
        cout << "There are no reviews in the Linked list!" << endl;

        return;      // Exit the function
    }

    // Declare a new MovieReview node to traverse
    MovieReview* current = head;

    // Declare some variables
    int count = 0;        // An integer counter for the number of nodes
    float sum = 0.0;      // A float variable for the sum of the ratings

    // Iterate through the Linked list until we reach the final node
    while (current)
    {
        // Display the rating and the comment
        cout << "   > Review #" << count + 1 << ": " << current->rating << ": " << current->comment << endl;

        // Update the variables
        count++;                     // Increment the count
        sum += current->rating;      // Update the sum

        // Move on to the next node
        current = current->next;
    }

    // Display the average rating
    cout << "   > Average: " << sum / (float) count << endl;
}