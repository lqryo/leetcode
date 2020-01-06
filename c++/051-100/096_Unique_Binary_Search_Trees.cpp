#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 参考：https://leetcode-cn.com/problems/unique-binary-search-trees/solution/bu-tong-de-er-cha-sou-suo-shu-by-leetcode/

 // Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


 // 动态规划
 
 // G(n)：长度为n的序列的不同二叉树搜索树个数
 // F(i,n)：以i为根的不同二叉树搜索树个数(1<=i<=n)

 class Solution {
 public:
	 int numTrees(int n) {
		 vector<int> G(n + 1);
		 G[0] = 1;
		 G[1] = 1;

		 for (size_t i = 2; i <= n; i++)
		 {
			 for (size_t j = 1; j <= i; j++)
			 {
				 G[i] += G[j - 1] * G[i - j];
			 }
		 }
		
		 return G[n];

	 }
 };





int main()
{
	Solution s;

	std::cout << s.numTrees(3) << std::endl;


	std::cin.get();
}
