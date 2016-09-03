#include <iostream>
#include <vector>

using namespace std;

class Solution {
	/**
	* param A : an integer sorted array
	* param target :  an integer to be inserted
	* return : an integer
	*/
public:
	int searchInsert(vector<int> &A, int target) {
		// write your code here
		int low = 0;
		int high = A.size();
		if (high==0)
		{
			return 0;
		}
		int mid = 0;
		while (low<=high)
		{
			mid = (low + high) / 2;

			if (target<A[mid])
			{
				high = mid - 1;
			}
			else if (target>A[mid])
			{
				low = mid + 1;
			}
			else
			{
				return mid;
			}
		}

		if (A[low]<target)
		{
			while (A[low]<target&&low<A.size())
			{
				low++;
			}
			return low;
		}else 
		{
			while (A[low]>target&&low>=0)
			{
				low--;
			}
			return low + 1;
		}	
	}
};




int main()
{

	vector<int> nums = { 1, 3, 5, 6 };
	Solution testCase;

	cout<<testCase.searchInsert(nums, 5)<<endl;


	getchar();
	return 0;
}