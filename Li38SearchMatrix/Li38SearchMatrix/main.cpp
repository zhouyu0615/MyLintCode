#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	/**
	* @param matrix: A list of lists of integers
	* @param target: An integer you want to search in matrix
	* @return: An integer indicate the total occurrence of target in the given matrix
	*/
	int searchMatrix(vector<vector<int> > &matrix, int target) {
		// write your code here

		int count = 0;
		int row = matrix.size();
		if (row == 0) return 0;

		int col = matrix[0].size();

		int i = 0;
		int j = col - 1;
		
		while (i<row&&j>=0)
		{
			if (matrix[i][j]==target)
			{
				count++;
				j--;
				i++;
			}else if (matrix[i][j]>target)
			{
				j--;
			}
			else
			{
				i++;
			}
		}
		return count;
	}
};




int main()
{

	getchar();
	return 0;
}