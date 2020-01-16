
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>

using namespace std;

class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		if (matrix.size() == 0) return 0;
		int row = matrix.size();
		int col = matrix[0].size();
		vector<vector<int>> dp(row + 1, vector<int>(col + 1));
		int ans = 0;

		// ³õÊ¼»¯²Ù×÷
		for (size_t i = 0; i <= row; i++)
		{
			dp[i][0] = 0;
		}

		for (size_t i = 0; i < col; i++)
		{
			dp[0][i] = 0;
		}

		for (size_t i = 1; i <= row; i++)
		{
			for (size_t j = 1; j <= col; j++)
			{
				if (matrix[i - 1][j - 1] == '1') {
					dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j],dp[i][j-1]) + 1;
					if (dp[i][j] > ans) ans = dp[i][j];
				}
			}
		}
		return ans * ans; 
	}

private:
	int min(int a, int b, int c) {
		a = (a < b) ? a : b;
		return a < c ? a : c;
	}
};

int main()
{
	Solution s;

	cin.get();

	return 0;
}

