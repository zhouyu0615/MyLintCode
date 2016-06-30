#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	/**
	* @param nums: A list of integers
	* @return: The majority number
	*/
	int majorityNumber(vector<int> nums) {

		if (nums.size()==0)
		{
			return -1;
		}

		int count = 1;
		int majNumber=nums[0];

		for (int i = 0; i < nums.size();i++)
		{
			if (majNumber==nums[i])
			{
				count++;
			}
			else
			{
				count--;
			}
			
			if (count==0)
			{
				majNumber = nums[i];
				count=1;
			}
		}
		return majNumber;
	}
};



int main()
{

	getchar();
	return 0;
}