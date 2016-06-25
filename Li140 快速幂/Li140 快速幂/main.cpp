#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	/*
	* @param a, b, n: 32bit integers
	* @return: An integer
	*/
	int fastPower(int a, int b, int n) {
		// write your code here
		if (b==0||n<0)
		{
			return 0;
		}

		if (b==1&&n==0)
		{
			return 0;
		}

		long ans = 1;
		long atem =a;
		while (n>0)
		{
			if (n%2==1)
			{
				ans = (ans*atem) % b;
			}
			n = n / 2;
			atem = ((atem%b)*(atem%b)) % b;
		}
		return ans;
	}
};




int main()
{

	getchar();
	return 0;
}