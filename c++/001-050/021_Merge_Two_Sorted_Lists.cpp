#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
};

ListNode * Solution::mergeTwoLists(ListNode * l1, ListNode * l2)
{
	vector<int> L{};
	while (l1 != nullptr)
	{
		L.push_back(l1->val);
		l1 = l1->next;
	}
	while (l2 != nullptr)
	{
		L.push_back(l2->val);
		l2 = l2->next;
	}
	
	sort(L.begin(),L.end());
	size_t length = L.size();
	if (length == 0) { return nullptr; }

	ListNode* head = new ListNode(L[0]);
	ListNode* lp = head;
	for (size_t i = 1; i < length; i++)
	{
		lp->next = new ListNode(L[i]);
		lp = lp->next;
	}

	return head;
}

int main()
{
	Solution s;
	s.mergeTwoLists(nullptr, nullptr);

	cin.get();
	return 0;
}




