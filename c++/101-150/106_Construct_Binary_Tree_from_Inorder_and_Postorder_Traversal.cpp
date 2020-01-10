#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <glog/logging.h>

using namespace std;


 //Definition for a binary tree node.
 struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

 // 递归构造
 
 class Solution {
 public:
	 TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		 if (inorder.size() == 0) return NULL;
		 this->inorder = inorder;
		 this->posorder = posorder;
		 
		 return build(0, inorder.size() - 1, 0, posorder.size() - 1);
	 }


 private:
	 vector<int> inorder;
	 vector<int> posorder;

	 TreeNode* build(int is, int ie, int ps, int pe)
	 {
		 if (is > ie || ps > pe) return NULL;

		 TreeNode* root = new TreeNode(posorder[pe]);

		 int index = is;
		 while (index <= ie && inorder[index] != posorder[pe])
			 index++;

		 // index为inorder中根的位置
		 int l_len = index - is;  // 左子树的长度
		 int r_len = ie - index;  // 右子树的长度

		 if (l_len != 0) {
			 root->left = build(is, is + l_len, ps, ps + l_len);
		 }
		 if (r_len != 0) {
			 root->right = build(index+1,ie,ps+l_len+1,pe-1);
		 }
		 return root;
	 }

 };




int main(int argc, char* argv[])
{
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	Solution s;
//	cout << s.maxDepth(root) << endl;
	

	std::cin.get();
}
