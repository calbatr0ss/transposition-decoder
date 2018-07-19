#include <fstream>
#include <map>
#include "decoder.hpp"
#include "transpoNode.hpp"

int main(int argc, char *argv[])
{
	if (argc <= 1)
	{
		std::cout << "Error: Please specify a dictionary filename." << std::endl;
		exit(1);
	}
	std::string filename = argv[1];

	Decoder *decoder = new Decoder();

	// Read the file.
	std::ifstream file;
	file.open(filename);
	if (!file)
	{
		std::cout << "Error opening file." << std::endl;
		return -1;
	}
	// Fill the dictionary.
	std::string w;
	while (file >> w)
	{
		decoder->addWordToDict(w);
	}
	file.close();
	decoder->printDictionary();

	// Set the message to decode. TEMPORARY!
	std::string s;
	std::cout << "Enter a string to decode: ";
	std::cin >> s;
	decoder->setMessage(s);
	decoder->generateLetterPool(s);
	// temp
	/* if (decoder->dictContainsWord(decoder->getMessage()))
	{
		std::cout << "That word is in the dictionary!" << std::endl;
	}
	else
	{
		std::cout << "That word is NOT in the dictionary." << std::endl;
	}

	decoder->generateLetterPool(decoder->getMessage());
	std::cout << decoder->isLetterInPool('a') << std::endl;
	std::cout << decoder->isLetterInPool('b') << std::endl; */

	// TODO Start creating a tree to traverse for the solution

	TranspoNode *root = new TranspoNode();
	// root->setChildren(decoder->getLetterPool());
	// root->printChildren();
	decoder->recursivelySolve(root);

	decoder->printSolutions();
}
