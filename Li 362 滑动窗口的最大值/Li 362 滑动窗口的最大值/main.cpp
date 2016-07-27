#include <iostream>
#include <vector>
#include <queue>


using namespace std;

class Solution {
public:
	/**
	* @param nums: A list of integers.
	* @return: The maximum number inside the window at each moving.
	*/
	vector<int> maxSlidingWindow(vector<int> &nums, int k) {
		// write your code here
		vector<int> result;
		deque<int> IndexQueue;

		int len = nums.size();

		if (k>nums.size()||k==0)
		{
			return result;
		}

		for (int i = 0; i < k;i++)
		{

			while (!IndexQueue.empty()&&nums[i]>=nums[IndexQueue.back()])
			{
				IndexQueue.pop_back();
			}
			IndexQueue.push_back(i);
		}

		for (int i = k; i < len;i++)
		{

			result.push_back(nums[IndexQueue.front()]);

			while (!IndexQueue.empty()&&nums[i]>=nums[IndexQueue.back()])
			{
				IndexQueue.pop_back();
			}

			while (!IndexQueue.empty()&&IndexQueue.front()<=(i-k))
			{
				IndexQueue.pop_front();
			}
			IndexQueue.push_back(i);
		}
		result.push_back(nums[IndexQueue.front()]);
		
		return result;
	}
};


int main()
{

	getchar();
	return 0;
}