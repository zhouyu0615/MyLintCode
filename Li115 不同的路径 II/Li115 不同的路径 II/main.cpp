#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
	/**
	* @param obstacleGrid: A list of lists of integers
	* @return: An integer
	*/
	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		// write your code here
		
		int row = obstacleGrid.size();
		if (row == 0) return 0;
		int col = obstacleGrid[0].size();

		vector<vector<int>> Dpsum;

		Dpsum.assign(row, vector<int>(col, 0));

		for (int i = 0; i < row;i++)
		{
			for (int j = 0; j < col;j++)
			{
				if (obstacleGrid[i][j]==1)
				{
					Dpsum[i][j] = 0;
				}
				else
				{
					if (i==0&&j>=1)
					{
						Dpsum[i][j] = Dpsum[i][j-1];
					}else if (i>=1&&j==0)
					{
						Dpsum[i][j] = Dpsum[i - 1][j];
					}else if (i==0&&j==0)
					{
						Dpsum[i][j] = 1;
					}
					else
					{
						Dpsum[i][j] = Dpsum[i][j - 1] + Dpsum[i - 1][j];
					}
				}
			}
		}
		return Dpsum[row - 1][col - 1];
	}
};



int main()
{

	getchar();
	return 0;
}