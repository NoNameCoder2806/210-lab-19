// COMSC-210 | Lab 19 | Dat Hoang Vien
// IDE used: Visual Studio Code

#pragma once

// Libraries
#include <iostream>
#include <string>
using namespace std;

// MovieReview struct
struct MovieReview
{
    float rating;             // The movie review's rating
    string comment;           // The movie review's comment
    MovieReview* next;        // The pointer to the next MovieReview node
};