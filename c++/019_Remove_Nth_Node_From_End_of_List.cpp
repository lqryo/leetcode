#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n);
};

//利用双指针
ListNode* Solution::removeNthFromEnd(ListNode* head, int n)
{
	ListNode* p1 = head;
	ListNode* p2 = head;
	for (size_t i = 0; i <= n ; i++)
	{
		if (p1 == nullptr)
		{
			if (i == n) {
				ListNode* temp = head->next;
//				head->next = nullptr;
				delete head;
				return temp;
			}
		}
		p1 = p1->next;
	}
	while (p1 != nullptr) {
		p1 = p1->next;
		p2 = p2->next;
	}
	//删除p2后面的元素
	ListNode* temp = p2->next;
	p2->next = p2->next->next;
//	temp->next = nullptr;
	delete temp;
	return head;
}

int main()
{
	ListNode* head = new ListNode(1);
	ListNode* L = head;
	L->next = new ListNode(2);
	L = L->next;
	L->next = new ListNode(3);
	L = L->next;
	L->next = new ListNode(4);
	L = L->next;
	L->next = new ListNode(5);


	Solution s;
	s.removeNthFromEnd(head, 2);
//	s.removeNthFromEnd(head, 5);

	cin.get();
	return 0;
}

