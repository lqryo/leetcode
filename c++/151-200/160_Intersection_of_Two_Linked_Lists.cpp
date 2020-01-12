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

// 参考：https://leetcode-cn.com/problems/intersection-of-two-linked-lists/solution/xiang-jiao-lian-biao-by-leetcode/


// Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

// 双指针法

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == NULL || headB == NULL) return NULL;
		ListNode* L1 = headA;
		ListNode* L2 = headB;

		ListNode* L1_tail = NULL;
		ListNode* L2_tail = NULL;


		while (true)
		{
			if (L1 == L2) return L1;

			if (L1->next != NULL) L1 = L1->next;
			else {
				L1_tail = L1;
				L1 = headB;
			}
			if (L2->next != NULL) L2 = L2->next;
			else {
				L2_tail = L2;
				L2 = headA;
			}

			if (L1_tail != NULL && L2_tail != NULL) {
				if (L1_tail != L2_tail) return NULL;
			}

		}
	}
};






int main()
{
	cin.get();
}
