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
	std::unordered_set<std::string>::iterator search = dictionary.find(w);
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

void Decoder::recursivelySolve()
{
	// TODO
}
