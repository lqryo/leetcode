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





// Definition for a binary tree node.
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

// iteration

class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		if (root == NULL) return ans;
		stack<TreeNode*> m_stack;
		m_stack.push(root);
		while (m_stack.size()!= 0)
		{
			TreeNode* node = m_stack.top();
			m_stack.pop();
			ans.push_back(node->val);
			if(node->right != NULL) m_stack.push(node->right);
			if(node->left != NULL) m_stack.push(node->left);
		}

		return ans;
	}

private:
	vector<int> ans;
};

int main()
{
	Solution s;


	cin.get();
}
