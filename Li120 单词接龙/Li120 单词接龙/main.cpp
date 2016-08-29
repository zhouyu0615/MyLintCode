#include <iostream>
#include <queue>
#include <map>
#include <unordered_set>
#include <string>


using namespace std;


class Solution {
public:
	/**
	* @param start, a string
	* @param end, a string
	* @param dict, a set of string
	* @return an integer
	*/
	int ladderLength(string start, string end, unordered_set<string> &dict) {
		// write your code here

		if (start==""||end==""||start.length()!=end.length())
		{
			return 0;
		}

		if (start==end)
		{
			return 1;
		}
		map<string, int> DistMap; //key存储路径中string,val为步数。
		queue<string>  strQueue;

		strQueue.push(start);
		string headStr;
		string tempStr;
		DistMap[start] = 1;
		int distStep = 1;
		while (!strQueue.empty())
		{
			headStr = strQueue.front();
			strQueue.pop();
			distStep=DistMap[headStr];
			distStep++;
			for (int i = 0; i < headStr.size();i++)
			{
				tempStr = headStr;
				for (char c = 'a'; c <= 'z';c++)
				{
					tempStr[i] = c;
					if (tempStr==end)
					{
						return distStep;
					}
					if (dict.count(tempStr)>0&&(DistMap.count(tempStr)==0))
					{
						DistMap[tempStr] = distStep;
						strQueue.push(tempStr);
					}
				}
			}
		}

		return 0;
	}

};




int main()
{
	getchar();
	return 0;
}
