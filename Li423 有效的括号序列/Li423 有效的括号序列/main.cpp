#include <iostream>
#include <stack>

using namespace std;


class Solution {
public:
	/**
	* @param s A string
	* @return whether the string is a valid parentheses
	*/
	bool isValidParentheses(string& s) {
		// Write your code here
		stack<char> vaildStack;

		if (s.length() == 0 ) return  true;

	
		for (int i = 0; i < s.length();i++)
		{
			if (vaildStack.empty())
			{
				vaildStack.push(s[i]);
				continue;
			}
			if (isCouple(vaildStack.top(),s[i]))
			{
				vaildStack.pop();			
			}
			else
			{
				vaildStack.push(s[i]);
			}
		}
		return vaildStack.empty() ? true : false;
	}

private:
	bool isCouple(char right, char left)
	{
		switch (right)
		{
		case '(':
			return left == ')' ? true : false;
		case '{':
			return left == '}' ? true : false;
		case '[':
			return left == ']' ? true : false;
		default:
			return false;
		}
	}
};

int main()
{

	getchar();
	return 0;
}