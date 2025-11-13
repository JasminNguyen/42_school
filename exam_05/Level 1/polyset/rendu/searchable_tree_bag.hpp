#ifndef SEARCHABLE_TREE_BAG
#define SEARCHABLE_TREE_BAG
#include "tree_bag.hpp"
#include "searchable_bag.hpp"


class searchable_tree_bag: public tree_bag, public searchable_bag {

	public:
		bool has(int i) const
		{
			node *_node = this->tree; //does this automatically start at the top of the tree?
			while(_node)
			{
				if(_node->value == i)
				{
					return true;
				}
				if(_node->value > i)
				{
					_node = _node->l;
				}
				else
				{
					_node = _node->r;
				}
			}
			return false;
		}
};

#endif