//递归
//用时52ms 击败39.48%用户
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k);
};

ListNode * Solution::reverseKGroup(ListNode * head, int k)
{
	ListNode* tempNode = head;
	for (size_t i = 0; i < k; i++)
	{
		if (tempNode == nullptr) { return head; }
		tempNode = tempNode->next;
	}

	ListNode* pHead = head;
	ListNode* pPre = head;
	ListNode* pCurrent = head->next;
	for (size_t i = 0; i < k-1; i++)
	{
		ListNode* pNext = pCurrent->next;
		pCurrent->next = pPre;
		pPre = pCurrent;
		pCurrent = pNext;
	}

	pHead->next = reverseKGroup(pCurrent, k);

	return pPre;
}

int main()
{
	ListNode* L1 = new ListNode(1);
	L1->next = new ListNode(2);
	L1->next->next = new ListNode(3);
	L1->next->next->next = new ListNode(4);
	L1->next->next->next->next = new ListNode(5);


	Solution s;
	s.reverseKGroup(L1,2);

	cin.get();
	return 0;
}

