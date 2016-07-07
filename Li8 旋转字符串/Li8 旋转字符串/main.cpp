#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	/**
	* @param str: a string
	* @param offset: an integer
	* @return: nothing
	*/
	void rotateString(string &str, int offset){
		//wirte your code here

		int len = str.size();
		if (len==0)
		{
			return;
		}

		offset = offset%len;

		rotate(str, 0, len - 1);
		
		rotate(str, 0, offset-1);
		rotate(str, offset, len - 1);
		return;
	}
private:
	void rotate(string &str,int start, int end)
	{

		while (start<end)
		{
			char temp = str[start];
			str[start] = str[end];
			str[end] = temp;

			start++;
			end--;
		}
		return;
	}
};



int main()
{
	getchar();
	return 0;
}
