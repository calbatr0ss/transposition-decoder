#ifndef TRANSPONODE__HPP
#define TRANSPONODE__HPP

#include <vector>

class TranspoNode
{
  private:
	char letter;
	TranspoNode *parent;
	std::vector<TranspoNode *> *children;

  public:
	TranspoNode();
	TranspoNode(char);
	TranspoNode(char, TranspoNode *);
	char getLetter() const;
	TranspoNode *getParent() const;
	std::vector<TranspoNode *> *getChildren() const;
};
#endif