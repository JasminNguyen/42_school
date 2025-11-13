#ifndef SET_HPP
#define SET_HPP

#include "searchable_bag.hpp"

class set {

		private:
			searchable_bag &bag;
		public:
			//set() {} -> reference member needs to be initialized immediately -> no default constructor
			set(searchable_bag &b): bag(b) {}
			// set(searchable_bag &other): bag(other) {} --> same as constructor so no need for it -> we cannot put const since the bag (int private) is not const
			// set& operator=(const set &other) -> no need for the assignment operator since we don't assign a new thing, instead we handle the exact same object
			// {
			// 	if(this != &other)
			// 	{
			// 		bag = other.bag;
			// 	}
			// 	return *this;
			// }
			~set() {}

			////////////////////
			void insert (int val)
			{	
				if(!bag.has(val))
				{
					bag.insert(val);
				}
			}
			void insert (int *array, int size)
			{
				for(int i = 0; i < size; i++)
				{
					if(!bag.has(array[i]))
					{
						bag.insert(array[i]);
					}
				}
			}
			void print() const
			{
				bag.print();
			}
			void clear()
			{
				bag.clear();
			}
			const searchable_bag& get_bag() const
			{
				return bag;
			}
			bool has(int val) const
			{
				return bag.has(val);
			}
};


#endif