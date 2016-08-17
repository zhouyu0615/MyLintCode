#include <iostream>
#include <vector>


using namespace std;



/* Definition of ListNode*/
class ListNode {
 public:
     int val;
     ListNode *next;
     ListNode(int val) {
         this->val = val;
         this->next = NULL;
     }
};

class Solution2 {
public:
	/**
	* @param head: The first node of linked list.
	* @return: You should return the head of the sorted linked list,
	using constant space complexity.
	*/
	ListNode *sortList(ListNode *head) {
		// write your code here
		
		ListNode *pnewHead, *pnewTail;

		pnewHead = NULL;
		pnewTail = NULL;

		ListNode* pMinNode;
		ListNode* prvNode;
		ListNode* prestHead=head;

		ListNode* pNode;

		while (prestHead!=NULL)
		{
			pMinNode = prestHead;
			pNode = prestHead;
			prvNode = prestHead;
			while (pNode->next!=NULL)
			{
				if (pMinNode->val > pNode->next->val)
				{
					pMinNode = pNode->next;
					prvNode = pNode;
				}
				pNode = pNode->next;
			}

			if (pMinNode==prestHead)
			{
				prestHead = prestHead->next;
			}
			else
			{
				prvNode->next = pMinNode->next;
				pMinNode->next = NULL;
			}
			
			if (pnewHead==NULL)
			{
				pnewHead = pnewTail = pMinNode;
			}
			else
			{
				pnewTail->next = pMinNode;
				pnewTail = pnewTail->next;
			}
		}

		return pnewHead;
	}
};



class Solution {
public:
	/**
	* @param head: The first node of linked list.
	* @return: You should return the head of the sorted linked list,
	using constant space complexity.
	*/
	ListNode *sortList(ListNode *head) {
		// write your code here

		if (head==NULL||head->next==NULL)
		{
			return head;
		}

		ListNode* pMid = getMidNode(head);
		ListNode* pRest=NULL;
		if (pMid!=NULL)
		{
			pRest=pMid->next;
			pMid->next = NULL;
		}	
		return MergeLists(sortList(head), sortList(pRest));
	}

private:
	ListNode* MergeLists(ListNode* pHead1, ListNode*pHead2)
	{
		if (pHead1 == NULL) return pHead2;
		if (pHead2 == NULL) return pHead1;
		
		ListNode *pNewHead, *pNewTail;
		ListNode *p1, *p2;
		pNewHead = pNewTail = NULL;
		p1 = pHead1;
		p2 = pHead2;
		ListNode* pNode;
		while (p1!=NULL&&p2!=NULL)
		{
			if (p1->val < p2->val)
			{
				pNode = p1;
				p1 = p1->next;
			} else
			{
				pNode = p2;
				p2 = p2->next;			
			}
			pNode->next = NULL;

			if (pNewHead!=NULL)
			{
				pNewTail->next = pNode;
				pNewTail = pNewTail->next;
			}
			else
			{
				pNewHead = pNewTail = pNode;
			}
		}
		if (p1==NULL)
		{
			pNewTail->next = p2;
		}
		if (p2==NULL)
		{
			pNewTail->next = p1;
		}

		return pNewHead;
	}

	ListNode* getMidNode(ListNode* pHead)
	{
		if (pHead == NULL || pHead->next == NULL)
		{
			return pHead;
		}
		ListNode* pFast, *pSlow;
		pFast = pHead->next;
		pSlow = pHead;

		while (pFast!=NULL&&pFast->next!=NULL)
		{
			pFast = pFast->next->next;		
			pSlow = pSlow->next;
		}	
		return pSlow;
	}
};




int main()
{

	Solution testCase;
	
	ListNode *pHead = new ListNode(1);
	pHead->next = new ListNode(1);
	pHead->next->next = new ListNode(5);
	pHead->next->next->next = new ListNode(2);

	testCase.sortList(pHead);


	getchar();
	return 0;
}