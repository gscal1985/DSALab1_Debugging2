/*
	File:			main.cpp - Main for error/debug project
	Author:			Justin Tackett
	Created:		04/25/2020
	Last Modified:	04/25/2020
*/

/***********/
/* Includes*/
/***********/

#include <iostream>
#include "Movie.h"
using namespace std;

// Memory leak detection
#define _CRTDBG_MAP_ALLOC

// Display a movie using its Display method
void DisplayMovie(const Movie _movie);

int main() {

	// Memory leak detection
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	// this function call will set a breakpoint at the location of a leaked block
	// set the parameter to the identifier for a leaked block
	_CrtSetBreakAlloc(-1);

	// Creating a couple of movies
	Movie film1("Lord of the Rings: The Fellowship of the Ring", 208);
	Movie film2("Avengers: Endgame", 182);

	// Setting their reviews
	int film1Reviews[5] = { 9, 10, 10, 10, 8 };
	int film2Reviews[8] = { 9, 8, 8, 10, 6, 7, 11, 0 };

	// Setting review scores
	film1.SetStars(film1Reviews, 5);
	film2.SetStars(film2Reviews, 8);

	// Displaying
	DisplayMovie(film1);
	cout << '\n';
	DisplayMovie(film2);

	// Flipping order by doing a swap
	Movie temp = film1;
	film1 = film2;
	film2 = temp;

	cout << "\n\n";

	// Displaying after swap
	DisplayMovie(film1);
	cout << '\n';
	DisplayMovie(film2);



	cout << "\n\n";
	system("pause");
	return 0;
}

