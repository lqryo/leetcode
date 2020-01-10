#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <utility>
#include <stack>


using namespace std;


// 双路归并

 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 


class Solution {
public:
	ListNode* sortList(ListNode* head) {
		ListNode dummyHead(0);
		dummyHead.next = head;
		auto p = head;
		int length = 0;
		while (p)
		{
			++length;
			p = p->next;
		}

		for (size_t size = 1; size < length; size <<= 1)
		{
			auto cur = dummyHead.next;
			auto tail = &dummyHead;

			while (cur)
			{
				auto left = cur;
				auto right = cut(left, size); //cut后的链表都已排好序
				cur = cut(right, size);

				tail->next = merge(left, right);
				while (tail->next)
				{
					tail = tail->next;
				}

			}
		}
		return dummyHead.next;

	}

private:
	ListNode* merge(ListNode* L1, ListNode* L2) {
		ListNode dummyHead(0);
		auto p = &dummyHead;
		while (L1 && L2)
		{
			if (L1->val < L2->val) {
				p->next = L1;
				p = L1;
				L1 = L1->next;
			}
			else {
				p->next = L2;
				p = L2;
				L2 = L2->next;
			}
		}
		p->next = L1 ? L1 : L2;
		return dummyHead.next;
	}

	// 切掉链表的前n个节点，并返回后半部分的链表头
	ListNode* cut(ListNode* head, int n)
	{
		auto p = head;
		while (--n && p) {
			p = p->next;
		}

		if (!p) return NULL;

		auto next = p->next;
		p->next = NULL;
		return next;

	}

};



int main()
{
	


	cin.get();
}
