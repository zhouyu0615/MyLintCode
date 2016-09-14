#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
	/**
	*@param A: A list of integers
	*@param elem: An integer
	*@return: The new length after remove
	*/
	int removeElement(vector<int> &A, int elem) {
		// write your code here

		if (A.size() == 0) return 0;

		int front = 0;
		int back = A.size()-1;

		while (front < back)
		{
			while (back>front&&A[back]==elem)
			{
				back--;
			}

			while (front<back&&A[front]!=elem)
			{
				front++;
			}
			if (front==back) break;
			Swap(A[front], A[back]);
			front++;
			back--;
		}

		if (A[front] != elem&&front!=A.size()) front++;
		

		A.erase(A.begin() + front, A.end());
		return A.size();
	}

	void Swap(int &a, int &b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
};


int main()
{
	vector<int> nums = { 4,4,4,4,4,4,4,4 };
	int target = 4;

	Solution testCase;

	cout << testCase.removeElement(nums, target)  << endl;

 
	getchar();
	return 0;
}