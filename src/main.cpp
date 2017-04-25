/**************************************************************************************************/

/*
 * File: main.cpp
 * Author: Coby Allred
 * NetID: cobyallred
 * Date: 11/7/16
 *
 * Description: Runs the trending program to determine the rankings of various hashtags from two input files
 *
 */

/**************************************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>

#include "Input.h"
#include "Hashtag.h"
#include "Execute.h"

using namespace std;

/**************************************************************************************************/


int main(int argc, char *argv[]) {
	
	if (argc != 4) { // If incorrect # of arguments, print usage statement and exit
		cout << "Usage: trending startHashtagFile endHashtagFile trendFile" << endl;
		return EXIT_FAILURE;
	}

	HashInputs inputHash(argv[1], argv[2]); // Creates the HashInputs class using the specified input files

	if (inputHash.IsGood()) { // If the files are good, read inputs
		inputHash.ReadInputs();
	}
	else { // Else print an error and exit
		cout << "Error opening " << argv[1] << "or " << argv[2] << "for reading." << endl;
		return EXIT_FAILURE;
	}

	Output hashOutput(inputHash.GetInputs(), argv[3]); // Creates the output class using the input hashtag vector and specified output file

	if (hashOutput.isOutputGood()) { // If output file is good, execute main program steps
		hashOutput.Execute();
	}
	else { // Else print an error and exit
		cout << "Error opening " << argv[3] << "for writing." << endl;
		return EXIT_FAILURE;
	}

    return EXIT_SUCCESS;
}

/**************************************************************************************************/
