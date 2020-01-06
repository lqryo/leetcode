

#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix);
};

vector<int> Solution::spiralOrder(vector<vector<int>>& matrix)
{
	vector<int> ans;

	int row = matrix.size();

	if (row == 0) return ans;

	int col = matrix[0].size();

	//四条界线
	int up = 0;
	int right = col - 1;
	int down = row - 1;
	int left = 0;

	while (true)
	{
		int i = left;
		for (int i = left; i <= right; i++) {
			ans.push_back(matrix[up][i]);
		}
		up++;
		if (up > down) break;

		for (int i = up; i <= down; i++)
		{
			ans.push_back(matrix[i][right]);
		}
		right--;
		if (right < left) break;

		for (int i = right; i >= left; i--)
		{
			ans.push_back(matrix[down][i]);
		}
		down--;
		if (down < up) break;

		for (int i = down; i >= up; i--)
		{
			ans.push_back(matrix[i][left]);
		}
		left++;
		if (left > right) break;
	}


	return ans;
}




int main()
{

	vector<vector<int>> matrix{ {2,5,8},{4,0,-1} };

	Solution s;
	s.spiralOrder(matrix);
	
	


	cin.get();
	return 0;
}


