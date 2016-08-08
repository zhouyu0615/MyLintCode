#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
	/**
	*@param n, m: Two integer
	*@param i, j: Two bit positions
	*return: An integer
	*/
	int updateBits(int n, int m, int i, int j) {
		// write your code here
		long long temp = m;
		temp = m << i;
		for (int k = i; k <= j;k++)
		{
			if (temp&(1<<k))
			{
				n |= (1 << k);
			}
			else
			{
				n &= ~(1 << k);
			}
		}
		return n;
	}
};


int main()
{

	Solution testCase;

	cout << testCase.updateBits(1024, 21, 2, 6)<<endl;

	getchar();
	return 0;
}