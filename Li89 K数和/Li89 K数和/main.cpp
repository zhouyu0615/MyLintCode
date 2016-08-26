#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution2 {
public:
	/**
	* @param A: an integer array.
	* @param k: a positive integer (k <= length(A))
	* @param target: a integer
	* @return an integer
	*/
	int kSum(vector<int> A, int k, int target) {
		// wirte your code here
		sort(A.begin(), A.end());

	    find(A, 0, k, target);
		
		return count;
	}

private:
	int count = 0;
	
	void find(vector<int>&Nums, int start, int k, int target)
	{
		if (k==0&&target==0)
		{
			count++;
			return;
		}
		if (k==0||target<0)
		{
			return;
		}

		if (target<Nums[start])
		{
			return;
		}

		for (int i = start; i < Nums.size();i++)
		{
			target = target - Nums[i];
			find(Nums, i + 1, k-1, target);
			target += Nums[i];
		}
		return;
	}
};



class Solution {
public:
	/**
	* @param A: an integer array.
	* @param k: a positive integer (k <= length(A))
	* @param target: a integer
	* @return an integer
	*/
	int kSum(vector<int> A, int k, int target) {
		// wirte your code here

		vector<vector<int>> dpNums;
		dpNums.assign(k + 1, vector<int>(target + 1, 0));

		dpNums[0][0] = 1;
		
		for (int i = 1; i <= A.size(); i++)
		{
			for (int j = k; j >=1;j--)
			{
				for (int temp = target; temp >= A[i-1];temp--)
				{
					dpNums[j][temp] += dpNums[j-1][temp - A[i-1]];
				}				
			}
		}
		return dpNums[k][target];
	}
};


int main()
{

	Solution testCase;

	vector<int> nums = { 1, 2, 3, 4 };
	int k = 2;
	int target = 5;

	cout << testCase.kSum(nums, k, target)<<endl;


	getchar();
	return 0;
}