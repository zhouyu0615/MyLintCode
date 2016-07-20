#include <iostream>
#include <queue>
#include <functional>

using namespace std;



class Solution {
public:
	/**
	* @param nums: A list of integers.
	* @return: The median of numbers
	*/
	vector<int> medianII(vector<int> &nums) {
		// write your code here
		vector<int> result;

		for (int i = 0; i < nums.size();i++)
		{
			InsertNum(nums[i]);
			result.push_back(bigQueue.top());
		}
		return result;
	}

private:
	priority_queue<int> bigQueue; //存放前半段的一半数。顶端为最大值
	priority_queue<int, vector<int>, greater<int>> leQueue; //存放后半段的一半数，顶端为最小值

	void InsertNum(int num)
	{
		if ((bigQueue.size()+leQueue.size())%2==1)
		{
			if (bigQueue.size()>0&&num<bigQueue.top())
			{
				bigQueue.push(num);
				num = bigQueue.top();
				bigQueue.pop();
			}
			leQueue.push(num);
		}
		else
		{
			if (leQueue.size()>0 && num > leQueue.top())
			{
				leQueue.push(num);
				num = leQueue.top();
				leQueue.pop();
			}
			bigQueue.push(num);
		}	
	}

};


int main()
{
	Solution testCase;
	
	vector<int> Nums = { 4, 5, 1, 3, 2, 6, 0 };
	vector<int> result=testCase.medianII(Nums);

	for (int i = 0; i < result.size();i++)
	{
		cout << result[i] << " ";
	}

	getchar();
	return 0;
}