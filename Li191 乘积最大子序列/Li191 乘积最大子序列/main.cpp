#include <iostream>
#include <vector>

using namespace std;




class Solution {
public:
	/**
	* @param nums: a vector of integers
	* @return: an integer
	*/
	int maxProduct(vector<int>& nums) {
		// write your code here
		int len = nums.size();
		
		if (len==0){
			return 0;
		}
		if (len==1){
			return nums[0];
		}

		vector<long long> MinVec;
		vector<long long> MaxVec;

		MinVec.assign(len, 0);
		MaxVec.assign(len, 0);

		MinVec[0] = nums[0];
		MaxVec[0] = nums[0];
		long long result = nums[0];

		for (int i = 1; i < len;i++)
		{
			MinVec[i] = Min(nums[i], Min(MaxVec[i-1] * nums[i], MinVec[i-1]*nums[i]));
			MaxVec[i] = Max(nums[i], Max(MaxVec[i-1] * nums[i], MinVec[i-1] * nums[i]));

			result = Max(MaxVec[i], result);
		}
		
		return result;
	}

private:
	inline long long Max(long long a, long long b)
	{
		return a > b ? a : b;
	}

	inline long long Min(long long a, long long b)
	{
		return a <b ? a : b;
	}
};

int main()
{
	Solution testCase;


	getchar();
	return 0;
}