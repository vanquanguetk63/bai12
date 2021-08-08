#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

template <typename T>
class List;

template <typename T>
class ListNode
{
	friend class List<T>;

public:
	ListNode(T);
	T getData();

private:
	T data;
	ListNode* nextPtr;
};

template <typename T>
ListNode<T>::ListNode(T dataIn)
{
	data = dataIn;
	nextPtr = 0;
}

template <typename T>
T ListNode<T>::getData()
{
	return data;
}

#endif
#endif // NODE_H_INCLUDED
