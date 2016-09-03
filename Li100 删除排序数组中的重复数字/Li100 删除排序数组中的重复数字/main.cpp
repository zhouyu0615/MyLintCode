#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
	/**
	* @param A: a list of integers
	* @return : return an integer
	*/
	int removeDuplicates(vector<int> &nums) {
		// write your code here
		if (nums.size()<=1)
		{
			return nums.size();
		}

		int count = 1;
		for (int i = 1; i < nums.size();i++)
		{
			if (nums[i]==nums[i-1])
			{
				continue;
			}
			else
			{
				nums[count] = nums[i];
				count++;
			}
		}

		nums.erase(nums.begin() + count, nums.end());
		return count;
	}

};

int main()
{



	getchar();
	return 0;
}