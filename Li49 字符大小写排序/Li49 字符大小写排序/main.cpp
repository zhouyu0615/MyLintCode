#include <iostream>
#include <string>


using namespace std;


class Solution {
public:
	/**
	* @param chars: The letters array you should sort.
	*/
	void sortLetters(string &letters) {
		// write your code here

		int i = 0;
		int j = letters.length()-1;
		
		while (i<=j)
		{
			while (i<j&&islower(letters[i]))
			{
				i++;
			}

			while (i<j&&isupper(letters[j]))
			{
				j--;
			}

			Swap(letters[i], letters[j]);
			i++;
			j--;
		}
	}

	void Swap(char &a, char &b)
	{
		char temp = a;
		a = b;
		b = temp;
		return;
	}
};



int main()
{

	string str = "abAcD";
	Solution testCase;

	testCase.sortLetters(str);
	cout << str << endl;

	getchar();
	return 0;
}