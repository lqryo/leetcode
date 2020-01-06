#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


 // Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

 // Recursive

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		fun(root);
		return ans;
	}



private:
	vector<int> ans;
	void fun(TreeNode* node) {
		if (node == NULL) return;
		else {
			fun(node->left);
			ans.push_back(node->val);
			fun(node->right);
		}
	}
};





int main()
{
	Solution s;


	std::cin.get();
}
