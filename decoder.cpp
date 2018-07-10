#include "decoder.hpp"

Decoder::Decoder(void)
{
	message = "";
}

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
	if (a > message.length() - 1 || a < 0 || b > message.length() - 1 || b < 0)
	{
		std::cout << "Error: Swap index out of range." << std::endl;
		exit(1);
	}
	char temp = message[a];
	message[a] = message[b];
	message[b] = temp;
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
	for (int i = 0; i < m.length() - 1; i++)
	{
		addLetterToPool(m[i]);
	}
}

std::vector<std::string> Decoder::getSolutions() const
{
	return solutions;
}

// needs access to the tree and pool
void Decoder::recursivelySolve()
{
	// TODO: Do I need a separate letterPool for each node?
	// Recursion base case
	// if (usedAllLetters())
	// {
	// 	// add current node back to pool
	// 	return;
	// }
	// check if string is in the dictionary I guess...
	std::vector<char>::iterator it = letterPool.begin();
	while (it != letterPool.end())
	{
		// create a new node with a char from the pool
		// remove that from the pool
		// recursivelySolve();
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