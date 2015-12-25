#include <stack>
#include <cassert>
#include <iostream>


void sort(std::stack<int>& st)
{
	std::stack<int> tmpStack;

	while (!st.empty())
	{
		int nTmp = st.top();
		st.pop();

		while (!tmpStack.empty () && tmpStack.top() > nTmp)
		{
			int n = tmpStack.top();
			tmpStack.pop();
			st.push(n);
		}
		tmpStack.push(nTmp);
	}
	
	while (!tmpStack.empty())
	{
		int n = tmpStack.top();
		tmpStack.pop();

		st.push(n);
	}
}


void main()
{
	std::stack<int> stack;

	stack.push(100);
	stack.push(101);
	stack.push(99);
	stack.push(88);
	stack.push(200);


	sort(stack);

	assert(stack.top() == 88);
	stack.pop();
	assert(stack.top() == 99);
	stack.pop();
	assert(stack.top() == 100);
	stack.pop();
	assert(stack.top() == 101);
	stack.pop();
	assert(stack.top() == 200);
	stack.pop();

	std::cout << "End!" << std::endl;

}