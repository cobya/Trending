//-------------------------------------------------------------------------------------

#ifndef HASHTAG_H
#define HASHTAG_H

//-------------------------------------------------------------------------------------
//
// File: Hashtag.h
// Author: Coby Allred
// NetID: cobyallred
// Date: 11/7/16
//
// Description: Contains the hashtag class definitions and its getters and setters and the operator overload used in sorting
//
//--------------------------------------------------------------------------------------

#include <string>

using namespace std;

//--------------------------------------------------------------------------------------

/* Defining the Hashtag class which stores the various hashtags taken from the input file and the data used to rank them */
class Hashtag {
	private:
		string word;      // The hashtag itself
		int startCount;   // Number of occurrences in start file
		int endCount;     // Number of occurrences in end file
		int startRank;    // Rank in start file
		int endRank;      // Rank in end file
	
	public:
		Hashtag(string word); // Constructor using specified string
		Hashtag(string word, int startCount, int endCount); // Constructor using specified string, startCount, and endCount
   
	// Getter and setter functions for hashtag word, counts, and ranks
	string getWord() const;
	int getStartCount() const;
	int getEndCount() const;
	int getStartRank() const;
	int getEndRank() const;
	void setStartRank(int rank);
	void setEndRank(int rank);
	
	// Functions to increment start or end counts
	void IncrementStartCount();
	void IncrementEndCount();
	
	// Overloaded < operator for Hashtag objects
	bool operator<(const Hashtag& rhs) const;
};

//--------------------------------------------------------------------------------------

#endif // HASHTAG_H
