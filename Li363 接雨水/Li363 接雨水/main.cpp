#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
	/**
	* @param heights: a vector of integers
	* @return: a integer
	*/
	int trapRainWater(vector<int> &heights) {
		// write your code here

		int left = 0;
		int right = heights.size() - 1;
		int result = 0;
		int secHight = 0;

		while (left<right)
		{
			if (heights[left]<heights[right])
			{
				secHight = Max(heights[left], secHight);
				result += secHight - heights[left];
				left++;
			}
			else
			{
				secHight = Max(secHight, heights[right]);
				result += secHight - heights[right];
				right--;
			}
		}
		return result;
	}

private:
	int Max(int a, int b)
	{
		return a>b ? a : b;
	}
};


int main()
{
	Solution testCase;


	getchar();
	return 0;
}