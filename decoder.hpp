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
	std::string currentMessage;
	std::unordered_set<std::string> dictionary;
	std::vector<char> letterPool;
	std::vector<std::string> solutions;

  public:
	Decoder(void);
	// Message
	std::string getMessage(void) const;
	void setMessage(const std::string &);
	void swapLetters(int, int);
	// Current Message
	void append(char);
	void pop();
	std::string getCurrentMessage() const;
	void printCurrentMessage() const;
	// Dictionary
	void addWordToDict(const std::string &);
	bool dictContainsWord(const std::string &) const;
	void printDictionary() const;
	// Letter Pool
	void addLetterToPool(char);
	bool isLetterInPool(char) const;
	void removeLetterFromPool(char);
	void generateLetterPool(const std::string &);
	std::vector<char> getLetterPool() const;
	void printLetterPool() const;
	// Solutions
	std::vector<std::string> getSolutions() const;
	void recursivelySolve(TranspoNode *);
	bool usedAllLetters(const std::vector<TranspoNode *> &) const;
	void printSolutions() const;
};
#endif