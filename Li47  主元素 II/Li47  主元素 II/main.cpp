#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
	/**
	* @param nums: A list of integers
	* @return: The majority number occurs more than 1/3.
	*/
	int majorityNumber(vector<int> nums) {
		// write your code here
		int len = nums.size();
		if (len == 0) return -1;
		if (len<=2)
		{
			return nums[0];
		}

		int count1 = 0, count2 = 0;
		int num1 = nums[0], num2 = nums[1];
		for (int i = 0; i < nums.size();i++)
		{
			if (num1==nums[i])
			{
				count1++;
			}
			else if (num2 == nums[i])
			{
				count2++;
			}
			else if (count1==0)
			{
				num1 = nums[i];
				count1 = 1;
			}else if (count2==0)
			{
				num2 = nums[i];
				count2 = 1;
			}
			else
			{
				count1--;
				count2--;
			}
		}

		count1 = count2=0;

		for (int i = 0; i < len;i++)
		{
			if (nums[i]==num1)
			{
				count1++;
			}else if (nums[i]==num2)
			{
				count2++;
			}
		}

		if (count1>len/3)
		{
			return num1;
		}
		else
		{
			return num2;
		}
	}
};


int main()
{


	getchar();
	return 0;
}