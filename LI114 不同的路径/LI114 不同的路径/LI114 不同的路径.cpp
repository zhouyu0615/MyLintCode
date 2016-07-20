// LI114 不同的路径.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>
#include<vector>


using namespace std;


class Solution {
public:
	/**
	* @param n, m: positive integer (1 <= n ,m <= 100)
	* @return an integer
	*/
	int uniquePaths(int m, int n) {
		// wirte your code here

		if (m==0||n==0)
		{
			return 0;
		}
		vector<vector<unsigned int>> DpSum;
		DpSum.assign(m, vector<unsigned int>(n, 0));

		DpSum[0][0] = 1;

		for (int row = 0; row < m;row++)
		{
			for (int col = 0; col < n;col++)
			{
				if (row == 0||col==0)
				{
					DpSum[row][col] = DpSum[0][0];
				}
				else
				{
					DpSum[row][col] = DpSum[row - 1][col] + DpSum[row][col - 1];
				}
			}
		}
		return DpSum[m - 1][n - 1];
	}
};



int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

