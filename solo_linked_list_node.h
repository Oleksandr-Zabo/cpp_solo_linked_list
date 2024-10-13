#ifndef SOLO_NODE
#define SOLO_NODE

#include <iostream>
using namespace std;

#include "base_node.h"

template <typename T>
class BaseSoloLinkedListNode : public BaseNode<T>, public INext<T>
{
public:
	BaseSoloLinkedListNode() : BaseNode<T>(), INext<T>()
	{}
	BaseSoloLinkedListNode<T>* get_next()
	{
		return this->_next;
	}
	virtual ~BaseSoloLinkedListNode()
	{
		if (this->_next != nullptr)
		{
			delete this->_next;
		}
	}
	BaseSoloLinkedListNode(T value) : BaseNode<T>(value), INext<T>()
	{}

	
	virtual T getValue() const = 0;
	virtual void setValue(T value) = 0;
	virtual BaseSoloLinkedListNode<T>* get_next() const = 0;
	virtual void setNext(BaseSoloLinkedListNode<T>* next) = 0;
};

template <typename T>
class SoloLinkedListNode : public BaseSoloLinkedListNode<T>
{

private:
	T value;
	BaseSoloLinkedListNode<T>* next;
public:
	SoloLinkedListNode() : BaseSoloLinkedListNode<T>()
	{
	}
	SoloLinkedListNode(T value) : BaseSoloLinkedListNode<T>(value)
	{
	}
	virtual ~SoloLinkedListNode() {
		if (this->getNext() != nullptr)
		{
			delete this->getNext();
		}
	}
	T getValue() const override
	{
		return value;
	}
	void setValue(T value) override
	{
		this->setValue(value);
	}

	BaseSoloLinkedListNode<T>* get_next() const override
	{
		return next;
	}
	
	void setNext(BaseSoloLinkedListNode<T>* next)
	{
		this->setNext(next);
	}
	void print() const
	{
		std::cout << this->_value << std::endl;
	}
};


#endif // !SOLO_NODE
