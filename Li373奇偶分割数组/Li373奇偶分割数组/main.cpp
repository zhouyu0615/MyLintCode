#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	/**
	* @param nums: a vector of integers
	* @return: nothing
	*/
	void partitionArray(vector<int> &nums) {
		int len = nums.size();

		if (len<=1)
		{
			return;
		}

		int i = 0;
		int j = len - 1;
		while (i<j)
		{
			while (i<j&&nums[i]%2!=0)
			{
				i++;
			}
			while (i<j&&nums[j]%2==0)
			{
				j--;
			}

			long long temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
			i++;
			j--;
		}
		return;
	}
};


int main()
{
	vector<int> nums = { 2147483644, 2147483645, 2147483646, 2147483647 };
	Solution testCase;

	testCase.partitionArray(nums);

	for (int i = 0; i < nums.size();i++)
	{
		cout << nums[i] << " ";
	}


	getchar();
	return 0;
}