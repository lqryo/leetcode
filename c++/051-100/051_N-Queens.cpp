// 参考：https://leetcode-cn.com/problems/jump-game-ii/solution/chao-jian-dan-de-dong-tai-gui-hua-kan-bu-dong-ni-d/

#include <vector>
#include <array>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>


using namespace std;

class Solution {
public:
	vector<vector<string>> solveNQueens(int n);

private:
	int N;
	vector<int> queens;  //存放每行皇后所放的位置
	vector<vector<int>> ans;

	//检查第row行的皇后能否放在index位置
	bool check(int index,int row)
	{
		for (int i = 0; i < row; i++) {
			if ((index == queens[i]) ||((index - row) == (queens[i]  - i)) || (index + row) == (i + queens[i]))
				return false;			
		}
		return true;

	}

	void trackback(int row)
	{
		if (row == N) {
			ans.push_back(queens);
			return;
		}

		for (size_t i = 0; i < N; i++)
		{
			if (check(i, row)) {
				queens.push_back(i);
				trackback(row + 1);
				queens.pop_back();

			}
		}
	}
	
};


vector<vector<string>> Solution::solveNQueens(int n) {
	vector<vector<string>> result;
	ans.clear();
	N = n;
	trackback(0);
	int ans_num = ans.size();
	
	for (size_t i = 0; i < ans_num; i++)
	{
		vector<string> solution;
		for (size_t j = 0; j < n; j++)
		{
			string s(n, '.');
			s.replace(ans[i][j], 1, "Q");
			solution.push_back(s);
		}
		result.push_back(solution);
	}

	return result;
}


int main()
{
	
	Solution s;

	vector<vector<string>> ans;

	ans = s.solveNQueens(4);
	getchar();	
	return 0;

}