

#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n);
};

vector<vector<int>> Solution::generateMatrix(int n)
{
	int N = n * n;
	vector<vector<int>> ans(n, vector<int>(n));

	if (n == 0) return ans;

	int up = 0;
	int right = n - 1;
	int down = n - 1;
	int left = 0;
	int curNum = 1;

	while (true)
	{
		for (int i = left; i <= right; i++) {
			ans[up][i] = curNum;
			curNum++;
		}
		up++;
		if (up > down) break;

		for (int i = up; i <= down; i++) {
			ans[i][right] = curNum;
			curNum++;
		}
		right--;
		if (right < left) break;

		for (int i = right; i >= left; i--) {
			ans[down][i] = curNum;
			curNum++;
		}
		down--;
		if (down < up) break;

		for (int i = down; i >= up; i--) {
			ans[i][left] = curNum;
			curNum++;
		}
		left++;
		if (left > right) break;
	}

	return ans;


}




int main()
{
	Solution s;
	s.generateMatrix(3);

	cin.get();

	return 0;
}

