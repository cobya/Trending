/**************************************************************************************************/

/*
* File: Hashtag.cpp
* Author: Coby Allred
* NetID: cobyallred
* Date: 11/7/16
*
* Description: Contains the hashinput class definition and the functions used for 
*
*/

/**************************************************************************************************/

#ifndef INPUT_H
#define INPUT_H

#include "Hashtag.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

/* The HashInputs class is responsible for getting the hashtags from their input files and creating a vector with their data */
class HashInputs {
	private:
		char* inputStartFileName;
		ifstream inputStartFile;
		char* inputEndFileName;
		ifstream inputEndFile;
		vector<Hashtag> inputHashtags;

	public:
		HashInputs();
		HashInputs(char* inputStartFileName, char* inputEndFileName); // Constructor for a specified file name

		void ReadInputs(); // Reads the input files to create the vector of inputted hashtags
		bool IsGood(); // Checks for valid input file
		
		vector<Hashtag> GetInputs() const { // Returns the vector of stored hashtags
			return inputHashtags;
		};

};

#endif