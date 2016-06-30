#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
	/**
	* @param nums: A list of integers
	* @return: A integer indicate the sum of max subarray
	*/
	int maxSubArray(vector<int> nums) {
		// write your code here
		if (nums.size()==0)
		{
			return -0x7fffffff;
		}
		vector<int> DpSum;
		int len = nums.size();

		DpSum.assign(len, 0);

		DpSum[0] = nums[0];
		
		for (int i = 1; i < len;i++)
		{
			DpSum[i] = Max(DpSum[i - 1] + nums[i], nums[i]);
		}
		
		int maxVal = -0x7fffffff;

		for (int i = 0; i < len;i++)
		{
			maxVal = Max(DpSum[i], maxVal);
		}
		return maxVal;
	}

private:
	inline int Max(int a, int b)
	{
		return a > b ? a : b;
	}
};



class Solution {
public:
	/**
	* @param nums: A list of integers
	* @return: A integer indicate the sum of max subarray
	*/
	int maxSubArray(vector<int> nums) {
		// write your code here

		int len = nums.size();
		int maxVal = -0x7fffffff;
		if (len==0)
		{
			return  maxVal;
		}
		int sum = nums[0];
		maxVal = Max(sum, maxVal);
		for (int i = 1; i < len;i++)
		{
			if (sum>=0)
			{
				sum += nums[i];
			}
			else
			{
				sum = nums[i];
			}
			maxVal = Max(sum, maxVal);
		}
		
		return maxVal;
	}

private:
	inline int Max(int a, int b)
	{
		return a > b ? a : b;
	}
};


int main()
{

	getchar();
	return 0;
}