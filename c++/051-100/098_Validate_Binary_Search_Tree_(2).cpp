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


// Iteration 24ms

 class Solution {
 public:
	 bool isValidBST(TreeNode* root) {
		 llong lower = LLONG_MIN;
		 llong upper = LLONG_MAX;
		 int val;
		 update(root, lower, upper);

		 while (!stack.empty())
		 {
			 root = stack.back();
			 lower = lowers.back();
			 upper = uppers.back();

			 stack.pop_back();
			 lowers.pop_back();
			 uppers.pop_back();

			 if (root == NULL) continue;
			 val = root->val;
			 if (val <= lower) return false;
			 if (val >= upper) return false;
			 update(root->right, val, upper);
			 update(root->left, lower, val);
		 }
		 return true;
	 }

 private:
	 typedef long long int llong;
	 vector<llong>uppers;
	 vector<llong>lowers;
	 vector<TreeNode*> stack;

	 void update(TreeNode* node, llong lower, llong upper)
	 {
		 stack.push_back(node);
		 lowers.push_back(lower);
		 uppers.push_back(upper);
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
