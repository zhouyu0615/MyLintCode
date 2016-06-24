#include <iostream>
#include <stack>

using namespace std;

class Queue {
public:
	stack<int> stack1;
	stack<int> stack2;

	Queue() {
		// do intialization if necessary
	}

	void push(int element) {
		// write your code here
		stack1.push(element);
	}

	int pop() {
		// write your code here
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		int val = stack2.top();
		stack2.pop();
		return val;
	}

	int top() {
		// write your code here
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		return stack2.top();	
	}
};


int main()
{

	getchar();
	return 0;
}