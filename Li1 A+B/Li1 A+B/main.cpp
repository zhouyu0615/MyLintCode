#include <iostream>


class Solution {
public:
	/*
	* @param a: The first integer
	* @param b: The second integer
	* @return: The sum of a and b
	*/
	int aplusb(int a, int b) {
		// write your code here, try to do it without arithmetic operators.

		int sum = 0;
		int carry = 0;//½øÎ»


		while (b!=0)
		{
			sum = a^b;
			carry = (a&b) << 1;
			
			a = sum;
			b = carry;
		}
		return a;
	}
};


int main()
{
	getchar();
	return 0;
}