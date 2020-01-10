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

// 完美二叉树劈成两半，先处理大的两半二叉树中间的左右连接，然后递归处理小的连接

class Solution {
public:
	Node* connect(Node* root) {
		if (root == NULL) return root;
		Node* left = root->left;
		Node* right = root->right;
		while (left) {
			left->next = right;
			left = left->right;
			right = right->left;
		}

		connect(root->left);
		connect(root->right);

		return root;

	}
};





int main(int argc, char* argv[])
{



	Solution s;


	std::cin.get();
}
