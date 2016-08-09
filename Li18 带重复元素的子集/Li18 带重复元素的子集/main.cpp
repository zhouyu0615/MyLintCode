#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	/**
	* @param S: A set of numbers.
	* @return: A list of lists. All valid subsets.
	*/
	vector<vector<int> > subsetsWithDup(const vector<int> &S) {
		// write your code here
		
		vector<int> nums = S;
		sort(nums.begin(), nums.end());

		DfsAdd(nums, 0);
		return result;
	}

private:
	vector<vector<int>> result;
	vector <int>  temp;

	void DfsAdd(const vector<int> &nums, int start)
	{
		if (temp.size() <= nums.size())
		{
			result.push_back(temp);
		}
		for (int i = start; i < nums.size(); i++)
		{
			if (i > start && nums[i] == nums[i - 1])
			{
				continue;
			}
			temp.push_back(nums[i]);
			DfsAdd(nums, i + 1);
			temp.pop_back();
		}
	}
};



int main()
{

	getchar();
	return 0;
}