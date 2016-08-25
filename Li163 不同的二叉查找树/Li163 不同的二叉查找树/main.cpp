#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
	/**
	* @paramn n: An integer
	* @return: An integer
	*/
	int numTrees(int n) {
		// write your code here
		vector<int> dpSum;
		dpSum.assign(n+1, 0);
		dpSum[0] = 1;
		dpSum[1] = 1;
		for (int i = 2; i <=n;i++)
		{		
			for (int j = 0; j <=i - 1;j++)
			{
				dpSum[i] += dpSum[j] * dpSum[i - j - 1];
			}
		}
		return dpSum[n];
	}
};


int main()
{
	Solution testCase;

	cout<<testCase.numTrees(5)<<endl;

	getchar();
	return 0;
}