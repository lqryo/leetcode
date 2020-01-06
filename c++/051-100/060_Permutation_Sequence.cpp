//参考:https://leetcode-cn.com/problems/permutation-sequence/solution/hui-su-jian-zhi-python-dai-ma-java-dai-ma-by-liwei/

#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
	string getPermutation(int n, int k);

	Solution()
	{
		for (int i = 0; i <= 9; i++) {
			used.push_back(false);
		}
	}


private:
	
	vector<int> factorial{ 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };

	string ans;

	vector<bool> used;


	//回溯+剪枝
	void dfs(int depth,int n,int k)
	{
		if (depth == n  - 1) {
			for (int i = 1; i <= n; i++) {
				if (!used[i]) {
					ans.append(to_string(i));
					return;
				}
			}
		}

		int ps = factorial[n - 1 - depth];
		for (int i = 1; i <= n; i++) {
			if (used[i]) continue;

			if (ps < k) {
				k -= ps;
				continue;
			}
			ans.append(to_string(i));
			used[i] = true;
			return dfs(depth + 1, n, k);
		}

	}


};


string Solution::getPermutation(int n, int k)
{
	ans.clear();
	dfs(0, n, k);
	return ans;
}




int main()
{
	Solution s;
	cout << s.getPermutation(4, 9) << endl;

	cin.get();

	return 0;
}

