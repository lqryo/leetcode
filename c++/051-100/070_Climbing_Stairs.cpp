

#include <vector>
#include <array>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>


using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		if (n == 0) return 0;
		if (n == 1) return 1;
		if (n == 2) return 2;
		vector<int> dp(n + 1);
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 2;
		for (int i = 3; i <= n; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[n];
	}
};


int main()
{
	Solution s;
	cout << s.climbStairs(3) << endl;
	cin.get();
	return 0;

}