#ifndef ABSTRACT_BAG_HPP
#define ABSTRACT_BAG_HPP

template <typename T>
class AbstractBag{
	public:
		
		//add an item to the bag
		virtual bool add(const T & item) = 0;

		//remove an item
		virtual bool remove(const T & item) = 0;

		//check is the bag empty
		virtual bool isEmpty() const = 0;

		//get number of items in the bag
		virtual std::size_t getCurrentSize() const = 0;

		//clear the bag contents
		virtual void clear() = 0;

		//count how many time item occurs in bag
		virtual std::size_t getFrequencyOf(const T & item) const = 0;

		//check if item is in the bag
		virtual bool contains(const T & item) const = 0;
};

#endif 