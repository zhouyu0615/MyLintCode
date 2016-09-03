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
	vector<vector<int> > subsets(vector<int> &nums) {
		// write your code here
		sort(nums.begin(), nums.end());
		
		result.push_back(temp);
		AddSets(nums, 0);
	
		return result;
	}
private:
	vector<vector<int>> result;
	vector<int> temp;

	void AddSets(vector<int> &nums, int start)
	{	
		if (start==nums.size())
		{
			return;
		}
		
		for (int i = start; i < nums.size();i++)
		{
			temp.push_back(nums[i]);
			result.push_back(temp);
			AddSets(nums, i + 1);
			temp.pop_back();
		}
	}
};


class Solution2 {
public:
	/**
	* @param S: A set of numbers.
	* @return: A list of lists. All valid subsets.
	*/
	vector<vector<int> > subsets(vector<int> &nums) {
		// write your code here
		sort(nums.begin(), nums.end());
		
		

		result.push_back(temp);

		for (int i = 0; i < nums.size();i++)
		{
			AddSets(nums[i]);
		}
		return result;
	}
private:
	vector<vector<int>> result;
	vector<int> temp;
	void AddSets(int num)
	{
		int len = result.size();
		for (int i = 0; i < len;i++)
		{
			temp = result[i];
			temp.push_back(num);
			result.push_back(temp);
		}
	}

};


int main()
{
	getchar();
	return 0;
}