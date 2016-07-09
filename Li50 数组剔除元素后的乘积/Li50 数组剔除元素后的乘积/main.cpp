#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	/**
	* @param A: Given an integers array A
	* @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
	*/
	vector<long long> productExcludeItself(vector<int> &nums) {
		// write your code here
		int len = nums.size();
		vector<long long> result;
		if (len==0)
		{
			return result;
		}

		vector<long long> vStart, vEnd;
		vStart.assign(len, 1);
		vEnd.assign(len, 1);
		result.assign(len, 1);

		vStart[0] = 1;
		for (int i = 1; i < len;i++)
		{
			vStart[i] = vStart[i - 1] * nums[i-1];
		}

		vEnd[len - 1] = 1;
		for (int i = len - 2; i >= 0;i--)
		{
			vEnd[i] = vEnd[i + 1] * nums[i+1];
		}

		for (int i = 0; i < len;i++)
		{
			result[i] = vStart[i] * vEnd[i];
		}
		return result;
	}
};


int main()
{
	getchar();
	return 0;
}