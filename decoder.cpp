#include "decoder.hpp"

Decoder::Decoder(void) : message("") {}

std::string Decoder::getMessage(void) const
{
	return message;
}

void Decoder::setMessage(const std::string &m)
{
	message = m;
}

void Decoder::swapLetters(int a, int b)
{
	if (a > int(message.length() - 1) || a < 0 || b > int(message.length() - 1) || b < 0)
	{
		std::cout << "Error: Swap index out of range." << std::endl;
		exit(1);
	}
	char temp = message[a];
	message[a] = message[b];
	message[b] = temp;
}

void Decoder::append(char c)
{
	currentMessage += c;
}
void Decoder::pop()
{
	currentMessage.pop_back();
}
std::string Decoder::getCurrentMessage() const
{
	return currentMessage;
}

void Decoder::printCurrentMessage() const
{
	std::cout << "Current Message: " << currentMessage << std::endl;
}

void Decoder::addWordToDict(const std::string &w)
{
	dictionary.insert(w);
}

bool Decoder::dictContainsWord(const std::string &w) const
{
	std::unordered_set<std::string>::const_iterator search = dictionary.find(w);
	return (search != dictionary.end());
}

void Decoder::printDictionary() const
{
	std::cout << "Dictionary:" << std::endl;
	std::unordered_set<std::string>::const_iterator it = dictionary.begin();
	while (it != dictionary.end())
	{
		std::cout << *it << std::endl;
		it++;
	}
}

void Decoder::addLetterToPool(char l)
{
	letterPool.push_back(l);
}

bool Decoder::isLetterInPool(char l) const
{
	std::vector<char>::const_iterator search = letterPool.begin();
	while (search != letterPool.end())
	{
		if (*search == l)
		{
			return true;
		}
		search++;
	}
	return false;
}

void Decoder::removeLetterFromPool(char l)
{

	std::vector<char>::iterator it = letterPool.begin();
	while (it != letterPool.end())
	{
		if (*it == l)
		{
			letterPool.erase(it);
			return;
		}
		it++;
	}
}

void Decoder::generateLetterPool(const std::string &m)
{
	for (unsigned int i = 0; i < m.length(); i++)
	{
		addLetterToPool(m[i]);
	}
}

std::vector<char> Decoder::getLetterPool() const
{
	return letterPool;
}

void Decoder::printLetterPool() const
{
	std::cout << "Letter Pool: [ ";
	for (unsigned int i = 0; i < letterPool.size(); i++)
	{
		std::cout << letterPool[i];
		if (i != letterPool.size() - 1)
		{
			std::cout << ", ";
		}
	}
	std::cout << " ]" << std::endl;
}

std::vector<std::string> Decoder::getSolutions() const
{
	return solutions;
}

// needs access to the tree and pool
void Decoder::recursivelySolve(TranspoNode *node)
{
	printLetterPool();
	node->setChildren(getLetterPool());
	// TODO: Do I need a separate letterPool for each node?
	// Recursion base case
	if (usedAllLetters(node->getChildren()))
	{
		addLetterToPool(node->getLetter());
		pop();
		return;
	}
	// check if string is in the dictionary I guess...
	if (dictContainsWord(getCurrentMessage()))
	{
		solutions.push_back(getCurrentMessage());
	}
	// check for new letter in pool to use
	std::unordered_set<char> child_map;
	std::vector<TranspoNode *>::const_iterator childIt = node->getChildren().begin();
	while (childIt != node->getChildren().end())
	{
		child_map.insert((*childIt)->getLetter());
	}
	std::vector<char>::iterator it = letterPool.begin();
	while (it != letterPool.end())
	{
		std::unordered_set<char>::const_iterator search = child_map.find(*it);
		if (search == child_map.end()) // did not find
		{
			std::cout << "should not be here" << std::endl;
			return;
		}
		removeLetterFromPool(*search);
		append(*search);
		// TranspoNode *n = new TranspoNode(*search, node);
		recursivelySolve(node->getChild(*search)); // recurse
		// after recurse
		addLetterToPool(*search);
		pop();
		it++;
	}
	// recursion over and pool exhausted... climbing back up
	// add letter back to pool
}

bool Decoder::usedAllLetters(const std::vector<TranspoNode *> &children) const
{
	std::unordered_set<char> child_map;
	std::vector<TranspoNode *>::const_iterator childIt = children.begin();
	while (childIt != children.end())
	{
		child_map.insert((*childIt)->getLetter());
	}
	std::vector<char>::const_iterator letterIt = letterPool.begin();
	while (letterIt != letterPool.end())
	{
		std::unordered_set<char>::const_iterator search = child_map.find(*letterIt);
		if (search == child_map.end())
		{
			return false;
		}
		letterIt++;
	}
	return true;
}

void Decoder::printSolutions() const
{
	std::cout << "Solutions:" << std::endl;
	std::vector<std::string>::const_iterator it = solutions.begin();
	while (it != solutions.end())
	{
		std::cout << *it << std::endl;
		it++;
	}
}

/*
	if unique pooled letters are all children
		add current letter
		return
	if string is in dict
		add string to sols
	for l in pooled letters
		if l is not already a child
			remove l from pool
			recurse
			add l back to pool
*/