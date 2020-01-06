#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

//参考：https://leetcode-cn.com/problems/set-matrix-zeroes/solution/c-tong-guo-di-yi-xing-he-di-yi-lie-jin-xing-pan-du/
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		if (matrix.size() == 0) return ;
		const int m = matrix.size();  //row
		const int n = matrix[0].size(); //column
		bool firstRow = false;
		bool firstCol = false;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				const int item = matrix[i][j];
				if (item == 0) {
					if (i == 0) { firstRow = true; }
					if (j == 0) { firstCol = true; }
					matrix[0][j] = 0;
					matrix[i][0] = 0;
				}
			}
		}

		for (size_t i = 1; i < m; i++)
		{
			for (size_t j = 1; j < n; j++)
			{
				if (matrix[0][j] == 0 || matrix[i][0] == 0) {
					matrix[i][j] = 0;
				}
			}
		}

		//修改第一行和第一列
		if (firstRow) {
			for (int i = 0; i < n; i++) {
				matrix[0][i] = 0;
			}
		}

		if (firstCol) {
			for (int i = 0; i < m; i++) {
				matrix[i][0] = 0;
			}
		}
	}

};

int main()
{
	Solution s;

	vector<vector<int>> matrix = { {1,1,1},{1,0,1},{1,1,1} };
	s.setZeroes(matrix);


	std::cin.get();
}
