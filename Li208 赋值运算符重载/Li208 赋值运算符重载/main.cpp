#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
	char *m_pData;
	Solution() {
		this->m_pData = NULL;
	}
	Solution(char *pData) {
		this->m_pData = pData;
	}

	// Implement an assignment operator
	Solution operator=(const Solution &object) {
		// write your code here
		if (m_pData!=object.m_pData)
		{
			free(m_pData);
			if (object.m_pData != NULL)
			{
				m_pData = new char[strlen(object.m_pData + 1)];
				strcpy(m_pData, object.m_pData);
			}
			
		}
		return *this;
	}
};


int main()
{
	getchar();
	return 0;
}