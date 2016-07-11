#include <iostream>
#include <string>
#include <vector>

using namespace std;





class Solution {
public:
	/**
	* @param s: A string
	* @param p: A string includes "?" and "*"
	* @return: A boolean
	*/
	bool isMatch(const char *s, const char *p) {
		// write your code here
		const char*str, *ptr;
		bool start = false;
		const char* i = p;
		int k = 0;
		for (str = s, ptr = p; *str != '\0'; str++, ptr++){
			if (*ptr == '?'){
				start = false; continue;
			}
			else if (*ptr == '*'){
				start = true;
				i = ptr;   //i�洢*���ڵ�λ��//
				while (*ptr == '*')ptr++;
				if (*ptr == '\0')return true;
				str--;
				ptr--;  //ptr���˵�*//
			}
			else {
				if (*ptr != *str){
					if (k == 0)return false;
					if (!start){ ptr = i; }
					ptr--;
				}
				else
					start = false;
			}
			k++;
		}
		while (*ptr == '*')ptr++;
		return *ptr == '\0';
	}
};



class Solution1 {
public:
	/**
	* @param s: A string
	* @param p: A string includes "?" and "*"
	* @return: A boolean
	*/
	bool isMatch(const char *s, const char *p) {
		// write your code here

		if (*s=='\0')
		{
			return *p == '\0' || *p == '*';
		}

		int n = strlen(s);
		int m = strlen(p);
		vector<vector<bool> > dp(n + 1, vector<bool>(m + 1, false)); 
		//dp[i][j]��ʾS��iλ����p��jλ�õ�ƥ�����
		vector<vector<bool> > f(n + 1, vector<bool>(m + 1, false));
		dp[0][0] = true;
		f[0][0] = true;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (p[j - 1] == '?')
					dp[i][j] = dp[i - 1][j - 1];
				else if (p[j - 1] == '*')
				{
					if (f[i][j - 1] || j == 1)
						dp[i][j] = true;
				}
				else
				{
					if (s[i - 1] == p[j - 1])
						dp[i][j] = dp[i - 1][j - 1];
					else
						dp[i][j] = false;
				}
				f[i][j] = f[i - 1][j] | dp[i][j];
			}

		}
		return dp[n][m];
	}
};


int main()
{

	Solution testCase;
	char* str = "aab";
	char* pattern = "a**b";

	cout<<testCase.isMatch(str, pattern);

	getchar();
	return 0;
}