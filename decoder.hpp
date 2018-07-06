#ifndef DECODER__HPP
#define DECODER__HPP

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

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
	void setMessage(const std::string &m);
	void swapLetters(int a, int b);
	// Dictionary
	void addWordToDict(const std::string &w);
	bool dictContainsWord(const std::string &w) const;
	// Letter Pool
	void addLetterToPool(char l);
	bool isLetterInPool(char l) const;
	void removeLetterFromPool(char l);
	void generateLetterPool(const std::string &m);
	// Solutions
	std::vector<std::string> getSolutions() const;
	void recursivelySolve();
};
#endif