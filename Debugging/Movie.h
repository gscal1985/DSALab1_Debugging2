/*
	File:			Movie.h - declaration of the Movie class
	Author:			Justin Tackett
	Created:		04/25/2020
	Last Modified:	04/25/2020
*/

// Header protection
#pragma once

class Movie {

private:

	/****************/
	/* Data members */
	/****************/
	char* mTitle;		// Name of the movie
	int mRuntime;		// Length of the movie
	int* mStars;		// Dynamic array of review scores (1-10)
	int mNumReviews;	// Number of reviews stored (elements in mStars)

public:

	// Constructor
	// In:	_title			Title of the movie
	//		_runtime		Length of the movie
	Movie(const char* _title, int _runtime);

	// Destructor
	~Movie();

	// Copy constructor
	//			Used to copy one object to another (initialization)
	// 
	// In:	_copy			The object to copy from
	Movie(const Movie& _copy);

	// Assignment operator
	//			Used to assign one object to another (assignment)
	//
	// In:	_assign			The object to assign from
	//
	// Return: The invoking object (by reference)
	Movie& operator=(const Movie& _assign);

	// Set the reviews
	// In:	_stars			An array of review scores (1-10)
	//		_numReviews		Number of elements in the _stars array
	void SetStars(const int* _stars, int _numReviews);

	// Get the average number of stars
	//
	// Return:	The average review score
	float GetAverage() const;

	// Display a Movie to the console
	void Display() const;
};

