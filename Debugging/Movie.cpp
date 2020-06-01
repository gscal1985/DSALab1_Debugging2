/*
	File:			Movie.cpp - definitions for the Movie class
	Author:			Justin Tackett
	Created:		04/25/2020
	Last Modified:	04/25/2020
*/

/************/
/* Includes */
/************/
#include "Movie.h"
#include <iostream>
using namespace std;


// Constructor
	// In:	_title			Title of the movie
	//		_runtime		Length of the movie
Movie::Movie(const char* _title, int _runtime) {
	// Dynamically allocate and set the name
	mTitle = new char[strlen(_title+1)];
	strcpy_s(mTitle, strlen(_title+1), _title);

	mRuntime = _runtime;
	mStars = nullptr;
	mNumReviews = 0;
}

// Destructor
Movie::~Movie() {
	delete[] mTitle;
}

// Copy constructor
//			Used to copy one object to another (initialization)
// 
// In:	_copy			The object to copy from
Movie::Movie(const Movie& _copy) {
	// Using a shortcut to re-use the assignment operator to do the deep copy
	*this = _copy;
}

// Assignment operator
//			Used to assign one object to another (assignment)
//
// In:	_assign			The object to assign from
//
// Return: The invoking object (by reference)
Movie& Movie::operator=(const Movie& _assign) {
	// Self-assignment check
	if (this == _assign)
		return *this;
	

	// Shallow copy non-dynamic data members
	mRuntime = _assign.mRuntime;

	// Deep copy appropriate data members
	mTitle = new char[strlen(_assign.mTitle) + 1];
	strcpy_s(mTitle, strlen(_assign.mTitle) + 1, _assign.mTitle);

	// Deep copy the reviews
	SetStars(_assign.mStars, mNumReviews);

	return *this;
}

// Set the reviews
// In:	_stars			An array of review scores (1-10) - may need to range-check/cap
//		_numReviews		Number of elements in the _stars array
void Movie::SetStars(const int* _stars, int _numReviews) {
	
	// Allocate array and deep copy
	mStars = new int[_numReviews];
	for (int i = 0; i < _numReviews; ++i) {
		// Cap reviews between 1-10
		mStars[i] = _stars[i];
	}

	// Set the number of reviews
	mNumReviews = _numReviews;
}

// Get the average number of stars
//
// Return:	The average review score
float Movie::GetAverage() const {
	int total = 0;

	// Sum up the review scores
	for (int i = 0; i < mNumReviews; ++i)
		total += mStars[i];

	// Return the average
	return total / mNumReviews;
}

// Display a Movie to the console
void Movie::Display() const {
	cout << mTitle << '\n'
		<< mRuntime << '\n'
		<< GetAverage() << " stars average\n";
}