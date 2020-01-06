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

 // 参考：https://leetcode-cn.com/problems/binary-tree-inorder-traversal/solution/er-cha-shu-de-zhong-xu-bian-li-by-leetcode/
 // 莫里斯遍历

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ans;
		TreeNode* curr = root;
		TreeNode* pre;
		while (curr != NULL) {
			if (curr->left == NULL) {
				ans.push_back(curr->val);
				curr = curr->right;
			}
			else {
				pre = curr->left;
				while (pre->right != NULL)
				{
					pre = pre->right;
				}
				pre->right = curr;
				TreeNode* tmp = curr;
				curr = curr->left;
				tmp->left = NULL;  //original cur left be null, avoid infinite loops
			}
		}
		return ans;

	}

};





int main()
{
	Solution s;


	std::cin.get();
}
