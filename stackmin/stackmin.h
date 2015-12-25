template <class T>
class stackmin
{
	class Node
	{
	private: 
		T data;
	public:
		Node(T t)
		{
			data = t;			
		}
		T GetData()
		{
			return data;
		}
		Node* next;
	};
private:
	Node* top;
	Node* min;

public:
	stackmin()
	{
		top = nullptr;
		min = nullptr;
	}

	void push(T t)
	{
		Node* p = new Node(t);
		if (p == nullptr)
			throw "No memory!";
		p->next = top;
		top = p;
		if (min == nullptr || t < min->GetData())
			min = p;		
	}

	T pop()
	{
		if (top == nullptr)
			throw "empty stack";

		T tmp = top->GetData();
		Node* tmpptr = top;
		top = top->next;
	
		if (min == tmpptr)
		{  // we need to iterate through the list to find the min
			min = FindMin();
		}

		delete tmpptr;
		return tmp;
	}

	T getMin()
	{
		if (min == nullptr)
			throw "empty stack";

		return min->GetData ();
	}


	Node* FindMin()
	{
		Node* pMin = top;
		Node* tmp = top;
		while (tmp != nullptr)
		{
			if (tmp->GetData() >= pMin->GetData())
			{
				tmp = tmp->next;
			}
			else
			{
				pMin = tmp;
			}
		}

		return pMin;
	}

};