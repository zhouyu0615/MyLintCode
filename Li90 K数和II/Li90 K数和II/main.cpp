#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	/**
	* @param A: an integer array.
	* @param k: a positive integer (k <= length(A))
	* @param target: a integer
	* @return a list of lists of integer
	*/
	vector<vector<int> > kSumII(vector<int> A, int k, int target) {
		// write your code here
		if (k>A.size())
		{
			return result;
		}

		finder(A, 0, k, target);
		return result;
	}

	void finder(vector<int>&Nums, int start, int k, int target)
	{
		if (k==0&&target==0)
		{
			result.push_back(temp);
			return;
		}

		if (k==0||target<0)
		{
			return;
		}

		for (int i = start; i < Nums.size();i++)
		{
			if (target<Nums[i])
			{
				return;
			}
			temp.push_back(Nums[i]);
			finder(Nums, i + 1, k - 1, target - Nums[i]);
			temp.pop_back();
		}
		return;
	}

private:
	vector<vector<int>> result;
	vector<int> temp;

};



int main()
{
	getchar();
	return 0;
}