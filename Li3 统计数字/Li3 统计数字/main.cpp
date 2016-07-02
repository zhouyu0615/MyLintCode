#include <iostream>
#include <vector>

using namespace std;



class Solution {
	/*
	* param k : As description.
	* param n : As description.
	* return: An integer denote the count of digit k in 1..n
	*/
public:
	int digitCounts(int k, int n) {
		// write your code here
		int res = 0;
		int base = 1;
		if (n == 0 && k == 0)   return 1;

		while (n / base > 0)
		{
			int curBit = (n / base) % 10;
			int low = n - (n / base)*base;
			int high = n / (base * 10);
			if (curBit < k) 
			{
				res += high*base;
			}
			else if (curBit == k) 
			{
				res += high*base + low + 1;
			}
			else 
			{
				if (k == 0 && high == 0){

				}
				else{
					res += (high + 1)*base;
				}
			}
			base *= 10;
		}
		return res;
	}
};



int main()
{

	getchar();
	return 0;
}