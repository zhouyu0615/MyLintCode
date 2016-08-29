#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


class Solution {
public:
	/**
	* @param s: A string s
	* @param dict: A dictionary of words dict
	*/
	bool wordBreak(string s, unordered_set<string> &dict) {
		// write your code here
		int size = s.length();
		vector<int> flag;
		
		flag.assign(size+1, 0);

		int maxLen = GetMaxDictLen(dict);
		flag[0] = 1;
		for (int i = 0; i < size;i++)
		{
			
			if (flag[i])
			{
				for (int len = 1; i + len - 1 < size&&len<=maxLen;len++)
				{
					if (dict.count(s.substr(i,len))>0)
					{
						flag[i + len] = 1;
					}
				}
			}
		}	
		return flag[size];
	}


private:
	int GetMaxDictLen(unordered_set<string> &dict)
	{
		int maxLen = 0;
		
		unordered_set<string>::iterator pI;
		pI = dict.begin();
		for (pI = dict.begin(); pI != dict.end();++pI)
		{
			maxLen = Max(pI->size(), maxLen);
		}
		return maxLen;
	}
	inline int Max(int a, int b){ return a > b ? a : b; };
};


int main()
{

	getchar();
	return 0;
}