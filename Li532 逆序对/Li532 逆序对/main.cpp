#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	/**
	* @param A an array
	* @return total of reverse pairs
	*/
	long long reversePairs(vector<int>& A) {
		// Write your code here

		long long count = 0;

		int len = A.size();

		for (int i = 0; i < len;i++)
		{
			for (int j = i; j < len;j++)
			{
				if (A[i]>A[j])
				{
					count++;
				}
			}
		}
		return count;
	}
};



class Solution {
public:
	/**
	* @param A an array
	* @return total of reverse pairs
	*/
	long long reversePairs(vector<int>& A) {
		
		int len = A.size();
		if (len==0)
		{
			return 0;
		}

		vector<int> copy(A);

		long long count = InversePairsCore(A, copy, 0, len - 1);
		return count;
	}
private:
	long long InversePairsCore(vector<int>& A, vector<int>& copy,int start,int end)
	{
		if (start==end)
		{
			copy[start] = A[start];
			return 0;
		}

		int halfLen = (end - start) / 2;
		long long left = InversePairsCore( A, copy,start, start + halfLen);
		long long right = InversePairsCore( A,copy, start + halfLen + 1, end);

		
		int i = start + halfLen; //i为前半段最后一个数字的下标//
		int j = end; //j为后半段最后一个数字的下标//

		int IndexCopy = end;
		long long count = 0;

		while (i>=start&&j>=start+halfLen+1)
		{
			if (A[i]>A[j])
			{
				copy[IndexCopy--] = A[i--];
				count += j - start - halfLen;
			}
			else
			{
				copy[IndexCopy--] = A[j--];
			}	
		}
		for (; i >= start; --i)
		{
			copy[IndexCopy--] = A[i];
		}

		for (; j >= start + halfLen + 1; --j)
		{
			copy[IndexCopy--] = A[j];
		}

		return left + right + count;

	}
};



int main()
{
	getchar();
	return 0;
}