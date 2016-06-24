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

class Solution {
public:
	/**
	* @param head: The first node of linked list.
	* @param n: An integer.
	* @return: The head of linked list.
	*/
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		// write your code here

		ListNode* fake = new ListNode(0);

		fake->next = head;

		ListNode *slow, *fast;

		slow = fake;
		fast = fake->next;

		while (n--&&fast!=NULL)
		{
			fast = fast->next;
		}

		while (fast!=NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
		ListNode* temp=slow->next;
		
		slow->next = temp->next;
		free(temp);
		return fake->next;
	}
};