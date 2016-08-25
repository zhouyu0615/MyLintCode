#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	/**
	* @param A, B: Two integer arrays.
	* @return: Their smallest difference.
	*/
	int smallestDifference(vector<int> &A, vector<int> &B) {
		// write your code here
		sort(B.begin(), B.end());

		int lenA = A.size();
		int lenB = B.size();

		int minVal = INT_MAX;		
		for (int i = 0; i < lenA;i++)
		{
			int pos = binSearch(B, A[i]);
			minVal = Min(minVal, abs(A[i] - B[pos]));
			if (pos+1<lenB)
			{
				minVal = Min(minVal, abs(A[i] - B[pos + 1]));
			}
			if (minVal==0)
			{
				return minVal;
			}
		}
		return minVal;
	}

private:
	int binSearch(vector<int>& Nums, int target)
	{
		int low = 0;
		int high = Nums.size();
		int mid = (low + high) / 2;
		while (low<high)
		{
			mid = (low + high) / 2;
			if (Nums[mid]>target)
			{
				high = mid -1;
			}else if (Nums[mid]<target)
			{
				low = mid + 1;
			}
			else
			{
				return mid;
			}
		}
	
		if (Nums[mid]<target)
		{
			while (mid < (Nums.size()-1) && Nums[mid]<target)
			{
				mid++;
			}
			return mid;
		}
		else if (Nums[mid] > target)
		{
			while (mid > 0 && Nums[mid]>target)
			{
				mid--;
			}
			return mid;
		}
		else {
			return mid;
		}
		
	

	};
	inline int Min(int a, int b)
	{
		return a < b ? a : b;
	}
};




int main()
{

	vector<int> A = { 1999 };
	vector<int> B = { 5, 10, 19, 112, 100 };

	Solution testCase;

	cout<<testCase.smallestDifference(A, B)<<endl;

	getchar();
	return 0;
}