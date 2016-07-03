#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
	/*
	* @param n an integer
	* @return the nth prime number as description.
	*/
	int nthUglyNumber(int n) {
		// write your code here
		if (n<=0)
		{
			return 0;
		}

		int number=0;
		int uglycount = 0;
		while (uglycount<n)
		{
			number++;
			if (isUgly(number))
			{
				uglycount++;
			}
		}
		return number;
	}
private:
	bool isUgly(int number)
	{	
		while (number%2==0)
		{
			number /= 2;
		}
		while (number % 3 == 0)
		{
			number /= 3;
		}
		while (number % 5 == 0)
		{
			number /= 5;
		}

		return number == 1 ? true : false;
	}
};



class Solution {
public:
	/*
	* @param n an integer
	* @return the nth prime number as description.
	*/
	int nthUglyNumber(int n) {
		// write your code here
		if (n<=0)
		{
			return 0;
		}

		int *pUglyNums = new int[n];
		pUglyNums[0] = 1;

		int *pUglyNums2 = pUglyNums;
		int *pUglyNums3 = pUglyNums;
		int *pUglyNums5 = pUglyNums;

		int nextUglyIndex = 1;
		while (nextUglyIndex<n)
		{
			int min = Min(*pUglyNums2 * 2, *pUglyNums3 * 3, *pUglyNums5 * 5);
			pUglyNums[nextUglyIndex] = min;
			while (*pUglyNums2*2<=pUglyNums[nextUglyIndex])
			{
				*pUglyNums2++;
			}
			while (*pUglyNums3 * 3 <= pUglyNums[nextUglyIndex])
			{
				*pUglyNums3++;
			}
			while (*pUglyNums5 * 5 <= pUglyNums[nextUglyIndex])
			{
				*pUglyNums5++;
			}
			nextUglyIndex++;
		}

		int ugly = pUglyNums[nextUglyIndex - 1];
		delete[] pUglyNums;
		return ugly;
	}
private:
	int Min(int a, int b, int c)
	{
		int min = a < b ? a : b;
		min = (min < c ? min : c);
		return min;
	}

};



int main()
{


	getchar();
	return 0;
}