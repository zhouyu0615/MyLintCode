#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

class Solution {
public:
	/*
	* param k : description of k
	* param nums : description of array and index 0 ~ n-1
	* return: description of return
	*/
	int kthLargestElement(int k, vector<int> nums) {
		// write your code here	
		int len = nums.size();
		if (len < k||len==0)
		{
			return -1;
		}

		int maxNum = 0;
		int maxNumIndex = 0;
		for (int i = 0; i <k;i++) //½øÐÐKÌË²éÕÒ//
		{
			maxNum = nums[i];
			maxNumIndex = i;
			for (int j = i; j < len;j++)
			{
				if (nums[j]>maxNum)
				{
					maxNum = nums[j];
					maxNumIndex = j;
				}
			}
			swap(nums[i], nums[maxNumIndex]);
		}
		return nums[k - 1];
	}
	
private:
	void swap(int&a, int &b)
	{
		if (a==b)
		{
			return;
		}
		int temp = a;
		a=b;
		b = temp;
	}
};


class Solution2 {
public:
	/*
	* param k : description of k
	* param nums : description of array and index 0 ~ n-1
	* return: description of return
	*/
	int kthLargestElement(int k, vector<int> nums) {
		// write your code here
		priority_queue<int, vector<int>, greater<int>> priQueue;

		int len = nums.size();

		if (k>len)
		{
			return -1;
		}

		for (int i = 0; i < len;i++)
		{
			if (priQueue.size()<k)
			{
				priQueue.push(nums[i]);
			}
			else
			{
				if (nums[i]>priQueue.top())
				{
					priQueue.pop();
					priQueue.push(nums[i]);
				}				
			}
		}
		return priQueue.top();
	}
};



int main()
{


	getchar();
	return 0;
}