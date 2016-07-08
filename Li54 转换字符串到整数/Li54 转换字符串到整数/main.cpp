#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	/**
	* @param str: A string
	* @return An integer
	*/
	int atoi(string str) {
		// write your code here
		long long Num = 0;

		if (str.length()==0||str[0]=='\0')
		{
			return 0;
		}

		int index = 0;
		bool minus = false;

		while (str[index] == ' ')
		{
			index++;
		}
		if (str[index]=='+')
		{
			index++;
		}
		else if (str[index]=='-')
		{
			minus = true;
			index++;
		}
		


		while (index<str.length())
		{
			if (str[index]>='0'&&str[index]<='9')
			{
				Num = Num * 10 + (str[index] - '0');

				if ((!minus)&&Num>(long long)0x7fffffff)
				{
					Num = 0x7fffffff;
					return 0x7fffffff;
				}
				else if (minus&&(Num>=(long long)0x80000000))
				{
					Num = -0x80000000;
					return Num;
				}
			}
			else
			{
				break;
			}
			index++;
		}
		
		Num = (minus ? -Num : Num);
		return (int)Num;
	}
};



int main()
{

	Solution testCase;

	cout << testCase.atoi("-1")<<endl;

	getchar();
	return 0;
}