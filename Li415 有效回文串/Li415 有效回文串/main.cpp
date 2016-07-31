#include <iostream>
#include <string>

using namespace std;




class Solution {
public:
	/**
	* @param s A string
	* @return Whether the string is a valid palindrome
	*/
	bool isPalindrome(string& s) {
		// Write your code here

		if (s.length()==0)
		{
			return true;
		}
		int i = 0;
		int j = s.length();
		while (i<j)
		{
			while (i<j&&!(isdigit(s[i])||isalpha(s[i])))
			{
				i++;
			}
			while (i<j&&!(isdigit(s[j])||isalpha(s[j])))
			{
				j--;
			}
			if (tolower(s[i])==tolower(s[j]))
			{
				i++;
				j--;
			}
			else
			{
				return false;
			}
		}
		return true;
	}
};




int main()
{
	string str = "A man, a plan, a canal: Panama";
	Solution testCase;

	cout << testCase.isPalindrome(str) << endl;

	getchar();
	return 0;
}