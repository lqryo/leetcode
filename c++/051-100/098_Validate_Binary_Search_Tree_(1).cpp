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


// Recursion 16ms

 class Solution {
 public:
	 bool isValidBST(TreeNode* root) {
		 return fun(root,LLONG_MIN,LLONG_MAX);
	 }

 private:
	 bool fun(TreeNode* node, long long lower, long long upper)
	 {
		 if (node == NULL) return true;

		 int val = node->val;
		 if (val <= lower) return false;
		 if (val >= upper) return false;

		 if (!fun(node->right, val, upper)) return false;
		 if (!fun(node->left, lower, val)) return false;

		 return true;

	 }

 };





int main()
{
	Solution s;

	int i = 1;
	if (i > LLONG_MIN) { cout << "i > llong_min" << endl; }
	if (i < LLONG_MAX) { cout << "i < llong_max" << endl; }

	TreeNode* root = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left = new TreeNode(1);

	cout << s.isValidBST(root) << endl;

	std::cin.get();
}
