#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	/**
	* @param board: A list of lists of character
	* @param word: A string
	* @return: A boolean
	*/
	bool exist(vector<vector<char> > &board, string word) {
		// write your code here
		row = board.size();
		if (row == 0) return false;
		col = board[0].size();

		if (row*col<word.size())
		{
			return false;
		}

		targetWord = word;
		Visited.assign(row, vector<bool>(col, false));
		result = false;


		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col;j++)
			{
				if (targetWord[0]==board[i][j])
				{
					DfsBackTrack(board, i, j, "");
				}
				if (result==true)
				{
					return result;
				}
			}
		}
		return result;
	}


private:
	vector<vector<bool>> Visited;
	int row, col;
	bool result;
	string targetWord;

	void DfsBackTrack(vector<vector<char> > &board, int startRow, int startCol, string word)
	{
		if (word==targetWord)
		{
			result = true;
			return;
		}

		if (startRow<0||startRow>=row||startCol<0||startCol>=col||word.length()>=targetWord.length())
		{
			return;
		}

		if (Visited[startRow][startCol])
		{
			return;
		}

		int directions[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

		word =word+ board[startRow][startCol];
		Visited[startRow][startCol] = true;
		if (word==targetWord.substr(0,word.length()))
		{
			for (int k = 0; k <4;k++)
			{
				DfsBackTrack(board, startRow + directions[k][0], startCol + directions[k][1], word);
				if (result==true)
				{
					return;
				}
			}
		}
		Visited[startRow][startCol] = false;
	}
};



int main()
{



	getchar();
	return 0;
}