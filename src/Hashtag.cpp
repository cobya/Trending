/**************************************************************************************************/

/*
* File: Hashtag.cpp
* Author: Coby Allred
* NetID: cobyallred
* Date: 11/7/16
*
* Description: Implements the getters and setters of Hashtag and its operator overload used to sort the vectors
*
*/

/**************************************************************************************************/

#include "Hashtag.h"
#include <iostream>


// The constructor for a hashtag given a specified word
Hashtag::Hashtag(string word) {
	this->word = word;
	setEndRank(0);
	setStartRank(0);
	startCount = 0;
	endCount = 0;
	return;
}

// Constructor for the hashtag class using a specified word, startCount, and endCount
Hashtag::Hashtag(string word, int startCount, int endCount) {
	this->word = word;
	this->startCount = startCount;
	this->endCount = endCount;
	endRank = 0;
	startRank = 0;
	return;
}

// Getter and setter functions for hashtag word, counts, and ranks
string Hashtag::getWord() const {
	return this->word;
}

int Hashtag::getStartCount() const {
	return this->startCount;
}

int Hashtag::getEndCount() const {
	return this->endCount;
}

int Hashtag::getStartRank() const {
	return this->startRank;
}

int Hashtag::getEndRank() const {
	return this->endRank;
}

void Hashtag::setStartRank(int rank) {
	this->startRank = rank;
	return;
}

void Hashtag::setEndRank(int rank) {
	this->endRank = rank;
	return;
}

// Increment the start count rank
void Hashtag::IncrementStartCount() {
	this->startCount = this->startCount + 1;
	return;
}

void Hashtag::IncrementEndCount() {
	this->endCount = this->endCount + 1;
	return;
}

// Overloaded < operator for Hashtag objects
bool Hashtag::operator<(const Hashtag& rhs) const {
	if (rhs.endCount < endCount) {
		return true;
	}
	else if (rhs.endCount == endCount && rhs.endCount != 0  && endCount != 0 && word < rhs.word) {
		return true;
	}
	else if (rhs.endCount == 0 && endCount == 0 && rhs.startCount < startCount) {
		return true;
	}
	else if (rhs.endCount == 0 && endCount == 0 && rhs.startCount == startCount && word < rhs.word){
		return true;
	}
	else {
		return false;
	}
}