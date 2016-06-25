#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	/**
	* @param n: An integer.
	* return : An array storing 1 to the largest number with n digits.
	*/
	vector<int> numbersByRecursion(int n) {
		// write your code here
		if (n == 0)
		{
			vector<int> temp;
			return temp;
		}
		CreateNumbers(1, n);
		return result;
	}
private:
	vector<int> result ;
	void CreateNumbers(int curN, int n)
	{
		if (curN>n)
		{
			return;
		}

		if (curN==1)
		{
			result = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		}
		else
		{
			int len = result.size();
			for (int i = len - 9*(pow(10,curN-1)); i < len; i++)
			{
				for (int j = 0; j < 10;j++)
				{
					result.push_back(result[i] * 10 + j);
				}
			}
		}
		CreateNumbers(curN + 1, n);
		return;
	}
};

int main()
{
	Solution testCase;
    vector<int> result=testCase.numbersByRecursion(2);
	
	for (int i = 0; i < result.size();i++)
	{
		cout << result[i] << " ";
	}


	getchar();
	return 0;
}