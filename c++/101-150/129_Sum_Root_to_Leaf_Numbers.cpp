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


using namespace std;


// Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
// DFS
class Solution {
public:
	int sumNumbers(TreeNode* root) {
		int res = 0;
		dfs(root, 0, res);
		return res;
	}
private:
	void dfs(TreeNode* root, int p, int& res) {
		if (root == NULL) return;
		p = 10 * p + root->val;
		if (root->left == NULL && root->right == NULL) {
			res += p;
			return;
		}
		dfs(root->left, p, res);
		dfs(root->right, p, res);
	}
};



int main(int argc, char* argv[])
{



	Solution S;

	

	std::cin.get();
}
