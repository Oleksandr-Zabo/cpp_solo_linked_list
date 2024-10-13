#ifndef SOLO_LIST_H
#define SOLO_LIST_H

#include "base_solo_linked_list.h"

template <typename T>
class SoloLinkedList : public BaseLinkedList<T>
{
public:
	SoloLinkedList() = default;
	~SoloLinkedList()
	{
		if (this->getHead() != nullptr)
		{
			delete this->_head;
		}
		if (this->_tail != nullptr)
		{
			delete this->_tail;
		}
	}

	//From BaseAddingOperations
	void push_back(T value) override
	{
		BaseSoloLinkedListNode<T>* newNode = new SoloLinkedListNode<T>(value);
		if (this->_head == nullptr)
		{
			this->_head = newNode;
			this->_tail = newNode;
		}
		else
		{
			this->_tail->setNext(newNode);
			this->_tail = newNode;
		}
	}

	void push_front(T value) override
	{
		SoloLinkedListNode<T>* newNode = new SoloLinkedListNode<T>(value);
		if (this->_head == nullptr)
		{
			this->_head = newNode;
			this->_tail = newNode;
		}
		else
		{
			newNode->setNext(this->_head);
			this->_head = newNode;
		}
	}

	void insert(T value, size_t index) override
	{
		BaseSoloLinkedListNode<T>* newNode = new SoloLinkedListNode<T>(value);
		BaseSoloLinkedListNode<T>* current = this->_head;
		BaseSoloLinkedListNode<T>* previous = nullptr;
		size_t i = 0;
		while (current != nullptr && i < index)
		{
			previous = current;
			current = current->get_next();
			i++;
		}
		if (current == nullptr)
		{
			this->_tail->setNext(newNode);
			this->_tail = newNode;
		}
		else if (previous == nullptr)
		{
			newNode->setNext(this->_head);
			this->_head = newNode;
		}
		else
		{
			previous->setNext(newNode);
			newNode->setNext(current);
		}
	}

	//From BaseRemovingOperations
	void pop_front() override
	{
		if (this->_head == nullptr)
		{
			return;
		}
		BaseSoloLinkedListNode<T>* temp = this->_head;
		this->_head = this->_head->get_next();
		temp->setNext(nullptr);
		delete temp;
	}

	void pop_back() override
	{
		if (this->_head == nullptr)
		{
			return;
		}
		BaseSoloLinkedListNode<T>* current = this->_head;
		BaseSoloLinkedListNode<T>* previous = nullptr;
		while (current->getNext() != nullptr)
		{
			previous = current;
			current = current->get_next();
		}
		if (previous == nullptr)
		{
			this->_head = nullptr;
			this->_tail = nullptr;
		}
		else
		{
			previous->setNext(nullptr);
			this->_tail = previous;
		}
		delete current;
	}

	void erase(size_t index) override
	{
		BaseSoloLinkedListNode<T>* current = this->_head;
		BaseSoloLinkedListNode<T>* previous = nullptr;
		size_t i = 0;
		while (current != nullptr && i < index)
		{
			previous = current;
			current = current->get_next();
			i++;
		}
		if (current == nullptr)
		{
			return;
		}
		if (previous == nullptr)
		{
			this->_head = this->_head->get_next();
			current->setNext(nullptr);
			delete current;
		}
		else
		{
			previous->setNext(current->getNext());
			current->setNext(nullptr);
			delete current;
		}
	}

	void remove(T value) override
	{
		BaseSoloLinkedListNode<T>* current = this->_head;
		BaseSoloLinkedListNode<T>* previous = nullptr;
		while (current != nullptr && current->getValue() != value)
		{
			previous = current;
			current = current->get_next();
		}
		if (current == nullptr)
		{
			return;
		}
		if (previous == nullptr)
		{
			this->_head = this->_head->get_next();
			current->setNext(nullptr);
			delete current;
		}
		else
		{
			previous->setNext(current->get_next());
			current->setNext(nullptr);
			delete current;
		}
	}

	//Setter and Getter
	BaseSoloLinkedListNode<T>* getHead() override
	{
		return this->_head;
	}

	BaseSoloLinkedListNode<T>* getTail() override
	{
		return this->_tail;
	}

	void setHead(BaseSoloLinkedListNode<T>* head) override
	{
		this->_head = head;
	}

	void setTail(BaseSoloLinkedListNode<T>* tail) override
	{
		this->_tail = tail;
	}

	//Methods
	void print() override
	{
		BaseSoloLinkedListNode<T>* current = this->_head;
		while (current != nullptr)
		{
			std::cout << current->getValue() << " ";
			current = current->get_next();
		}
		cout << endl;
	}

};

#endif // !LIST_H