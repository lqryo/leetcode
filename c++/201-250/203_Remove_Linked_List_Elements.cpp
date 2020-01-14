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


// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		ListNode dumyNode(0);
		dumyNode.next = head;

		ListNode* cur = &dumyNode;
		while (cur->next != NULL)
		{
			if (cur->next->val == val) {
				cur->next = cur->next->next;
			}
			else {
				cur = cur->next;
			}

		}

		return dumyNode.next;

	}
};


 


int main()
{
	cin.get();
}
