#ifndef BASE_NODE
#define BASE_NODE



template <typename T>
class BaseNode abstract
{
protected:
	T _value;
public:
	BaseNode() = default;
	virtual ~BaseNode() = default;
	virtual void setValue(T value) = 0;
	virtual T getValue() = 0;
};

template <typename T>
class INext abstract
{
public:
	BaseNode<T>* _next = nullptr;
	INext() = default;
	virtual ~INext() = default;
	virtual BaseNode<T>* getNext() = 0;
	virtual void setNext(BaseNode<T>* next) = 0;
};

template <typename T>
class IPrev abstract
{
public:
	BaseNode<T>* _prev = nullptr;
	IPrev() = default;
	virtual ~IPrev() = default;
	virtual BaseNode<T>* getPrev() = 0;
	virtual void setPrev(BaseNode<T>* next) = 0;
};

#endif // !BASE_NODE