#include <iostream>

using namespace std;


/*Definition of ListNode*/

class ListNode {
 public:
     int val;
     ListNode *next;

     ListNode(int val) {
         this->val = val;
         this->next = NULL;
     }
};

class Solution {
public:
	/**
	* @param head: The first node of linked list.
	* @return: The new head of reversed linked list.
	*/
	ListNode *reverse(ListNode *head) {
		// write your code here

		if (head==NULL||head->next==NULL)
		{
			return head;
		}
		ListNode *pre, *p, *post;
		pre = head;
		p = head->next;

		head->next = NULL;
		while (p!=NULL)
		{
			post = p->next;
			p->next = pre;

			pre = p;
			p = post;
		}

		return pre;
	}
};


int main()
{
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);

	Solution testCase;
	ListNode*p=testCase.reverse(head);

	
	while (p!=NULL)
	{
		cout << p->val << ", ";
		p = p->next;
	}


	getchar();
	return 0;
}
