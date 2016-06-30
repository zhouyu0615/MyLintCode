#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
	/**
	* @param matrix a matrix of m x n elements
	* @return an integer array
	*/
	vector<int> spiralOrder(vector<vector<int>>& matrix)
	{		
		if (matrix.size()==0)
		{
			return result;
		}
		int row = matrix.size();
		int col = matrix[0].size();

		int colLen = col;
		int rowLen = row;

		int i = 0, j = 0;
		while (rowLen>=0&&colLen>=0)
		{
			spiralAdd(matrix, i, j, rowLen, colLen);
			rowLen-=2;
			colLen-=2;
			i++;
			j++;
			
		}	
		return result;
	}

private:
	vector<int> result;
	void spiralAdd(vector<vector<int>>& matrix, int startRow, int startCol, int rowLen,int colLen)
	{
		
		for (int i = 0; i < colLen; i++)
		{
			result.push_back(matrix[startRow][startCol + i]);
		}
		for (int i = 1; i < rowLen; i++)
		{
			result.push_back(matrix[startRow + i][startCol + colLen-1]);
		}

		if (rowLen!=1)
		{
			for (int i = colLen - 2; i >= 0; i--)
			{
				result.push_back(matrix[startRow + rowLen - 1][startCol + i]);
			}
		}
		if (colLen!=1)
		{
			for (int i = rowLen - 2; i > 0 && ((colLen - 1) != 0); i--)
			{
				result.push_back(matrix[startRow + i][startCol]);
			}
		}		
	}
};


int main()
{

	vector<vector<int>> matrix = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }};

	Solution testCase;
	vector<int> result=testCase.spiralOrder(matrix);

	for (int i = 0; i < result.size();i++)
	{
		cout << result[i] << " ";
	}

	getchar();
	return 0;
}