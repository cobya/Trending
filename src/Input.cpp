/**************************************************************************************************/

/*
* File: Hashtag.cpp
* Author: Coby Allred
* NetID: cobyallred
* Date: 11/7/16
*
* Description: Performs the function of inputting the data given from various files into data vectors
*
*/

/**************************************************************************************************/

#include "Input.h"

HashInputs::HashInputs() { // Do nothing, empty constructor
	return; 
}

HashInputs::HashInputs(char* inputStartFileName, char* inputEndFileName) { // Constructor for HashInputs given both filenames
	this->inputStartFileName = inputStartFileName;
	this->inputEndFileName = inputEndFileName;
	return;
}

void HashInputs::ReadInputs() { // Reads the input file to create the vector of inputted hashtags
	if (inputStartFileName != NULL && inputEndFileName != NULL) { // If the input filenames are not NULL continue
		string inputHashtag;

		inputStartFile.open(inputStartFileName); // Opens the starting file

		if (inputStartFile.is_open()) { // While the starting input is open continue

			while (inputStartFile >> inputHashtag) { // If hashtag is read, go

				transform(inputHashtag.begin(), inputHashtag.end(), inputHashtag.begin(), ::tolower); // Executes the transform using tolower to overwrite the string

				if (this->inputHashtags.size() > 0) { // If the vector has anything in it
					int found = 0;

					for (int count = 0; (unsigned)count < this->inputHashtags.size(); count++) { // Increment through hashtag vector to see if any match
						if (inputHashtag == this->inputHashtags.at(count).getWord()) { // If there is a matching hashtag, increment
							this->inputHashtags.at(count).IncrementStartCount(); // Increment starting count
							found = 1;
							break;
						}
					}
					
					if (found == 0) { // If there is no match in the vector, push the new hashtag
						Hashtag inputHash(inputHashtag, 1, 0);
						this->inputHashtags.push_back(inputHash);
					}

				}
				else { // If there is nothing in the vector, push the new hashtag
					Hashtag inputHash(inputHashtag, 1, 0);
					this->inputHashtags.push_back(inputHash);
				}

			}
		}

		inputStartFile.close(); // Closes the starting inputs

		inputEndFile.open(inputEndFileName); // Opens the ending input file

		if (inputEndFile.is_open()) { // While the starting input is open continue

			while (inputEndFile >> inputHashtag) { // If hashtag is read, go

				transform(inputHashtag.begin(), inputHashtag.end(), inputHashtag.begin(), ::tolower); // Executes the transform using tolower to overwrite the string

				if (this->inputHashtags.size() > 0) { // If the vector has anything in it
					int found = 0;

					for (int count = 0; (unsigned)count < this->inputHashtags.size(); count++) { // Increment through hashtag vector to see if any match
						if (inputHashtag == this->inputHashtags.at(count).getWord()) { // If there is a matching hashtag, increment
							this->inputHashtags.at(count).IncrementEndCount(); // Increment end count
							found = 1;
							break;
						}
					}

					if (found == 0) { // If there is no match in the vector, push the new hashtag
						Hashtag inputHash(inputHashtag, 0, 1);
						this->inputHashtags.push_back(inputHash);
					}

				}
				else { // If there is nothing in the vector, push the new hashtag
					Hashtag inputHash(inputHashtag, 0, 1);
					this->inputHashtags.push_back(inputHash);
				}

			}
		}

		inputEndFile.close(); // Closing the ending inputs

	}

	return;
}

bool HashInputs::IsGood() { // Checks for valid input file
	if (inputStartFile.good() && inputEndFile.good()) {
		return true;
	}
	else {
		return false;
	}
} 

