/**************************************************************************************************/

/*
* File: Hashtag.cpp
* Author: Coby Allred
* NetID: cobyallred
* Date: 11/7/16
*
* Description:
*
*/

/**************************************************************************************************/

#include "Execute.h"

Output::Output() { // Empty constructor for output class
	return;
}

Output::Output(vector<Hashtag> inputHashtags, char* outputFileName) { // Constructor for output class given hashtag vector and output filename
	this->theHashtags = inputHashtags;
	this->outFileName = outputFileName;

	return;
}

void Output::Execute() { // Executes the main program functions
	setStartRanking(); // Sets the start ranking for the hashtags
	setEndRanking(); // Sets the end ranking for the hashtags

	sortByEndRanking(); // Sorts the hashtag vector by their end rankings

	writeOutputs(); // Writes the output file

	return;
}

bool Output::isOutputGood() { // Checking whether the output file is valid
	return this->outFile.good();
}

void Output::setStartRanking() { // Setting the start ranking of the hashtag based on the other hashtags within the vector

	int maxStartCount = 0;

	for (int count = 0; (unsigned)count < theHashtags.size(); count++) { // Finding the max start count
		if (theHashtags.at(count).getStartCount() > maxStartCount) {
			maxStartCount = theHashtags.at(count).getStartCount();
		}
	}

	int currRank = 1;
	int matchedAtCurr = 0;

	for (int count = 0; count < maxStartCount; count++) { // Going through startcounts, ranking starting at max
		matchedAtCurr = 0; // Reset match count

		for (int location = 0; (unsigned)location < theHashtags.size(); location++) {
			if (theHashtags.at(location).getStartCount() == maxStartCount - count) {  // If there is a match, set to currRank and set that match was found
				theHashtags.at(location).setStartRank(currRank);
				matchedAtCurr = 1;
			}
		}

		if (matchedAtCurr == 1) { // If there are matches, increment rank
			currRank = currRank + 1;
		}
		
	}

	return;
}

void Output::setEndRanking() { // Setting the end ranking of the hashtag based on the other hashtags within the vector
	int maxEndCount = 0;

	for (int count = 0; (unsigned)count < theHashtags.size(); count++) { // Finding the max end count
		if (theHashtags.at(count).getStartCount() > maxEndCount) {
			maxEndCount = theHashtags.at(count).getEndCount();
		}
	}

	int currRank = 1;
	int matchedAtCurr = 0;

	for (int count = 0; count < maxEndCount; count++) { // Going through endcounts, ranking starting at max
		matchedAtCurr = 0; // Reset match count

		for (int location = 0; (unsigned)location < theHashtags.size(); location++) {
			if (theHashtags.at(location).getEndCount() == maxEndCount - count) {  // If there is a match, set to currRank and set that match was found
				theHashtags.at(location).setEndRank(currRank);
				matchedAtCurr = 1;
			}
		}

		if (matchedAtCurr == 1) { // If there are matches, increment rank
			currRank = currRank + 1;
		}

	}

	return;
}

void Output::sortByEndRanking() { // Sorts the hashtag vector by end ranking using the overloaded operator
	sort(theHashtags.begin(), theHashtags.end()); // C++ sorting algorithm, probably quite inefficient
	return;
}

void Output::writeOutputs() { // Writes the output file given in the output class
	if (this->theHashtags.size() == 0) { // If there are no outputs, create and close the file
		outFile.open(outFileName);
		outFile.close();
		return;
	}

	outFile.open(outFileName); // Creating the output file stream

	for (int count = 0; (unsigned)count < theHashtags.size(); count++) { // Iterate through hashtag vector to print
		if (theHashtags.at(count).getEndCount() != 0) { // If not in the end file, do not output
			int isPrinted = 0;

			if ((unsigned)count < theHashtags.size() - 1 && isPrinted != 1) { // Checking for ties and outputting tie if there is
				if (theHashtags.at(count).getEndRank() == theHashtags.at(count + 1).getEndRank()) {
					outFile << "T" << noshowpos << theHashtags.at(count).getEndRank() << ": ";
					isPrinted = 1;
				}
			}
			
			if ((unsigned)count > 0 && isPrinted != 1) { // Checking for ties and outputting tie if there is
				if (theHashtags.at(count).getEndRank() == theHashtags.at(count - 1).getEndRank()) {
					outFile << "T" << noshowpos << theHashtags.at(count).getEndRank() << ": ";
					isPrinted = 1;
				}
			}
			
			if (isPrinted != 1) { // If no tie, just print endrank
				outFile << noshowpos << theHashtags.at(count).getEndRank() << ": ";
			}

			outFile << theHashtags.at(count).getWord(); // print the word itself

			if (theHashtags.at(count).getStartCount() > 0) { // Printing the change in rank
				outFile << " (" << showpos << theHashtags.at(count).getStartRank() - theHashtags.at(count).getEndRank() << ")" << endl;
			}
			else { // Else printing new
				outFile << " (new)" << endl;
			}
		}
		
	}

	outFile.close(); // Close the output file

	return;
}