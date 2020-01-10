#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <glog/logging.h>

using namespace std;


// Definition for a binary tree node.
 struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


 // 参考：https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by--26/
 // Morris遍历

 class Solution {
 public:
	 void flatten(TreeNode* root) {
		 while (root != NULL)
		 {
			 // 左树为Null，直接考虑下一个节点
			 if (root->left == NULL) {
				 root = root->right;
			 }
			 else {
				 // 找左子树最右边的节点
				 TreeNode* pre = root->left;
				 while(pre->right != NULL){
					 pre = pre->right;
				 }

				 // 将原来的右子树接到左子树最右边节点
				 pre->right = root->right;
				 // 将左子树插入到右子树的地方
				 root->right = root->left;
				 root->left = NULL;
				 
				 // 考虑下一个节点
				 root = root->right;

			 }
		 }

	 }

 };



int main(int argc, char* argv[])
{
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);


	Solution s;

	s.flatten(root);
	std::cin.get();
}
