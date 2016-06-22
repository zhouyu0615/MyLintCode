#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
	/**
	* @param string: An array of Char
	* @param length: The true length of the string
	* @return: The true length of new string
	*/
	int replaceBlank(char* string, int length) {
		// Write your code here
		if (string==NULL||length==0)
		{
			return length;
		}

		char * pOrg=string;
		int NumOfBanks=0;
		int orgLen=0;

		while (*pOrg!='\0')
		{
			orgLen++;
			if (*pOrg==' ')
			{
				NumOfBanks++;
			}
			pOrg++;
		}

		int newStringLen = orgLen + NumOfBanks * 2;

		char* pOrgEnd = string + orgLen;

		char *pNewEnd = string + newStringLen;
		length += 1;
		while (length--&&pNewEnd!=pOrgEnd)
		{
			if (*pOrgEnd!=' ')
			{
				*pNewEnd = *pOrgEnd;
				pNewEnd--;
			}
			else
			{
				*pNewEnd = '0';
				pNewEnd--;
				*pNewEnd = '2';
				pNewEnd--;
				*pNewEnd = '%';
				pNewEnd--;
			}
			pOrgEnd--;
		}
		return newStringLen;
	}
};


int main()
{
	char string[] = " he llo wo rld ";
	Solution testCase;

	cout << testCase.replaceBlank(string, strlen(string))<<endl;

	cout << string << endl;


	getchar();
	return 0;
}