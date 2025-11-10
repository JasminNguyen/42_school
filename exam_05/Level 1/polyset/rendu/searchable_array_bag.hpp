#ifndef SEARCHABLE_ARRAY_BAG
#define SEARCHABLE_ARRAY_BAG

#include "array_bag.hpp"
#include "searchable_bag.hpp"

class searchable_array_bag: public array_bag, public searchable_bag {

	public:
		bool has(int i) const
		{
			for(int index = 0; index < size; index++)
			{
				if(data[index] == i)
				{
					return true;
				}
			}
			return false;
		}
};


#endif