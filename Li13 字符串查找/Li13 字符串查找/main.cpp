#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
	/**
	* Returns a index to the first occurrence of target in source,
	* or -1  if target is not part of source.
	* @param source string to be scanned.
	* @param target string containing the sequence of characters to match.
	*/
	int strStr(const char *source, const char *target) {
		// write your code here
		if (source == NULL || target == NULL)
		{
			return -1;
		}

		if (*target=='\0')
		{
			return 0;
		}
		int pos = 0;
		while (*source!='\0')
		{
			const char* pt = target;
			if (*pt==*source)
			{   
				const char* ps=source;
				while (*pt == *ps&&*pt != '\0')
				{
					pt++;
					ps++;
				}
				if (*pt=='\0')
				{
					return pos;
				}
			}
			pos++;
			source++;
		}
		return -1;
	}
};



int main()
{
	getchar();
	return 0;
}