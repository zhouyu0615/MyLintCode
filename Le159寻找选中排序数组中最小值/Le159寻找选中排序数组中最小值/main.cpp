#include <iostream>
#include <vector>


using namespace std;



class Solution {
public:
	/**
	* @param num: a rotated sorted array
	* @return: the minimum number in the array
	*/
	int findMin(vector<int> &num) {
		// write your code here
		int left = 0;
		int right = num.size() - 1;

		if (num[left]<num[right])
		{
			return num[left];
		}
		
		while (left<right)
		{
			int mid = (left + right) / 2;

			if (num[mid]>num[right])
			{
				left = mid+1;
			}
			else
			{
				right = mid;
			}
		}
		return num[left];
	}

	
};


int main()
{

	getchar();
	return 0;
}