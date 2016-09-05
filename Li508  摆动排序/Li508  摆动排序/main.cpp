#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class Solution {
public:
	/**
	* @param nums a list of integer
	* @return void
	*/
	void wiggleSort(vector<int>& nums) {
		// Write your code here

		sort(nums.begin(), nums.end());

		int len = nums.size();
		for (int i = 1; i < nums.size();)
		{
			if (i<(nums.size()-1))
			{
				Swap(nums[i], nums[i + 1]);
			}
			i = i + 2;
		}
		return;
	}
private:
	void Swap(int &a, int &b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
};


int main()
{
	getchar();
	return 0;
}