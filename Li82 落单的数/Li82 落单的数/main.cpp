#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
	/**
	* @param A: Array of integers.
	* return: The single number.
	*/
	int singleNumber(vector<int> &A) {
		// write your code here

		int len = A.size();
		if (len==0)
		{
			return -1;
		}
		int result = A[0];
		for (int i = 1; i < len;i++)
		{
			result = result^A[i];
		}
		return result;
	}
};

int main()
{
	getchar();
	return 0;
}
