#ifndef DECODER__HPP
#define DECODER__HPP

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include "transpoNode.hpp"

class Decoder
{
  private:
	std::string message;
	std::unordered_set<std::string> dictionary;
	std::vector<char> letterPool;
	std::vector<std::string> solutions;

  public:
	Decoder(void);
	// Message
	std::string getMessage(void) const;
	void setMessage(const std::string &);
	void swapLetters(int, int);
	// Dictionary
	void addWordToDict(const std::string &);
	bool dictContainsWord(const std::string &) const;
	// Letter Pool
	void addLetterToPool(char);
	bool isLetterInPool(char) const;
	void removeLetterFromPool(char);
	void generateLetterPool(const std::string &);
	// Solutions
	std::vector<std::string> getSolutions() const;
	void recursivelySolve();
	bool usedAllLetters(const std::vector<TranspoNode *> &) const;
};
#endif