#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution2 {
public:
	/**
	* @param nums: A list of integers
	* @return an integer
	*/
	int longestConsecutive(vector<int> &num) {
		// write you code here

		int len = num.size();

		
		int maxVal = num[0];
		int minVal = num[0];

		for (int i = 0; i < len;i++)
		{
			maxVal = Max(maxVal, num[i]);
			minVal = Min(minVal, num[i]);
		} 

		long long diff = (long long)maxVal - minVal;
		vector<int> flag;

		flag.assign((diff/32+1),0);
	
		for (int i = 0; i < len;i++)
		{
			long long diffval =(long long) num[i] - minVal;
			int pos = diffval/ 32;
			int bitPos = diffval% 32;
			flag[pos] |= (1<<bitPos);
		}

		int result = 0;
		int count = 0;
		for (int i = 0; i < flag.size();i++)
		{
			if (flag[i]==0)
			{
				count = 0;
				continue;
			}
			else
			{
				for (int j = 0; j < 32;j++)
				{
					if (flag[i]&(1<<j))
					{
						count++;
						result = Max(result, count);
					}
					else
					{
						count = 0;
					}
				}
			}
		}		
		return result;
	}

private:
	inline int Min(int a, int b)
	{
		return a < b ? a : b;
	}

	inline int Max(int a, int b)
	{
		return a > b ? a : b;
	}
};




class Solution {
public:
	/**
	* @param nums: A list of integers
	* @return an integer
	*/
	int longestConsecutive(vector<int> &num) {
		// write you code here

		int len = num.size();
		map<int,int> CountMap; //key为num[i]值，val 出子序列中的排序个数

		for (int i = 0; i < len;i++)
		{
			CountMap[num[i]] = 1;
		}

		map<int, int>::iterator pIter ;
		map<int, int>::iterator pTemp;
		int result = 0;
		for (pIter = CountMap.begin(); pIter != CountMap.end();++pIter)
		{
			pTemp = CountMap.find((pIter->first - 1));
			if (pTemp!=CountMap.end())
			{
				pIter->second = CountMap.find((pIter->first - 1))->second + 1;
			}
			result = Max(result, pIter->second);
		}
		
		return result;
	}


private:
	inline int Max(int a, int b)
	{
		return a > b ? a : b;
	}
};


int main()
{

	Solution testCase;
	vector<int> nums= {2147483646, -2147483647, 0, 2, 2147483644, -2147483645, 2147483645};

	cout<<testCase.longestConsecutive(nums)<<endl;

	getchar();
	return 0;
}