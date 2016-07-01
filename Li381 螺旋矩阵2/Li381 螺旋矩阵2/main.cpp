#include <iostream>
#include <vector>

using  namespace std;




class Solution {
public:
	/**
	* @param n an integer
	* @return a square matrix
	*/
	vector<vector<int>> generateMatrix(int n) {
		// Write your code here
		int len = n;
		vector<vector<int>> result;
		result.assign(len, vector<int>(len, 0));
		int index = 0;
		int startVal = 1;
		while (len>0)
		{
			startVal = FillSqure(result, startVal, index, len);
			index++;
			len-=2;
		}
		return result;
	}
private:
	int FillSqure(vector<vector<int>>& result, int startVal, const int startPos, int len)
	{
		for (int i = startPos; i < startPos + len;i++)
		{
			result[startPos][i] = startVal++;
		}

		for (int i = startPos + 1; i < startPos + len;i++)
		{
			result[i][startPos + len - 1] = startVal++;
		}

		for (int i = startPos + len - 2; i >= startPos;i--)
		{
			result[startPos + len - 1][i] = startVal++;
		}

		for (int i = startPos + len - 2; i > startPos;i--)
		{
			result[i][startPos] = startVal++;
		}
		return startVal;
	}
};




int main()
{
	Solution testCase;
	
	vector<vector<int>> result = testCase.generateMatrix(3);
	


	getchar();
	return 0;
}