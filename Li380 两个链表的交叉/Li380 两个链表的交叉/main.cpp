#include <iostream>



/**
* Definition for singly-linked list.*/
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	/**
	* @param headA: the first list
	* @param headB: the second list
	* @return: a ListNode
	*/
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA==NULL||headB==NULL)
		{
			return NULL;
		}
		int lenA = 0;
		int lenB = 0;

		ListNode* pA=headA;
		ListNode* pB=headB;
		while (pA  !=  NULL)
		{
			lenA++;
			pA = pA->next;
		}

		while (pB!= NULL)
		{
			lenB++;
			pB = pB->next;
		}

		if (pA!=pB)
		{
			return NULL;
		}

		pA = headA;
		pB = headB;
		if (lenA>lenB)
		{
			int nStep = lenA - lenB;
			while (nStep--)
			{
				pA = pA->next;
			}
		}
		else if (lenA<lenB)
		{
			int nStep = lenB - lenA;
			while (nStep--)
			{
				pB = pB->next;
			}	
		}
		
		while (pA!=pB)
		{
			pA=pA->next;
			pB=pB->next;
		}
		return pA;
	}
};


int main()
{
	getchar();
	return 0;
}

