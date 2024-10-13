#ifndef BASE_SOLO_LINKED_LIST
#define BASE_SOLO_LINKED_LIST

#include "solo_linked_list_node.h"
#include "base_operations.h"

template <typename T>
class BaseLinkedList abstract : public BaseAddingOperations<T>, public BaseRemovingOperations<T>
{
protected:
	BaseSoloLinkedListNode<T>* _head = nullptr;
	BaseSoloLinkedListNode<T>* _tail = nullptr;
public:
	//Getters and setters
	virtual void setHead(BaseSoloLinkedListNode<T>* head) = 0;
	virtual void setTail(BaseSoloLinkedListNode<T>* tail) = 0;
	virtual BaseSoloLinkedListNode<T>* getHead() = 0;
	virtual BaseSoloLinkedListNode<T>* getTail() = 0;

	//Methods
	virtual void print() = 0;
};

#endif