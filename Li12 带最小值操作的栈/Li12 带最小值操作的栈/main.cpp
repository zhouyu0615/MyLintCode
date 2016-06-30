#include <iostream>
#include <stack>


using namespace std;

class MinStack {
public:
	MinStack() {
		// do initialization if necessary
	}

	void push(int number) {
		// write your code here
		m_Data.push(number);
		if (!m_Min.empty())
		{
			m_Min.push(Min(m_Min.top(), number));
		}
		else
		{
			m_Min.push(number);
		}
		
	}

	int pop() {
		// write your code here	
		m_Min.pop();
		int val = m_Data.top();
		m_Data.pop();
		return val;
	}

	int min() {
		// write your code here
		return m_Min.top();
	}
private:
	stack<int> m_Data;
	stack<int> m_Min;

	inline int Min(int a, int b)
	{
		return a < b ? a : b;
	}

};


int main()
{


	getchar();
	return 0;
}