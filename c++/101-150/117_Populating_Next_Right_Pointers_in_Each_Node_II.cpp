#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <glog/logging.h>

using namespace std;


// Definition for a Node.
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() : val(0), left(NULL), right(NULL), next(NULL) {}

	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

	Node(int _val, Node* _left, Node* _right, Node* _next)
		: val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
	Node* connect(Node* root) {
		Node* last = root;
		while (last != NULL) {
			// 获取首元素
			while (last && last->left == NULL && last->right == NULL)
			{
				last = last->next;
			}
			if (last == NULL) break;
			Node* cur = NULL;
			// 遍历队列
			for (Node* i = last; i != NULL; i = i->next) {
				// 进行push和pop操作
				if (i->left) {
					if (cur != NULL) {
						cur->next = i->left;
					}
					cur = i->left;
				}
				if (i->right) {
					if (cur != NULL) {
						cur->next = i->right;
					}
					cur = i->right;
				}
			}
			//更新队首
			last = last->left ? last->left : last->right;
		}
		return root;
	}
};





int main(int argc, char* argv[])
{



	Solution s;


	std::cin.get();
}
