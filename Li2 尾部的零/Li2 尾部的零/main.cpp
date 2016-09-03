#include <iostream>

using namespace std;


class Solution {
public:
	// param n : description of n
	// return: description of return 
	long long trailingZeros(long long n) {
		long long temp = n;
		long long count = 0;
		while (temp)
		{
			count += (long long)temp / 5;
			temp = temp / 5;
		}
		return count;
	}
};



int main()
{
	getchar();
	return 0;
}