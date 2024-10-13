#ifndef BASE_OP
#define BASE_OP

template <typename T>
class BaseAddingOperations abstract
{
public:
	virtual void push_back(T value) = 0;
	virtual void push_front(T value) = 0;
	virtual void insert(T value, size_t index) = 0;
};

template <typename T>
class BaseRemovingOperations abstract
{
public:
	virtual void pop_front() = 0;
	virtual void pop_back() = 0;
	virtual void erase(size_t index) = 0;
	virtual void remove(T value) = 0;
	virtual void print() = 0;
};

#endif // !BASE_OP