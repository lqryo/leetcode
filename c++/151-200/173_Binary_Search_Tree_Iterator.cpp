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



 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class BSTIterator {
public:
	BSTIterator(TreeNode* root) {
		push(root);
	}

	/** @return the next smallest number */
	int next() {
		TreeNode* node = m_stack.top();
		m_stack.pop();
		if (node->right != NULL) {
			push(node->right);
		}
		return node->val;
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !m_stack.empty();
	}


private:
	stack<TreeNode*> m_stack;

	void push(TreeNode* root) {
		while (root != NULL)
		{
			m_stack.push(root);
			root = root->left;
		}
	}
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */



 


int main()
{
	cin.get();
}
