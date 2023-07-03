#pragma once

#include <iostream>
#include <list>
#include <exception>
#include <iterator>

template<typename T>
struct MyComparator {
	T operator()(T a, T b) const {
		return a - b;
	}
};

template<typename T>
class PriorityQueue {

public:
	// Destructor
	~PriorityQueue();

	// Push an element into the queue
	void push(const T& t);

	// Remove and return the front element from the queue
	T _poll();

private:
	std::list<T> queue;  // The underlying container for the queue
};


template<typename T>
PriorityQueue<T>::~PriorityQueue()
{
	queue.clear();  
}

template<typename T>
void PriorityQueue<T>::push(const T& t)
{
	MyComparator<T> comparator;
	typename std::list<T>::iterator it = queue.begin();

	// Find the correct position to insert the new element while maintaining the sorted order
	while (it != queue.end() && comparator(*it, t) < 0) {
		++it;
	}

	queue.insert(it, t);
}

template<typename T>
T PriorityQueue<T>::poll()
{
	if (queue.empty())
		throw std::exception("PriorityQueue empty!");

	T frontElement = queue.front();
	queue.pop_front();
	return frontElement;
}
