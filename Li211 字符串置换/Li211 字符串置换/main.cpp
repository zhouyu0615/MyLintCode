#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
	/**
	* @param A a string
	* @param B a string
	* @return a boolean
	*/
	bool stringPermutation(string& A, string& B) {
		// Write your code here

		if (A.length()!=B.length())
		{
			return false;
		}
		vector<int> charFlag;
		charFlag.assign(256, 0);
		for (int i = 0; i < A.length();i++)
		{
			charFlag[A[i]]++;
		}

		for (int i = 0; i < B.length();i++)
		{
			charFlag[B[i]]--;
		}

		for (int i = 0; i < charFlag.size();i++)
		{
			if (charFlag[i]!=0)
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