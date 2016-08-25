#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	/**
	* @param s: The first string
	* @param b: The second string
	* @return true or false
	*/
	bool anagram(string s, string t) {
		
		int lenA = s.length();
		int lenB = t.length();
		if (lenA!=lenB)
		{
			return false;
		}

		int flag[256] = {0};
		for (int i = 0; i < lenA;i++)
		{
			flag[s[i]]++;
		}
		for (int i = 0; i < lenB;i++)
		{
			flag[t[i]]--;
		}
		for (int i = 0; i < lenA;i++)
		{
			if (flag[s[i]]!=0)
			{
				return false;
			}
		}
		return true;
	}
};


int main()
{
	Solution testCase;

	cout<<testCase.anagram("django", "naogdj")<<endl;


	getchar();
	return 0;
}