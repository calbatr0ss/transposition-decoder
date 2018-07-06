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

std::vector<TranspoNode *> *TranspoNode::getChildren() const
{
	return children;
}