#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	/**
	* @param str: a string
	* @return: a boolean
	*/
	bool isUnique(string &str) {
		// write your code here
		char flag[255] = {0};

		for (int i = 0; i < str.length();i++)
		{
			if (flag[str[i]]==0)
			{
				flag[str[i]] = 1;
			}
			else
			{
				return false;
			}
		}
		return true;
	}
};


int main()
{
	getchar();
	return 0;
}