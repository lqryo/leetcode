//µÝ¹é
//40ms »÷°Ü95.91ÓÃ»§
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};

ListNode* merge2Lists(ListNode* node1, ListNode* node2)
{
	if (node1 == nullptr) { return node2; }
	if (node2 == nullptr) { return node1; }

	if (node1->val < node2->val) {
		node1->next = merge2Lists(node1->next,node2);
		return node1;
	}
	else {
		node2->next = merge2Lists(node2->next, node1);
		return node2;
	}
}

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists);
};

ListNode * Solution::mergeKLists(vector<ListNode*>& lists)
{
	size_t length = lists.size();
	if (length == 0) { return nullptr; }

	queue<ListNode*> qlists{};
	for (size_t i = 0; i < length; i++)
	{
		qlists.push(lists[i]);
	}
	while (qlists.size() > 1)
	{
		ListNode* t1 = qlists.front();
		qlists.pop();
		ListNode* t2 = qlists.front();
		qlists.pop();
		ListNode* t = merge2Lists(t1,t2);
		qlists.push(t);
	}
	return qlists.front();
}

int main()
{
	Solution s;
	vector<ListNode*> L{};

	s.mergeKLists(L);

	cin.get();
	return 0;
}
