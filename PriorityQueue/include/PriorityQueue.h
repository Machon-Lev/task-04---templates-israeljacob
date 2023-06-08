#pragma once

#include <iostream>
#include <list>
#include <exception>
#include<iterator>

template<typename T>
struct MyComparator {
	T operator()(T a, T b) const {
		return a - b;
	}
};

template<typename T>
class PriorityQueue {
   
public:
	~PriorityQueue();
	void push(const T& t); 
	T poll();

private:
	std::list<T> queue;
};


template<typename T>
PriorityQueue<T>::~PriorityQueue()
{
	queue.clear();
}

template<typename T>
void PriorityQueue<T>::push(const T& t)
{
	MyComparator<T> comperator;
	typename std::list<T>::iterator it = queue.begin();
	while (it != queue.end() && comperator(*it, t) < 0) {
		++it;
	}
	queue.insert(it, t);
}

template<typename T>
T PriorityQueue<T>::poll()
{
	if (queue.empty())
		throw std::exception("PriorityQueue empty !");
	T frontElement = queue.front();
	queue.pop_front();
	return frontElement;
}


