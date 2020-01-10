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


using namespace std;


// Definition for a Node.
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};




class Solution {
public:
	// 先构造节点，在完成连接关系
	Node* copyRandomList(Node* head) {
		if (head == NULL) return NULL;

		unordered_map<Node*, Node*>  m_map;
		unordered_map<Node*, Node*> m_connection;
		Node* cur = head;
		Node* pre = NULL;
		while (cur != NULL)
		{
			Node* newnode = new Node(cur->val);
			if (pre == NULL) {
				pre = newnode;
			}
			else {
				pre->next = newnode;
				pre = newnode;   // don't miss this
			}
			m_map[cur] = newnode;
			m_connection[cur] = cur->random;
			cur = cur->next;

		}

		cur = head;
		Node* ans = m_map[head];
		Node* tmp;
		while (cur != NULL)
		{
			tmp = m_map[cur];
			tmp->random = m_map[m_connection[cur]];
			cur = cur->next;
		}

		return ans;
	}
};

int main()
{
	Solution s;

	Node* n1 = new Node(7);
	Node* n2 = new Node(13);
	Node* n3 = new Node(1);

	n1->next = n2;
	n2->next = n3;

	n1->random = NULL;
	n2->random = n1;
	n3->random = n1;

	s.copyRandomList(n1);

	cin.get();
}
