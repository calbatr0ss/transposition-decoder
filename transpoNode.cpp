#include "transpoNode.hpp"

TranspoNode::TranspoNode() : letter('\0'),
							 parent(nullptr),
							 children(new std::vector<TranspoNode *>()) {}

TranspoNode::TranspoNode(char l) : letter(l),
								   parent(nullptr),
								   children(new std::vector<TranspoNode *>()) {}

TranspoNode::TranspoNode(char l, TranspoNode *p) : letter(l),
												   parent(p),
												   children(new std::vector<TranspoNode *>()) {}

char TranspoNode::getLetter() const
{
	return letter;
}

TranspoNode *TranspoNode::getParent() const
{
	return parent;
}

std::vector<TranspoNode *> &TranspoNode::getChildren() const
{
	return *(children);
}

void TranspoNode::addChild(char c)
{
	children->push_back(new TranspoNode(c, this));
}

void TranspoNode::setChildren(std::vector<char> vec)
{
	std::vector<char>::iterator it = vec.begin();
	while (it != vec.end())
	{
		addChild(*it);
		it++;
	}
}

TranspoNode *TranspoNode::getChild(char c)
{
	std::vector<TranspoNode *>::iterator it = (*children).begin();
	while (it != (*children).end())
	{
		if ((*it)->getLetter() == c)
		{
			return *it;
		}
		it++;
	}
	return nullptr;
}

void TranspoNode::printChildren() const
{
	std::cout << "Children of TranspoNode(" << ((letter == '\0') ? '^' : letter) << "):";
	std::vector<TranspoNode *>::iterator it = (*children).begin();
	while (it != (*children).end())
	{
		std::cout << " (" << (*it)->getLetter() << ") ";
		it++;
	}
	std::cout << std::endl;
}
