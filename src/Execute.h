/**************************************************************************************************/

/*
* File: Hashtag.cpp
* Author: Coby Allred
* NetID: cobyallred
* Date: 11/7/16
*
* Description: Contains the hashtag class definition and the function prototypes to create and edit its data
*
*/

/**************************************************************************************************/

#ifndef EXECUTE_H
#define EXECUTE_H

#include "Hashtag.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;

/* The output class executes the main functions of the program including setting rankings, sorting, and writing the output */
class Output {
	private:
		char* outFileName; // Output filename
		ofstream outFile; // Output file stream
		vector<Hashtag> theHashtags; // Hashtag vector
	
	public:
		Output(); // Default constructor
		Output(vector<Hashtag> inputHashtags, char* outputFileName); // Constructor using specified hashtags and output file name

		void Execute(); // Executes main program functions
		bool isOutputGood(); // Checks for a valid output file

		void setStartRanking(); // Sets the start ranking for the hashtags
		void setEndRanking(); // Sets the end ranking for the hashtags

		void sortByEndRanking(); // Sorts the hashtags by their end rankings

		void writeOutputs(); // Writes the output file
};

#endif