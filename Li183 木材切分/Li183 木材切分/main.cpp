#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
	/**
	*@param L: Given n pieces of wood with length L[i]
	*@param k: An integer
	*return: The maximum length of the small pieces.
	*/
	int woodCut(vector<int> L, int k) {
		// write your code here
		long long sum = 0;
		int len = L.size();
		int max = 0;
		for (int i = 0; i < len;i++)
		{
			sum += L[i];
			max = (L[i]>max ? L[i] : max);
		}
		if (sum < k) return 0;

		long long  low = 1;
		long long  high = max;
		long long  mid = 0;
		while (low<=high)
		{
			mid = (low + high) / 2;
			if (isValid(L,k,mid))
			{
				low = mid+1;
			}
			else
			{
				high = mid-1;
			}
		}
		return high;
	}
private:
	int isValid(vector<int>& Nums, int k, long long target)
	{
		  int count = 0;
		  for (int i = 0; i < Nums.size();i++)
	      {
			  count += Nums[i] / target;
	      }
		  return count >= k ? true : false;
	}
};



int main()
{

	vector<int> nums = { 2147483644, 2147483645, 2147483646, 2147483647 };
	int k = 4;

	Solution testCase;

	cout << testCase.woodCut(nums, k) << endl;

	getchar();
	return 0;
}


