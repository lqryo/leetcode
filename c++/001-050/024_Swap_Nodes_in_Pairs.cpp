//µİ¹é
//ÓÃÊ±12ms »÷°Ü56%
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head);
};

ListNode * Solution::swapPairs(ListNode * head)
{
	if (head == nullptr) { return head; }
	if (head->next == nullptr) { return head; }

	ListNode* newHead = head->next->next;
	ListNode* nextNode = head->next;
	nextNode->next = head;
	head->next = swapPairs(newHead);

	return nextNode;
}

int main()
{
	Solution s;

	cin.get();
	return 0;
}
