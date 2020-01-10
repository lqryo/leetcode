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
	 TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		 if (preorder.size() == 0) return NULL;
		 this->preorder = preorder;
		 this->inorder = inorder;
		 return build(0, preorder.size() - 1, 0, inorder.size() - 1);
	 }
 private:
	 TreeNode* build(int ps, int pe, int is, int ie)
	 {
		 // 构建根节点
		 TreeNode* root = new TreeNode(preorder[ps]);
		 
		 // 在中序序列中寻找根节点
		 int i = is;
		 while (i <= ie && preorder[ps] != inorder[i])
			 i++;

		 // i指向中序序列中根节点位置
		 int l1 = i - is;  //左子树序列长度
		 int r1 = ie - i;  //右子树序列长度
		 
		 // 构建左右子树
		 if (l1 > 0) {
			 root->left = build(ps + 1, ps + l1, is, is + l1 - 1);
		 }
		 if (r1 > 0) {
			 root->right = build(ps + l1 + 1, pe, is + l1 + 1, ie);
		 }
		 return  root;


	 }

	 vector<int> preorder;
	 vector<int> inorder;
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
